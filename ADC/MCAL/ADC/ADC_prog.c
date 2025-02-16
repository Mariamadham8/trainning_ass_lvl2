/*
 * ADC_prog.c
 *
 *  Created on: Feb 15, 2025
 *      Author: Mariem
 */
#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include"ADC_config.h"
#include"ADC_priv.h"

#include"../Interrupt.h"


static void (*ADC_pfunISRFUN)(void*)=NULL;
static void *ADC_pvidISRPARAMETER=NULL;
ES_t ADC_enuInit(void)
{
	ES_t LocalErrorStatus=NOT_OK;
#if ADC_PRES ==PRES_2
	ADCSRA |=(1<<0);
#elif ADC_PRES ==PRES_4
	ADCSRA |=(1<<1);
#elif ADC_PRES ==PRES_8
	ADCSRA |=(1<<0);
	ADCSRA |=(1<<1);
#elif ADC_PRES ==PRES_16
	ADCSRA |=(1<<2);
#elif ADC_PRES ==PRES_32
	ADCSRA |=(1<<0);
	ADCSRA |=(1<<2);
#elif ADC_PRES ==PRES_64
	ADCSRA |=(1<<1);
	ADCSRA |=(1<<2);
#elif ADC_PRES ==PRES_128
	ADCSRA |=(1<<0);
	ADCSRA |=(1<<1);
	ADCSRA |=(1<<2);
#else
#error "ADC PRES IS WRONG"
#endif

#if ADC_REF_VOLT ==AVCC
	ADMUX &= (1 << 6);
#elif ADC_REF_VOLT==AREF
#elif ADC_REF_VOLT==Internal_VREF
	ADMUX |= (1 << 6) | (1 << 7);

#else
#error "ADC REF IS WRONG"
#endif

#if ADC_ADJ==Right_ADJ
	ADMUX &=~(1<<5);
#elif ADC_ADJ==Left_ADJ
	ADMUX |=(1<<5);
#else
#error "ADC ADJ IS WRONG"
#endif

	return LocalErrorStatus;
}

ES_t ADC_enuStartConversion(void)
{
	ES_t LocalErrorStatus=NOT_OK;
	ADCSRA |=(1<<6);
	return LocalErrorStatus;
}

ES_t ADC_enuPollingSystem(void)  //wait till inttrupt flag is activated
{
	ES_t LocalErrorStatus=NOT_OK;
	while(((ADCSRA>>4)&1)==0);    //the flag is set after the conversion is complete
	ADCSRA |=(1<<4);
	return LocalErrorStatus;
}


ES_t ADC_enuReadHighValue(u8 *Copy_pu8Value)
{
		ES_t LocalErrorStatus=NOT_OK;
		//i will read eather its right adj or left
		#if ADC_ADJ==Right_ADJ
		*Copy_pu8Value =(ADCL>>2); //read low first
		*Copy_pu8Value|=(ADCH<<6);

		#elif ADC_ADJ==Left_ADJ   //easy to ignore left
		*Copy_pu8Value=ADCH;
		#else
		#error "ADC ADJ IS WRONG"
		#endif
		return LocalErrorStatus;
}

//Read ALL the data
ES_t ADC_enuReadValue(u16 *Copy_pu8Value)
{
	    ES_t LocalErrorStatus=NOT_OK;
		#if ADC_ADJ==Right_ADJ
		*Copy_pu8Value =ADCL;
		*Copy_pu8Value|=(u16)(ADCH<<8);   //WIll not depend on implicit casting cz its compilar dependant

		#elif ADC_ADJ==Left_ADJ   //easy to ignore left
		*Copy_pu8Value=(ADCL>>6)
		*Copy_pu8Value|=(ADCH<<>2);
		#else
		#error "ADC ADJ IS WRONG"
		#endif
		return LocalErrorStatus;
}


ES_t ADC_enuCallBack(void(* Cpoy_pfunAPPFUN)(void*),void * Copy_pvidADDParameter)
{
	ES_t LocalErrorStatus=NOT_OK;
	if(Cpoy_pfunAPPFUN !=NULL)
	{
		ADC_pfunISRFUN = Cpoy_pfunAPPFUN;
		ADC_pvidISRPARAMETER=Copy_pvidADDParameter;
	}

	else
	{
		LocalErrorStatus=NULL_POINTER;
	}
		return LocalErrorStatus;
}


ES_t ADC_enuSelectChannel(u8 Copy_u8ChannelID )
{
	ES_t LocalErrorStatus=NOT_OK;
	  ADMUX &=~0X1F;
	  ADMUX |=Copy_u8ChannelID;

	return LocalErrorStatus;
}


ES_t ADC_enuEnableTriggerMode(u8 Copy_u8TriggeringSource)
{
	ES_t LocalErrorStatus=NOT_OK;
	ADCSRA &=~(1<<5);
	switch(Copy_u8TriggeringSource)
	{
	    case Free_Running:
	    	   SFIOR &=~(1<<5);
	    	   SFIOR &=~(1<<6);
	    	   SFIOR &=~(1<<7);
		       break;
	    case EXTI:
				SFIOR &=~(1<<5);
				SFIOR |=(1<<6);
				SFIOR &=~(1<<7);
	    		break;
	}
	ADCSRA |=(1<<5);
		return LocalErrorStatus;
}


ES_t ADC_enuDisbleTriggerMode(void)
{
		ES_t LocalErrorStatus=NOT_OK;
		ADCSRA &=~(1<<5);
		return LocalErrorStatus;
}


ES_t ADC_enuEnableADC(void)
{
	ES_t LocalErrorStatus=NOT_OK;
	ADCSRA |=(1<<7);
	return LocalErrorStatus;
}


ES_t ADC_enuDisableADC(void)
{
	ES_t LocalErrorStatus=NOT_OK;
	ADCSRA &=~(1<<7);
	return LocalErrorStatus;
}


ES_t ADC_enuEnableInntruptMode(void)
{
	ES_t LocalErrorStatus=NOT_OK;
	ADCSRA |=(1<<3);
	return LocalErrorStatus;
}


ES_t ADC_enuDisableInntruptMode(void)
{
	ES_t LocalErrorStatus=NOT_OK;
	ADCSRA &=~(1<<3);
	return LocalErrorStatus;
}

ISR(VECT_ADC)
{
	    if(ADC_pfunISRFUN !=NULL)
		{
		    ADC_pfunISRFUN (ADC_pvidISRPARAMETER);
		}
}


