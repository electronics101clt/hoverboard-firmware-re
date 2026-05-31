# Hoverboard Foot Pad Analysis - Complete Operation Modes

## Sensor Variables

| Variable | Role |
|----------|------|
| `DAT_08002bc4` | Left foot sensor 1 (front?) |
| `DAT_08002bd4` | Left foot sensor 2 (rear?) |
| `DAT_08002bd8` | Right foot sensor 1 (front?) |
| `DAT_08002bdc` | Right foot sensor 2 (rear?) |
| `DAT_08002be0` | Combined/any sensor active |

## State Variables

| Variable | Meaning |
|----------|---------|
| `cVar1` (`DAT_08002be4`) | Left side active (both pads pressed) |
| `cVar3` (`DAT_08002be8`) | Previous left side state |
| `cVar8` (`DAT_08002c1c`) | Right side active (both pads pressed) |
| `DAT_08002c30` | Previous right side state |
| `DAT_08002c20` | **RIDE MODE LEFT** - left side enabled |
| `DAT_08002c2c` | **RIDE MODE RIGHT** - right side enabled |
| `pcVar15` (`DAT_08002bd0`) | Master motor enable flag |
| `cVar7` (`DAT_08002c0c`) | Override/bypass flag |

## Error Flags (ALL must be 0 to enable)

| Variable | Likely meaning |
|----------|----------------|
| `cVar2` (`DAT_08002bf0`) | Error flag 1 |
| `cVar4` (`DAT_08002bec`) | Error flag 2 |
| `cVar5` (`DAT_08002bf4`) | Error flag 3 |
| `cVar6` (`DAT_08002bf8`) | Error flag 4 |
| `cVar9` (`DAT_08002bfc`) | Error flag 5 |
| `cVar10` (`DAT_08002c00`) | Error flag 6 |
| `cVar11` (`DAT_08002c04`) | Error flag 7 |
| `cVar12` (`DAT_08002c08`) | Error flag 8 |

---

## All Angles of Operation

### ANGLE 1: Full Disable (No feet at all)
**Condition:** `DAT_08002bc4 == 0 && DAT_08002bd4 == 0`
```
Line 3616-3620: Both left sensors OFF
         ↓
    goto LAB_08002b9a
         ↓
    Disable BOTH motors
    Clear ALL ride modes
```

### ANGLE 2: Left Side Enable
**Condition:** `cVar1 == 1 && cVar3 == 1` (left pads pressed, stable)
```c
// Line 3641-3658
if ((cVar3 == 1) && (cVar1 == 1)) {
    if (ride_mode_left == 0) {           // Not already riding
        if (ALL_ERROR_FLAGS == 0) {       // No errors
            if (tilt <= MAX_TILT) {       // Board is level enough
                ride_mode_left = 1;       // Enable left ride mode
                LEFT_MOTOR |= 0x8000;     // Enable left motor
                RIGHT_MOTOR |= 0x8000;    // Enable right motor
                motor_enabled = 1;
            }
        }
    }
}
```
**Purpose:** Only enable motors when:
- Both left foot pads pressed
- State is stable (not transitioning)
- No error conditions
- Board is reasonably level

### ANGLE 3: Left Side Disable (Step off)
**Condition:** `cVar1 == 0 && cVar3 == 0 && ride_mode_active && cVar8 == 0`
```c
// Line 3665-3671
if (left_pads_off && was_riding && right_side_not_active) {
    ride_mode_left = 0;
    LEFT_MOTOR &= 0x7FFF;    // Disable left motor
    RIGHT_MOTOR &= 0x7FFF;   // Disable right motor
    motor_enabled = 0;
}
```
**Purpose:** Disable when rider steps off LEFT side (and right side not active)

### ANGLE 4: Right Side Enable
**Condition:** `cVar8 != 0 && DAT_08002c30 != 0` (right pads pressed, stable)
```c
// Line 3683-3706
if (right_side_active) {
    if (previous_right_active) {
        if (ALL_ERROR_FLAGS == 0) {
            if (tilt <= MAX_TILT) {
                ride_mode_right = 1;
                LEFT_MOTOR |= 0x8000;
                RIGHT_MOTOR |= 0x8000;
            }
        }
    }
}
```
**Purpose:** Same as left side, but for right foot

### ANGLE 5: Right Side Disable
**Condition:** `cVar8 == 0 && DAT_08002c30 == 0 && right_ride_mode && cVar1 == 0`
```c
// Line 3673-3680
if (right_off && was_right_riding && left_not_active) {
    ride_mode_right = 0;
    LEFT_MOTOR &= 0x7FFF;
    RIGHT_MOTOR &= 0x7FFF;
}
```

