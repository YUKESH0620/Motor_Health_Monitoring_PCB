#include "filter.h"

float adc_to_voltage(unsigned int adc)
{
    return (adc * 5.0f) / 255.0f;
}

float voltage_to_current(float v)
{
    // ACS770LCB-050B
    return (v - 2.5f) / 0.04f;
}

float voltage_to_temperature(float v)
{
    // LM35: 10mV per °C
    return v * 100.0f;
}
