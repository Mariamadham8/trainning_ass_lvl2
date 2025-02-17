/*
 * LED_int.h
 *
 *  Created on: Oct 14, 2024
 *      Author: Mariem
 */

#ifndef LED_INT_H_
#define LED_INT_H_

#include "../LIB/stdTypes.h"
#include "../LIB/errorStates.h"

#include"../HAL/LED/LED_config.h"

ES_t LED_enuInit(LED_t * Copy_pstrLedConfig);

ES_t LED_enuTurnON(LED_t * Copy_pstrLedID);

ES_t LED_enuTurnOFF(LED_t * Copy_pstrLedID);



#endif /* LED_INT_H_ */
