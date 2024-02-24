/*
 * Reg.h
 *
 * Created: 11/20/2023 1:18:22 AM
 *  Author: Mohamed
 */ 

#ifndef REG_H_
#define REG_H_
/******************************_INCLUDES_***********************************/
#include "STD_types.h"
/******************************_DIO_REGESTERS_******************************/
/**************_SECTION_A_****************/
#define  PORTA       (*((volatile u8 *) 0x3B))
#define  DDRA        (*((volatile u8 *) 0x3A))
#define  PINA        (*((volatile u8 *) 0x39))
/**************_SECTION_B_****************/
#define  PORTB       (*((volatile u8 *) 0x38))
#define  DDRB        (*((volatile u8 *) 0x37))
#define  PINB        (*((volatile u8 *) 0x36))
/**************_SECTION_C_****************/
#define  PORTC       (*((volatile u8 *) 0x35))
#define  DDRC        (*((volatile u8 *) 0x34))
#define  PINC        (*((volatile u8 *) 0x33))
/**************_SECTION_D_****************/
#define  PORTD       (*((volatile u8 *) 0x32))
#define  DDRD        (*((volatile u8 *) 0x31))
#define  PIND        (*((volatile u8 *) 0x30))
/*******************************_SREG_REGESTERS_******************************/
#define  SREG        (*((volatile u8 *) 0x5F))
/******************************_EXTINT_REGESTERS_*****************************/
#define  MCUCR       (*((volatile u8 *) 0x55))
#define  GICR        (*((volatile u8 *) 0x5B))
/******************************_ADC_REGESTERS_*****************************/
#define ADMUX		 (*((volatile u8 *) 0x27))
#define ADCSRA		 (*((volatile u8 *) 0x26))
#define ADCH		 (*((volatile u8 *) 0x25))
#define ADCL		 (*((volatile u8 *) 0x24))
#define ADC_VALUE	 (*((volatile u16*) 0x24))
/******************************_TIMER0_REGESTERS_*****************************/
#define TCNT0		 (*((volatile u8 *) 0x52)) 
#define TCCR0		 (*((volatile u8 *) 0x53))
#define TIMSK		 (*((volatile u8 *) 0x59))
#define OCR0		 (*((volatile u8 *) 0x5C))
/******************************_TIMER1_REGESTERS_*****************************/
#define TCNT1		 (*((volatile u16 *) 0x4C)) 
#define TCCR1A		 (*((volatile u8 *) 0x4F))
#define TCCR1B		 (*((volatile u8 *) 0x4E))
#define OCR1A		 (*((volatile u16 *) 0x4A))
#define OCR1B		 (*((volatile u16 *) 0x48))
#define ICR1		 (*((volatile u16 *) 0x46))
/******************************_WDT_REGESTERS_*****************************/
#define WDTCR		 (*((volatile u8 *) 0x41))
/******************************_UART_REGESTERS_*****************************/
#define UDR		     (*((volatile u8 *) 0x2C))
#define UCSRA	     (*((volatile u8 *) 0x2B))
#define UCSRB	     (*((volatile u8 *) 0x2A))
#define UBRRL	     (*((volatile u8 *) 0x29))
#define UBRRH	     (*((volatile u8 *) 0x40))
#define UCSRC	     (*((volatile u8 *) 0x40))
/******************************_SPI_REGESTERS_*****************************/
#define SPCR         (*((volatile u8 *) 0x2D))
#define SPSR	     (*((volatile u8 *) 0x2E))
#define SPDR	     (*((volatile u8 *) 0x2F))
/******************************_TWI_REGESTERS_*****************************/
#define TWBR         (*((volatile u8 *) 0x20))
#define TWAR	     (*((volatile u8 *) 0x22))
#define TWCR	     (*((volatile u8 *) 0x56))
#define TWDR	     (*((volatile u8 *) 0x23))
#define TWSR	     (*((volatile u8 *) 0x21))
/*****************************************************************************/
/***********************************END***************************************/
/*****************************************************************************/
#endif /* REG_H_ */