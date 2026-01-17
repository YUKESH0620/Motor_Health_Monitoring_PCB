#ifndef SYSTEM_H
#define SYSTEM_H

#include <8051.h>   // 8051 register definitions

#define SYS_CLOCK_HZ 12000000UL   // 12 MHz crystal

void System_Init(void);

#endif
