/*
 * ADC_priv.c
 *
 *  Created on: Feb 15, 2025
 *      Author: Mariem
 */

#ifndef MCAL_ADC_ADC_PRIV_C_
#define MCAL_ADC_ADC_PRIV_C_


//registers difinition

#define ADMUX  *((volatile u8 *)0x27)
#define ADCSRA *((volatile u8 *)0x26)
#define ADCH   *((volatile u8 *)0x25)
#define ADCL   *((volatile u8 *)0x24)
#define SFIOR  *((volatile u8 *)0x50)

//prescaller choices
#define PRES_2       1
#define PRES_4       2
#define PRES_8       3
#define PRES_16      4
#define PRES_32      5
#define PRES_64      6
#define PRES_128     7

//Vref choices

#define AVCC      16
#define AREF      23
#define Internal_VREF    55

//ADJUSTMENT options

#define Right_ADJ 22
#define Left_ADJ  90

//trigrring modes
#define     Free_Running   67
#define	    EXTI           98



#endif /* MCAL_ADC_ADC_PRIV_C_ */
