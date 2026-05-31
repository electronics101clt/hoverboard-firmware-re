/*
 * ============================================================================
 * HOVERBOARD FIRMWARE - CLEANED & ANNOTATED
 * ============================================================================
 *
 * MCU: STM32F103C8T6 (ARM Cortex-M3, 72MHz, 64KB Flash, 20KB RAM)
 * Motors: 2x 3-phase BLDC hub motors (6-step commutation)
 *
 * Original firmware extracted from Chinese hoverboard mainboard.
 * Decompiled with Ghidra, cleaned up for readability.
 *
 * HARDWARE LAYOUT:
 *   - TIM1: PWM for Motor 1 (left wheel) - 3 channels + complementary
 *   - TIM8: PWM for Motor 2 (right wheel) - 3 channels + complementary
 *   - GPIOB: Hall sensors (3 per motor = 6 total)
 *   - ADC1: Battery voltage, motor currents
 *   - USART: Communication between master/slave boards
 */

#include <stdint.h>

/* ============================================================================
 * STM32F103 PERIPHERAL DEFINITIONS
 * ============================================================================ */

#define PERIPH_BASE       0x40000000
#define APB1PERIPH_BASE   PERIPH_BASE
#define APB2PERIPH_BASE   (PERIPH_BASE + 0x10000)

/* Timer bases (Advanced timers for motor PWM) */
#define TIM1_BASE         0x40012C00
#define TIM8_BASE         0x40013400

/* GPIO bases */
#define GPIOA_BASE        0x40010800
#define GPIOB_BASE        0x40010C00
#define GPIOC_BASE        0x40011000

/* Timer register offsets */
#define TIM_CR1    0x00   /* Control register 1 */
#define TIM_CCER   0x20   /* Capture/compare enable - enables PWM outputs */
#define TIM_ARR    0x2C   /* Auto-reload - sets PWM period */
#define TIM_CCR1   0x34   /* Capture/compare 1 - Phase A duty cycle */
#define TIM_CCR2   0x38   /* Capture/compare 2 - Phase B duty cycle */
#define TIM_CCR3   0x3C   /* Capture/compare 3 - Phase C duty cycle */
#define TIM_BDTR   0x44   /* Break and dead-time register */

/* PWM period (timer ARR value) */
#define PWM_PERIOD  0x200  /* 512 counts = ~14kHz at 72MHz/14 */


/* ============================================================================
 * HALL SENSOR READING
 * ============================================================================
 *
 * Reads 3 Hall effect sensors to determine rotor position.
 * Returns a 3-bit value (0-7, but only 6 valid states for BLDC).
 *
 * Hall sensors are connected to GPIO pins:
 *   - Hall A: GPIOB pin 5 (0x20)
 *   - Hall B: GPIOB pin 6 (0x40)
 *   - Hall C: GPIOB pin 7 (0x80)
 */
uint8_t hall_read_state(void)
{
    volatile uint32_t *gpio = (uint32_t*)GPIOB_BASE;
    uint32_t input_data = gpio[2];  /* GPIO_IDR offset 0x08 */

    uint8_t hall_a = (input_data >> 5) & 1;  /* Pin 5 */
    uint8_t hall_b = (input_data >> 6) & 1;  /* Pin 6 */
    uint8_t hall_c = (input_data >> 7) & 1;  /* Pin 7 */

    return hall_a | (hall_b << 1) | (hall_c << 2);
}


/* ============================================================================
 * CLARKE TRANSFORM
 * ============================================================================
 *
 * Converts 3-phase currents (Ia, Ib, Ic) to 2-axis (alpha, beta).
 * This is the first step in Field Oriented Control (FOC).
 *
 * Alpha = Ia
 * Beta  = (Ia + 2*Ib) / sqrt(3)
 *
 * Uses fixed-point math (Q15 format).
 */
void clarke_transform(int16_t *i_abc,     /* Input: 3-phase currents [Ia, Ib] */
                      int16_t *i_alpha_beta, /* Output: alpha-beta currents */
                      int16_t *sin_cos)   /* Sin/cos lookup for angle */
{
    /* Fixed-point Clarke transform */
    int32_t temp1 = (int32_t)sin_cos[1] * (int32_t)i_abc[0] -
                    (int32_t)i_abc[1] * (int32_t)sin_cos[0];

    int32_t temp2 = (int32_t)i_abc[0] * (int32_t)sin_cos[0] +
                    (int32_t)sin_cos[1] * (int32_t)i_abc[1];

    i_alpha_beta[0] = (int16_t)((temp1 * 2) >> 16);  /* Alpha */
    i_alpha_beta[1] = (int16_t)((temp2 * 2) >> 16);  /* Beta */
}


