/*
 * LED_prog.c
 *
 *  Created on: Oct 14, 2024
 *      Author: Mariem
 */

#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include"../../MCAL/DIO/DIO_int.h"

#include "./LED_priv.h"
#include "./LED_config.h"



ES_t LED_enuInit(LED_t * Copy_pstrLedConfig)
{
	ES_t Local_enuErrorState=NOT_OK;
	if(Copy_pstrLedConfig !=NULL)
	{
		u8 i=0;
		for ( ;i < 8; i++)
		{
			Local_enuErrorState =enuSetPinDirection(Copy_pstrLedConfig[i].LED_u8PortID,Copy_pstrLedConfig[i].LED_u8PinID,OUTPUT);
			if(Copy_pstrLedConfig[i].LED_u8Connection ==sink)
			{
				if(Copy_pstrLedConfig[i].LED_u8InitState==ON)
				{
					Local_enuErrorState= enuSetPinValue(Copy_pstrLedConfig[i].LED_u8PortID,Copy_pstrLedConfig[i].LED_u8PinID,LOW);

				}
				else if(Copy_pstrLedConfig[i].LED_u8InitState==OFF)
				{
					Local_enuErrorState=enuSetPinValue(Copy_pstrLedConfig[i].LED_u8PortID,Copy_pstrLedConfig[i].LED_u8PinID,HIGH);
				}
				else
				{
					return ES_OUT_OF_RANGE;
				}

			}
			else if(Copy_pstrLedConfig[i].LED_u8Connection ==source)
			{
				if(Copy_pstrLedConfig[i].LED_u8InitState==ON)
								{
					              Local_enuErrorState=	enuSetPinValue(Copy_pstrLedConfig[i].LED_u8PortID,Copy_pstrLedConfig[i].LED_u8PinID,HIGH);
								}
								else if(Copy_pstrLedConfig[i].LED_u8InitState==OFF)
								{
									Local_enuErrorState= enuSetPinValue(Copy_pstrLedConfig[i].LED_u8PortID,Copy_pstrLedConfig[i].LED_u8PinID,LOW);
								}
								else
								{
									return ES_OUT_OF_RANGE;
								}


			}
			else
			{
				return ES_OUT_OF_RANGE;
			}
		}
	}
	else
	{
		Local_enuErrorState =NULL_POINTER;
	}


	return Local_enuErrorState;
}

ES_t LED_enuTurnON(LED_t * Copy_pstrLedID)
{
	ES_t Local_enuErrorState = NOT_OK;

			if (Copy_pstrLedID != NULL)
			{

				if(Copy_pstrLedID->LED_u8Connection ==sink)
							{
									Local_enuErrorState= enuSetPinValue(Copy_pstrLedID->LED_u8PortID,Copy_pstrLedID->LED_u8PinID,LOW);

							}
							else if(Copy_pstrLedID->LED_u8Connection ==source)
							{
									              Local_enuErrorState=	enuSetPinValue(Copy_pstrLedID->LED_u8PortID,Copy_pstrLedID->LED_u8PinID,HIGH);
							}
							else
							{
								Local_enuErrorState=ES_OUT_OF_RANGE;
							}

			}
			else
				{
					Local_enuErrorState =NULL_POINTER;
				}

		return Local_enuErrorState;
}

ES_t LED_enuTurnOFF(LED_t * Copy_pstrLedID)
{ES_t Local_enuErrorState = NOT_OK;

    if (Copy_pstrLedID != NULL)
   {
    	if(Copy_pstrLedID->LED_u8Connection ==sink)
    								{
    										Local_enuErrorState= enuSetPinValue(Copy_pstrLedID->LED_u8PortID,Copy_pstrLedID->LED_u8PinID,HIGH);
    								}
    								else if(Copy_pstrLedID->LED_u8Connection ==source)
    								{

    										              Local_enuErrorState=	enuSetPinValue(Copy_pstrLedID->LED_u8PortID,Copy_pstrLedID->LED_u8PinID,LOW);
    								}
    								else
    								{
    									Local_enuErrorState=ES_OUT_OF_RANGE;
    								}


   }
   else
   {
    		Local_enuErrorState =NULL_POINTER;
   }

    return Local_enuErrorState;

}


