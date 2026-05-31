# Hoverboard Firmware Reverse Engineering

Reverse engineering of Chinese hoverboard mainboard firmware to understand the balance control algorithm and identify design flaws.

## Hardware

- **MCU**: STM32F103C8T6 (ARM Cortex-M3, 72MHz)
- **Motors**: 2x 3-phase BLDC hub motors
- **Control**: 6-step commutation with FOC elements

## Files

| File | Description |
|------|-------------|
| `original_firmware.hex` | Original Intel HEX dump from hoverboard |
| `hoverboard_fw.bin` | Converted raw binary (35KB) |
| `hoverboard_annotated.c` | Full Ghidra decompilation with STM32 headers |
| `hoverboard_readable.c` | Cleaned up key functions with comments |
| `hoverboard_firmware_analysis.md` | Architecture overview |
| `hoverboard_balance_flaws.md` | **Analysis of balance control flaws** |

## Key Findings

### Balance Control Flaws

1. **No Derivative Term** - Uses PI control only, causing oscillation and overshoot
2. **Weak Proportional Gain** - Angle error divided by 4, sluggish response
3. **Integral Windup** - No anti-windup, causes jerky recovery
4. **Slow Sensor Filter** - ~40% new data per cycle, adds lag
5. **Speed Ramping** - Limits acceleration/braking agility
6. **No Sensor Fusion** - No complementary/Kalman filter for gyro+accel
7. **Fixed Gains** - Not tuned for different speeds

### Control Architecture

```
Timer Interrupt (~1ms)
       │
       ▼
┌──────────────────────────┐
│ Read Hall Sensors        │ → 3-bit rotor position
├──────────────────────────┤
│ Read Gyro/Accel          │ → Tilt angle (filtered)
├──────────────────────────┤
│ PI Controller            │ → Speed setpoint (NO D TERM!)
├──────────────────────────┤
│ Speed Ramping            │ → Rate-limited output
├──────────────────────────┤
│ Clarke Transform         │ → 3-phase to alpha-beta
├──────────────────────────┤
│ SVPWM Calculate          │ → Duty cycles for 3 phases
├──────────────────────────┤
│ Write to Timer PWM       │ → Motor moves
└──────────────────────────┘
```

## Key Functions

| Address | Function | Purpose |
|---------|----------|---------|
| `0x08003290` | Left motor control | Balance loop for left wheel |
| `0x08003398` | Right motor control | Balance loop for right wheel |
| `0x08004154` | Speed integrator | **PI controller (missing D)** |
| `0x080041a0` | Sensor filter | Low-pass filter on angle |
| `0x08004b0c` | Clarke transform | 3-phase to 2-axis conversion |
| `0x08004b48` | PI controller | Current/speed regulation |
| `0x08004b96` | SVPWM | Space vector PWM calculation |
| `0x08004cf4` | Motor commutation | 6-step BLDC state machine |
| `0x08002378` | Hall read | Read 3 hall sensor pins |

## Tools Used

- **Ghidra** - Decompilation (headless mode)
- **srec_cat** - Intel HEX to binary conversion
- **radare2** - Initial analysis

## Better Alternative

Instead of using this flawed firmware, consider open-source replacements:

- [hoverboard-firmware-hack-FOC](https://github.com/EmanuelFeru/hoverboard-firmware-hack-FOC) - Proper FOC with configurable PID
- [hoverboard-firmware-hack](https://github.com/NiklasFauth/hoverboard-firmware-hack) - Simpler, well documented

## License

This reverse engineering is for educational purposes. Original firmware copyright belongs to the manufacturer.
