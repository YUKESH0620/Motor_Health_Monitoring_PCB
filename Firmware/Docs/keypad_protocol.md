KEYPAD PROTOCOL – MOTOR HEALTH MONITORING SYSTEM

Keypad Type : 4 × 4 Matrix Keypad
Interface   : GPIO (Row–Column Scanning)
MCU         : AT89C51

--------------------------------------------------
HARDWARE CONNECTION
--------------------------------------------------

Rows (Outputs):
- R1 → P0.0
- R2 → P0.1
- R3 → P0.2
- R4 → P0.3

Columns (Inputs with pull-up resistors):
- C1 → P0.4
- C2 → P0.5
- C3 → P0.6
- C4 → P0.7

Active Logic:
- Columns are pulled HIGH by resistors
- Key press pulls corresponding column LOW
- Row driven LOW sequentially during scan

--------------------------------------------------
KEY FUNCTION MAPPING
--------------------------------------------------

Key numbering follows logical order returned by firmware
(1 to 16).

Row 1:
--------------------------------------------------
Key 1  | START MOTOR
Key 2  | STOP MOTOR
Key 3  | RESET FAULT
Key 4  | EMERGENCY STOP

Row 2:
--------------------------------------------------
Key 5  | PWM +5%
Key 6  | PWM −5%
Key 7  | PWM +10%
Key 8  | PWM −10%

Row 3:
--------------------------------------------------
Key 9  | PWM = 25%
Key 10 | PWM = 50%
Key 11 | PWM = 75%
Key 12 | PWM = 100%

Row 4:
--------------------------------------------------
Key 13 | Reserved (Future use)
Key 14 | Reserved (Future use)
Key 15 | Reserved (Future use)
Key 16 | Reserved (Future use)

--------------------------------------------------
FUNCTIONAL RULES
--------------------------------------------------

- START is ignored if a fault is latched
- RESET clears fault latch and returns system to IDLE
- PWM keys are effective only in RUN state
- EMERGENCY STOP immediately disables motor PWM
- Fault state overrides all keypad inputs except RESET

--------------------------------------------------
DEBOUNCE POLICY
--------------------------------------------------

- Software debounce implemented
- Key must be released before next detection
- Long press is treated as single press

--------------------------------------------------
NOTES
--------------------------------------------------

- Keypad control and UART control operate in parallel
- Both interfaces follow the same state machine rules
- Keypad is intended for local/manual control