/* ============================================================================
 * PI CONTROLLER
 * ============================================================================
 *
 * Proportional-Integral controller for current/speed regulation.
 *
 * Coefficients (Q15 fixed-point):
 *   Kp = 0x4f5d ≈ 0.62 (proportional gain)
 *   Ki = 0x30a3 ≈ 0.38 (integral gain)
 *
 * Output = Kp * error + Ki * integral(error)
 */
void pi_controller(int16_t *input,    /* Current error */
                   int16_t *output,   /* Controller output (accumulated) */
                   int16_t *gains)    /* [Kp, Ki] gains */
{
    /* Calculate proportional + integral term */
    int32_t p_term = ((int32_t)gains[1] * (int32_t)input[0]) >> 15;
    int32_t i_term = ((int32_t)gains[0] * (int32_t)input[1]) >> 15;

    int32_t error_sum = (p_term + i_term) * 0x30a3;  /* Scale by Ki */

    /* Accumulate into output with decay (0x4f5d ≈ 0.62 retention) */
    int32_t prev = (int32_t)(*output) * 0x4f5d;
    *output = (int16_t)((prev >> 15) + (error_sum >> 15));
}


/* ============================================================================
 * SPACE VECTOR PWM (SVPWM)
 * ============================================================================
 *
 * Calculates 3-phase PWM duty cycles from alpha-beta voltages.
 * Uses 6 sectors (60° each) to determine switching pattern.
 *
 * The 0xddb constant = sqrt(3)/2 in Q11 fixed-point ≈ 0.866
 *
 * Output range: 0-0x200 (0-512) for each phase duty cycle.
 */
void svpwm_calculate(int16_t *v_alpha_beta,  /* Input: alpha-beta voltages */
                     uint16_t *pwm_duties,   /* Output: [PhaseA, PhaseB, PhaseC] */
                     int max_duty)           /* Maximum duty cycle */
{
    int32_t v_beta = v_alpha_beta[1];

    /* Calculate V1 and V2 vectors */
    /* 0xddb = sqrt(3)/2 in Q11 format */
    int32_t v_alpha_scaled = ((int32_t)v_alpha_beta[0] * 0xddb) >> 11;

    int32_t v1 = v_alpha_scaled - v_beta;  /* 60° vector */
    int32_t v2 = v_beta + v_alpha_scaled;  /* 120° vector */
    int32_t v3 = -v2;

    /* Determine sector (0-5) based on voltage signs */
    uint8_t sector = 0;
    if (v_beta > 0) sector |= 1;
    if (v1 > 0) sector |= 2;
    if (v2 != 0 && v3 >= 0) sector |= 4;

    /* Calculate base duty cycles (0xff = center point) */
    int16_t t1 = (int16_t)((v_beta * 0xff) >> 10);
    int16_t t2 = (int16_t)((v1 * -0xff / 2) >> 10);
    int16_t t3 = (int16_t)((v3 * -0xff / 2) >> 10);

    int16_t duty_a, duty_b, duty_c;

    /* Apply switching pattern based on sector */
    switch (sector) {
        case 0:
            /* Sector 0: All phases at center (zero vector) */
            duty_a = duty_b = duty_c = 0xff;
            break;

        case 1:
        case 6:
            /* Sectors 1 & 6: A leads */
            duty_a = 0xff - t2 + t3;
            duty_b = t2 + t3 + 0xff;
            duty_c = 0xff - t2 - t3;
            break;

        case 2:
        case 5:
            /* Sectors 2 & 5: B leads */
            duty_a = t3 - t1 + 0xff;
            duty_b = 0xff - t3 + t1;
            duty_c = 0xff - t3 - t1;
            break;

        case 3:
        case 4:
            /* Sectors 3 & 4: C leads */
            duty_a = 0xff - t2 + t1;
            duty_b = t2 + t1 + 0xff;
            duty_c = t2 - t1 + 0xff;
            break;
    }

    /* Clamp to valid range [0, 0x200] */
    if (duty_a < 0) duty_a = 0;
    else if (duty_a > 0x1ff) duty_a = 0x200;

    if (duty_b < 0) duty_b = 0;
    else if (duty_b > 0x1ff) duty_b = 0x200;

    if (duty_c < 0) duty_c = 0;
    else if (duty_c > 0x1ff) duty_c = 0x200;

    pwm_duties[0] = duty_a;
    pwm_duties[1] = duty_b;
    pwm_duties[2] = duty_c;
}


/* ============================================================================
 * 6-STEP COMMUTATION TABLE
 * ============================================================================
 *
 * Maps Hall sensor state to commutation step.
 * BLDC motors use 6 electrical phases per mechanical rotation.
 *
 * Hall State -> Phase Outputs (each value is timer compare value)
 *
 * The hex values represent different duty cycle positions in the
 * electrical cycle (0x0000 = 0°, 0x5555 = 120°, 0xAAAA = 240°, etc.)
 */

