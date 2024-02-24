/*
 * PushButton.h
 *
 * Created: 11/28/2023 2:01:35 AM
 *  Author: Mohamed
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_
/***********************************_INCLUDES_***********************************/
#include "PushButtonCfg.h"
#include "Dio.h"
#include "STD_types.h"
#define  F_CPU 16000000UL
#include <util/delay.h>
/*************************************_MACROS_***********************************/
#define  PUSHBUTTON0     0
#define  PUSHBUTTON1     1
#define  PUSHBUTTON2     2
		 
#define  ACTIVE_HIGH	 1
#define  ACTIVE_LOW		 2
		 
#if      PUSH_BUTTON_MODE  == ACTIVE_HIGH
#define  RELEASED		 0
#define  PRESSED		 1
#elif	 PUSH_BUTTON_MODE  == ACTIVE_LOW
#define  RESSED			 0
#define  RELEASED		 1
#endif

  
/***********************************_PROTOTYPES_*********************************/
void H_PushButton_Init(u8);
u8 H_PushButton_Read(u8);
/********************************************************************************/
/***********************************END******************************************/
/********************************************************************************/
#endif /* PUSHBUTTON_H_ */