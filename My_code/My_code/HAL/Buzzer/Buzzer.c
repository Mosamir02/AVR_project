/*
 * Buzzer.c
 *
 * Created: 11/27/2023 6:38:07 PM
 *  Author: Mohamed
 */ 

/***********************************_INCLUDES_***********************************/
#include "Buzzer.h"
/***********************************_FUNCTIONS_*********************************/
void H_Buzzer_Init(void)
{
	M_Dio_PinMode(BUZZER_PIN,OUTPUT);
}
void H_Buzzer_On(void)
{
	M_Dio_PinWrite(BUZZER_PIN,HIGH);
}
void H_Buzzer_Off(void)
{
	M_Dio_PinWrite(BUZZER_PIN,LOW);
}
void H_Buzzer_Tog(void)
{
	M_Dio_Pin_Tog(BUZZER_PIN);		
}
void H_Buzzer_BeepShort(void)
{
	H_Buzzer_On();
	_delay_ms(BUZZER_DELAY_TIME_ON);
	H_Buzzer_Off();
}
void H_Buzzer_BeepLong(void)
{
	 H_Buzzer_On();
	 _delay_ms(BUZZER_DELAY_TIME_LONG);

	 H_Buzzer_Off();
}
void H_Buzzer_BeepTwice(void)
{
	H_Buzzer_BeepShort();
	_delay_ms(BUZZER_DELAY_TIME_OFF);
	H_Buzzer_BeepShort();
}
void H_Buzzer_BeepTriple(void)
{
	H_Buzzer_BeepTwice();
	_delay_ms(BUZZER_DELAY_TIME_OFF); 
	H_Buzzer_BeepShort();
}
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/