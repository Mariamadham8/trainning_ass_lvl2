/*
 * main.c
 *
 *  Created on: Feb 13, 2025
 *      Author: Mariem
 */
#include "../LIB/stdTypes.h"
#include "../LIB/errorStates.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/EXTI/EXTI_config.h"
#include "../MCAL/GIE/GIE_int.h"

#include "../HAL/Switch/switch_int.h"
#include "../HAL/Switch/switch_config.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/LCD/LCD_config.h"

#include "util/delay.h"

volatile u8 flag_SW1_Pressed = 0;
volatile u8 flag_SW2_Pressed = 0;

void Dot_Forward(void);
void Dot_Backward(void);

void EXTI_SW1_Handler(void);
void EXTI_SW2_Handler(void);

extern SW_t Switch_AstrSwitchState[2];
extern EXTI_t EXTI_AstrEXTIConfig[3];

int main()
{

    DIO_enuInit();
    LCD_enuInit();
    Switch_enuInit(Switch_AstrSwitchState);
    EXTI_enuinit(EXTI_AstrEXTIConfig);
    GIE_enuEnable();

    enuSetPinDirection(DIO_PORTD, DIO_PIN2, INPUT);
    enuSetPinDirection(DIO_PORTD, DIO_PIN3, INPUT);

    EXTI_enuSetSenceMOde(0, Rising_edge);
    EXTI_enuSetSenceMOde(1, Rising_edge);
    EXTI_enuEnableINT(0);
    EXTI_enuEnableINT(1);

    EXTI_enuCallBack(EXTI_SW1_Handler, NULL, 0);
    EXTI_enuCallBack(EXTI_SW2_Handler, NULL, 1);

    while (1)
    {

        if (flag_SW1_Pressed)
        {
            Dot_Forward();
            flag_SW1_Pressed = 0;
        }

        if (flag_SW2_Pressed)
        {
            Dot_Backward();
            flag_SW2_Pressed = 0;
        }
        else
        {
        	LCD_enuSendString("GAME OVER");

        }
    }

    return 0;
}

void Dot_Forward(void)
{
    int x = 1, y = 0;
    for (; x <= 16; x++)
    {
        LCD_enuSetPosition(x, y);
        LCD_enuDisplayChar('.');
        _delay_ms(100);
        LCD_enuSendCommand(0x01);
    }
}

void Dot_Backward(void)
{
    int y = 0;
    for (int x = 15; x >= 1; x--)
    {
        LCD_enuSetPosition(x, y);
        LCD_enuDisplayChar('.');
        _delay_ms(100);
        LCD_enuSendCommand(0x01);
    }
}

void EXTI_SW1_Handler(void)
{
    _delay_ms(50);
    flag_SW1_Pressed = 1;
}

void EXTI_SW2_Handler(void)
{
    _delay_ms(50);
    flag_SW2_Pressed = 1;
}
