/*
 * LM35_int.h
 *
 *  Created on: Feb 18, 2025
 *      Author: Mariem
 */

#ifndef HAL_LM35_LM35_INT_H_
#define HAL_LM35_LM35_INT_H_

#include"../LM35/LM35_config.h"

ES_t LM35_Init(LM35_t *Copy_Astr);
ES_t LM35_ReadTemp(u8 number,f32 * Temp);

#define Positive_Pin  23
#define Negative_Pin  44

#endif /* HAL_LM35_LM35_INT_H_ */
