/*
 * I2C_prog.c
 *
 *  Created on: Jun 2, 2025
 *      Author: Mariem
 */

#ifndef MCAL_I2C_I2C_PROG_C_
#define MCAL_I2C_I2C_PROG_C_

/*
 * I2C_int.h
 *
 *  Created on: Jun 2, 2025
 *      Author: Mariem
 */

#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include"../../MCAL/I2C/I2C_config.h"
#include"../../MCAL/I2C/I2C_priv.h"

#ifndef MCAL_I2C_I2C_INT_H_
#define MCAL_I2C_I2C_INT_H_


ES_t IIC_enuInint()
{
	ES_t LocalErrorStatus=NOT_OK;

#if IIC_Mode == Master
	TWBR =(u8) BitRate(IIC_Speed);
    #if  IIC_Pres==1ul
	TWSR &=~(3<<0);
#endif
	TWAR &=~(1<<0);
	TWAR =(IIC_Node_ADD<<1)|IIC_Genral_Call;

	TWCR |=(1<<7);
	TWCR |=(1<<2); //Enable IIC
#elif IIC_Mode ==Slave
	TWAR &=~(1<<0);
		TWAR =(IIC_Node_ADD<<1)|IIC_Genral_Call;

		TWCR |=(1<<7);
		TWCR |=(1<<2); //Enable IIC

#endif
	return LocalErrorStatus;

}

ES_t IIC_StartCondition()
{
	ES_t LocalErrorStatus=NOT_OK;
    TWCR |=(1<<5);
    //clear flag
	TWCR |=(1<<7);
	while(!(TWCR>>7)&1);
	if((TWSR &0XF8) ==0X08)
		LocalErrorStatus=OK;
	return LocalErrorStatus;

}

ES_t IIC_ReStartCondition()
{
	ES_t LocalErrorStatus=NOT_OK;
	 TWCR |=(1<<5);
	    //clear flag
		TWCR |=(1<<7);
		while(!(TWCR>>7)&1);
		if((TWSR &0XF8) ==0X10)
			LocalErrorStatus=OK;
		return LocalErrorStatus;
}

ES_t IIC_StopCondition()
{
	ES_t LocalErrorStatus=NOT_OK;
    TWCR |=(1<<4);
    //clear flag
   	TWCR |=(1<<7);
	return LocalErrorStatus;

}

ES_t IIC_WriteSlaveAdd(u8 Copy_u8SlaveAdd,u8 Copy_u8Opperation)
{
	ES_t LocalErrorStatus=NOT_OK;
    TWDR =(Copy_u8SlaveAdd<<1)|Copy_u8Opperation;

    TWCR |=(1<<2);
    TWCR |=(1<<7);
     while (!(TWCR & (1 << 7)));
    if((TWSR &0XF8) == 0X20 && Copy_u8Opperation==0)
    			LocalErrorStatus=OK;
    if((TWSR &0XF8) == 0X48 && Copy_u8Opperation==1)
       			LocalErrorStatus=OK;
	return LocalErrorStatus;

}

ES_t IIC_WriteData(u8 Copy_u8Data)
{
	ES_t LocalErrorStatus=NOT_OK;
	 TWDR =Copy_u8Data;
	    TWCR |=(1<<7);
	    while (!(TWCR & (1 << 7)));
	    if((TWSR &0XF8) == 0X30)
	    			LocalErrorStatus=OK;
	    if((TWSR &0XF8) == 0X20 )
	       			LocalErrorStatus=OK;

	return LocalErrorStatus;

}

ES_t IIC_CheckMyAddress()
{
	ES_t LocalErrorStatus=NOT_OK;
	//ACK enable
    TWCR |=(1<<6);
    TWCR |=(1<<7);
    while(!(TWCR>>7)&1);
    if((TWSR &0XF8) == 0X60 )
        			LocalErrorStatus=OK;
        if((TWSR &0XF8) == 0XA8 )
           			LocalErrorStatus=OK;

	return LocalErrorStatus;

}

ES_t IIC_ReadData(u8 *Copy0u8Data)
{
	ES_t LocalErrorStatus=NOT_OK;
		    TWCR |=(1<<7);
		    while(!(TWCR>>7)&1);
		    if((TWSR &0XF8 )== 0X58  || (TWSR &0XF8 ) ==50){
		    	 *Copy0u8Data=TWDR;
		    	LocalErrorStatus=OK;
		    }
		    else if((TWSR &0XF8) == 0X80 ){
		            	*Copy0u8Data=TWDR;
		       			LocalErrorStatus=OK;
		    }

		return LocalErrorStatus;

}

#endif /* MCAL_I2C_I2C_INT_H_ */
#endif /* MCAL_I2C_I2C_PROG_C_ */
