/*
 * DIO_priv.h
 *
 *  Created on: Sep 26, 2024
 *      Author: Mariem
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_




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

#define DIO_MASK_BTI 1


#define Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0
#define Conc(b7,b6,b5,b4,b3,b2,b1,b0)      Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)

#define INPUT 0
#define OUTPUT 1

#define HIGH  1
#define LOW   0
#define FLOAT  0
#define PULL_UP  1


// Define I/O Registers (Ports)
#define PINA    (*(volatile uint8_t*)0x39)   // Input Pins, Port A
#define DDRA    (*(volatile uint8_t*)0x3A)   // Data Direction Register, Port A
#define PORTA   (*(volatile uint8_t*)0x3B)   // Data Register, Port A

#define PINB    (*(volatile uint8_t*)0x36)   // Input Pins, Port B
#define DDRB    (*(volatile uint8_t*)0x37)   // Data Direction Register, Port B
#define PORTB   (*(volatile uint8_t*)0x38)   // Data Register, Port B

#define PINC    (*(volatile uint8_t*)0x33)   // Input Pins, Port C
#define DDRC    (*(volatile uint8_t*)0x34)   // Data Direction Register, Port C
#define PORTC   (*(volatile uint8_t*)0x35)   // Data Register, Port C

#define PIND    (*(volatile uint8_t*)0x30)   // Input Pins, Port D
#define DDRD    (*(volatile uint8_t*)0x31)   // Data Direction Register, Port D
#define PORTD   (*(volatile uint8_t*)0x32)   // Data Register, Port D

// Define External Interrupt Registers
#define EIFR    (*(volatile uint8_t*)0x3C)   // External Interrupt Flag Register
#define EIMSK   (*(volatile uint8_t*)0x3D)   // External Interrupt Mask Register
#define GICR    (*(volatile uint8_t*)0x3B)   // General Interrupt Control Register

// Define Timer/Counter Registers
#define TCCR0   (*(volatile uint8_t*)0x53)   // Timer/Counter Control Register 0
#define TCNT0   (*(volatile uint8_t*)0x52)   // Timer/Counter Register 0
#define OCR0    (*(volatile uint8_t*)0x5C)   // Output Compare Register 0

#define TCCR1A  (*(volatile uint8_t*)0x4F)   // Timer/Counter 1 Control Register A
#define TCCR1B  (*(volatile uint8_t*)0x4E)   // Timer/Counter 1 Control Register B
#define TCNT1H  (*(volatile uint8_t*)0x4D)   // Timer/Counter 1 High Byte
#define TCNT1L  (*(volatile uint8_t*)0x4C)   // Timer/Counter 1 Low Byte
#define OCR1AH  (*(volatile uint8_t*)0x4B)   // Output Compare Register 1A High
#define OCR1AL  (*(volatile uint8_t*)0x4A)   // Output Compare Register 1A Low

// Define ADC Registers
#define ADMUX   (*(volatile uint8_t*)0x27)   // ADC Multiplexer Selection Register
#define ADCSRA  (*(volatile uint8_t*)0x26)   // ADC Control and Status Register A
#define ADCH    (*(volatile uint8_t*)0x25)   // ADC Data Register High
#define ADCL    (*(volatile uint8_t*)0x24)   // ADC Data Register Low

// Define UART Registers
#define UDR     (*(volatile uint8_t*)0x2C)   // USART I/O Data Register
#define UCSRA   (*(volatile uint8_t*)0x2B)   // USART Control and Status Register A
#define UCSRB   (*(volatile uint8_t*)0x2A)   // USART Control and Status Register B
#define UBRRH   (*(volatile uint8_t*)0x40)   // USART Baud Rate Register High
#define UBRRL   (*(volatile uint8_t*)0x29)   // USART Baud Rate Register Low

// Define SPI Registers
#define SPCR    (*(volatile uint8_t*)0x2D)   // SPI Control Register
#define SPSR    (*(volatile uint8_t*)0x2E)   // SPI Status Register
#define SPDR    (*(volatile uint8_t*)0x2F)   // SPI Data Register

// Define Status and Control Registers
#define SREG    (*(volatile uint8_t*)0x5F)   // Status Register
#define SPH     (*(volatile uint8_t*)0x5E)   // Stack Pointer High
#define SPL     (*(volatile uint8_t*)0x5D)   // Stack Pointer Low
#define MCUCR   (*(volatile uint8_t*)0x55)   // MCU Control Register
#define MCUCSR  (*(volatile uint8_t*)0x54)   // MCU Control and Status Register


//****************************************************************************



#endif /* DIO_PRIV_H_ */
