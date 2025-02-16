/*
 * main.c
 *
 *  Created on: Feb 13, 2025
 *      Author: Mariem
 */

#include"../LIB/stdTypes.h"
#include"../LIB/errorStates.h"

#include"../MCAL/EXTI/EXTI_int.h"
#include"../MCAL/EXTI/EXTI_config.h"

#include"../MCAL/DIO/DIO_int.h"
#include"../MCAL/DIO/DIO_config.h"

#include"../MCAL/ADC/ADC_int.h"
#include"../MCAL/ADC/ADC_config.h"

#include"../MCAL/GIE/GIE_int.h"

extern EXTI_t  EXTI_AstrEXTIConfig[3];


void read(void *Param)
{
	ADC_enuReadValue((u16*)Param);
}
int main()
{
	    u8 adcread=0;
	    u16 adc16=0;
		enuSetPinDirection(DIO_PORTA,DIO_PIN2,INPUT);
		enuSetPortDirection(DIO_PORTC,0xff);
		enuSetPinDirection(DIO_PORTD,DIO_PIN2,INPUT);


		EXTI_enuinit(EXTI_AstrEXTIConfig);
		EXTI_enuSetSenceMOde(0,Falling_edge);
		EXTI_enuEnableINT(0);

		ADC_enuInit();
		ADC_enuSelectChannel(2);
		ADC_enuEnableTriggerMode(EXTI);
		ADC_enuEnableInntruptMode();
		ADC_enuEnableADC();
		ADC_enuCallBack(&read,&adcread);
		ADC_enuStartConversion();

		GIE_enuEnable();


		while(1){
			//Polling

			//ADC_enuStartConversion();
			//ADC_enuPollingSystem();
			//ADC_enuReadHighValue(&adcread);
			enuSetPortValue(DIO_PORTC,adcread);

		}



}
