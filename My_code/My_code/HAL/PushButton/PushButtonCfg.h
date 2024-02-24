/*
 * PushButtonCfg.h
 *
 * Created: 11/28/2023 2:02:20 AM
 *  Author: Mohamed
 */ 


#ifndef PUSHBUTTONCFG_H_
#define PUSHBUTTONCFG_H_


/****************************_SELECT_PUSH_BUTTON_MODE_************************/
//  option 1 ->[ ACTIVE_HIGH ]
//  option 2 ->[ ACTIVE_LOW  ]

#define PUSH_BUTTON_MODE        ACTIVE_HIGH
/****************************_PUSH_BUTTON_DEBOUNCING_TIME_********************/
#define PUSH_BUTTON_DEBOUNCING_TIME  80
/*****************************_SELECT_BTN_PIN_********************************/
#define PUSHBUTTON0_PIN              PB0
#define PUSHBUTTON1_PIN	             PD6
#define PUSHBUTTON2_PIN	             PD2	

#endif /* PUSHBUTTONCFG_H_ */