#include "uart.h"

void UART_Init(void)
{
    TMOD |= 0x20;    // Timer1 Mode2 (8-bit auto-reload)
    TH1  = 0xFD;     // 9600 baud @ 12MHz
    TL1  = 0xFD;

    SCON = 0x50;     // 8-bit UART, REN enabled
    TR1  = 1;        // Start Timer1
}

void UART_SendChar(char c)
{
    SBUF = c;
    while (TI == 0);
    TI = 0;
}

void UART_SendString(char *s)
{
    while (*s)
    {
        UART_SendChar(*s++);
    }
}
