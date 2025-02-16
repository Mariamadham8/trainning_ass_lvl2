/*
 * Interrupt.h
 *
 *  Created on: Jan 6, 2025
 *      Author: Mariem
 */

#ifndef MCAL_INTERRUPT_H_
#define MCAL_INTERRUPT_H_



#define TIMER2_CTC   4


#define ISR(vector)  void vector(void) __attribute__((signal)); \
                     void vector(void)

//then complete the remaining of 22 intruupt source like this fom data sheet and subtract one
#define VECT_INT0                        __vector_1
#define VECT_INT1                        __vector_2
#define VECT_INT2                        __vector_3
#define TIMER2_COMP_vect                 __vector_4
#define  VECT_ADC                        __vector_16
#endif /* MCAL_INTERRUPT_H_ */
