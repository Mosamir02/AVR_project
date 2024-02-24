/*
 * Twi.c
 *
 * Created: 12/16/2023 10:41:45 PM
 *  Author: Mohamed
 */ 

/***********************************_INCLUDES_***********************************/
#include "Twi.h"
/***********************************_FUNCTIONS_*********************************/
void M_Twi_Init(void)
{
	#if   TWI_MODE == TWI_MASTER
	TWBR = 12;					//to select Fscl = 400khz
	#elif TWI_MODE == TWI_SLAVE
	TWAR = 0b00000010;			// to select slave add = 1. and disable general call rec.
	#endif 
	SET_BIT(TWCR,2);			//to enable  TWI  circuit
}

void M_Twi_StartCondition(void)
{
	SET_BIT(TWCR,5);
	SET_BIT(TWCR,7);				//to clear the flag
	while(GET_BIT(TWCR,7)==0);	
	while((TWSR & 0xF8) != START_ACK);
}
void M_Twi_SendSlaveAdressWrite(u8 Local_u8_Adress)
{
	TWDR = (Local_u8_Adress << 1);
	CLR_BIT(TWCR,5);
	SET_BIT(TWCR,7);				//to clear the flag 
	while(GET_BIT(TWCR,7) == 0);
	while((TWSR & 0xF8)  != SLAVE_AD_AND_WR_ACK);
}
void M_Twi_SendSlaveAdressRead(u8 Local_u8_Adress)
{
	TWDR = (Local_u8_Adress << 1) | 1;
	SET_BIT(TWCR,7);				//to clear the flag
	while(GET_BIT(TWCR,7)==0);
	while((TWSR & 0xF8) != SLAVE_AD_AND_RD_ACK);
}
void M_Twi_SendByte(u8 Local_u8_Data)
{
	TWDR = Local_u8_Data;
	CLR_BIT(TWCR,5);
	SET_BIT(TWCR,7);
	while(GET_BIT(TWCR,7)==0);
	while((TWSR & 0xF8) != WR_BYTE_ACK);
}
u8   M_Twi_ReadByte(void)
{
	CLR_BIT(TWCR,5); 
	CLR_BIT(TWCR,4);
	SET_BIT(TWCR,6);
	SET_BIT(TWCR,7);				//to clear the flag
	while(GET_BIT(TWCR,7) == 0);
	while((TWSR & 0xF8)   != RD_BYTE_WITH_ACK);
	return TWDR;
}
void M_Twi_RepeatedStart(void)
{
	SET_BIT(TWCR,5);
	SET_BIT(TWCR,7);				//to clear the flag
	while(GET_BIT(TWCR,7)==0);
	while((TWSR & 0xF8) != REP_START_ACK);
}
void M_Twi_StopCondition(void)
{
	SET_BIT(TWCR,4);
	SET_BIT(TWCR,7);				//to clear the flag
	//while(GET_BIT(TWCR,7)==0);
}
void M_Twi_ACK(void)
{
	SET_BIT(TWCR,6);
	SET_BIT(TWCR,7);				//to clear the flag
	while(GET_BIT(TWCR,7)==0);
}
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/