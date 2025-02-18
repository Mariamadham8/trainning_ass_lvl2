/*
 * LED_prog.c
 *
 *  Created on: Oct 25, 2024
 *      Author: Mariem
 */

#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include"../../MCAL/DIO/DIO_int.h"

#include"./LCD_config.h"
#include"./LCD_priv.h"

#include"util/delay.h"

ES_t LCD_enuInit(void)
{
	ES_t LocalErrorStates= NOT_OK;
	    enuSetPinDirection(RS_PORT,RS_PIN,OUTPUT);
	    enuSetPinDirection(RW_PORT,RW_PIN,OUTPUT);
	    enuSetPinDirection(EN_PORT,EN_PIN,OUTPUT);

	    enuSetPinDirection(D7_PORT,D7_PIN,OUTPUT);
	    enuSetPinDirection(D6_PORT,D6_PIN,OUTPUT);
	    enuSetPinDirection(D5_PORT,D5_PIN,OUTPUT);
	    enuSetPinDirection(D4_PORT,D4_PIN,OUTPUT);
		_delay_ms(35);
#if LCDMODE ==_8BIT
		enuSetPinDirection(D3_PORT,D3_PIN,OUTPUT);
		enuSetPinDirection(D2_PORT,D2_PIN,OUTPUT);
		enuSetPinDirection(D1_PORT,D1_PIN,OUTPUT);
		enuSetPinDirection(D0_PORT,D0_PIN,OUTPUT);
   //function set
	LCD_invoiSendCommand(0x38);
#elif LCDMODE==_4BIT
	LCD_invoiSendCommand(0x28);
#endif
      _delay_ms(1);
      LCD_invoiSendCommand(0x0C); //dispaly on/off
      _delay_ms(1);
      LCD_invoiSendCommand(0x01); //despaly clear
      _delay_ms(2);
      LCD_invoiSendCommand(0x06); //left to write without shift
       LocalErrorStates= OK;
	return LocalErrorStates;
}
ES_t LCD_enuDisplayChar(u8 Copy_u8Data)
{
	ES_t LocalErrorStates= NOT_OK;

	  //SET RS AS COMMAND
		enuSetPinValue(RS_PORT,RS_PIN,HIGH);
		LCD_invoiLatch( Copy_u8Data);
		 LocalErrorStates= OK;
		return LocalErrorStates;

}
ES_t LCD_enuSendCommand(u8 Copy_u8Command)
{

	ES_t LocalErrorStates= NOT_OK;
	//SET RS AS COMMAND
	enuSetPinValue(RS_PORT,RS_PIN,LOW);
	LCD_invoiLatch( Copy_u8Command);
	 LocalErrorStates= OK;
		return LocalErrorStates;
}

static inline void LCD_invoiLatch(u8 Copy_u8Command)
{
	//RW WRITE
		enuSetPinValue(RW_PORT,RW_PIN,LOW);
		enuSetPinValue(EN_PORT,EN_PIN,LOW);
		//write data
		enuSetPinValue(D7_PORT,D7_PIN,((Copy_u8Command>>7)&1));
		enuSetPinValue(D6_PORT,D6_PIN,((Copy_u8Command>>6)&1));
		enuSetPinValue(D5_PORT,D5_PIN,((Copy_u8Command>>5)&1));
		enuSetPinValue(D4_PORT,D4_PIN,((Copy_u8Command>>4)&1));
#if LCDMODE ==_8BIT
		enuSetPinValue(D3_PORT,D3_PIN,((Copy_u8Command>>3)&1));
		enuSetPinValue(D2_PORT,D2_PIN,((Copy_u8Command>>2)&1));
		enuSetPinValue(D1_PORT,D1_PIN,((Copy_u8Command>>1)&1));
		enuSetPinValue(D0_PORT,D0_PIN,((Copy_u8Command>>0)&1));

#elif LCDMODE ==_4BIT

#endif
		//enable latch
		enuSetPinValue(EN_PORT,EN_PIN,HIGH);
		_delay_ms(10);
		enuSetPinValue(EN_PORT,EN_PIN,LOW);
		_delay_ms(10); // to manage the diffrence in speed between atmega and lcd
}

static inline void  LCD_invoiSendCommand(u8 Copy_u8Command)   //text repalcement in compilation
{
	//SET RS AS COMMAND
		enuSetPinValue(RS_PORT,RS_PIN,LOW);
		//RW WRITE
		enuSetPinValue(RW_PORT,RW_PIN,LOW);
		enuSetPinValue(EN_PORT,EN_PIN,LOW);
		//write data
		enuSetPinValue(D7_PORT,D7_PIN,((Copy_u8Command>>7)&1));
		enuSetPinValue(D6_PORT,D6_PIN,((Copy_u8Command>>6)&1));
		enuSetPinValue(D5_PORT,D5_PIN,((Copy_u8Command>>5)&1));
		enuSetPinValue(D4_PORT,D4_PIN,((Copy_u8Command>>4)&1));
		enuSetPinValue(D3_PORT,D3_PIN,((Copy_u8Command>>3)&1));
		enuSetPinValue(D2_PORT,D2_PIN,((Copy_u8Command>>2)&1));
		enuSetPinValue(D1_PORT,D1_PIN,((Copy_u8Command>>1)&1));
		enuSetPinValue(D0_PORT,D0_PIN,((Copy_u8Command>>0)&1));

		//enable latch
		enuSetPinValue(EN_PORT,EN_PIN,HIGH);
		_delay_ms(10);
		enuSetPinValue(EN_PORT,EN_PIN,LOW);
}

ES_t LCD_enuSendString(u8 *Copy_u8data)
{
	u8 Localerrorstatus=NOT_OK;
	if(Copy_u8data !=NULL)
	{
		u8 local_u8Itrator=0;
		while(Copy_u8data[local_u8Itrator] !='\0')
		{
			LCD_enuDisplayChar(*Copy_u8data);
			Copy_u8data++;
		}
	}
	else{
		Localerrorstatus =NULL_POINTER;
	}
	return Localerrorstatus;
}


ES_t LCD_enuSetPosition(u8 x,u8 y)
{
	ES_t LocalErrorState =NOT_OK;
	    u8 address;
	    if (x < 16 && y < 2) {

	        if (y == 0) {
	            address = 0x80 + x;    // Line 1 start address is 0x80
	        } else if (y == 1) {
	            address = 0xC0 + x;    // Line 2 start address is 0xC0
	        }
	        LCD_invoiSendCommand(address);
	        LocalErrorState = OK;
	    } else {
	        LocalErrorState = ES_OUT_OF_RANGE;
	    }
	    return LocalErrorState;
}
