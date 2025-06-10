/*
 * I2C_priv.h
 *
 *  Created on: Jun 2, 2025
 *      Author: Mariem
 */

#ifndef MCAL_I2C_I2C_PRIV_H_
#define MCAL_I2C_I2C_PRIV_H_

#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"


#define  TWDR *((volatile u8*)0x23)
#define  TWAR *((volatile u8*)0x22)
#define  TWSR *((volatile u8*)0x21)
#define  TWBR *((volatile u8*)0x20)
#define  TWCR *((volatile u8*)0x56)

#define Master 10
#define  Slave 20

#endif /* MCAL_I2C_I2C_PRIV_H_ */
