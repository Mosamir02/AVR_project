/*
 * ExtInt.c
 *
 * Created: 12/2/2023 10:46:04 PM
 *  Author: Mohamed
 */ 

/***********************************_INCLUDES_***********************************/
#include "ExtInt.h"
/***********************************_FUNCTIONS_*********************************/
void (*CallBack_ExtInt)(void);

void M_ExtInt_Int0_Init(void)
{
	#if	   SENSE_CONTROL   ==	 RISING_EDGE	
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	#elif  SENSE_CONTROL ==   FAILLING_EDGE
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	#elif  SENSE_CONTROL ==   LOGICAL_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	#elif  SENSE_CONTROL ==   LOW_LEVEL
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
	#endif
	SET_BIT(GICR,6); // To Enable Local  Interrupt 
	SET_BIT(SREG,7); // To Enable Global Interrupt

}

//Function  Pointer to CallBack
void M_ExtInt_SetCallBack(void (*ptr)(void))
{
	CallBack_ExtInt = ptr; 
}

ISR(INT0_vect)
{
	CallBack_ExtInt();
}
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/