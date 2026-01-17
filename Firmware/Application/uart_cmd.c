#include "uart_cmd.h"
#include "motor_state.h"
#include "pwm.h"
#include "fault_manager.h"
#include "uart.h"
#include <string.h>
#include <stdlib.h>

void UART_CMD_Process(char *cmd)
{
    if (cmd == 0) return;

    // START
    if (strcmp(cmd, "START") == 0)
    {
        if (!Fault_IsActive())
        {
            MotorState_SetRun();
            UART_SendString("OK: RUN\r\n");
        }
        else
        {
            UART_SendString("ERR: FAULT ACTIVE\r\n");
        }
    }

    // STOP
    else if (strcmp(cmd, "STOP") == 0)
    {
        MotorState_SetIdle();
        UART_SendString("OK: STOP\r\n");
    }

    // RESET
    else if (strcmp(cmd, "RESET") == 0)
    {
        MotorState_ResetFault();
        UART_SendString("OK: RESET\r\n");
    }

    // PWM xx
    else if (strncmp(cmd, "PWM ", 4) == 0)
    {
        int val = atoi(cmd + 4);

        if (val < 0)   val = 0;
        if (val > 100) val = 100;

        if (!Fault_IsActive())
        {
            PWM_SetDuty((unsigned char)val);
            UART_SendString("OK: PWM SET\r\n");
        }
        else
        {
            UART_SendString("ERR: FAULT ACTIVE\r\n");
        }
    }

    else
    {
        UART_SendString("ERR: UNKNOWN CMD\r\n");
    }
}
