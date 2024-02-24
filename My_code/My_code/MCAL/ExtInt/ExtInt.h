/*
 * ExtInt.h
 *
 * Created: 12/2/2023 10:46:17 PM
 *  Author: Mohamed
 */ 

#ifndef EXTINT_H_
#define EXTINT_H_
/***********************************_INCLUDES_***********************************/
#include "ExtIntCfg.h"
#include "BIT_math.h"
#include "Reg.h"
#include <avr/interrupt.h>
/*************************************_MACROS_***********************************/
#define RISING_EDGE		1
#define FAILLING_EDGE	2
#define LOGICAL_CHANGE	3
#define LOW_LEVEL		4            
/***********************************_PROTOTYPES_*********************************/
void M_ExtInt_Int0_Init(void);
void M_ExtInt_SetCallBack(void(*)(void));
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/
#endif /* EXTINT_H_ */