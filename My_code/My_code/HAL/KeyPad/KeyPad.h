/*
 * KeyPad.h
 *
 * Created: 11/30/2023 6:12:11 PM
 *  Author: Mohamed
 */ 

#ifndef KEYPAD_H_
#define KEYPAD_H_
/***********************************_INCLUDES_***********************************/
#include "KeyPadCfg.h"
#include "STD_types.h"
#include "Dio.h"
#define  F_CPU 16000000UL
#include <util/delay.h>
/*************************************_MACROS_***********************************/
#define  KEYPAD_PRESSED		0
#define  KEYPAD_RELEASED	1
#define  KEYPAD_PROTEUS		1
#define  KEYPAD_KIT			2
/***********************************_PROTOTYPES_*********************************/
void H_Keypad_Init(void);
u8   H_Keypad_Read(void);
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/
#endif /* KEYPAD_H_ */