/*
 * Adc.c
 *
 * Created: 12/3/2023 2:39:10 AM
 *  Author: Mohamed
 */ 
 
/***********************************_INCLUDES_***********************************/
#include "Adc.h"
/***********************************_FUNCTIONS_**********************************/
void (*CallBack_Adc)(void);
u16 x=0;
//SET LINE IN MAIN.C    extern u16 x;
void  M_Adc_Init()
{
	#if    VREF   ==   AVCC
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	#elif  VREF   ==   AREF_PIN
	CLR_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	#elif  VREF   ==   _2V56
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
	#endif
	
	CLR_BIT(ADMUX,5);  //To Select right adjust
	CLR_BIT(ADMUX,4);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,2);
	CLR_BIT(ADMUX,1);
	SET_BIT(ADMUX,0);
	// To Select 128 as Devision factor -> ADC Circuit -> 125 khz
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,5);// To Enable Auto trigger
	#if   ADC_OPERATION_MODE == ADC_INT
	SET_BIT(ADCSRA,3);//To Enable local Int
	SET_BIT(SREG,7);//To Enable	  global Int
	SET_BIT(ADCSRA,6);// To Start Conversion
	#endif
	SET_BIT(ADCSRA,7);// To Enable ADC Circuit
	
	
}
#if ADC_OPERATION_MODE == ADC_POL
u16 M_Adc_Read(void)
{
	SET_BIT(ADCSRA,6);// To Start Conversion 
	while ((GET_BIT(ADCSRA,4) == 0));
	
	return ADC_VALUE;
}
#elif ADC_OPERATION_MODE == ADC_INT

/*
void M_Adc_SetCallBack(void (*ptr)(void))
{
	CallBack_Adc = ptr;
}
*/

ISR(ADC_vect)
{
	
	x=ADC_VALUE;
	//CallBack_Adc();
	
}
#endif

/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/