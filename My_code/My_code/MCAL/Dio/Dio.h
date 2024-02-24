/*
 * Dio_interface.h
 *
 * Created: 11/20/2023 4:33:52 PM
 *  Author: Mohamed
 */ 


#ifndef DIO_H_
#define DIO_H_
/*************************************_INCLUDES_****************************/
#include "STD_types.h" 
#include "BIT_math.h"
#include "Reg.h"
/*************************************_MACROS_******************************/

/***********************************PORT_A**********************************/
#define  PA0	10
#define  PA1	11
#define  PA2	12
#define  PA3	13
#define  PA4	14
#define  PA5	15
#define  PA6	16
#define  PA7	17
/***********************************PORT_B**********************************/
#define  PB0	20
#define  PB1	21
#define  PB2	22
#define  PB3	23
#define  PB4	24
#define  PB5	25
#define  PB6	26
#define  PB7	27
/***********************************PORT_C**********************************/
#define  PC0	30
#define  PC1	31
#define  PC2	32
#define  PC3	33
#define  PC4	34
#define  PC5	35
#define  PC6	36
#define  PC7	37
/***********************************PORT_D**********************************/
#define  PD0	40
#define  PD1	41
#define  PD2	42
#define  PD3	43
#define  PD4	44
#define  PD5	45
#define  PD6	46
#define  PD7	47
/***********************************I/O************************************/
#define  OUTPUT  1
#define  INPUT   2
/***********************************H/L************************************/
#define HIGH	 1
#define LOW		 0
/*********************************_PORT_MODES_****************************/
#define A		 1
#define B		 2
#define C		 3
#define D		 4
/***********************************_EN_DS_*****************************/
#define  ENABLE  1
#define  DISABLE 2
/***********************************_PROTOTYPES_************************************/
void M_Dio_PinMode(u8  , u8  );
void M_Dio_PinWrite(u8 , u8  );
void M_Dio_Pin_Tog(u8);
void M_Dio_PinPullUpRes(u8,u8);
u8   M_Dio_PinRead(u8);
void M_Dio_PortMode(u8 ,u8);
void M_Dio_PortWrite(u8,u8);
/*****************************************************************************/
/***********************************END***************************************/
/*****************************************************************************/
#endif /* DIO_H_ */