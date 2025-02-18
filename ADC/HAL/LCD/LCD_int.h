/*
 * LCD_int.h
 *
 *  Created on: Nov 7, 2024
 *      Author: Mariem
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_


ES_t LCD_enuInit(void);
ES_t LCD_enuDisplayChar(u8 Copy_u8Data);
ES_t LCD_enuSendCommand(u8 Copy_u8Command);
ES_t LCD_enuSendString(u8 *Copy_u8data);
ES_t LCD_enuSetPosition(u8 x,u8 y);


#endif /* LCD_INT_H_ */
