/*
 * I2C_config.h
 *
 *  Created on: Jun 2, 2025
 *      Author: Mariem
 */

#ifndef MCAL_I2C_I2C_CONFIG_H_
#define MCAL_I2C_I2C_CONFIG_H_

#define BitRate(IIC_Speed)   ((F_CPU - 16UL * (IIC_Speed)) / (2UL * (IIC_Speed) * (IIC_Pres)))

#define IIC_Mode Master
#define IIC_Speed 100000ul
#define IIC_Pres  1ul
#define IIC_Node_ADD   2 //2->118
#define IIC_Genral_Call   0
#endif /* MCAL_I2C_I2C_CONFIG_H_ */
