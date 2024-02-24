/*
 * Ssd.c
 *
 * Created: 12/2/2023 12:39:06 AM
 *  Author: Mohamed
 */ 

/***********************************_INCLUDES_***********************************/
#include "Ssd.h"
/***********************************_FUNCTIONS_*********************************/
static void H_Ssd_Digit_Display(u8,u8);
void H_Ssd_Init(void)
{
	M_Dio_PinMode(SSD_A_PIN,OUTPUT);
	M_Dio_PinMode(SSD_B_PIN,OUTPUT);
	M_Dio_PinMode(SSD_C_PIN,OUTPUT);
	M_Dio_PinMode(SSD_D_PIN,OUTPUT);
	M_Dio_PinMode(SSD_EN_1_PIN,OUTPUT);
	M_Dio_PinMode(SSD_EN_2_PIN,OUTPUT);
	
}
void H_Ssd_Write(u8 Local_u8_Number)
{
	u8 Local_u8_Units = Local_u8_Number % 10;
	u8 Local_u8_Tens  = Local_u8_Number / 10; 
	u8 Local_u8_Counter = 0;
	 for(Local_u8_Counter=0;Local_u8_Counter<50;Local_u8_Counter++)
	 {
	 	
	 H_Ssd_Digit_Display( Local_u8_Units ,RIGHT_SSD);
	 _delay_ms(5);
	 H_Ssd_Digit_Display( Local_u8_Tens  ,LEFT_SSD);
	 _delay_ms(5);
	
	 }
	 M_Dio_PinWrite(SSD_EN_1_PIN,LOW);
	 M_Dio_PinWrite(SSD_EN_2_PIN,LOW);
}

static void H_Ssd_Digit_Display(u8 Local_u8_Number,u8 Local_u8_Ss)
{
	switch(Local_u8_Ss)
	{
		case  RIGHT_SSD:
		M_Dio_PinWrite(SSD_EN_1_PIN,LOW);
		M_Dio_PinWrite(SSD_EN_2_PIN,HIGH);
									break;
		case  LEFT_SSD:
		M_Dio_PinWrite(SSD_EN_1_PIN,HIGH);
		M_Dio_PinWrite(SSD_EN_2_PIN,LOW);
									break;
		default:					break;
	}
	  switch (Local_u8_Number)
	  {
		case 0:
		M_Dio_PinWrite(SSD_A_PIN,LOW);
		M_Dio_PinWrite(SSD_B_PIN,LOW);
		M_Dio_PinWrite(SSD_C_PIN,LOW);
		M_Dio_PinWrite(SSD_D_PIN,LOW);
		break;
		case 1:
		M_Dio_PinWrite(SSD_A_PIN,HIGH);
		M_Dio_PinWrite(SSD_B_PIN,LOW);
		M_Dio_PinWrite(SSD_C_PIN,LOW);
		M_Dio_PinWrite(SSD_D_PIN,LOW);
		break;
		case 2:
		M_Dio_PinWrite(SSD_A_PIN,LOW);
		M_Dio_PinWrite(SSD_B_PIN,HIGH);
		M_Dio_PinWrite(SSD_C_PIN,LOW);
		M_Dio_PinWrite(SSD_D_PIN,LOW);
		break;
		case 3:
		M_Dio_PinWrite(SSD_A_PIN,HIGH);
		M_Dio_PinWrite(SSD_B_PIN,HIGH);
		M_Dio_PinWrite(SSD_C_PIN,LOW);
		M_Dio_PinWrite(SSD_D_PIN,LOW);
		break;
		case 4:
		M_Dio_PinWrite(SSD_A_PIN,LOW);
		M_Dio_PinWrite(SSD_B_PIN,LOW);
		M_Dio_PinWrite(SSD_C_PIN,HIGH);
		M_Dio_PinWrite(SSD_D_PIN,LOW);
		break;
		case 5:
		M_Dio_PinWrite(SSD_A_PIN,HIGH);
		M_Dio_PinWrite(SSD_B_PIN,LOW);
		M_Dio_PinWrite(SSD_C_PIN,HIGH);
		M_Dio_PinWrite(SSD_D_PIN,LOW);
		break;
		case 6:
		M_Dio_PinWrite(SSD_A_PIN,LOW);
		M_Dio_PinWrite(SSD_B_PIN,HIGH);
		M_Dio_PinWrite(SSD_C_PIN,HIGH);
		M_Dio_PinWrite(SSD_D_PIN,LOW);
		break;
		case 7:
		M_Dio_PinWrite(SSD_A_PIN,HIGH);
		M_Dio_PinWrite(SSD_B_PIN,HIGH);
		M_Dio_PinWrite(SSD_C_PIN,HIGH);
		M_Dio_PinWrite(SSD_D_PIN,LOW);
		break;
		case 8:
		M_Dio_PinWrite(SSD_A_PIN,LOW);
		M_Dio_PinWrite(SSD_B_PIN,LOW);
		M_Dio_PinWrite(SSD_C_PIN,LOW);
		M_Dio_PinWrite(SSD_D_PIN,HIGH);
		break;
		case 9:
		M_Dio_PinWrite(SSD_A_PIN,HIGH);
		M_Dio_PinWrite(SSD_B_PIN,LOW);
		M_Dio_PinWrite(SSD_C_PIN,LOW);
		M_Dio_PinWrite(SSD_D_PIN,HIGH);
		break;
		default:					break;
		
	 }
}

void H_Ssd_Count_Up(u8 Local_u8_Target)
{
		u8 Local_u8_Number=0;
		for(Local_u8_Number=0;Local_u8_Number<=Local_u8_Target;Local_u8_Number++)
		{
			H_Ssd_Write(Local_u8_Number);
		}
}
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/