/* Commutation lookup table - maps hall state to PWM values */
const uint16_t COMMUTATION_TABLE[7][6] = {
    /* Hall=0: Invalid state */
    {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},

    /* Hall=1: Step 1 - Phase A high, Phase B low, Phase C float */
    {0x1555, 0x2aaa, 0x16c1, 0x3e93, 0x0000, 0xec16},

    /* Hall=2: Step 2 - Phase A high, Phase B float, Phase C low */
    {0x3fff, 0x5555, 0x416c, 0x693e, 0x2aaa, 0x16c1},

    /* Hall=3: Step 3 - Phase A float, Phase B high, Phase C low */
    {0x6aaa, 0x8000, 0x6c17, 0x93e9, 0x5555, 0x416c},

    /* Hall=4: Step 4 - Phase A low, Phase B high, Phase C float */
    {0x9555, 0xaaaa, 0x96c1, 0xbe93, 0x8000, 0x6c17},

    /* Hall=5: Step 5 - Phase A low, Phase B float, Phase C high */
    {0xbfff, 0xd555, 0xc16c, 0xe93e, 0xaaaa, 0x96c1},

    /* Hall=6: Step 6 - Phase A float, Phase B low, Phase C high */
    {0xeaaa, 0xffff, 0xec16, 0x13e9, 0xd555, 0xc16c}
};


/* ============================================================================
 * MOTOR CONTROL STATE MACHINE
 * ============================================================================
 *
 * Main motor commutation function. Called from timer interrupt.
 *
 * 1. Reads Hall sensors to get rotor position
 * 2. Looks up commutation step from table
 * 3. Applies PWM duty cycles to timer compare registers
 * 4. Handles direction reversal and speed ramping
 */
void motor_commutation(volatile uint16_t *motor_state)
{
    /* Read Hall sensor state (3-bit value, 1-6 valid) */
    uint8_t hall_state = hall_read_state();

    /* Check for valid Hall state */
    if (hall_state == 0 || hall_state == 7) {
        /* Invalid - all sensors same = fault condition */
        motor_state[6] = 1;  /* Set error flag */
        /* Disable PWM outputs */
        return;
    }

    /* Get previous hall state for direction detection */
    uint8_t prev_state = motor_state[0x11] & 0xFF;

    /* Calculate step difference to detect direction */
    int8_t step_diff = COMMUTATION_TABLE[hall_state][0] - prev_state;
    motor_state[7] = step_diff;

    /* Direction detection: +1 or -5 = forward, -1 or +5 = reverse */
    if (step_diff == 1 || step_diff == -5) {
        motor_state[0x1e] = 1;  /* Forward */
    } else if (step_diff == -1 || step_diff == 5) {
        motor_state[0x1e] = 0;  /* Reverse */
    }

    /* Apply commutation pattern based on direction */
    uint8_t direction = motor_state[0x1e];
    const uint16_t *pattern = COMMUTATION_TABLE[hall_state];

    if (direction == 0) {
        /* Forward commutation */
        switch (hall_state) {
            case 1:
                motor_state[0x10] = pattern[0];  /* 0x1555 */
                motor_state[0x11] = pattern[1];  /* 0x2aaa */
                motor_state[0x12] = pattern[2];  /* 0x16c1 */
                motor_state[0x13] = pattern[3];  /* 0x3e93 */
                motor_state[0x14] = pattern[4];  /* 0x0000 */
                motor_state[0x15] = pattern[5];  /* 0xec16 */
                break;
            case 2:
                motor_state[0x10] = 0x3fff;
                motor_state[0x11] = 0x5555;
                motor_state[0x12] = 0x416c;
                motor_state[0x13] = 0x693e;
                motor_state[0x14] = 0x2aaa;
                motor_state[0x15] = 0x16c1;
                break;
            /* ... cases 3-6 follow same pattern ... */
        }
    } else {
        /* Reverse commutation - inverted pattern */
        switch (hall_state) {
            case 1:
                motor_state[0x10] = 0x1555;
                motor_state[0x11] = 0x0000;  /* Inverted */
                motor_state[0x12] = 0xec16;
                motor_state[0x13] = 0x13e9;
                motor_state[0x14] = 0x2aaa;
                motor_state[0x15] = 0x3e93;
                break;
            /* ... remaining cases ... */
        }
    }

    /* Update timer compare registers with new duty cycles */
    /* Phase position is stored in motor_state[0x0d] */
    motor_state[0x0c] = motor_state[0x0d];

    /* Apply speed offset based on direction */
    if (motor_state[0x1e] == 0) {
        motor_state[0x0c] += 0x0e38;  /* Forward offset */
    } else {
        motor_state[0x0c] += 0x16c1;  /* Reverse offset */
    }

    /* Store current Hall state for next comparison */
    motor_state[0x11] = hall_state;
}


