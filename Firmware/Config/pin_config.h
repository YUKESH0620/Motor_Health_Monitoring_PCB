#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

#include <8051.h>

// LED pins (from schematic)
#define LED_FAULT  P1_4
#define LED_MOTOR  P1_5

// ADC pins (U11)
#define CS    P1_0
#define CLK   P1_1
#define DIN   P1_2
#define DOUT  P1_3

// Motor PWM enable pins
#define EN1_PWM  P2_0
#define EN2_PWM  P2_3

// Keypad rows (outputs)
#define KP_R1  P0_0
#define KP_R2  P0_1
#define KP_R3  P0_2
#define KP_R4  P0_3

// Keypad columns (inputs, pull-up)
#define KP_C1  P0_4
#define KP_C2  P0_5
#define KP_C3  P0_6
#define KP_C4  P0_7

// OLED I2C pins
#define OLED_SCL  P3_4
#define OLED_SDA  P3_5

#endif
