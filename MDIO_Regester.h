/*
 * MDIO_Regester.h
 *
 *  Created on: Sep 8, 2024
 *      Author: Abdel Hafez
 */

#ifndef MDIO_REGESTER_H_
#define MDIO_REGESTER_H_
#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Calc.h"

// REGESTER IN PORTA
#define u8DDRA_Regester *((volatile u8 * )0x3A)
#define u8PORTA_Regester *((volatile u8 * )0x3B)
#define u8PINA_Regester *((volatile u8 * )0x39)

//REGESTER IN PORT B
#define u8DDRB_Regester *((volatile u8 * )0x37)
#define u8PORTB_Regester *((volatile u8 * )0x38)
#define u8PINB_Regester *((volatile u8 * )0x36)

//REGESTER IN PORT C
#define u8DDRC_Regester *((volatile u8 * )0x34)
#define u8PORTC_Regester *((volatile u8 * )0x35)
#define u8PINC_Regester *((volatile u8 * )0x33)

//REGESTER IN PORT D
#define u8DDRD_Regester *((volatile u8 * )0x31)
#define u8PORTD_Regester *((volatile u8 * )0x32)
#define u8PIND_Regester *((volatile u8 * )0x30)





#endif /* MDIO_REGESTER_H_ */
