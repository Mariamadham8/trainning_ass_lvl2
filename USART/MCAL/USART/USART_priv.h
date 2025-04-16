#ifndef USART_PRIV_H_
#define USART_PRIV_H_

#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"


#ifndef F_CPU
#define F_CPU 1000000UL  // 16MHz default
#endif

// Correct baud rate calculation
#define Bouad_Fun(val) (F_CPU/(Speed_Mode *8UL*val)-1)

// Speed modes
#define Normal 2
#define Double 1

// Operation modes
#define Transmitter 30
#define Reciever    10
#define Tranciever  20

// Clock modes
#define Synch  23
#define Asynch 1

// Parity modes
#define No_Parity   0
#define Even_Parity 2
#define Odd_Parity  3

// Stop bits
#define one_bit 90
#define two_bit 1

// Character sizes
#define CH_5 33
#define CH_6 55
#define CH_7 89
#define CH_8 45

// Register definitions
#define UDR   *((volatile u8 *)0x2C)
#define UCSRA *((volatile u8 *)0x2B)
#define UCSRB *((volatile u8 *)0x2A)
#define UBRRL *((volatile u8 *)0x29)
#define UBRRH *((volatile u8 *)0x40)
#define UCSRC *((volatile u8 *)0x40)

#endif /* USART_PRIV_H_ */
