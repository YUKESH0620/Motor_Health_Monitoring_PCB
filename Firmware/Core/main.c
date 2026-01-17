#include "system.h"
#include "uart.h"
#include "gpio.h"
#include "timer.h"
#include "adc.h"
#include "pwm.h"
#include "keypad.h"
#include "uart_rx.h"
#include "fault_manager.h"
#include "motor_state.h"
#include "uart_cmd.h"
#include "oled.h"
#include "pin_config.h"
#include "filter.h"

void main(void)
{
    unsigned long last = 0;
	  unsigned int adc_current = 0;   //Raw ADC Values
	  unsigned int adc_temp = 0;
	
	  float v_current = 0.0f;        //Converted Voltages
    float v_temp    = 0.0f;
	
	  float current_A = 0.0f;       //Final physical values
    float temperature_C = 0.0f;

    System_Init();
    UART_Init();
    GPIO_Init();
    Timer0_Init();
    ADC_Init();
    Fault_Init();
    MotorState_Init();
    PWM_Init();
    UART_RX_Init();
    Keypad_Init();
    OLED_Init();
          	
    UART_SendString("ADC TEST START\r\n");

    while (1)
    {
        unsigned char key = Keypad_GetKey();
if (key)
{
        while (Keypad_GetKey()); // wait for release
}

	UART_RX_Process();
			  
    {
   unsigned char key = Keypad_GetKey();

if (key)
{
    if (!Fault_IsActive())
    {
        switch (key)
        {
            case 1:   // START
                MotorState_SetRun();
                break;

            case 2:   // STOP
                MotorState_SetIdle();
                break;

            case 3:   // RESET FAULT
                MotorState_ResetFault();
                break;

            case 4:   // EMERGENCY STOP
                MotorState_SetIdle();
                break;

            case 5:   // PWM +5
                PWM_AdjustSigned(+5);
                break;

            case 6:   // PWM -5
                PWM_AdjustSigned(-5);
                break;

            case 7:   // PWM +10
                PWM_AdjustSigned(+10);
                break;

            case 8:   // PWM -10
                PWM_AdjustSigned(-10);
                break;

            case 9:   // 25%
                PWM_SetDuty(25);
                break;

            case 10:  // 50%
                PWM_SetDuty(50);
                break;

            case 11:  // 75%
                PWM_SetDuty(75);
                break;

            case 12:  // 100%
                PWM_SetDuty(100);
                break;

            default:
                break;
        }
    }
    else
    {
        // FAULT active → only RESET allowed
        if (key == 3)
        {
            MotorState_ResetFault();
        }
    }

    // Wait for key release (debounce)
    while (Keypad_GetKey());
}

    } 
    
	if (UART_RX_CommandReady())
{
    UART_CMD_Process(UART_RX_GetCommand());
}
		
        if (millis() - last >= 1000)
        {
            last = millis();
					   
					  adc_current = ADC_Read(ADC_CH_ACS712);
            adc_temp    = ADC_Read(ADC_CH_LM35);
         
            v_current = adc_to_voltage(adc_current); //ADC -> Voltage
            v_temp    = adc_to_voltage(adc_temp);
					
					  current_A      = voltage_to_current(v_current); //Voltage-> Physical Units
            temperature_C  = voltage_to_temperature(v_temp);
					
					  Fault_Check(current_A, temperature_C);
	    OLED_Clear();
            OLED_SetCursor(0, 0);
            OLED_Print("SYSTEM OK");


				
	/*  OLED_Clear();

            //Line 1 
            OLED_SetCursor(0, 0);
            OLED_Print("STATE:");
            if (MotorState_Get() == MOTOR_RUN)
               OLED_Print("RUN");
            else if (MotorState_Get() == MOTOR_FAULT)
               OLED_Print("FAULT");
            else
               OLED_Print("IDLE");

            //Line 2 
            OLED_SetCursor(2, 0);
            OLED_Print("PWM:");
            //show duty roughly
            OLED_Print("XX%");   // (numeric formatting can be refined)

            //Line 3
            OLED_SetCursor(4, 0);
            OLED_Print("I:");
            OLED_Print("A");

            //Line 4 
            OLED_SetCursor(6, 0);
            OLED_Print("T:");
            OLED_Print("C"); */

					
					  //STATE OVERRIDE BY FAULT
         if (Fault_IsActive())
         {
              MotorState_SetFault();
         }  
        }
				 if (Fault_IsActive())
           {
                  // placeholder
           }

    }
}
