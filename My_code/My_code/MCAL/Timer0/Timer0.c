/*
 * Timer0.c
 *
 * Created: 12/3/2023 6:54:19 PM
 *  Author: Mohamed
 */ 

/***********************************_INCLUDES_***********************************/
#include "Timer0.h"
/***********************************_FUNCTIONS_*********************************/
u32 Timer0_u32_NumofOverFlow	= 0; 
u8  Timer0_u8_RemTicks			= 0;
u32 Timer0_Num_of_CompareMatch  = 0;
void (*CallBack_Timer0)(void)= NULL_;


void M_Timer0_Init(void)
{
	#if  TIMER0_MODE == NORMAL_MODE
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	SET_BIT(TIMSK,0); //to enable timer0 overflow int
	#elif TIMER0_MODE == CTC_MODE
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	SET_BIT(TIMSK,1); //to enable timer0 compare match int
	#elif TIMER0_MODE == FAST_PWM
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	SET_BIT(TIMSK,1); //to enable timer0 compare match int
	#endif
	SET_BIT(SREG,7);  //to enable global int		
}


void M_Timer0_Start(void)
{
	#if   TIMER0_PRESCALER  == 1024
	//to select PRESCALER -> 1024
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	#elif TIMER0_PRESCALER  == 256
	//to select PRESCALER -> 1024
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	#endif
}

void M_Timer0_SetTime(u32 Local_u8_Desired_Time)
{
	#if TIMER0_MODE == NORMAL_MODE
	u32 Local_u32_Tick_Time       =  TIMER0_PRESCALER/F_OSC;
	u32 Local_u32_Total_Ticks     =  (Local_u8_Desired_Time *1000) / Local_u32_Tick_Time;
	Timer0_u32_NumofOverFlow  =  Local_u32_Total_Ticks / 256;
	Timer0_u8_RemTicks 		  =  Local_u32_Total_Ticks % 256;
	if (Timer0_u8_RemTicks != 0)
	{
		TCNT0					  =  256 - Timer0_u8_RemTicks;
		Timer0_u32_NumofOverFlow++;
	}
	#elif TIMER0_MODE			 ==  CTC_MODE
	u32 Local_u32_Tick_Time       =  TIMER0_PRESCALER/F_OSC;
	u32 Local_u32_Total_Ticks     =  (Local_u8_Desired_Time *1000) / Local_u32_Tick_Time;
	u8 Local_u8_devisionFactor    =  255;
	while(Local_u32_Total_Ticks % Local_u8_devisionFactor)
	{
		Local_u8_devisionFactor--;
	}
		Timer0_Num_of_CompareMatch    =  Local_u32_Total_Ticks / Local_u8_devisionFactor;
		OCR0						  =  Local_u8_devisionFactor - 1;
	#endif
}

void M_Timer0_Stop(void)
{
	//to select PRESCALER -> clear bit to stop 
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}

void M_Timer0_SetCallBack(void (*ptr)(void))
{
	CallBack_Timer0 = ptr;
}


void M_Timer0_Pwm0_Init(void)
{
	SET_BIT(DDRB,3);	     // to make PD3 -> OUTPUT
	//TO Select Fast_PWM_Mode
	#if  PWM0_MODE		 ==   FAST_PWM0
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);	
		#if   FAST_PWM_MODE  ==   NON_INVERTED
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
		#elif FAST_PWM_MODE  ==   INVERTED
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
		#endif
	#elif  PWM0_MODE	 ==	  PHASE_CORRECT_PWM0
	CLR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
		#if   PHASE_CORRECT_PWM0_MODE  ==   NON_INVERTED
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
		#elif PHASE_CORRECT_PWM0_MODE  ==   INVERTED
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
		#endif
	#endif
	
	
}

void M_Timer0_Pwm0_SetDutyCycle(u8 Local_u8_DutyCycle)
{
	#if   PWM0_MODE		 ==   FAST_PWM0
			#if   FAST_PWM_MODE    ==   NON_INVERTED
			OCR0=(((Local_u8_DutyCycle * 256) / 100)-1);
			#elif   FAST_PWM_MODE  ==   INVERTED
			
			#endif
	#elif PWM0_MODE		==    PHASE_CORRECT_PWM0
			#if   PHASE_CORRECT_PWM0_MODE    ==   NON_INVERTED
			OCR0=((Local_u8_DutyCycle * 255) / 100);
			#elif   FAST_PWM_MODE            ==   INVERTED
			//OCR0 = 100;
			#endif
	#endif
}

void M_Timer0_Pwm0_Start(void)
{
	
	M_Timer0_Start();
}

void M_Timer0_Pwm0_Stop(void)
{
	
	M_Timer0_Stop();
}


#if TIMER0_MODE == NORMAL_MODE
ISR(TIMER0_OVF_vect)
{
	static  u32 Local_u32_Counter = 0;
	Local_u32_Counter++;
	if( Local_u32_Counter==Timer0_u32_NumofOverFlow)
	{		
		CallBack_Timer0();
		Local_u32_Counter = 0;
		TCNT0			  = 256 - Timer0_u8_RemTicks;
	}
}
#elif TIMER0_MODE == CTC_MODE
ISR(TIMER0_COMP_vect)
{
	static  u32 Local_u32_Counter = 0;
	Local_u32_Counter++;
	if( Local_u32_Counter ==  Timer0_Num_of_CompareMatch)
	{
		CallBack_Timer0();
		Local_u32_Counter = 0;
	}
}
#endif
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/