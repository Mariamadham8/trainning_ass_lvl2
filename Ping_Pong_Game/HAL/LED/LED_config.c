/*
 * LED_config.c
 *
 *  Created on: Oct 14, 2024
 *      Author: Mariem
 */
#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include"../../MCAL/DIO/DIO_int.h"

#include "./LED_config.h"
#include "./LED_priv.h"



LED_t Led_AstrState [8] =
{
		{DIO_PORTB, DIO_PIN0, source, OFF},
		{DIO_PORTB, DIO_PIN1, source, OFF},
		{DIO_PORTB, DIO_PIN2, source, OFF},
		{DIO_PORTB, DIO_PIN3, source, OFF},
		{DIO_PORTB, DIO_PIN4, source, OFF},
		{DIO_PORTB, DIO_PIN5, source, OFF},
		{DIO_PORTB, DIO_PIN6, source, OFF},
		{DIO_PORTB, DIO_PIN7, source, OFF},

};
