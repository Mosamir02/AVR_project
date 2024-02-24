/*
 * Adc.h
 *
 * Created: 12/3/2023 2:38:47 AM
 *  Author: Mohamed
 */ 


#ifndef ADC_H_
#define ADC_H_
/***********************************_INCLUDES_***********************************/
#include "AdcCfg.h"
#include "STD_types.h"
#include "BIT_math.h"
#include "Reg.h"
#include <avr/interrupt.h>
/*************************************_MACROS_***********************************/
#define AREF_PIN		1		
#define AVCC 			2
#define _2V56			3
#define ADC_INT			1
#define ADC_POL			2
/***********************************_PROTOTYPES_*********************************/
void M_Adc_Init(void);
u16  M_Adc_Read(void);
void M_Adc_SetCallBack(void (*)(void));
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/
#endif /* ADC_H_ */