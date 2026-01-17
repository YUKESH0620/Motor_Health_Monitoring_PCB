#ifndef UART_RX_H
#define UART_RX_H

void UART_RX_Init(void);
void UART_RX_Process(void);   // call from main loop

unsigned char UART_RX_CommandReady(void);
char* UART_RX_GetCommand(void);

#endif
