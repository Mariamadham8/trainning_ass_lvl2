/*
 * EEPROM_prog.c
 *
 *  Created on: Jun 7, 2025
 *      Author: Mariem
 */

#include "../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include"../../MCAL/I2C/I2C_int.h"

#include"../../HAL/EEPROM/EEPROM_config.h"
#include"../../HAL/EEPROM/EEPROM_priv.h"
#include "avr./io.h"
ES_t EEPROM_enuInit()
{
	ES_t LocalErrorStatus =NOT_OK;
	LocalErrorStatus =IIC_enuInint();
	return  LocalErrorStatus;
}

ES_t EEPROM_enuWriteData(u16 Copy_u8Address,u8 Copy_u8Data)
{
	ES_t LocalErrorStatus =NOT_OK;
#if EEPROM_TYPE == EGHT_K
	u8 LocalAddress =((0XA0 |(EEPROM_A2State <<3) | ( ( (Copy_u8Address >> 8) & 3) <<1) )>>1);
	u8 Local_ByteAddress =(u8)Copy_u8Address;
#endif
	if(OK == IIC_StartCondition())
	{

		if(OK ==IIC_WriteSlaveAdd(LocalAddress,0))
		{

			if(OK == IIC_WriteData(Local_ByteAddress))
			{
				 DDRC =0xaa;
				if(OK ==IIC_WriteData(Copy_u8Data))
				{
					IIC_StopCondition();
					LocalErrorStatus=OK;
				}
			}
		}
	}

	return  LocalErrorStatus;
}


ES_t EEPROM_enuReadData(u16 Copy_u8Address,u8 *Copy_u8Data)
{
	ES_t LocalErrorStatus =NOT_OK;
#if EEPROM_TYPE == EGHT_K
	u8 LocalAddress =((0XA0 |(EEPROM_A2State <<3) | (((Copy_u8Address >> 8) & 3) <<1))>>1);
	u8 Local_ByteAddress =(u8)Copy_u8Address;
#endif
	if(OK == IIC_StartCondition())
	{
		if(OK ==IIC_WriteSlaveAdd(LocalAddress,0))
		{
			if(OK == IIC_WriteData(Local_ByteAddress))
			{
				if(OK ==IIC_ReStartCondition())
				{
					if(OK ==IIC_WriteSlaveAdd(LocalAddress,1))
					{
						if(OK == IIC_ReadData(Copy_u8Data))
						{
							IIC_StopCondition();
							LocalErrorStatus=OK;
						}
					}
				}
			}
		}
	}


	return  LocalErrorStatus;
}