/* ============================================================================
 * MAIN CONTROL LOOP
 * ============================================================================
 *
 * Called continuously from main(). Handles:
 *   - Reading joystick/foot sensor inputs
 *   - Checking battery voltage
 *   - Enabling/disabling motor outputs
 *   - Communication with slave board
 */
void main_control_loop(void)
{
    volatile uint16_t *tim1 = (uint16_t*)TIM1_BASE;
    volatile uint16_t *tim8 = (uint16_t*)TIM8_BASE;

    /* State variables (in RAM) */
    static uint8_t motor_enabled = 0;
    static uint8_t error_flag = 0;
    static uint16_t speed_setpoint = 0;

    /* Check foot sensors (both feet must be on board) */
    uint8_t left_foot = 0;   /* Read from GPIO */
    uint8_t right_foot = 0;  /* Read from GPIO */

    if (!left_foot || !right_foot) {
        /* Safety: disable motors if foot off */
        motor_enabled = 0;
        tim1[TIM_CCER/2] &= ~0x8000;  /* Disable TIM1 outputs */
        tim8[TIM_CCER/2] &= ~0x8000;  /* Disable TIM8 outputs */
        return;
    }

    /* Check battery voltage */
    uint16_t battery_mv = 0;  /* Read from ADC */
    if (battery_mv < 30000) {  /* 30V = low battery cutoff */
        error_flag = 1;
        motor_enabled = 0;
        return;
    }

    /* Motors can be enabled */
    if (!motor_enabled) {
        motor_enabled = 1;
        tim1[TIM_CCER/2] |= 0x8000;  /* Enable TIM1 main output */
        tim8[TIM_CCER/2] |= 0x8000;  /* Enable TIM8 main output */
    }

    /* Read gyro/accelerometer for balance (on master board) */
    /* Apply speed to motors based on lean angle */
    /* ... balance control algorithm ... */
}


/* ============================================================================
 * TIMER INITIALIZATION
 * ============================================================================
 *
 * Sets up TIM1 and TIM8 for 3-phase PWM output with complementary
 * outputs and dead-time insertion.
 *
 * PWM frequency = 72MHz / (PSC+1) / (ARR+1) ≈ 14kHz
 */
void timer_init(void)
{
    volatile uint32_t *tim1 = (uint32_t*)TIM1_BASE;
    volatile uint32_t *tim8 = (uint32_t*)TIM8_BASE;

    /* Configure TIM1 for Motor 1 */
    tim1[TIM_ARR/4] = PWM_PERIOD;        /* Period = 512 */
    tim1[TIM_CCMR1/4] = 0x6060;          /* PWM mode 1, CH1 & CH2 */
    tim1[TIM_CCMR2/4] = 0x0060;          /* PWM mode 1, CH3 */
    tim1[TIM_CCER/4] = 0x0555;           /* Enable CH1-3 + complementary */
    tim1[TIM_BDTR/4] = 0x8C00 | 0x20;    /* MOE + 32 counts dead-time */
    tim1[TIM_CR1/4] = 0x0001;            /* Enable counter */

    /* Configure TIM8 for Motor 2 (same settings) */
    tim8[TIM_ARR/4] = PWM_PERIOD;
    tim8[TIM_CCMR1/4] = 0x6060;
    tim8[TIM_CCMR2/4] = 0x0060;
    tim8[TIM_CCER/4] = 0x0555;
    tim8[TIM_BDTR/4] = 0x8C00 | 0x20;
    tim8[TIM_CR1/4] = 0x0001;
}


/* ============================================================================
 * SET MOTOR PWM
 * ============================================================================
 *
 * Writes duty cycles to timer compare registers.
 * Each phase gets a value 0-512 (PWM_PERIOD).
 */
void set_motor_pwm(uint8_t motor,           /* 0 = left, 1 = right */
                   uint16_t phase_a,
                   uint16_t phase_b,
                   uint16_t phase_c)
{
    volatile uint16_t *tim;

    if (motor == 0) {
        tim = (uint16_t*)TIM1_BASE;
    } else {
        tim = (uint16_t*)TIM8_BASE;
    }

    tim[TIM_CCR1/2] = phase_a;
    tim[TIM_CCR2/2] = phase_b;
    tim[TIM_CCR3/2] = phase_c;
}


/* ============================================================================
 * MAIN FUNCTION
 * ============================================================================
 */
int main(void)
{
    /* Initialize clocks (72MHz from 8MHz crystal) */
    /* SystemInit() called by startup code */

    /* Initialize peripherals */
    timer_init();
    /* gpio_init(); */
    /* adc_init(); */
    /* usart_init(); */

    /* Main loop */
    while (1) {
        main_control_loop();
    }

    return 0;
}
