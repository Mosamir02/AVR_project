/*
 * Twi.h
 *
 * Created: 12/16/2023 10:41:54 PM
 *  Author: Mohamed
 */ 


#ifndef TWI_H_
#define TWI_H_
/***********************************_INCLUDES_***********************************/
#include "TwiCfg.h"
#include "STD_types.h"
#include "Reg.h"
#include "BIT_math.h"
/*************************************_MACROS_***********************************/
#define  TWI_MASTER   1
#define  TWI_SLAVE    2

#define   START_ACK		              0x08
#define	  REP_START_ACK               0x10
#define	  SLAVE_AD_AND_WR_ACK         0x18
#define   SLAVE_AD_AND_RD_ACK	      0x40
#define	  WR_BYTE_ACK			      0x28
#define   WR_BYTE_NACK			      0x30
#define   RD_BYTE_WITH_ACK		      0x50
#define   RD_BYTE_WITH_NACK		      0x58
#define	  SLAVE_AD_REC_RD_REQ	      0xA8
#define	  SLAVE_AD_REC_WR_REQ	      0x60
#define	  SLAVE_DATA_REC		      0x80
#define   SLAVE_BYTE_TRANSMITTED      0xC0

/***********************************_PROTOTYPES_*********************************/
void M_Twi_Init(void);
void M_Twi_StartCondition(void);
void M_Twi_SendSlaveAdressWrite(u8);
void M_Twi_SendSlaveAdressRead(u8);
void M_Twi_SendByte(u8);
u8   M_Twi_ReadByte(void);
void M_Twi_RepeatedStart(void);
void M_Twi_StopCondition(void);
void M_Twi_ACK(void);
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/
#endif /* TWI_H_ */