/*
 * HKeypad_config.h
 *
 *  Created on: Sep 21, 2024
 *      Author: Abdel Hafez
 */

#ifndef HKEYPAD_CONFIG_H_
#define HKEYPAD_CONFIG_H_
#include "MDIO_Interface.h"

/***************select mode*******************
 * 1- seven_segment
 * 2_lcd
 */
#define mode_keyPad lcd 
/***************mode seven segment**************** */
/**************selct two port for seven segment *********** */
#define port_rssd                   PORTB //right
#define port_lssd                   PORTA //right

/*********************select row port******** */
#define row_port                     PORTD
/*****************pins raw*********************/
#define row1                         PIN0
#define row2                         PIN1
#define row3                         PIN2
#define row4                         PIN3
/******************select culom port******** */
#define colum_port PORTD
/*****************pins culoms*********************/
#define colum1                      PIN4
#define colum2                      PIN5
#define colum3                      PIN6
#define colum4                      PIN7






#endif /* HKEYPAD_CONFIG_H_ */
