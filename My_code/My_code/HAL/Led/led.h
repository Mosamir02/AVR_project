/*
 * led.h
 *
 * Created: 11/22/2023 6:45:49 PM
 *  Author: Mohamed
 */ 


#ifndef LED_H_
#define LED_H_
/***********************************_INCLUDES_*************************************/
#include "led_cfg.h"
#include "STD_types.h"
#include "Dio.h"
#define  F_CPU 16000000UL
#include <util/delay.h>
/*************************************_MACROS_*************************************/
#define LED0	0
#define LED1	1
#define LED2	2 
/***********************************_PROTOTYPES_***********************************/
void H_Led_Init(u8);
void H_Led_On(u8);
void H_Led_Off(u8);
void H_Led_Tog(u8);
void H_Led_Blink_Once(u8);
void H_Led_Blink_Twice(u8);
/********************************************************************************/
/***********************************END******************************************/
/********************************************************************************/

#endif /* LED_H_ */