/*
 * led.c
 *
 * Created: 11/22/2023 6:43:57 PM
 *  Author: Mohamed
 */ 

/***********************************_INCLUDES_***********************************/
#include "led.h"
/***********************************_FUNCTIONS_*********************************/
void H_Led_Init(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case LED0:M_Dio_PinMode(LED_PIN0,OUTPUT);  break;
		case LED1:M_Dio_PinMode(LED_PIN1,OUTPUT);  break;
		case LED2:M_Dio_PinMode(LED_PIN2,OUTPUT);  break;
		default:								   break;
	}
}

void H_Led_On(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case LED0:M_Dio_PinWrite(LED_PIN0,HIGH);  break;
		case LED1:M_Dio_PinWrite(LED_PIN1,HIGH);  break;
		case LED2:M_Dio_PinWrite(LED_PIN2,HIGH);  break;
		default:							      break;
	}
}

void H_Led_Off(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case LED0:M_Dio_PinWrite(LED_PIN0,LOW);  break;
		case LED1:M_Dio_PinWrite(LED_PIN1,LOW);  break;
		case LED2:M_Dio_PinWrite(LED_PIN2,LOW);  break;
		default:							     break;
	}
}


void H_Led_Tog(u8 Local_u8_Led)
{
	switch(Local_u8_Led)
	{
		case LED0:M_Dio_Pin_Tog(LED_PIN0);  break;
		case LED1:M_Dio_Pin_Tog(LED_PIN1);  break;
		case LED2:M_Dio_Pin_Tog(LED_PIN2);  break;
		default:					        break;
	}
}


void H_Led_Blink_Once(u8 Local_u8_Led)
{
	switch(Local_u8_Led){
	case LED0:
	     M_Dio_PinWrite(LED_PIN0,HIGH);  
	     _delay_ms(LED_DELAY_TIME);		    
	     M_Dio_PinWrite(LED_PIN0,LOW);   
										break;
	case LED1:
	     M_Dio_PinWrite(LED_PIN1,HIGH);
	     _delay_ms(LED_DELAY_TIME);
	     M_Dio_PinWrite(LED_PIN1,LOW);
										break;
	case LED2:
	     M_Dio_PinWrite(LED_PIN2,HIGH);
	     _delay_ms(LED_DELAY_TIME);
	     M_Dio_PinWrite(LED_PIN2,LOW);
										break;									
	default:							break;									
	}
}


void H_Led_Blink_Twice(u8 Local_u8_Led)
{	  
	 H_Led_Blink_Once(Local_u8_Led);
	 _delay_ms(LED_DELAY_TIME);
	 H_Led_Blink_Once(Local_u8_Led);             
}
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/