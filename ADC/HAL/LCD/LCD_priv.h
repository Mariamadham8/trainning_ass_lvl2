/*
 * LED_priv.h
 *
 *  Created on: Oct 25, 2024
 *      Author: Mariem
 */

#ifndef LED_PRIV_H_
#define LED_PRIV_H_

#define _8BIT  11
#define _4BIT  10

static inline void  LCD_invoiSendCommand(u8 Copy_u8Command);
static inline void LCD_invoiLatch(u8 Copy_u8Command);

#endif /* LED_PRIV_H_ */
