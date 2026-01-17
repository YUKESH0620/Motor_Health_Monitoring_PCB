#ifndef MOTOR_STATE_H
#define MOTOR_STATE_H

typedef enum {
    MOTOR_IDLE = 0,
    MOTOR_RUN,
    MOTOR_FAULT
} motor_state_t;

void MotorState_Init(void);
void MotorState_SetRun(void);
void MotorState_SetIdle(void);
void MotorState_SetFault(void);
void MotorState_ResetFault(void);
motor_state_t MotorState_Get(void);

#endif
