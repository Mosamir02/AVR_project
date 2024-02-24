/*
 * UartCfg.h
 *
 * Created: 12/7/2023 2:39:37 AM
 *  Author: Mohamed
 */ 


#ifndef UARTCFG_H_
#define UARTCFG_H_

/*******************************_F_OSC_******************************/
#define  F_OSC		 16
/*******************************_SELECT_PARITY_MODE_******************************/
//option1 -> [	PARITY_DISABLE ]
//option2 -> [	PARITY_EVEN	   ]
//option3 -> [  PARITY_ODD	   ]
#define	PARITY_MODE	 PARITY_DISABLE
/*******************************_SELECT_BUADRATE_******************************/
//option1 -> [ 2400 bps->  (416) ]
//option2 -> [ 4800 bps->  (207) ]
//option3 -> [ 9600 bps	-> (103) ] 
#define BUADRATE_MODE 9600



#endif /* UARTCFG_H_ */