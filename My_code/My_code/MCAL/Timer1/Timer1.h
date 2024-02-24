/*
 * Timer1.h
 *
 * Created: 12/6/2023 3:25:12 AM
 *  Author: Mohamed
 */ 

#ifndef TIMER1_H_
#define TIMER1_H_
/***********************************_INCLUDES_***********************************/
#include "Timer1Cfg.h"
#include "STD_types.h"
#include "BIT_math.h"
#include "Reg.h"
/*************************************_MACROS_***********************************/
//#define	  NULL_		            '\0'
//#define   NORMAL_MODE	             1
//#define   CTC_MODE		          2
//#define	  FAST_PWM0		          3
//#define   PHASE_CORRECT_PWM0        4
//#define   NON_INVERTED			  1
//#define   INVERTED				  2

/***********************************_PROTOTYPES_*********************************/
void M_Timer1_Pwm1_Init(void);
void M_Timer1_Pwm1_SetDutyCycle(u8);
void M_Timer1_Pwm1_Start(void);
void M_Timer1_Pwm1_Stop(void);
void M_Timer1_Pwm1_SetFreq(u32);
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/
#endif /* TIMER1_H_ */