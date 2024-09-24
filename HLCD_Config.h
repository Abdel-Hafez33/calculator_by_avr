/*
 * HLCD_Config.h
 *
 *  Created on: Sep 22, 2024
 *      Author: Abdel Hafez
 */

#ifndef HLCD_CONFIG_H_
#define HLCD_CONFIG_H_
#include"MDIO_Interface.h"

/**************************choose port data************* */
#define port_data_lcd                 PORTA
/***************************CHOOSE CONTROL PINS AND PORT********** */
#define port_control_lcd             PORTC
#define RS                           PIN0
#define rw                           PIN1
#define en                           PIN2     




#endif /* HLCD_CONFIG_H_ */
