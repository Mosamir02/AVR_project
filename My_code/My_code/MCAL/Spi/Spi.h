/*
 * Spi.h
 *
 * Created: 12/9/2023 6:10:39 PM
 *  Author: Mohamed
 */ 


#ifndef SPI_H_
#define SPI_H_
/***********************************_INCLUDES_***********************************/
#include "SpiCfg.h"
#include "STD_types.h"
#include "BIT_math.h"
#include "Reg.h"
/*************************************_MACROS_***********************************/
#define SPI_MASTER 1
#define SPI_SLAVE  2
		

/***********************************_PROTOTYPES_*********************************/
void M_Spi_Init(void);
u8 M_Spi_Transive(u8);

/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/
#endif /* SPI_H_ */