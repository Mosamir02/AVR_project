/*
 * PushButton.c
 *
 * Created: 11/28/2023 2:01:07 AM
 *  Author: Mohamed
 */ 

/***********************************_INCLUDES_***********************************/
#include "PushButton.h"
/***********************************_FUNCTIONS_*********************************/
void H_PushButton_Init(u8 Local_u8_PushButton)
{
	switch(Local_u8_PushButton)
	{
		case PUSHBUTTON0 :	M_Dio_PinMode(PUSHBUTTON0_PIN,INPUT); break;
		case PUSHBUTTON1 :	M_Dio_PinMode(PUSHBUTTON1_PIN,INPUT); break;
		case PUSHBUTTON2 :	M_Dio_PinMode(PUSHBUTTON2_PIN,INPUT); break;
		default:	 											   break;
	}
}
u8 H_PushButton_Read(u8 Local_u8_PushButton)
{
	u8 Local_u8_Reading = RELEASED; 
	switch(Local_u8_PushButton)
	{
	  case PUSHBUTTON0 :
		if (M_Dio_PinRead(PUSHBUTTON0_PIN) == PRESSED)
		{
		    _delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
		    if (M_Dio_PinRead(PUSHBUTTON0_PIN) == PRESSED)
		    {
		  	     while(M_Dio_PinRead(PUSHBUTTON0_PIN) == PRESSED);
		    	 Local_u8_Reading = PRESSED;
		    }
		}                                       break;
	  case PUSHBUTTON1 :
		if (M_Dio_PinRead(PUSHBUTTON1_PIN) == PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if (M_Dio_PinRead(PUSHBUTTON1_PIN) == PRESSED)
			{
				while(M_Dio_PinRead(PUSHBUTTON1_PIN) == PRESSED);
				Local_u8_Reading = PRESSED;
			}
		}										break; 	
	  case PUSHBUTTON2:
		if (M_Dio_PinRead(PUSHBUTTON2_PIN) == PRESSED)
		{
			_delay_ms(PUSH_BUTTON_DEBOUNCING_TIME);
			if (M_Dio_PinRead(PUSHBUTTON2_PIN) == PRESSED)
			{
				while(M_Dio_PinRead(PUSHBUTTON2_PIN) == PRESSED);
				Local_u8_Reading = PRESSED;
			}
		}										break;
		default:	 				       		break;
	}
	return Local_u8_Reading;
}
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/