/*
 * EXTI_priv.h
 *
 *  Created on: Jan 5, 2025
 *      Author: Mariem
 */

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

#define INT0 6
#define INT1 7
#define INT2 5


#define Active 5
#define Deactive 9

#define Falling_edge 0
#define Rising_edge  1
#define Low_level    2
#define On_change    3


#define MCUCR    *((volatile u8*)0x55)
#define MCUSCR   *((volatile u8*)0x54)
#define GICR	 *((volatile u8*)0x5B)
#define GIFR	 *((volatile u8*)0x5A)




#endif /* EXTI_PRIV_H_ */
