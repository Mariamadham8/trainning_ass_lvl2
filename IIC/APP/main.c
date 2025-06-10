/*
 * main.c
 *
 *  Created on: Jun 2, 2025
 *      Author: Mariem
 */

#include"../LIB/stdTypes.h"
#include"../LIB/errorStates.h"

#include"../MCAL/I2C/I2C_int.h"
#include"../MCAL/I2C/I2C_config.h"

#include"../HAL/EEPROM/EEPROM_int.h"
#include"../HAL/EEPROM/EEPROM_config.h"

#include"avr/io.h"
#include"util/delay.h"

#define code 3
#if code == 0
int main(void)
{
    ES_t Error;
    u8 data;
    IIC_enuInint();

    while (1)
    {

        if (OK == IIC_StartCondition())
        {
            if (OK == IIC_WriteSlaveAdd(5, 0))
            {

                if (OK == IIC_WriteData('@'))
                {

                    IIC_StopCondition();
                }
            }
        }
        if(OK == IIC_CheckMyAddress())
                {
                    // 4. Read data and show on PORTA
                    if(OK == IIC_ReadData(&data))
                    {
                        DDRC = data;
                    }
                }
    }

    return 0;
}
#elif code ==1
int main()
{
    u8 data;

    IIC_enuInint();

    while(1)
    {

        if(OK == IIC_CheckMyAddress())
        {

            if(OK == IIC_ReadData(&data))
            {
                DDRA = data;
            }
        }
        if (OK == IIC_StartCondition())
               {

                   if (OK == IIC_WriteSlaveAdd(2, 0))
                   {

                       if (OK == IIC_WriteData('#'))
                       {

                           IIC_StopCondition();
                       }
                   }
               }
    }

    return 0;
}
#elif code ==3
int main()
{

	EEPROM_enuInit();
	u8 data;
	EEPROM_enuWriteData(15,'a');
	_delay_ms(150);
	EEPROM_enuReadData(15,&data);
	DDRA=data;

	return 0;
}

#endif

