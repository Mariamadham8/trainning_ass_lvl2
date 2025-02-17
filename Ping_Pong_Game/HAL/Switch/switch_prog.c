/*
 * switch_prog.c
 *
 *  Created on: Oct 14, 2024
 *      Author: Mariem
 */
#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include"../../MCAL/DIO/DIO_int.h"

#include "./switch_priv.h"
#include "./switch_config.h"



ES_t Switch_enuInit(SW_t * Copy_AstrSwitchs)
{
	ES_t Local_enuErrorState = NOT_OK;

	if (Copy_AstrSwitchs != NULL)
	{
		u8 Local_u8Iterator =0;
		for (Local_u8Iterator=0; Local_u8Iterator < SW_NUM ; Local_u8Iterator++)
		{
			Local_enuErrorState = enuSetPinDirection(Copy_AstrSwitchs[Local_u8Iterator].SW_PortID ,Copy_AstrSwitchs[Local_u8Iterator].SW_PinID, INPUT);
			Local_enuErrorState = enuSetPinValue(Copy_AstrSwitchs[Local_u8Iterator].SW_PortID ,Copy_AstrSwitchs[Local_u8Iterator].SW_PinID,Copy_AstrSwitchs[Local_u8Iterator].SW_Status);
		}
	}
	else
	{
		Local_enuErrorState = NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t Switch_enuGetState(SW_t * Copy_AstrSwitchs, u8 * Copy_pu8SwState)
{
	ES_t Local_enuErrorState = NOT_OK;

	if (Copy_AstrSwitchs != NULL && Copy_pu8SwState != NULL)
	{
		Local_enuErrorState = enuGetPinValue(Copy_AstrSwitchs->SW_PortID, Copy_AstrSwitchs->SW_PinID, Copy_pu8SwState);
	}
	else
	{
		Local_enuErrorState = NULL_POINTER;
	}

	return Local_enuErrorState;
}


