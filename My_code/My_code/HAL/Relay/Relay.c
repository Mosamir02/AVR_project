/*
 * Relay.c
 *
 * Created: 11/27/2023 7:48:08 PM
 *  Author: Mohamed
 */ 

/***********************************_INCLUDES_***********************************/
#include "Relay.h"
/***********************************_FUNCTIONS_*********************************/
void H_Relay_Init()
{
	M_Dio_PinMode(RELAY_PIN,OUTPUT);
}
void H_Relay_On(void)
{
	M_Dio_PinWrite(RELAY_PIN,HIGH);
}
void H_Relay_Off(void)
{
	M_Dio_PinWrite(RELAY_PIN,LOW);
}
void H_Relay_Tog(void)
{
	M_Dio_Pin_Tog(RELAY_PIN);
}
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/