/*
 * TempSensor.h
 *
 * Created: 12/3/2023 2:39:08 PM
 *  Author: Mohamed
 */ 

#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_
/***********************************_INCLUDES_***********************************/
#include "TempSensorCfg.h"
#include "Adc.h"
/***********************************_PROTOTYPES_*********************************/
void H_TempSensor_Inint(void);
u16 H_TempSensor_Read(void);
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/
#endif /* TEMPSENSOR_H_ */