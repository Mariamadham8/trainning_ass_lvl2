/*
 * KeyPad2_prog.c
 *
 *  Created on: Nov 24, 2024
 *      Author: Mariem
 */


/*
 * Keypad_prog.c
 *
 *  Created on: Nov 12, 2024
 *      Author: Mariem
 */

#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include"../../MCAL/DIO/DIO_int.h"
#include"../../MCAL/DIO/DIO_priv.h"

#include"./KeyPad2_int.h"
#include"./KeyPad2_config.h"

ES_t Keypad_enuInit(void)
{


	ES_t Local_ErrorState= NOT_OK;
	//set rows as output
	Local_ErrorState =enuSetPinDirection(output_pins ,output_pin0 ,OUTPUT);
	Local_ErrorState =enuSetPinDirection(output_pins ,output_pin1 ,OUTPUT);
	Local_ErrorState =enuSetPinDirection(output_pins ,output_pin2 ,OUTPUT);
	Local_ErrorState =enuSetPinDirection(output_pins ,output_pin3 ,OUTPUT);

	//set col as input
	Local_ErrorState =enuSetPinDirection(input_pins ,input_pin4 ,INPUT);
	Local_ErrorState =enuSetPinDirection(input_pins ,input_pin5 ,INPUT);
	Local_ErrorState =enuSetPinDirection(input_pins ,input_pin6 ,INPUT);
	Local_ErrorState =enuSetPinDirection(input_pins ,input_pin7 ,INPUT);

	//activate internal pullup for inputpins
	Local_ErrorState=enuSetPinValue(input_pins,input_pin4,HIGH);
	Local_ErrorState=enuSetPinValue(input_pins,input_pin5,HIGH);
	Local_ErrorState=enuSetPinValue(input_pins,input_pin6,HIGH);
	Local_ErrorState=enuSetPinValue(input_pins,input_pin7,HIGH);

	//set col to no output state (not pressed)
	Local_ErrorState=enuSetPinValue(output_pins,output_pin3,HIGH);
	Local_ErrorState=enuSetPinValue(output_pins,output_pin1,HIGH);
	Local_ErrorState=enuSetPinValue(output_pins,output_pin2,HIGH);
	Local_ErrorState=enuSetPinValue(output_pins,output_pin3,HIGH);


	return Local_ErrorState;
}

ES_t Keypad_enuScan(u8* button)
{
    static const u8 mapped_keypad[4][4] = {
        {'7', '8', '9', '/'},
        {'4', '5', '6', '*'},
        {'1', '2', '3', '-'},
        {'?', '0', '=', '+'}
    };

    ES_t local_errorstates = NOT_OK;
    u8 col_value = 0;
    u8 button_found = 0;
    for (u8 row = 0; row < 4; row++)
    {

        local_errorstates |= enuSetPinValue(output_pins, output_pin0 + row, LOW);  // Activate current row
        // Check for any column being pressed
        for (u8 col = 0; col < 4; col++) {
            local_errorstates |= enuGetPinValue(input_pins, input_pin4 + col, &col_value);
            if (col_value == LOW) {  // Detect a press (active LOW)
                *button = mapped_keypad[row][col];
                button_found = 1;
                break;
            }
            else
            {
            	 *button = '\0';

            }
        }

        if (button_found) {
            break;
        }
    }

    // Restore rows to idle state (HIGH)
    for (u8 r = 0; r < 4; r++) {
        local_errorstates |= enuSetPinValue(output_pins, output_pin0 + r, HIGH);
    }
    if (!button_found) {
        *button = '\0';
        local_errorstates = NOT_OK;
    } else {
        local_errorstates = OK;
    }

    return local_errorstates;
}
