#ifndef PWM_H
#define PWM_H

void PWM_Init(void);
void PWM_SetDuty(unsigned char duty_percent); // 0–100
void PWM_Update(void); // call every 1 ms
unsigned char PWM_GetDuty(void);
void PWM_AdjustSigned(signed char delta);

#endif
