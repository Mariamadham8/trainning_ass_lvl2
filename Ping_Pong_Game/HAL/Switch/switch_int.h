/*
 * switch_int.h
 *
 *  Created on: Oct 14, 2024
 *      Author: Mariem
 */






#ifndef SWITCH_INT_H_
#define SWITCH_INT_H_

#include"switch_config.h"

ES_t Switch_enuInit(SW_t * Copy_AstrSwitchs);
ES_t Switch_enuGetState(SW_t * Copy_AstrSwitchs, u8 * Copy_pu8SwState);


#endif /* SWITCH_INT_H_ */
