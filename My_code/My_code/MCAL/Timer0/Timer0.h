/*
 * Timer0.h
 *
 * Created: 12/3/2023 6:53:48 PM
 *  Author: Mohamed
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
/***********************************_INCLUDES_***********************************/
#include "Timer0Cfg.h"
#include "STD_types.h"
#include "BIT_math.h"
#include "Reg.h"
#include <avr/interrupt.h>
/*************************************_MACROS_***********************************/
#define	  NULL_		            '\0'
#define   NORMAL_MODE	          1
#define   CTC_MODE		          2
#define	  FAST_PWM0		          3
#define   PHASE_CORRECT_PWM0      4
#define   NON_INVERTED			  1
#define   INVERTED				  2
	  
/***********************************_PROTOTYPES_*********************************/
void M_Timer0_Init(void);
void M_Timer0_SetTime(u32);
void M_Timer0_Start(void); 
void M_Timer0_Stop(void);
void M_Timer0_SetCallBack(void (*)(void));


void M_Timer0_Pwm0_Init(void);
void M_Timer0_Pwm0_SetDutyCycle(u8);
void M_Timer0_Pwm0_Start(void);
void M_Timer0_Pwm0_Stop(void);
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/
#endif /* TIMER0_H_ */