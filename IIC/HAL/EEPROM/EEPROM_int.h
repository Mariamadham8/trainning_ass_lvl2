/*
 * EEPROM_int.h
 *
 *  Created on: Jun 7, 2025
 *      Author: Mariem
 */

#ifndef HAL_EEPROM_EEPROM_INT_H_
#define HAL_EEPROM_EEPROM_INT_H_

#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

ES_t EEPROM_enuInit();

ES_t EEPROM_enuWriteData(u16 Copy_u8Address,u8 Copy_u8Data);


ES_t EEPROM_enuReadData(u16 Copy_u8Address,u8 *Copy_u8Data);

#endif /* HAL_EEPROM_EEPROM_INT_H_ */
