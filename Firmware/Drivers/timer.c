#include <8051.h>
#include "timer.h"
#include "pwm.h"

volatile unsigned long sys_millis = 0;

/* Timer0 ISR */
void timer0_ISR(void) __interrupt (1)
{
    // Reload for 1 ms (12 MHz crystal)
    TH0 = 0xFC;
    TL0 = 0x18;

    sys_millis++;
	  PWM_Update(); 
}

void Timer0_Init(void)
{
    sys_millis = 0;   // FORCE reset value
	
	  TMOD &= 0xF0;   // Clear Timer0 bits
    TMOD |= 0x01;   // Timer0 Mode1 (16-bit)

    // 1 ms reload value
    TH0 = 0xFC;
    TL0 = 0x18;

    ET0 = 1;        // Enable Timer0 interrupt
    TR0 = 1;        // Start Timer0
}

unsigned long millis(void)
{
    unsigned long t;

    EA = 0;
    t = sys_millis;
    EA = 1;

    return t;
}
