POWER ON / RESET
        |
        v
System_Init()
GPIO_Init()
Timer_Init()
UART_Init()
PWM_Init()
Keypad_Init()
OLED_Init()
        |
        v
STATE = IDLE
Motor PWM = 0%
Fault_Latched = NO
        |
        v
---------------- MAIN LOOP ----------------
        |
        v
UART_RX_Process()
Keypad_Scan()
        |
        v
Is START command / key pressed?
        |
       YES
        |
        v
Is Fault_Latched?
        |
       NO
        |
        v
STATE = RUN
Motor PWM = Last_Set_Value
        |
        v
------------------------------------------
        |
        v
Read Sensors
(ADC Current, ADC Temperature)
        |
        v
Convert ADC -> Voltage
Convert Voltage -> Physical Units
        |
        v
Check Fault Conditions
(Current > OC_LIMIT?)
(Temperature > OT_LIMIT?)
        |
        v
If FAULT DETECTED
        |
        v
Fault_Latched = YES
STATE = FAULT
Motor PWM = 0%
Fault LED = ON
        |
        v
------------------------------------------
        |
        v
If RESET command / key pressed
        |
        v
Clear Fault_Latched
STATE = IDLE
Motor PWM = 0%
        |
        v
------------------------------------------
        |
        v
Update OLED Display
(State, PWM %, Current, Temp)
        |
        v
Repeat MAIN LOOP

