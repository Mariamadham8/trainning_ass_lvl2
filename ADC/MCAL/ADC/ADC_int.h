/*
 * ADC_int.h
 *
 *  Created on: Feb 15, 2025
 *      Author: Mariem
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

ES_t ADC_enuInit(void);

ES_t ADC_enuStartConversion(void);

ES_t ADC_enuPollingSystem(void);

ES_t ADC_enuReadHighValue(u8 *Copy_pu8Value);

ES_t ADC_enuReadValue(u16 *Copy_pu8Value);

ES_t ADC_enuCallBack(void(* Cpoy_pfunAPPFUN)(void*),void * Copy_pvidADDParameter);

ES_t ADC_enuSelectChannel(u8 Copy_u8ChannelID );

ES_t ADC_enuEnableTriggerMode(u8 Copy_u8TriggeringSource);

ES_t ADC_enuDisbleTriggerMode(void);

ES_t ADC_enuEnableADC(void);

ES_t ADC_enuDisableADC(void);

ES_t ADC_enuEnableInntruptMode(void);

ES_t ADC_enuDisableInntruptMode(void);


//trigrring modes
#define     Free_Running   67
#define	    EXTI           98


#endif /* MCAL_ADC_ADC_INT_H_ */
