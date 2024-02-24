/*
 * Timer1.c
 *
 * Created: 12/6/2023 3:25:29 AM
 *  Author: Mohamed
 */ 

/***********************************_INCLUDES_***********************************/
#include "Timer1.h"
/***********************************_FUNCTIONS_**********************************/

void M_Timer1_Pwm1_Init(void)
 {
	 //To make PD5 as output  
	  SET_BIT(DDRD,5);
	  //To Select Mode Number 14 in table  47.
	  CLR_BIT(TCCR1A,0);
	  SET_BIT(TCCR1A,1);
	  SET_BIT(TCCR1B,3);
	  SET_BIT(TCCR1B,4);
	  // To select Non inverted  mode  generate PWM  at OC1A pin.
	  CLR_BIT(TCCR1A,6);
	  SET_BIT(TCCR1A,7);
	  
}
 
void M_Timer1_Pwm1_SetFreq(u32 Local_u32_Frequancy)
{
  ICR1 = (((F_OSC * 1000000)/TIMER1_PRESCALER) / Local_u32_Frequancy);
}
 
void M_Timer1_Pwm1_SetDutyCycle(u8 Local_u8_DutyCycle)
{

	 OCR1A = (((Local_u8_DutyCycle * ICR1) / 100)-1);
}
 
void M_Timer1_Pwm1_Start(void)
 {
	 #if TIMER1_PRESCALER == 256
	 CLR_BIT(TCCR1B,0);
	 CLR_BIT(TCCR1B,1);
	 SET_BIT(TCCR1B,2);
	 #endif
 }
 
void M_Timer1_Pwm1_Stop(void)
 {
	 
	 CLR_BIT(TCCR1B,0);
	 CLR_BIT(TCCR1B,1);
	 CLR_BIT(TCCR1B,2);
 }
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/