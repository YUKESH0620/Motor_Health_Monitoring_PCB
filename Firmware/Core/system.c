#include "system.h"

void System_Init(void)
{
    EA = 0;   // Disable interrupts

    P0 = 0xFF;
    P1 = 0xFF;
    P2 = 0xFF;
    P3 = 0xFF;

    EA = 1;   // Enable interrupts
}
