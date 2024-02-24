/*
 * DcMotor.h
 *
 * Created: 12/5/2023 4:43:36 AM
 *  Author: Mohamed
 */ 

#ifndef DCMOTOR_H_
#define DCMOTOR_H_
/***********************************_INCLUDES_***********************************/
#include "STD_types.h"
#include "Dio.h"
#include "Timer0.h"
#include "DcMotorCfg.h"
/*************************************_MACROS_***********************************/
#define CLK     1
#define ACLK    2
/***********************************_PROTOTYPES_*********************************/
void H_DcMotor_Init(void);
void H_DcMotor_SetDirection(u8);
void H_DcMotor_SetSpeed(u8);
void H_DcMotor_Start(void);
void H_DcMotor_Stop(void);

/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/
#endif /* DCMOTOR_H_ */