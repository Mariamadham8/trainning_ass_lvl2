/*
 * USART_init.h
 *
 *  Created on: Apr 12, 2025
 *      Author: Mariem
 */

#ifndef USART_INIT_H_
#define USART_INIT_H_
/*
 * v_prog.c
 *
 *  Created on: Apr 12, 2025
 *      Author: Mariem
 */
#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include"../USART/USART_config.h"
#include"../USART/USART_priv.h"

 void USART_Init();


 void USART_Transmit( unsigned char data );


 void USART_Transmit_String( unsigned char* data );


 void USART_Read( u8 *Copy_pu8Data);

//enter is \r or \n
 void USART_Read_String( unsigned char* data);



#endif /* USART_INIT_H_ */
