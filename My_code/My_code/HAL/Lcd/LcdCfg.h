/*
 * LcdCfg.h
 *
 * Created: 11/28/2023 5:26:22 PM
 *  Author: Mohamed
 */ 


#ifndef LCDCFG_H_
#define LCDCFG_H_
/*******************************_SELECT_LCD_MODE_******************************/
//Option1 -> [ _4_BIT_MODE ] 
//Option2 -> [ _8_BIT_MODE ] 
#define	  LCD_MODE				_4_BIT_MODE
/*******************************_SELECT_LCD_PIN_******************************/
#define   LCD_DATA_PORT         PORTA

#define   LCD_DATA0_PIN			PA0	
#define   LCD_DATA1_PIN			PA1
#define   LCD_DATA2_PIN			PA2
#define   LCD_DATA3_PIN			PA3
#define   LCD_DATA4_PIN			PA4
#define   LCD_DATA5_PIN			PA5
#define   LCD_DATA6_PIN			PA6
#define   LCD_DATA7_PIN			PA7

#define   LCD_RS_PIN			PB1
#define   LCD_EN_PIN		 	PB2
#define   LCD_RW_PIN			PB3

/*******************************_SELECT_DELAY_TIME_******************************/
#define   LCD_DELAY_TIME		1
#define   LCD_SMALL_DELAY		5
#define   LCD_LONG_DELAY		1000

#endif /* LCDCFG_H_ */