/*
 * GIE_prog.c
 *
 *  Created on: Feb 15, 2025
 *      Author: Mariem
 */
#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include"GIE_priv.h"

ES_t GIE_enuEnable(void)
{
	ES_t LocalErrorStatus =NOT_OK;

	SREG |=(1<<7);

	return LocalErrorStatus;
}

ES_t GIE_enuDiable(void)
{
	ES_t LocalErrorStatus =NOT_OK;
	SREG &=~(1<<7);
		return LocalErrorStatus;
}
