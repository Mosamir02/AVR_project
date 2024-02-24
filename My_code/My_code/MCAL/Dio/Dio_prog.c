/*
 * Dio_prog.c
 *
 * Created: 11/20/2023 4:32:45 PM
 *  Author: Mohamed
 */ 

/***********************************_INCLUDES_***********************************/
#include "Dio.h"
/***********************************_FUNCTIONS_*********************************/
void M_Dio_PinMode(u8 Local_u8_Num, u8 Local_u8_Mode)
{
	u8 Local_u8_Pin=Local_u8_Num %10;//models
	u8 Local_u8_Port=Local_u8_Num /10;
	
	switch(Local_u8_Mode)
	{
		case OUTPUT:
				switch(Local_u8_Port)
				{
					case 1: SET_BIT(DDRA,Local_u8_Pin);break;
					case 2: SET_BIT(DDRB,Local_u8_Pin);break;
					case 3: SET_BIT(DDRC,Local_u8_Pin);break;
					case 4: SET_BIT(DDRD,Local_u8_Pin);break;
					default: 						   break;
					
				}break;
				
				
		case INPUT:
		switch(Local_u8_Port)
		{
			case 1: CLR_BIT(DDRA,Local_u8_Pin);break;
			case 2: CLR_BIT(DDRB,Local_u8_Pin);break;
			case 3: CLR_BIT(DDRC,Local_u8_Pin);break;
			case 4: CLR_BIT(DDRD,Local_u8_Pin);break;
			default: 						   break;
			
		}
		
		break;
		default:
		break;
	}	
}


void M_Dio_PinWrite(u8 Local_u8_Num,u8 Local_u8_Mode)
{
	
	u8 Local_u8_Pin=Local_u8_Num %10;//models
	u8 Local_u8_Port=Local_u8_Num /10;
	
	switch(Local_u8_Mode)
	{
		case HIGH:
		switch(Local_u8_Port)
		{
			case 1: SET_BIT(PORTA,Local_u8_Pin);break;
			case 2: SET_BIT(PORTB,Local_u8_Pin);break;
			case 3: SET_BIT(PORTC,Local_u8_Pin);break;
			case 4: SET_BIT(PORTD,Local_u8_Pin);break;
			default: 						   break;
			
		}
		
		break;
		case LOW:
		switch(Local_u8_Port)
		{
			case 1: CLR_BIT(PORTA,Local_u8_Pin);break;
			case 2: CLR_BIT(PORTB,Local_u8_Pin);break;
			case 3: CLR_BIT(PORTC,Local_u8_Pin);break;
			case 4: CLR_BIT(PORTD,Local_u8_Pin);break;
			default: 						   break;
			
		}
		
		break;
		default:
		break;
	}	
}

u8   M_Dio_PinRead(u8 Local_u8_Num)
{
	u8 Local_u8_Pin=Local_u8_Num %10;     //local pin to get number of pin
	u8 Local_u8_Port=Local_u8_Num /10;    //local pin to get number of port
	u8 Local_u8_PinReading = 0;			  //local pin Reading to  info to see pin is zero  or one 
	switch(Local_u8_Port)
	{
		case 1 :Local_u8_PinReading = GET_BIT(PINA,Local_u8_Pin);    break;
		case 2 :Local_u8_PinReading = GET_BIT(PINB,Local_u8_Pin);	 break;
		case 3 :Local_u8_PinReading = GET_BIT(PINC,Local_u8_Pin);	 break;
		case 4 :Local_u8_PinReading = GET_BIT(PIND,Local_u8_Pin);	 break;
		default:													 break;
	}
	return Local_u8_PinReading;
}


void M_Dio_PortMode(u8 Local_u8_Port ,u8 Local_u8_Mode)
{
	switch(Local_u8_Mode)
	{
		
	case OUTPUT:
	switch(Local_u8_Port)
	{
		case A:DDRA =0xFF;  break;
		case B:DDRB =0xFF;  break;
		case C:DDRC =0xFF;  break;
		case D:DDRD =0xFF;  break; 
		default:			break;
	}						break;
	
	case INPUT:
	switch(Local_u8_Port)
	{
		case A:DDRA =0x00;  break;
		case B:DDRB =0x00;  break;
		case C:DDRC =0x00;  break;
		case D:DDRD =0x00;  break;
		default:			break;
	}						break;
	default:				break;
	
	
	
	}
}

 



void M_Dio_PortWrite(u8 Local_u8_Port ,u8 Local_u8_value)
{

		switch(Local_u8_Port)
		{
			case A:PORTA =Local_u8_value;  break;
			case B:PORTB =Local_u8_value;  break;
			case C:PORTC =Local_u8_value;  break;
			case D:PORTD =Local_u8_value;  break;
			default:					   break;
		}							
	}
	
	
void M_Dio_Pin_Tog(u8 Local_u8_Num)
{
	
	u8 Local_u8_Pin=Local_u8_Num  %10;     
	u8 Local_u8_Port=Local_u8_Num /10;
	switch(Local_u8_Port)
	{
		case 1 :TOG_BIT(PORTA,Local_u8_Pin); break;
		case 2 :TOG_BIT(PORTB,Local_u8_Pin); break;
		case 3 :TOG_BIT(PORTC,Local_u8_Pin); break;
		case 4 :TOG_BIT(PORTD,Local_u8_Pin); break;
		default:							 break;
	}
}

	
void M_Dio_PinPullUpRes(u8 Local_u8_Num , u8 Local_u8_Mode)
{
	u8 Local_u8_Pin=Local_u8_Num %10;
	u8 Local_u8_Port=Local_u8_Num /10;
	
	switch(Local_u8_Mode)	
	{
		
		case ENABLE:  //to make enable => setbits 
 		switch(Local_u8_Port)
		{
			case 1: SET_BIT(PORTA,Local_u8_Pin); break;
			case 2: SET_BIT(PORTB,Local_u8_Pin); break;
			case 3: SET_BIT(PORTC,Local_u8_Pin); break;
			case 4: SET_BIT(PORTD,Local_u8_Pin); break;
			default:							 break;
		}
		break;
		case DISABLE:
		switch(Local_u8_Port)
		{
			case 1: CLR_BIT(PORTA,Local_u8_Pin); break;
			case 2: CLR_BIT(PORTB,Local_u8_Pin); break;
			case 3: CLR_BIT(PORTC,Local_u8_Pin); break;
			case 4: CLR_BIT(PORTD,Local_u8_Pin); break;
			default:							 break;
		}   
		break;
		default:			break;
	}
}
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/