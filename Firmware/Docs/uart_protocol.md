UART PROTOCOL – MOTOR HEALTH MONITORING SYSTEM

Baud Rate   : 9600
Data Bits   : 8
Parity      : None
Stop Bits   : 1
Line Ending : LF (\n)
Case        : Case-insensitive
Echo        : Enabled

-----------------------------------------
COMMAND LIST
-----------------------------------------

START
- Action: Start motor
- Condition: Only if no fault is latched
- Response: OK:RUN

STOP
- Action: Stop motor
- Response: OK:IDLE

RESET
- Action: Clear fault latch and go to IDLE
- Response: OK:RESET

PWM <0–100>
- Action: Set PWM duty cycle percentage
- Example: PWM 60
- Response: OK:PWM=60

STATUS
- Action: Report current system status
- Response Format:
  STATE=<IDLE/RUN/FAULT>
  PWM=<value>
  I=<current_A>
  T=<temperature_C>

-----------------------------------------
ERROR RESPONSES
-----------------------------------------

ERR:FAULT_ACTIVE
ERR:INVALID_CMD
ERR:OUT_OF_RANGE
