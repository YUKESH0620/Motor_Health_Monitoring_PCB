#include <8051.h>
#include "uart_rx.h"
#include "uart.h"
#include "motor_state.h"
#include "pwm.h"
#include "fault_manager.h"

#define RX_BUF_LEN  16

char rx_buf[32];
static unsigned char rx_idx = 0;
unsigned char cmd_ready = 0;

/* UART ISR (shared vector with TX) */
void uart_ISR(void) __interrupt (4)
{
    char c;

    if (RI)
    {
        RI = 0;
        c = SBUF;

        /* Echo */
        UART_SendChar(c);

        /* Line ending = LF */
        if (c == '\n')
        {
            rx_buf[rx_idx] = '\0';
            rx_idx = 0;
            cmd_ready = 1;
        }
        else
        {
            if (rx_idx < (RX_BUF_LEN - 1))
            {
                rx_buf[rx_idx++] = c;
            }
            else
            {
                /* overflow: reset buffer */
                rx_idx = 0;
            }
        }
    }

    if (TI)
    {
        TI = 0;
    }
}

void UART_RX_Init(void)
{
    rx_idx = 0;
    cmd_ready = 0;
    ES = 1;     // Enable UART interrupt
    EA = 1;     // Global interrupt already enabled, safe
}

/* Simple helpers */
static unsigned char is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

static unsigned char parse_pwm_value(const char *s)
{
    /* expects "PWM xx" */
    unsigned char val = 0;

    if (is_digit(s[4]))
    {
        val = s[4] - '0';
        if (is_digit(s[5]))
            val = (val * 10) + (s[5] - '0');
    }
    return val;
}

void UART_RX_Process(void)
{
    if (!cmd_ready) return;

    cmd_ready = 0;

    /* ---- COMMAND PARSER (UPPERCASE ONLY) ---- */

    if (rx_buf[0]=='S' && rx_buf[1]=='T' && rx_buf[2]=='A' &&
        rx_buf[3]=='R' && rx_buf[4]=='T' && rx_buf[5]=='\0')
    {
        MotorState_SetRun();
        UART_SendString("\r\nOK START\r\n");
    }
    else if (rx_buf[0]=='S' && rx_buf[1]=='T' && rx_buf[2]=='O' &&
             rx_buf[3]=='P' && rx_buf[4]=='\0')
    {
        MotorState_SetIdle();
        UART_SendString("\r\nOK STOP\r\n");
    }
    else if (rx_buf[0]=='R' && rx_buf[1]=='E' && rx_buf[2]=='S' &&
             rx_buf[3]=='E' && rx_buf[4]=='T' && rx_buf[5]=='\0')
    {
        MotorState_ResetFault();
        UART_SendString("\r\nOK RESET\r\n");
    }
    else if (rx_buf[0]=='P' && rx_buf[1]=='W' && rx_buf[2]=='M' &&
             rx_buf[3]==' ')
    {
        unsigned char duty = parse_pwm_value((const char*)rx_buf);
        PWM_SetDuty(duty);
        UART_SendString("\r\nOK PWM\r\n");
    }
    else
    {
        UART_SendString("\r\nERR\r\n");
    }
}

unsigned char UART_RX_CommandReady(void)
{
    return cmd_ready;
}

char* UART_RX_GetCommand(void)
{
    cmd_ready = 0;   // clear flag after reading
    return rx_buf;
}
