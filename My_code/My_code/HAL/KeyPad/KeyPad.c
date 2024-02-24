/*
 * KeyPad.c
 *
 * Created: 11/30/2023 6:11:58 PM
 *  Author: Mohamed
 */ 

/***********************************_INCLUDES_***********************************/
#include "KeyPad.h"
/***********************************_FUNCTIONS_*********************************/
void H_Keypad_Init(void)
{
	M_Dio_PinMode(KEYPAD_R0_PIN,OUTPUT);
	M_Dio_PinMode(KEYPAD_R1_PIN,OUTPUT);
	M_Dio_PinMode(KEYPAD_R2_PIN,OUTPUT);
	M_Dio_PinMode(KEYPAD_R3_PIN,OUTPUT);
	
	M_Dio_PinMode(KEYPAD_C0_PIN,INPUT);
	M_Dio_PinMode(KEYPAD_C1_PIN,INPUT);
	M_Dio_PinMode(KEYPAD_C2_PIN,INPUT);
	M_Dio_PinMode(KEYPAD_C3_PIN,INPUT);
	
	M_Dio_PinWrite(KEYPAD_R0_PIN,HIGH);
	M_Dio_PinWrite(KEYPAD_R1_PIN,HIGH);
	M_Dio_PinWrite(KEYPAD_R2_PIN,HIGH);
	M_Dio_PinWrite(KEYPAD_R3_PIN,HIGH);
	
	M_Dio_PinPullUpRes(KEYPAD_C0_PIN,ENABLE);
	M_Dio_PinPullUpRes(KEYPAD_C1_PIN,ENABLE);
	M_Dio_PinPullUpRes(KEYPAD_C2_PIN,ENABLE);
	M_Dio_PinPullUpRes(KEYPAD_C3_PIN,ENABLE);
	
}
u8   H_Keypad_Read(void)
{
	#if KEYPAD_MODE == KEYPAD_KIT
	u8 Local_u8_Arr[4][4] = { { '1' , '2' , '3' , 'A' },
							  { '4' , '5' , '6' , 'B' }, 
							  { '7' , '8' , '9' , 'C' },
							  { '*' , '0' , '#' , 'D' }};
	#elif KEYPAD_MODE == KEYPAD_PROTEUS						 
	u8 Local_u8_Arr[4][4] = { { '7' , '8' , '9' , '/' },
	                          { '4' , '5' , '6' , '*' },
	                          { '1' , '2' , '3' , '-' },
	                          { 'C' , '0' , '=' , '+' }};
	#endif							 
	u8 Local_u8_Reading =KEYPAD_RELEASED; 
	u8 Local_u8_Value = 0;
	u8 Local_u8_Col = 0 ;
	u8 Local_u8_Row = 0 ;
	for (Local_u8_Row=KEYPAD_R0_PIN;Local_u8_Row<=KEYPAD_R3_PIN;Local_u8_Row++)
	{
		M_Dio_PinWrite(Local_u8_Row,LOW);
		for (Local_u8_Col=KEYPAD_C0_PIN;Local_u8_Col<=KEYPAD_C3_PIN;Local_u8_Col++)
		{
			Local_u8_Reading = M_Dio_PinRead(Local_u8_Col);
			if(Local_u8_Reading == KEYPAD_PRESSED)
			{
				_delay_ms(KEYPAD_DEBOUNCING_TIME);
				if(M_Dio_PinRead(Local_u8_Col) == KEYPAD_PRESSED)
				{
					while(M_Dio_PinRead(Local_u8_Col) == KEYPAD_PRESSED);
					Local_u8_Value = Local_u8_Arr[Local_u8_Row - KEYPAD_R0_PIN][Local_u8_Col - KEYPAD_C0_PIN];
				}				
			}
		}
		M_Dio_PinWrite(Local_u8_Row,HIGH);
	}
	return Local_u8_Value;
}
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/