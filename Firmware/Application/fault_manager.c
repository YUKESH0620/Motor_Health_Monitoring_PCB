#include "fault_manager.h"
#include "pin_config.h"

/* Thresholds */
#define OC_THRESHOLD_A   15.0f
#define OT_THRESHOLD_C   70.0f

/* Latched fault flag (8051 style) */
static unsigned char fault_latched = 0;

void Fault_Init(void)
{
    fault_latched = 0;

    /* Enable motors (PWM allowed) */
    EN1_PWM = 1;
    EN2_PWM = 1;

    /* Fault LED OFF (active LOW) */
    LED_FAULT = 1;
}

void Fault_Check(float current_A, float temperature_C)
{
    if (fault_latched == 0)
    {
        if ((current_A >= OC_THRESHOLD_A) ||
            (temperature_C >= OT_THRESHOLD_C))
        {
            fault_latched = 1;

            /* Indicate fault */
            LED_FAULT = 0;

            /* Disable BOTH motors */
            EN1_PWM = 0;
            EN2_PWM = 0;
        }
    }
}

unsigned char Fault_IsActive(void)
{
    return fault_latched;   /* 0 = no fault, 1 = fault */
}


