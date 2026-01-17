#ifndef UART_H
#define UART_H

#include <8051.h>

void UART_Init(void);
void UART_SendChar(char c);
void UART_SendString(char *s);

#endif
