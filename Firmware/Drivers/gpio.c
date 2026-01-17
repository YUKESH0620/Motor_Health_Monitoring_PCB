#include "pin_config.h"
#include "gpio.h"

void GPIO_Init(void)
{
    // LEDs OFF initially (active LOW)
    LED_FAULT = 1;
    LED_MOTOR = 1;
}
