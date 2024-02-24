/*
 * Spi.c
 *
 * Created: 12/9/2023 6:10:27 PM
 *  Author: Mohamed
 */ 

/***********************************_INCLUDES_***********************************/
#include "Spi.h"
/***********************************_FUNCTIONS_*********************************/
void M_Spi_Init()
{
	#if   SPI_MODE == SPI_MASTER
	SET_BIT(SPCR,4);
	SET_BIT(DDRB,4);//to make SS   	AS OUTPUT
	SET_BIT(DDRB,5);//to make MOSI	AS OUTPUT
	CLR_BIT(DDRB,6);//to make MISO	AS INTPUT
	SET_BIT(DDRB,7);//to make SCK	AS OUTPUT
	//----------------------------------------to select division factor -> 128.
	SET_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	CLR_BIT(SPSR,0);
	#elif SPI_MODE == SPI_SLAVE
	CLR_BIT(SPCR,4);
	CLR_BIT(DDRB,4);//to make SS   	AS INTPUT
	CLR_BIT(DDRB,5);//to make MOSI	AS INTPUT
	SET_BIT(DDRB,6);//to make MISO	AS OUTPUT
	CLR_BIT(DDRB,7);//to make SCK	AS INTPUT
	#endif
	
	

	
	
	
	//to select enable spi.
	SET_BIT(SPCR,6);
}

u8 M_Spi_Transive(u8 Local_u8_Data_Send)
{
	
	SPDR=Local_u8_Data_Send;
	while(GET_BIT(SPSR,7) == 0);
	return SPDR;
}
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/