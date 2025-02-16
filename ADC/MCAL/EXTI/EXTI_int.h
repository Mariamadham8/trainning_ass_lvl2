/*
 * EXTI_int.h
 *
 *  Created on: Jan 5, 2025
 *      Author: Mariem
 */

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

#include"EXTI_config.h"

ES_t EXTI_enuinit( EXTI_t *EXTI_AstrEXTIConfig);
ES_t EXTI_enuSetSenceMOde(u8 CopypstrEXTI_ID,u8 Copy_u8Senselevel);
ES_t EXTI_enuEnableINT(u8 CopypstrEXTI_ID);
ES_t EXTI_enuDisableINT(u8 CopypstrEXTI_ID);
ES_t EXTI_enuCallBack(void (*Copy_pfunAppFun)(void),void *pvoiParameter,u8 CopypstrEXTI_ID);

#define Falling_edge 0
#define Rising_edge  1
#define Low_level    2
#define On_change    3


#endif /* EXTI_INT_H_ */
