/*
 * EXTI_config.c
 *
 *  Created on: Jan 5, 2025
 *      Author: Mariem
 */


#include"../../LIB/errorStates.h"
#include"../../LIB/stdTypes.h"

#include"../EXTI/EXTI_priv.h"
#include"../EXTI/EXTI_config.h"


EXTI_t  EXTI_AstrEXTIConfig[3]=
{
		{Active,Falling_edge},
		{Deactive,Low_level},
		{Deactive,Low_level},
};
