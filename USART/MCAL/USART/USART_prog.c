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


void USART_Init() {

    // Speed mode
    #if Speed_Mode == Double
	UCSRA |= (1 << 1);
    #elif Speed_Mode == Normal
        UCSRA &= ~(1 << 1);
    #endif

    // Enable TX/RX
    #if UART_Mode == Tranciever
        UCSRB = (3<<3);  // RXEN + TXEN
    #elif UART_Mode == Reciever
        UCSRB = (1 << 4);  // RXEN only
    #elif UART_Mode == Transmitter
        UCSRB = (1 << 3);  // TXEN only
    #endif

    u8 ucsrc =0;
    // Character size
    #if Character_Size == CH_8
        ucsrc |=(1<<1);
        ucsrc |=(1<<2);
    #elif Character_Size == CH_7
        ucsrc |= (1 << 2);
    #elif Character_Size == CH_6
        ucsrc |= (1 << 1);
    #elif Character_Size == CH_5
        // Nothing to set (00)
    #endif

    // Parity
    #if parity_mode == Even_Parity
        ucsrc |= (1 << 5);
    #elif parity_mode == Odd_Parity
        ucsrc |= (1 << 5) | (1 << 4);
     #else
        ucsrc &=~(3<<4);
    #endif

    // Stop bits
    #if Stop_Bit == two_bit
        ucsrc |= (1 << 3);
    #elif Stop_Bit==one_bit
        ucsrc &= ~(1 << 3);
    #endif

    #if UART_CLK ==Asynch
        ucsrc &=~(1<<6);
    #endif
        ucsrc |=(1<<7);
        UCSRC = ucsrc;

        // Set baud rate
           u16 ubrr = Bouad_Fun(Baud_Rate);
           UBRRL =(u8) ubrr;
           UBRRH |= (ubrr >> 8);
}


 void USART_Transmit( u8 data )
 {

    while ( !((UCSRA>>5)&1));
    UDR = data;
 }

 void USART_Transmit_String( unsigned char* data )
{
		while(*data !='\0'){

			while ( !( UCSRA & (1<<5)) );
			UDR = *data;
			data++;
		}
}


 void USART_Read( u8 *Copy_pu8Data)
 {
     	 while ( !((UCSRA>>7)&1));
		*Copy_pu8Data = UDR;
 }

//enter is \r or \n
 void USART_Read_String( unsigned char* data)
 {

	 u8 Local_u8Data=0,LocalIndex=0;
	 while(1)
	 {
		 while ( !( UCSRA & (1<<7)) );
		 Local_u8Data = UDR;
		 if(Local_u8Data=='\r' || Local_u8Data =='\n')
		 {
			 data[LocalIndex]='\0';
			 break;
		 }
		 data[LocalIndex]=Local_u8Data;
		 LocalIndex++;
	 }
 }
