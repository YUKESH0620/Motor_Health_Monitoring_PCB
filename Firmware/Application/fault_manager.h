#ifndef FAULT_MANAGER_H
#define FAULT_MANAGER_H

void Fault_Init(void);
void Fault_Check(float current_A, float temperature_C);
unsigned char Fault_IsActive(void);

#endif
