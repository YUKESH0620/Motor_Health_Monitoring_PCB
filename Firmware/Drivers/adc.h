#ifndef ADC_H
#define ADC_H

#include <8051.h>

typedef enum {
    ADC_CH_ACS712 = 1,
    ADC_CH_LM35   = 2
} adc_channel_t;

void ADC_Init(void);
unsigned int ADC_Read(adc_channel_t ch);

#endif
