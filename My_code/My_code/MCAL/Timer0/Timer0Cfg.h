/*
 * Timer0Cfg.h
 *
 * Created: 12/3/2023 6:54:05 PM
 *  Author: Mohamed
 */ 

#ifndef TIMER0CFG_H_
#define TIMER0CFG_H_
/**************************************_SELECT_TIMER0_MODE_****************************/
//option1 -> [	NORMAL_MODE ]
//option2 -> [  CTC_MODE	]
#define TIMER0_MODE					   CTC_MODE
/**************************************_SELECT_PWM0_MODE_****************************/
//option1 -> [	FAST_PWM0		   ]
//option2 -> [  PHASE_CORRECT_PWM0 ]
#define PWM0_MODE					   PHASE_CORRECT_PWM0   
/*******************************_SELECT_FAST_PWM_MODE_****************************/
//option1 -> [	NON_INVERTED ]
//option2 -> [  INVERTED	 ]
#define FAST_PWM_MODE				   NON_INVERTED
/*******************************_SELECT_PHASE_CORRECT_PWM0_MODE_****************************/
//option1 -> [	NON_INVERTED ]		   
//option2 -> [  INVERTED	 ]		   
#define PHASE_CORRECT_PWM0_MODE        NON_INVERTED
/**************************************_SELECT_F_OSC_****************************/
#define  F_OSC			  16
/**************************************_SELECT_TIMER0_PRESCALER_*****************/
//option1 -> [ 256  ]
//option2 -> [ 1024 ]
#define TIMER0_PRESCALER  1024
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/
#endif /* TIMER0CFG_H_ */