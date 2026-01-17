#include "adc.h"
#include "pin_config.h"

//Small delay for ADC timing
static void adc_delay(void)
{
    unsigned char i;
    for (i = 0; i < 10; i++);
}

void ADC_Init(void)
{
    CS   = 1;   // idle high
    CLK  = 0;
    DIN  = 0;
}

//Read 8 bits ADC value from selected channel
unsigned int ADC_Read(adc_channel_t ch)
{
    unsigned char i;
    unsigned int value = 0;

    CS = 0;              // select ADC
    adc_delay();

    //Send channel selection (simple protocol) 
    DIN = (ch & 0x01);   // LSB selects IN1/IN2
    adc_delay();

    //Clock out 8 bits
    for (i = 0; i < 8; i++)
    {
        CLK = 1;
        adc_delay();

        value <<= 1;
        if (DOUT)
            value |= 1;

        CLK = 0;
        adc_delay();
    }

    CS = 1;              // deselect ADC
    return value;
}
