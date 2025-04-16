/*
 * DIO_int.h
 *
 *  Created on: Sep 19, 2024
 *      Author: Mariem
 */

#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"
#ifndef DIO_INT_H_
#define DIO_INT_H_



#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define INPUT 0
#define OUTPUT 1

#define HIGH  1
#define LOW   0

#define FLOAT  0
#define PULL_UP  1



ES_t DIO_enuInit(void);
ES_t enuSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8Portvalue);

ES_t enuSetPortValue(u8 Copy_u8PortID,u8 Copy_u8Portvalue);

ES_t enuSetTogPort(u8 Copy_u8PortID);

ES_t enuGetPortValue(u8 Copy_u8PortID,u8 *Copy_u8Portvalue);

ES_t enuSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID ,u8 Copy_u8Pinvalue);

ES_t enuSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Portvalue);

ES_t enuSetTogPin(u8 Copy_u8PortID,u8 Copy_u8PinID);

ES_t enuGetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 *Copy_u8Portvalue);





#endif /* DIO_INT_H_ */
