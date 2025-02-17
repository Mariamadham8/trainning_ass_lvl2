
            /*
 * switch_config.c
 *
 *  Created on: Oct 14, 2024
 *      Author: Mariem
 */


#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include"../../MCAL/DIO/DIO_int.h"

#include "./Switch_priv.h"
#include "./Switch_config.h"



SW_t Switch_AstrSwitchState [SW_NUM] =
{
		{DIO_PORTD , DIO_PIN2 , PULL_UP},
		{DIO_PORTD , DIO_PIN3 , PULL_UP},

};

