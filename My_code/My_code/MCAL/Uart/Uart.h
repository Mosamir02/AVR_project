/*
 * Uart.h
 *
 * Created: 12/7/2023 2:39:25 AM
 *  Author: Mohamed
 */ 

#ifndef UART_H_
#define UART_H_
/***********************************_INCLUDES_***********************************/
#include "UartCfg.h"
#include "STD_types.h"
#include "BIT_math.h"
#include "Reg.h"
/*************************************_MACROS_***********************************/
#define  PARITY_DISABLE		1
#define	 PARITY_EVEN	    2
#define	 PARITY_ODD			3
/***********************************_PROTOTYPES_*********************************/
void M_Uart_Init(void);
void M_Uart_Transmit(u8);
u8   M_Uart_Rec(void);
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/
#endif /* UART_H_ */