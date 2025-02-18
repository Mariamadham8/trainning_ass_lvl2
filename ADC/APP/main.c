/*
 * main.c
 *
 *  Created on: Feb 18, 2025
 *      Author: Mariem
 */


#include"../LIB/stdTypes.h"
#include"../LIB/errorStates.h"
#include <stdlib.h>

#include"../MCAL/EXTI/EXTI_int.h"
#include"../MCAL/EXTI/EXTI_config.h"

#include"../MCAL/DIO/DIO_int.h"
#include"../MCAL/DIO/DIO_config.h"

#include"../MCAL/ADC/ADC_int.h"
#include"../MCAL/ADC/ADC_config.h"

#include"../MCAL/GIE/GIE_int.h"


#include"../HAL/LCD/LCD_int.h"
#include"../HAL/LCD/LCD_config.h"

extern EXTI_t  EXTI_AstrEXTIConfig[3];

u8  flag=0;
void read(void *Param)
{
	ADC_enuReadValue((u16*)Param);
	flag=1;
}
int main()
{
	    char adcString[100];  // Buffer to hold ADC value as a string (4 digits + null terminator)
	    u16 adcread=0;
	    enuSetPinDirection(DIO_PORTA,DIO_PIN2,INPUT);
		enuSetPortDirection(DIO_PORTC,0xff);
		enuSetPinDirection(DIO_PORTD,DIO_PIN2,INPUT);

        //conversion will only happen when falling edge in the INT0 pin
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
		LCD_enuInit();


		while(1){

			if(flag==1)
			{
					itoa(adcread, adcString, 10);  // Convert ADC value to a string in base 10
					LCD_enuSendCommand(0x01);      
					LCD_enuSendString(adcString); 
					flag = 0;
			}

		}



}
