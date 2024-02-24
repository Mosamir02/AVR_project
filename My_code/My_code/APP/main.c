/*
 * My_code.c
 *
 * Created: 11/19/2023 11:42:21 PM
 * Author : Mohamed
 */ 

/***********************************_INCLUDES_***********************************/
#include "BIT_math.h"
#include "STD_types.h"
#include "Dio.h"
#include "Reg.h"
#include "led.h"
#include "Lcd.h"
#include "Buzzer.h"
#include "PushButton.h"
#include "KeyPad.h"
#include "Ssd.h"
#include "Adc.h"
#include "ExtInt.h"
#include "Timer0.h"
#include "TempSensor.h"
#include "DcMotor.h"
#include "Timer1.h"
#include "ServoMotor.h"
#include "Wdt.h"
#include "Uart.h"
#include "Spi.h"
#include "Twi.h"
#include "Eeprom.h"
/*************************************_MACROS_***********************************/
#define  F_CPU 16000000UL
#include <util/delay.h>
/***********************************_FUNCTIONS_*********************************/
//void A_ExtInt0_Excution(void); 
//void A_Adc_Excution(void);
//void A_Timer0_Excution(void);


int main(void)	
{	
	
	H_Lcd_Init();
	
	H_Lcd_WriteCharacter('M');
	H_Lcd_WriteCharacter('A');
	H_Lcd_WriteCharacter('M');
	H_Lcd_WriteCharacter('A');
	while (1)
	{
		
	}
	/*
	H_Lcd_Init(); 
	H_Eeprom_Init();
	u32 x=0;
	x= H_Eeprom_Read(5,145);
	while(1)
	{
		H_Eeprom_Write(x,5,145);
		H_Lcd_WriteNumber(x);
		_delay_ms(100);
		x++;
	}
	*/
	
}

void A_Timer0_Excution(void)
{	
	H_Led_On(LED2);
}

void A_Adc_Excution(void)
{
	H_Led_On(LED1);
	H_Led_On(LED2);
}

void A_ExtInt0_Excution(void)
{
	H_Lcd_WriteCharacter('M');	
}



/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/


/***********************************_INCLUDES_***********************************/

/*************************************_MACROS_***********************************/

/***********************************_PROTOTYPES_*********************************/

/*******************************_SELECT_DELAY_TIME_******************************/

/*******************************_SELECT_BUZZER_PIN_******************************/

/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/
