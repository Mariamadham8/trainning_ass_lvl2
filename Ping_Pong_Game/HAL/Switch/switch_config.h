/*
 * switch_config.h
 *
 *  Created on: Oct 14, 2024
 *      Author: Mariem
 */

#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_


#define SW_NUM		2
typedef struct
{
	u8 SW_PortID;
	u8 SW_PinID;
	u8 SW_Status;
}SW_t;

#endif /* SWITCH_CONFIG_H_ */
