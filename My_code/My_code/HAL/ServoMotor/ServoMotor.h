/*
 * ServoMotor.h
 *
 * Created: 12/6/2023 2:47:00 AM
 *  Author: Mohamed
 */ 


#ifndef SERVOMOTOR_H_
#define SERVOMOTOR_H_
/***********************************_INCLUDES_***********************************/
#include "ServoMotorCfg.h"
#include "Timer1.h"
#include "STD_types.h"

/*************************************_MACROS_***********************************/

/***********************************_PROTOTYPES_*********************************/

void H_Servo_Init(void);
void H_Servo_SetDutyCycle(u8);
void H_Servo_Start(void);
void H_Servo_Stop(void);
void H_Servo_SetFreq(u32);
void H_Servo_SetAngel(u8);




/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/
#endif /* SERVOMOTOR_H_ */