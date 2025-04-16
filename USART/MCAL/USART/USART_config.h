#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

#include "../USART/USART_priv.h"

#define Speed_Mode Normal  // or Double

#define UART_Mode Tranciever  // or Transmitter/Reciever

#define UART_CLK Asynch  // or Synch

#define parity_mode No_Parity  // or Even_Parity/Odd_Parity

#define Stop_Bit one_bit  // or two_bit

#define Character_Size CH_8  // 5/6/7/8 bits

#define Baud_Rate 1200

#endif /* USART_CONFIG_H_ */
