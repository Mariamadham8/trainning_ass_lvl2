/*
 * LM35_porg.c
 *
 *  Created on: Feb 18, 2025
 *      Author: Mariem
 */
#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include"../../MCAL/DIO/DIO_int.h"



#include"../LCD/LCD_int.h"

#include"../LM35/LM35_config.h"
#include"../LM35/LM35_priv.h"



ES_t LM35_Init(LM35_t *Copy_Astr)
{
	ES_t LocalError=NOT_OK;
	for (int i=0;i<num;i++)
	{
		if(Copy_Astr[i].Type==Positive_Pin)
		{
			LocalError=enuSetPinDirection(DIO_PORTA,i,INPUT);
		}

	}
		return LocalError;
}

ES_t LM35_ReadTemp(u8 number,f32 * Temp)
{
    ES_t LocalError = OK;  // Start with success

    if (Temp != NULL)  // Correct NULL check
    {
        // Example formula for converting ADC value to temperature
        *Temp = (number * 4.88f) / 10.0f;  // Ensure your formula is correct
    }
    else
    {
        LocalError = NOT_OK;  // Handle NULL pointer
    }

    return LocalError;
}
