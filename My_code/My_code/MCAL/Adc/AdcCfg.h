/*
 * AdcCfg.h
 *
 * Created: 12/3/2023 2:38:58 AM
 *  Author: Mohamed
 */ 


#ifndef ADCCFG_H_
#define ADCCFG_H_


/*******************************_SELECT_ADC_OPERATION_MODE_******************************/
// option 1 -> [ADC_INT]
// option 2 -> [ADC_POL]
#define	ADC_OPERATION_MODE  ADC_INT

/*******************************_SELECT_VREF_PIN_*********************************/
//option1 -> [  AREF_PIN   ]
//option2 -> [    AVCC 	   ]
//option3 -> [    _2V56	   ]
#define      VREF		  AVCC




#endif /* ADCCFG_H_ */