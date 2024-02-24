/*
 * ServoMotor.c
 *
 * Created: 12/6/2023 2:46:51 AM
 *  Author: Mohamed
 */ 

/***********************************_INCLUDES_***********************************/
#include "ServoMotor.h"

/***********************************_FUNCTIONS_**********************************/
void H_Servo_Init(void)
{
	M_Timer1_Pwm1_Init();
	M_Timer1_Pwm1_SetFreq(50);
}


void H_Servo_SetAngel(u8 modes)
{
	if(modes==0 && modes<=85)
		{ 
		 M_Timer1_Pwm1_SetDutyCycle(0);	 
		}
	 else if(modes>=90 && modes<=175)
	 {
		 M_Timer1_Pwm1_SetDutyCycle(5);
	 }		 
	 else
	 {
		 M_Timer1_Pwm1_SetDutyCycle(10);
	 } 			     
	
}

void H_Servo_Start(void)
{
	M_Timer1_Pwm1_Start();
}

void H_Servo_Stop(void)
{
	M_Timer1_Pwm1_Stop();
}

/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/