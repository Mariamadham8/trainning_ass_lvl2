/*
 * DIO_prog.c
 *
 *  Created on: Sep 26, 2024
 *      Author: Mariem
 */
#include<stdint.h>

#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include"DIO_priv.h"
#include"DIO_config.h"

//initial values
ES_t DIO_enuInit(void)
{
	  ES_t local_enuErrorState=NOT_OK;

	  DDRA = Conc(PA_PIN7_DIR , PA_PIN6_DIR, PA_PIN5_DIR ,PA_PIN4_DIR, PA_PIN3_DIR ,PA_PIN2_DIR ,PA_PIN1_DIR ,PA_PIN0_DIR);
	  DDRB = Conc(PB_PIN7_DIR , PB_PIN6_DIR, PB_PIN5_DIR ,PB_PIN4_DIR, PB_PIN3_DIR ,PB_PIN2_DIR ,PB_PIN1_DIR ,PB_PIN0_DIR);
	  DDRC = Conc(PC_PIN7_DIR , PC_PIN6_DIR, PC_PIN5_DIR ,PC_PIN4_DIR, PC_PIN3_DIR ,PC_PIN2_DIR ,PC_PIN1_DIR ,PC_PIN0_DIR);
	  DDRD = Conc(PD_PIN7_DIR , PD_PIN6_DIR, PD_PIN5_DIR ,PD_PIN4_DIR, PD_PIN3_DIR ,PD_PIN2_DIR ,PD_PIN1_DIR ,PD_PIN0_DIR);

	  PORTA = Conc(PA_PIN7_VAL , PA_PIN6_VAL, PA_PIN5_VAL ,PA_PIN4_VAL, PA_PIN3_VAL ,PA_PIN2_VAL ,PA_PIN1_VAL ,PA_PIN0_VAL);
	  PORTB = Conc(PB_PIN7_VAL , PB_PIN6_VAL, PB_PIN5_VAL ,PB_PIN4_VAL, PB_PIN3_VAL ,PB_PIN2_VAL ,PB_PIN1_VAL ,PB_PIN0_VAL);
	  PORTC = Conc(PC_PIN7_VAL , PC_PIN6_VAL, PC_PIN5_VAL ,PC_PIN4_VAL, PC_PIN3_VAL ,PC_PIN2_VAL ,PC_PIN1_VAL ,PC_PIN0_VAL);
	  PORTD = Conc(PD_PIN7_VAL , PD_PIN6_VAL, PD_PIN5_VAL ,PD_PIN4_VAL, PD_PIN3_VAL ,PD_PIN2_VAL ,PD_PIN1_VAL ,PD_PIN0_VAL);
	   local_enuErrorState=OK;


	  return local_enuErrorState;
}

//periodic functions
ES_t enuSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8Portvalue){

	ES_t local_enuErrorState=NOT_OK;
   if(Copy_u8PortID<= DIO_PORTD)
   {
        switch(Copy_u8PortID)
        {
          case  DIO_PORTA:
        	  DDRA=Copy_u8Portvalue;
        	  break;
          case  DIO_PORTB:
                  	  DDRB=Copy_u8Portvalue;
                  	  break;
          case  DIO_PORTC:
                  	  DDRC=Copy_u8Portvalue;
                  	  break;
          case  DIO_PORTD:
                  	  DDRD=Copy_u8Portvalue;
                  	  break;
        }
         local_enuErrorState=OK;
   }
   else
   {
	   local_enuErrorState=ES_OUT_OF_RANGE;
   }

	return local_enuErrorState;
}

ES_t enuSetPortValue(u8 Copy_u8PortID,u8 Copy_u8Portvalue)
{
	ES_t local_enuErrorState=NOT_OK;
	if(Copy_u8PortID<= DIO_PORTD)
	   {
	        switch(Copy_u8PortID)
	        {
	          case  DIO_PORTA:
	        	  PORTA=Copy_u8Portvalue;
	        	  break;
	          case  DIO_PORTB:
	                  	  PORTB=Copy_u8Portvalue;
	                  	  break;
	          case  DIO_PORTC:
	                  	  PORTC=Copy_u8Portvalue;
	                  	  break;
	          case  DIO_PORTD:
	                  	  PORTD=Copy_u8Portvalue;
	                  	  break;
	        }
	         local_enuErrorState=OK;
	   }
	   else
	   {
		   local_enuErrorState=ES_OUT_OF_RANGE;
	   }


		return local_enuErrorState;
}

ES_t enuSetTogPort(u8 Copy_u8PortID)
{
	ES_t local_enuErrorState=NOT_OK;
	if(Copy_u8PortID<= DIO_PORTD)
		   {
		        switch(Copy_u8PortID)
		        {
		          case  DIO_PORTA:
		        	  PORTA=~PORTA;
		        	  break;
		          case  DIO_PORTB:
		                  	  PORTB=~PORTB;
		                  	  break;
		          case  DIO_PORTC:
		                  	  PORTC=~PORTC;
		                  	  break;
		          case  DIO_PORTD:
		                  	  PORTD=~PORTD;
		                  	  break;
		        }
		         local_enuErrorState=OK;
		   }
		   else
		   {
			   local_enuErrorState=ES_OUT_OF_RANGE;
		   }


		return local_enuErrorState;
}

