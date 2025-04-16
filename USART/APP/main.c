#include "stdio.h"
#include "../LIB/stdTypes.h"
#include "../LIB/errorStates.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/USART/USART_init.h"
#include "../MCAL/USART/USART_config.h"

int main() {
    u8 data[100];
    u8 TestON[100] = "LedOn";
    u8 TestOff[100] = "LedOff";

    DIO_enuInit();
    enuSetPinDirection(DIO_PORTD, DIO_PIN1, OUTPUT); // TXD
    enuSetPinDirection(DIO_PORTD, DIO_PIN0, INPUT);  // RXD
    enuSetPinDirection(DIO_PORTC, DIO_PIN0, OUTPUT); // Buzzer
    enuSetPinDirection(DIO_PORTC, DIO_PIN2, OUTPUT); // LED

    enuSetPinValue(DIO_PORTC, DIO_PIN0, LOW);
    enuSetPinValue(DIO_PORTC, DIO_PIN2, LOW);

    USART_Init();
    USART_Transmit_String("Welcome To Our Smart Home\r\n");
    USART_Transmit_String("Enter Command(LedOn/LedOff):\r\n");

    while (1) {
        USART_Read_String(data);
        USART_Transmit_String(data);
        USART_Transmit_String("\r\n");
        USART_Transmit_String("Enter Command(LedOn/LedOff):\r\n");

        if (strcmp(TestON, data) == 0) { // Check for "LedOn"
            enuSetPinValue(DIO_PORTC, DIO_PIN0, HIGH); // Buzzer ON
            enuSetPinValue(DIO_PORTC, DIO_PIN2, HIGH); // LED ON
        } else if (strcmp(TestOff, data) == 0) { // Check for "LedOff"
            enuSetPinValue(DIO_PORTC, DIO_PIN0, LOW);  // Buzzer OFF
            enuSetPinValue(DIO_PORTC, DIO_PIN2, LOW);  // LED OFF
        } else {
            USART_Transmit_String("ERROR\r\n");
        }
    }
    return 0;
}
