# Hoverboard Firmware Analysis

## Overview
- **MCU**: STM32F103 (ARM Cortex-M3)
- **Flash base**: 0x08000000
- **Size**: ~35KB compiled
- **Functions**: 162 detected

## Architecture

### Motor Control (BLDC - Brushless DC)
The firmware controls two 3-phase BLDC hub motors using **6-step commutation**.

**Key Functions:**
- `FUN_08004cf4` @ 0x08004cf4 - **Main motor control state machine**
  - Handles 6 commutation states (case '\x01' through '\x06')
  - PWM values: 0x1555, 0x2aaa, 0x3fff, 0x5555, 0x6aaa, 0x8000...
  - These are phase angles for sinusoidal commutation

- `FUN_08004b0c` @ 0x08004b0c - **Clarke/Park Transform**
  - Converts 3-phase currents to 2-axis (alpha/beta or d/q)
  - Formula visible: `param_3[1] * param_1 - param_1[1] * param_3`

- `FUN_08004b48` @ 0x08004b48 - **PI Controller or Filter**
  - Uses coefficients 0x4f5d, 0x30a3 (fixed-point math)

- `FUN_08004b96` @ 0x08004b96 - **Space Vector PWM (SVPWM)**
  - 6-sector switch statement
  - Calculates duty cycles for 3 phases

### Peripheral Setup (@ ~0x08002984)
Two timer peripherals configured for PWM:
- `DAT_08002964` - Timer for Motor 1 (left wheel)
- `DAT_08002968` - Timer for Motor 2 (right wheel)

Configuration observed:
- PWM frequency setting: 0x200 (period)
- Output mode: 0x60 (PWM mode 1)
- Deadtime: enabled
- Register `|= 0x555` - enables complementary outputs

### GPIO Configuration (@ ~0x080013d8)
- Port configs: 0x780, 0xe003, 0x1c0
- Mode: 0x18 (alternate function push-pull, 50MHz)

### ADC (Analog-to-Digital)
Multiple ADC channels for:
- Hall sensor inputs (motor position)
- Battery voltage monitoring
- Current sensing

### Communication
UART likely used for:
- Communication between master/slave boards
- Possible Bluetooth module interface

## Control Flow Summary

```
main()
  └── SystemInit()
  └── GPIO_Config()
  └── Timer_Config() [PWM for both motors]
  └── ADC_Config()
  └── while(1) {
        read_hall_sensors()
        calculate_commutation_state()
        apply_pwm_to_motors()
        check_battery()
        handle_uart_commands()
      }
```

## 6-Step Commutation Table
The switch statements reveal the commutation sequence:

| Step | Phase A | Phase B | Phase C |
|------|---------|---------|---------|
| 1    | +PWM    | -PWM    | Float   |
| 2    | +PWM    | Float   | -PWM    |
| 3    | Float   | +PWM    | -PWM    |
| 4    | -PWM    | +PWM    | Float   |
| 5    | -PWM    | Float   | +PWM    |
| 6    | Float   | -PWM    | +PWM    |

## Key Memory Addresses
- `0x20000xxx` - RAM (variables, buffers)
- `0x40000xxx` - Peripherals (TIM, GPIO, ADC, USART)
- `0x08000xxx` - Flash (code)

## Notes
- No encryption/protection detected
- Standard STM32 HAL-like function patterns
- Typical Chinese hoverboard firmware structure
- Similar to open-source projects like:
  - https://github.com/NiklasFauth/hoverboard-firmware-hack
  - https://github.com/EmanuelFeru/hoverboard-firmware-hack-FOC
