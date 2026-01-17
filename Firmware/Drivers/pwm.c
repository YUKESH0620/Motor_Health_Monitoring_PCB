#include "pwm.h"
#include "pin_config.h"
#include "motor_state.h"

static unsigned char duty = 0;     // 0–100
static unsigned char tick = 0;     // 0 or 1 (2 ms period)

void PWM_Init(void)
{
    duty = 0;
    tick = 0;
    EN1_PWM = 0;
    EN2_PWM = 0;
}

void PWM_SetDuty(unsigned char duty_percent)
{
    if (duty_percent > 100) duty_percent = 100;
    duty = duty_percent;
}

unsigned char PWM_GetDuty(void)
{
    return duty;
}

void PWM_AdjustSigned(signed char delta)
{
    signed int temp = duty + delta;

    if (temp < 0)   temp = 0;
    if (temp > 100) temp = 100;

    PWM_SetDuty((unsigned char)temp);
}

void PWM_Update(void)
{
    tick ^= 1; // toggle 0/1 every 1 ms ? 2 ms period (500 Hz)

    // Default OFF
    EN1_PWM = 0;
    EN2_PWM = 0;

    // Only RUN state allows PWM
    if (MotorState_Get() == MOTOR_RUN)
    {
        if (duty >= 100)
        {
            EN1_PWM = 1;
            EN2_PWM = 1;
        }
        else if (duty > 0)
        {
            // Simple 2-slice PWM
            if (duty >= 50)
            {
                // ON both slices
                EN1_PWM = 1;
                EN2_PWM = 1;
            }
            else
            {
                // ON only on one slice
                if (tick == 0)
                {
                    EN1_PWM = 1;
                    EN2_PWM = 1;
                }
            }
        }
    }
}
