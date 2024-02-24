/*
 * KeyPadCfg.h
 *
 * Created: 11/30/2023 6:12:28 PM
 *  Author: Mohamed
 */ 


#ifndef KEYPADCFG_H_
#define KEYPADCFG_H_
/*******************************_SELECT_KEYPAD_MODE_******************************/
//option1 -> [ KEYPAD_KIT ]
//option2 -> [ KEYPAD_PROTEUS ]
#define KEYPAD_MODE		 KEYPAD_PROTEUS
/****************************_KEYPAD_DEBOUNCING_TIME_********************/
#define KEYPAD_DEBOUNCING_TIME 80
/*******************************_SELECT_KEYPAD_PIN_******************************/
#define  KEYPAD_R0_PIN        PC0                           //PC3
#define  KEYPAD_R1_PIN	      PC1							//PC4
#define  KEYPAD_R2_PIN	      PC2							//PC5
#define  KEYPAD_R3_PIN	      PC3							//PC6

#define  KEYPAD_C0_PIN	      PC4							//PB4
#define  KEYPAD_C1_PIN	      PC5							//PB5
#define  KEYPAD_C2_PIN	      PC6							//PB6
#define  KEYPAD_C3_PIN	      PC7							//PB7
/********************************************************************************/
/*************************************END****************************************/
/********************************************************************************/
#endif /* KEYPADCFG_H_ */