#include <8051.h>
#include "keypad.h"
#include "pin_config.h"

// simple debounce delay
static void kp_delay(void)
{
    unsigned int i;
    for (i = 0; i < 500; i++);
}

void Keypad_Init(void)
{
    // rows HIGH (inactive)
    KP_R1 = 1; KP_R2 = 1; KP_R3 = 1; KP_R4 = 1;
}

// scan one row at a time
static unsigned char scan_row(unsigned char row)
{
    // deactivate all rows
    KP_R1 = KP_R2 = KP_R3 = KP_R4 = 1;

    // activate selected row (LOW)
    switch (row)
    {
        case 1: KP_R1 = 0; break;
        case 2: KP_R2 = 0; break;
        case 3: KP_R3 = 0; break;
        case 4: KP_R4 = 0; break;
    }

    kp_delay();

    if (KP_C1 == 0) return 1;
    if (KP_C2 == 0) return 2;
    if (KP_C3 == 0) return 3;
    if (KP_C4 == 0) return 4;

    return 0;
}

unsigned char Keypad_GetKey(void)
{
    unsigned char col;

    col = scan_row(1); if (col) return col;           // 1–4
    col = scan_row(2); if (col) return col + 4;       // 5–8
    col = scan_row(3); if (col) return col + 8;       // 9–12
    col = scan_row(4); if (col) return col + 12;      // 13–16

    return 0; // no key
}
