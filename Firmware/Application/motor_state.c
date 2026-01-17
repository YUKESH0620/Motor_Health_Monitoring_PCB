#include "motor_state.h"
#include "pin_config.h"
#include "fault_manager.h"

static motor_state_t motor_state = MOTOR_IDLE;

void MotorState_Init(void)
{
    motor_state = MOTOR_IDLE;

    // IDLE = PWM 0%
    EN1_PWM = 0;
    EN2_PWM = 0;
}

void MotorState_SetRun(void)
{
    if (!Fault_IsActive())
    {
        motor_state = MOTOR_RUN;
        // PWM duty will be applied elsewhere (UART command)
    }
}

void MotorState_SetIdle(void)
{
    motor_state = MOTOR_IDLE;
    EN1_PWM = 0;
    EN2_PWM = 0;
}

void MotorState_SetFault(void)
{
    motor_state = MOTOR_FAULT;
    EN1_PWM = 0;
    EN2_PWM = 0;
}

void MotorState_ResetFault(void)
{
    // Clear fault latch and go to IDLE
    Fault_Init();
    motor_state = MOTOR_IDLE;
    EN1_PWM = 0;
    EN2_PWM = 0;
}

motor_state_t MotorState_Get(void)
{
    return motor_state;
}