### ANGLE 6: Tilt Check Before Enable
**Condition:** Lines 3643-3647, 3686-3690
```c
uVar20 = current_tilt;
if (uVar20 <= MAX_TILT_THRESHOLD) {
    // OK to enable
} else if (override_flag != 0) {
    // Override allows enable anyway
} else {
    // TOO TILTED - don't enable
    // Set warning flag instead (line 3661)
}
```
**Purpose:** Won't enable motors if board is tilted too much when you step on. Prevents sudden acceleration.

### ANGLE 7: Error Lockout
**Condition:** Lines 3644-3645, 3687-3688
```c
if (cVar4 != 0 || cVar2 != 0 || cVar5 != 0 || cVar6 != 0 ||
    cVar9 != 0 || cVar10 != 0 || cVar11 != 0 || cVar12 != 0) {
    // ANY error flag set = DON'T ENABLE
}
```
**Purpose:** Error conditions (overcurrent, sensor fault, etc.) prevent motor enable

### ANGLE 8: Transition Detection
**Condition:** `cVar1 == 1 && cVar3 == 0` (Line 3637)
```c
if (left_active_NOW && !left_active_BEFORE) {
    // Just stepped on - clear startup flag
    *pcVar19 = 0;
}
```
**Purpose:** Detect the moment of stepping ON (rising edge)

---

## State Machine Diagram

```
                    ┌──────────────────────────────────────┐
                    │           MOTORS DISABLED            │
                    │  (puVar13 & puVar14 bit 15 = 0)     │
                    └──────────────┬───────────────────────┘
                                   │
            ┌──────────────────────┼──────────────────────┐
            │                      │                      │
            ▼                      ▼                      ▼
   ┌────────────────┐    ┌────────────────┐    ┌────────────────┐
   │ Left pads ON   │    │ Right pads ON  │    │  Both sides    │
   │ Right pads OFF │    │ Left pads OFF  │    │     ON         │
   └───────┬────────┘    └───────┬────────┘    └───────┬────────┘
           │                     │                     │
           ▼                     ▼                     ▼
   ┌────────────────┐    ┌────────────────┐    ┌────────────────┐
   │ Check errors   │    │ Check errors   │    │ Check errors   │
   │ Check tilt     │    │ Check tilt     │    │ Check tilt     │
   └───────┬────────┘    └───────┬────────┘    └───────┬────────┘
           │ ALL OK              │ ALL OK              │ ALL OK
           ▼                     ▼                     ▼
   ┌────────────────┐    ┌────────────────┐    ┌────────────────┐
   │ LEFT RIDE MODE │    │ RIGHT RIDE MODE│    │  BOTH MODES    │
   │ Motors ENABLED │    │ Motors ENABLED │    │ Motors ENABLED │
   └───────┬────────┘    └───────┬────────┘    └───────┬────────┘
           │                     │                     │
           │ Step off            │ Step off            │ Step off
           ▼                     ▼                     ▼
   ┌────────────────────────────────────────────────────────────┐
   │                    MOTORS DISABLED                         │
   └────────────────────────────────────────────────────────────┘
```

---

## If You Bypass (Always Active)

| What you bypass | What happens |
|-----------------|--------------|
| Just sensors (`bc4`, `bd4`, etc.) | Skips to main logic, still checks errors/tilt |
| Sensors + error flags | Only tilt check remains |
| Sensors + errors + tilt | **Motors ALWAYS enabled** |
| Everything | Permanent ride mode, no safety |

**The foot pads are the FIRST gate.** But there are multiple layers:
1. Foot pads (physical presence)
2. Error flags (system health)
3. Tilt threshold (safe starting position)
4. Transition detection (debounce/stability)

---

## Bypass Behavior Summary

### With Foot Pads Always "Pressed"

| Situation | Board Behavior |
|-----------|---------------|
| Flat on ground | Sits still |
| Tilted slightly | Drives toward tilt direction |
| Pick it up | Wheels spin based on how you hold it |
| Step off while moving | **Accelerates away (runaway)** |
| Falls over | Wheels spin max until overcurrent |
| Upside down | Wheels spin opposite direction |

### The Core Problem Without Rider Feedback

**Normal with rider:**
```
Tilt → Motors accelerate → Board moves under rider → Rider tilts back → FEEDBACK LOOP
              ↑                                              ↓
              └──────────────── Rider corrects ─────────────┘
```

**Without rider (pads bypassed):**
```
Tilt → Motors accelerate → Board moves → Nothing corrects tilt → MORE acceleration
              ↑                                                         ↓
              └──────────── No feedback, runaway! ─────────────────────┘
```

---

## Why People Bypass Foot Pads

Common use cases for bypassing:
- **Go-kart conversion** - sit in seat, control with levers
- **Robot platform** - external control system
- **Electric vehicle conversion** - different control interface

**Critical:** When bypassing, you MUST add your own enable switch or remote kill switch. Without it, you have a dangerous runaway machine.
