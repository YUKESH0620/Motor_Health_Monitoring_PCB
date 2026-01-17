#ifndef FILTER_H
#define FILTER_H

float adc_to_voltage(unsigned int adc);
float voltage_to_current(float v);
float voltage_to_temperature(float v);

#endif
