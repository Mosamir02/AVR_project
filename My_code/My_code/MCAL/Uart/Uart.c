/*
 * Uart.c
 *
 * Created: 12/7/2023 2:39:16 AM
 *  Author: Mohamed
 */ 

/***********************************_INCLUDES_***********************************/
#include "Uart.h"

/***********************************_FUNCTIONS_*********************************/
void M_Uart_Init(void)
{
	CLR_BIT(DDRD,0);// to enable  input circuit  for Rx pin.
	SET_BIT(DDRD,1);// to enable  output circuit for Tx pin.
	
	u8 Local_u8_UCSRC   = 0b10000000;
	u16 Local_u16_UBRRH = 0b00000000;
	
	//to select character  size = 8 bits.
	SET_BIT(Local_u8_UCSRC,1);
	SET_BIT(Local_u8_UCSRC,2);
	CLR_BIT(UCSRB,2);
	//to select asynch mode. 
	CLR_BIT(UCSRC,6);
	//to select parity mode.
	#if PARITY_MODE    == PARITY_DISABLE 
	CLR_BIT(Local_u8_UCSRC,4);
	CLR_BIT(Local_u8_UCSRC,5);
	#elif PARITY_MODE  == PARITY_ODD 
	SET_BIT(Local_u8_UCSRC,4);
	SET_BIT(Local_u8_UCSRC,5);
	#elif PARITY_MODE  == PARITY_EVEN 
	CLR_BIT(Local_u8_UCSRC,4);
	SET_BIT(Local_u8_UCSRC,5);
	#endif
	CLR_BIT(Local_u8_UCSRC,3);			//to select  stop -> 1 bit.
	UCSRC = Local_u8_UCSRC; 
	UBRRL=((u32)F_OSC * 1000000 / ((u32)16 * BUADRATE_MODE))-1;
	Local_u16_UBRRH = (((u32)F_OSC * 1000000 / ((u32)16 * BUADRATE_MODE))-1) >>8;
	UBRRH=Local_u16_UBRRH;
	SET_BIT(UCSRB,4);			//to enable  rx. circuit
	SET_BIT(UCSRB,3);			//to enable  tx. circuit
}

void M_Uart_Transmit(u8 Local_u8_Data)
{
	UDR=Local_u8_Data;
	while(GET_BIT(UCSRA,6) == 0);
}

u8   M_Uart_Rec(void)
{
	while(GET_BIT(UCSRA,7) == 0);
	return UDR;
}

/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/