# Hoverboard Balance Control Analysis - FLAWS IDENTIFIED

## Overview

The balance control is implemented in two main functions:
- `FUN_08003290` @ 0x08003290 - **Left motor balance control**
- `FUN_08003398` @ 0x08003398 - **Right motor balance control**

These call the core algorithm in:
- `FUN_08004154` @ 0x08004154 - **Speed/angle integrator** (THE MAIN PROBLEM)
- `FUN_080041a0` @ 0x080041a0 - **Sensor filter**
- `FUN_08004b48` @ 0x08004b48 - **PI controller**

---

## FLAW #1: NO DERIVATIVE TERM (PI only, not PID)

**Location**: `FUN_08004154` lines 5549-5555

```c
// Current implementation - PI ONLY
iVar3 = (param_1 >> 2) + (int)(short)(sVar2 + param_2[3]);
param_2[3] = sVar2 + param_2[3];  // Accumulates integral (I term)
```

**Problem**: The controller uses only:
- **P (Proportional)**: `param_1 >> 2` - reacts to current angle
- **I (Integral)**: `param_2[3]` accumulator - corrects steady-state error

**Missing D (Derivative)**: No term that predicts future error based on rate of change.

**Result**:
- **Oscillation** - board wobbles when trying to stabilize
- **Overshoot** - overcorrects then swings back
- **Slow response** - can't anticipate rapid tilts

**Fix needed**: Add derivative term:
```c
// What it SHOULD have:
error_derivative = current_angle - previous_angle;
output = Kp * angle + Ki * integral + Kd * error_derivative;
```

---

## FLAW #2: WEAK PROPORTIONAL GAIN (divide by 4)

**Location**: `FUN_08004154` line 5549

```c
iVar3 = (param_1 >> 2) + ...  // param_1 >> 2 = param_1 / 4
```

**Problem**: The angle error is divided by 4 before being used.

**Result**:
- **Sluggish response** - only 25% of the tilt angle is used
- **Needs larger tilt** to get same motor response
- **Feels "mushy"** when riding

**Fix**: Increase Kp gain or remove the `>> 2` shift.

---

## FLAW #3: INTEGRAL WINDUP - NO ANTI-WINDUP

**Location**: `FUN_08004154` lines 5550-5554

```c
param_2[3] = sVar2 + param_2[3];  // I term keeps accumulating

// Only clamps at extreme limits:
if ((iVar3 < iVar4) || (iVar4 = iVar1, iVar1 < iVar3)) {
    param_2[3] = (short)iVar4;  // Clamp only at max limit
}
```

**Problem**: The integral accumulator keeps growing until it hits the hard limit (`DAT_0800419c`).

**Result**:
- **Windup** - when tilted for extended time, integral builds up
- **Delayed recovery** - when you level out, the built-up integral causes continued acceleration
- **Sudden jerks** - integral "unwinds" causing unpredictable behavior

**Fix needed**: Add anti-windup:
```c
// Stop integrating when output is saturated
if (output_saturated) {
    dont_accumulate_integral();
}
// Or use back-calculation anti-windup
```

---

## FLAW #4: SLOW SENSOR FILTERING

**Location**: `FUN_080041a0` line 5570

```c
param_2[1] = (short)((uint)(((int)*param_1 + param_1[1] * 2) * 0x93ce) >> 0x10);
```

**Analysis**:
- `0x93ce / 0x10000 ≈ 0.577` - this is a low-pass filter coefficient
- Filter formula: `output = (current + 2*previous) * 0.577`
- This is a weighted average with ~40% of new data

**Problem**: Too much smoothing delays the sensor response.

**Result**:
- **Lag** between actual tilt and detected tilt
- **Phase shift** in the control loop
- **Instability** at higher speeds

---

## FLAW #5: SPEED RAMPING ADDS LAG

**Location**: `FUN_08003290` lines 4377-4393

