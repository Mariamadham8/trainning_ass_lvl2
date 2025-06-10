/*
 * I2C_int.h
 *
 *  Created on: Jun 2, 2025
 *      Author: Mariem
 */

#ifndef MCAL_I2C_I2C_INT_H_
#define MCAL_I2C_I2C_INT_H_

#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

ES_t IIC_enuInint();

ES_t IIC_StartCondition();

ES_t IIC_ReStartCondition();

ES_t IIC_StopCondition();

ES_t IIC_WriteSlaveAdd(u8 Copy_u8SlaveAdd,u8 Copy_u8Opperation);

ES_t IIC_WriteData(u8 Copy_u8Data);

ES_t IIC_CheckMyAddress();

ES_t IIC_ReadData(u8 *Copy0u8Data);






#endif /* MCAL_I2C_I2C_INT_H_ */