ES_t enuGetPortValue(u8 Copy_u8PortID,u8 *Copy_u8Portvalue)
{
	ES_t local_enuErrorState=NOT_OK;
	if(Copy_u8Portvalue !=NULL)
	{
		if(Copy_u8PortID<= DIO_PORTD)
		{
			 switch(Copy_u8PortID)
					        {
					          case  DIO_PORTA:
					        	  *Copy_u8Portvalue=PINA;
					        	  break;
					          case  DIO_PORTB:
					        	  *Copy_u8Portvalue=PINB;
					                  	  break;
					          case  DIO_PORTC:
					        	  *Copy_u8Portvalue=PINC;
					                  	  break;
					          case  DIO_PORTD:
					        	  *Copy_u8Portvalue=PIND;
					                  	  break;
					        }
					        local_enuErrorState=OK;

		}
		else
		{
			 local_enuErrorState=ES_OUT_OF_RANGE;
		}

	}
	else
	{
		 local_enuErrorState=NULL_POINTER;
	}
	return local_enuErrorState;

}

ES_t enuSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID ,u8 Copy_u8Pinvalue)
{
	ES_t local_enuErrorState=NOT_OK;
	if (Copy_u8PortID <= DIO_PORTD && Copy_u8PinID <= DIO_PIN7 && Copy_u8Pinvalue <= OUTPUT)
	{
			 switch(Copy_u8PortID)
			        {
			          case  DIO_PORTA:
			        	  DDRA &=~(1<<Copy_u8PinID);
			        	  DDRA|=(Copy_u8Pinvalue<<Copy_u8PinID);
			        	  break;
			          case  DIO_PORTB:
			        	  DDRB &=~(1<<Copy_u8PinID);
                          DDRB|=(Copy_u8Pinvalue<<Copy_u8PinID);
			                  	  break;
			          case  DIO_PORTC:
			        	  DDRC &=~(1<<Copy_u8PinID);
			        	  DDRC|=(Copy_u8Pinvalue<<Copy_u8PinID);
			                  	  break;
			          case  DIO_PORTD:
			        	  DDRD &=~(1<<Copy_u8PinID);
			        	  DDRD|=(Copy_u8Pinvalue<<Copy_u8PinID);
			                  	  break;
			        }
			         local_enuErrorState=OK;

		}
		else
		{
			 local_enuErrorState=ES_OUT_OF_RANGE;
		}
		return local_enuErrorState;
}

ES_t enuSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Pinvalue)
{
	ES_t local_enuErrorState=NOT_OK;

	if (Copy_u8PortID <= DIO_PORTD && Copy_u8PinID <= DIO_PIN7 && Copy_u8Pinvalue <= OUTPUT)
		{
				 switch(Copy_u8PortID)
				        {
				          case  DIO_PORTA:
				        	  PORTA &=~(1<<Copy_u8PinID);
				        	  PORTA|=(Copy_u8Pinvalue<<Copy_u8PinID);
				        	  break;
				          case  DIO_PORTB:
				        	  PORTB &=~(1<<Copy_u8PinID);
				        	  PORTB|=(Copy_u8Pinvalue<<Copy_u8PinID);
				                  	  break;
				          case  DIO_PORTC:
				        	  PORTC &=~(1<<Copy_u8PinID);
				        	  PORTC|=(Copy_u8Pinvalue<<Copy_u8PinID);
				                  	  break;
				          case  DIO_PORTD:
				        	  PORTD &=~(1<<Copy_u8PinID);
				        	  PORTD|=(Copy_u8Pinvalue<<Copy_u8PinID);
				                  	  break;
				        }
				         local_enuErrorState=OK;

			}
			else
			{
				 local_enuErrorState=ES_OUT_OF_RANGE;
			}

		return local_enuErrorState;
}

ES_t enuSetTogPin(u8 Copy_u8PortID,u8 Copy_u8PinID)
{
	ES_t local_enuErrorState=NOT_OK;


	if (Copy_u8PortID <= DIO_PORTD && Copy_u8PinID <= DIO_PIN7)
		{
				 switch(Copy_u8PortID)
				        {
				          case  DIO_PORTA :
				        	  PORTA ^=(DIO_MASK_BTI <<Copy_u8PinID);
				        	  break;
				          case  DIO_PORTB:
				        	  PORTB ^=(DIO_MASK_BTI <<Copy_u8PinID);
				                  	  break;
				          case  DIO_PORTC:
				        	  PORTC ^=(DIO_MASK_BTI <<Copy_u8PinID);
				                  	  break;
				          case  DIO_PORTD:
				        	  PORTD ^=(DIO_MASK_BTI <<Copy_u8PinID);
				                  	  break;
				        }
				         local_enuErrorState=OK;

			}
			else
			{
				 local_enuErrorState=ES_OUT_OF_RANGE;
			}


		return local_enuErrorState;
}

ES_t enuGetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 *Copy_u8Portvalue)
{
	ES_t local_enuErrorState=NOT_OK;
	if(Copy_u8Portvalue !=NULL)
	{
	  if(Copy_u8PortID <= DIO_PORTD && Copy_u8PinID <= DIO_PIN7)
		{

		  switch(Copy_u8PortID)
	          {
		  		 case  DIO_PORTA:
				 *Copy_u8Portvalue =((PINA>> Copy_u8PinID) & DIO_MASK_BTI);
		  				  break;
		  		 case  DIO_PORTB:
		  			*Copy_u8Portvalue =((PINB>> Copy_u8PinID) & DIO_MASK_BTI);
		  				  break;
		  		case  DIO_PORTC:
		  			*Copy_u8Portvalue =((PINC>> Copy_u8PinID) & DIO_MASK_BTI);
		  				   break;
		  		case  DIO_PORTD:
		  			*Copy_u8Portvalue =((PIND>> Copy_u8PinID) & DIO_MASK_BTI);
		  				    break;
		  	}
              local_enuErrorState=OK;
		}
	  else
	  {
		  local_enuErrorState =ES_OUT_OF_RANGE;
	  }

	}
	else
	{
		local_enuErrorState=NULL_POINTER;
	}

		return local_enuErrorState;
}