```c
if (iVar8 < iVar7) {
    iVar8 = iVar8 + (uint)*DAT_0800336c;  // Ramp up slowly
    if (iVar8 < iVar7) {
        puVar2[1] = (short)iVar8;
    }
}
else {
    iVar8 = iVar8 - (uint)*DAT_0800336c;  // Ramp down slowly
}
```

**Problem**: Speed setpoint changes gradually by `DAT_0800336c` per cycle.

**Result**:
- **Acceleration limiting** feels like "fighting" the board
- **Delayed braking** - can't stop quickly
- **Reduced agility**

This might be intentional for safety but is too aggressive.

---

## FLAW #6: NO COMPLEMENTARY/KALMAN FILTER FOR ANGLE

**Location**: `FUN_080041a0` - only uses simple weighted average

**Problem**: No sensor fusion between gyroscope and accelerometer.

**Expected in good design**:
```c
// Complementary filter
angle = 0.98 * (angle + gyro_rate * dt) + 0.02 * accel_angle;

// Or Kalman filter for better noise rejection
```

**Current implementation**: Just averaging raw values with lag.

**Result**:
- **Drift** - gyro bias causes slow drift
- **Noise** - accelerometer vibration not filtered
- **Inaccurate** angle estimation

---

## FLAW #7: FIXED GAINS - NO SPEED-DEPENDENT TUNING

**Location**: All control functions use hardcoded values:
- `DAT_0800419c` - max output limit
- `0x93ce` - filter coefficient
- `>> 2` - proportional scaling

**Problem**: Same gains at all speeds.

**Result**:
- **Stable at low speed**, unstable at high speed
- **Or vice versa** - tuned for one operating point only
- Real hoverboards need gain scheduling

---

## CONTROL FLOW SUMMARY

```
                    EVERY ~1ms (timer interrupt)
                           │
                           ▼
┌─────────────────────────────────────────────────────────────────┐
│  FUN_08003290 / FUN_08003398                                    │
│  (Left/Right motor control)                                     │
├─────────────────────────────────────────────────────────────────┤
│                                                                 │
│  1. Read sensor data → FUN_080041a0 (SLOW FILTER - FLAW #4)    │
│                                                                 │
│  2. Calculate error → FUN_08004b48 (PI only - NO D TERM #1)    │
│                                                                 │
│  3. Apply limits → FUN_08004154 (INTEGRAL WINDUP - FLAW #3)    │
│                    (WEAK P GAIN - FLAW #2)                      │
│                                                                 │
│  4. Ramp speed → if/else ramping (ADDS LAG - FLAW #5)          │
│                                                                 │
│  5. Clarke transform → FUN_08004b0c                             │
│                                                                 │
│  6. SVPWM → FUN_08004b96                                        │
│                                                                 │
│  7. Output to timer PWM registers                               │
│                                                                 │
└─────────────────────────────────────────────────────────────────┘
```

---

## RECOMMENDED FIXES (if modifying firmware)

### Priority 1: Add Derivative Term
```c
int16_t error_rate = angle - previous_angle;
previous_angle = angle;
int16_t d_term = Kd * error_rate;
output = p_term + i_term + d_term;
```

### Priority 2: Reduce Sensor Filter Lag
```c
// Change 0x93ce to higher value like 0xC000
// Or use complementary filter with gyro
```

### Priority 3: Add Anti-Windup
```c
if (abs(output) < max_output) {
    integral += error;  // Only integrate when not saturated
}
```

### Priority 4: Increase P Gain
```c
// Change >> 2 to >> 1 or remove entirely
// Or add configurable Kp variable
```

---

## BETTER ALTERNATIVE: Use Open Source Firmware

Instead of fixing this firmware, flash one of these:

1. **hoverboard-firmware-hack-FOC** (EmanuelFeru)
   - Proper Field Oriented Control
   - Configurable PID gains
   - Speed/torque modes
   - https://github.com/EmanuelFeru/hoverboard-firmware-hack-FOC

2. **hoverboard-firmware-hack** (NiklasFauth)
   - Simpler, well documented
   - Good for learning
   - https://github.com/NiklasFauth/hoverboard-firmware-hack

Both have proper PID control with derivative terms and adjustable parameters.
