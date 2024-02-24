/*
 * DcMotor.c
 *
 * Created: 12/5/2023 4:43:29 AM
 *  Author: Mohamed
 */ 

/***********************************_INCLUDES_***********************************/
#include "DcMotor.h"
/***********************************_FUNCTIONS_**********************************/
void H_DcMotor_Init(void)
{
	M_Dio_PinMode(DCMOTOR_PIN1,OUTPUT);
	M_Dio_PinMode(DCMOTOR_PIN2,OUTPUT);
	M_Timer0_Pwm0_Init();
	
}
void H_DcMotor_SetDirection(u8 Local_u8_Direction)
{
	
	switch(Local_u8_Direction)
	{
		case CLK:	
		M_Dio_PinWrite(DCMOTOR_PIN1,HIGH);	
		M_Dio_PinWrite(DCMOTOR_PIN2,LOW);
									break;
		case ACLK:	
		M_Dio_PinWrite(DCMOTOR_PIN2,HIGH);
		M_Dio_PinWrite(DCMOTOR_PIN1,LOW);
									break;
		default:					break;
		
	}
}
void H_DcMotor_SetSpeed(u8 Local_u8_Speed)
{
	M_Timer0_Pwm0_SetDutyCycle(Local_u8_Speed);
}
void H_DcMotor_Start(void)
{
	M_Timer0_Pwm0_Start();
}
void H_DcMotor_Stop(void)
{
	M_Timer0_Pwm0_Stop();
}
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/