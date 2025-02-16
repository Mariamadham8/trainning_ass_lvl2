/*
 * EXTI_prog.c
 *
 *  Created on: Jan 5, 2025
 *      Author: Mariem
 */

#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"


#include"../EXTI/EXTI_priv.h"
#include"../EXTI/EXTI_config.h"

#include"../Interrupt.h"

static volatile void( *EXTI_ApfunINTFUN[3])(void*)={NULL,NULL,NULL};

void *EXTI_ApfunGenaricparameter[3]={NULL,NULL,NULL};  //عشاناباصي البراميترز لو موجودين كمان مش ادرس الفانكشن بس

ES_t EXTI_enuinit( EXTI_t *EXTI_AstrEXTIConfig)
{
	 ES_t LocalerrorStates= NOT_OK;
	 if(EXTI_AstrEXTIConfig !=NULL)
	 	 {
	 		 for(int i=0;i<3;i++)
	 		 {
	 			 if(EXTI_AstrEXTIConfig[i].EXTI_u8State==Active)
	 			 {
	 				 switch(i)
	 				 {
	 				   case 0:
	 					   GICR |=(1<<6);
	 					  MCUCR &= ~(1 << 3);
	 					   switch(EXTI_AstrEXTIConfig[i].EXTI_u8State)
	 					   {
	 					   	   case Falling_edge:
	 					   		 MCUCR |=(1<<1);
	 					   		   break;
	 					   	   case  Rising_edge:
	 					   		 MCUCR |=(3<<0);
	 					   		   break;
	 					   	   case Low_level:
	 					   		   break;
	 					   	   case  On_change:
	 					   		MCUCR |=(1<<0);
	 					   		   break;
	 					   	   default :
	 					   		LocalerrorStates=ES_OUT_OF_RANGE;

	 					   }
	 					   break;
	 				   case 1:
	 		               GICR |=(1<<7);
	 		              MCUCR &= ~(3 << 2);
	 		               switch(EXTI_AstrEXTIConfig[i].EXTI_u8State)
							   {
								   case Falling_edge:
									 MCUCR |=(1<<3);
									   break;
								   case  Rising_edge:
									 MCUCR |=(3<<2);
									   break;
								   case Low_level:
									   break;
								   case  On_change:
									MCUCR |=(1<<2);
									   break;
								   default :
									LocalerrorStates=ES_OUT_OF_RANGE;

							   }
	 				       break;
	 				   case 2:
	 				   	   GICR |=(1<<5);
	 				   	   MCUSCR &=~(1<<6);
	 				   	switch(EXTI_AstrEXTIConfig[i].EXTI_u8State)
						   {
							   case Falling_edge:
								   break;
							   case  Rising_edge:
								MCUSCR |=(1<<6);
								   break;
							   default :
								LocalerrorStates=ES_OUT_OF_RANGE;

						   }
	 				   	   break;

	 				 }

	 			 }
	 		 }

	 	 }
	 	 else
	 	 {
	 		 LocalerrorStates=NULL_POINTER;
	 	 }
	 return LocalerrorStates;

}


ES_t EXTI_enuSetSenceMOde( u8 CopypstrEXTI_ID,u8 Copy_u8Senselevel)
{
	 ES_t LocalerrorStates= NOT_OK;
		if(CopypstrEXTI_ID==0)
		{
			 switch(Copy_u8Senselevel)
			   {
				   case Falling_edge:
					 MCUCR |=(1<<1);
					   break;
				   case  Rising_edge:
					 MCUCR |=(3<<0);
					   break;
				   case Low_level:
					   break;
				   case  On_change:
					MCUCR |=(1<<0);
					   break;
				   default :
					LocalerrorStates=ES_OUT_OF_RANGE;

			   }
		}
		else if(CopypstrEXTI_ID==1)
		{
			 switch(Copy_u8Senselevel)
			   {
				   case Falling_edge:
					 MCUCR |=(1<<3);
					   break;
				   case  Rising_edge:
					 MCUCR |=(3<<2);
					   break;
				   case Low_level:
					   break;
				   case  On_change:
					MCUCR |=(1<<2);
					   break;
				   default :
					LocalerrorStates=ES_OUT_OF_RANGE;

			   }
		}
		else if(CopypstrEXTI_ID==2)
		{
			MCUSCR &=~(1<<6);
			switch(Copy_u8Senselevel)
			   {
				   case Falling_edge:
					   break;
				   case  Rising_edge:
					MCUSCR |=(1<<6);
					   break;
				   default :
					LocalerrorStates=ES_OUT_OF_RANGE;

			   }
		}
		 return LocalerrorStates;
}


ES_t EXTI_enuEnableINT(u8 CopypstrEXTI_ID)
{
	 ES_t LocalerrorStates= NOT_OK;
	 if(CopypstrEXTI_ID==0)
	 {
		 GICR |=(1<<6);
	 }
	 else if(CopypstrEXTI_ID==1)
	 {
		 GICR |=(1<<7);
	 }
	 else if(CopypstrEXTI_ID==2)
	 {
		 GICR |=(1<<5);
	 }
	 else
	 {
		 LocalerrorStates =ES_OUT_OF_RANGE;
	 }

		 return LocalerrorStates;
}
ES_t EXTI_enuDisableINT(u8 CopypstrEXTI_ID)
{
	 ES_t LocalerrorStates= NOT_OK;

	 if(CopypstrEXTI_ID==0)
		 {
			 GICR &=~(1<<6);
		 }
		 else if(CopypstrEXTI_ID==1)
		 {
			 GICR &=~(1<<7);
		 }
		 else if(CopypstrEXTI_ID==2)
		 {
			 GICR &=~(1<<5);
		 }
		 else
		 {
			 LocalerrorStates =ES_OUT_OF_RANGE;
		 }


		 return LocalerrorStates;
}

ES_t EXTI_enuCallBack(void (*Copy_pfunAppFun)(void),void *pvoiParameter,u8 CopypstrEXTI_ID)
{
	 ES_t LocalerrorStates= NOT_OK;
	if(Copy_pfunAppFun !=NULL &&CopypstrEXTI_ID <3)
	{
		EXTI_ApfunINTFUN[CopypstrEXTI_ID]=Copy_pfunAppFun;
		EXTI_ApfunGenaricparameter[CopypstrEXTI_ID]=pvoiParameter;

	}
	return LocalerrorStates;

}




ISR(VECT_INT0)
{
	if(EXTI_ApfunINTFUN[0] !=NULL)
	{
		EXTI_ApfunINTFUN[0](EXTI_ApfunGenaricparameter[0]);
	}
}

ISR(VECT_INT1)
{
	if(EXTI_ApfunINTFUN[1] !=NULL)
		{
			EXTI_ApfunINTFUN[1](EXTI_ApfunGenaricparameter[1]);
		}
}

ISR(VECT_INT2)
{
	if(EXTI_ApfunINTFUN[2] !=NULL)
		{
			EXTI_ApfunINTFUN[2](EXTI_ApfunGenaricparameter[2]);
		}

}
