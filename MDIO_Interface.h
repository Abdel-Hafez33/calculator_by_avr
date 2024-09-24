/*
 * MDIO_Interface.h
 *
 *  Created on: Sep 8, 2024
 *      Author: Abdel Hafez
 */

#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_
#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Calc.h"

 //FUNCTION PROTOTYPE
void MDIO_voidSetPinDirection (u8 A_u8Portnumber, u8 A_u8Pinnumber,u8 A_u8DIRICTION);
void MDIO_voidSetPinValue(u8 A_u8PortID, u8 A_u8PinID, u8 A_u8Value);
void MDIO_voidSetPortValue(u8 A_u8PortID,  u8 A_u8value);
void MDIO_voidTogglePin(u8 A_u8PortID,  u8 A_u8PinNumber);
void MDIO_voidSetPortDirection(u8 A_u8PortID,  u8 A_u8direction);

//defention port number

#define PORTA 1
#define PORTB 2
#define PORTC 3
#define PORTD 4

//define diriction staties

#define INPUT  0
#define OUTPOT 1

/* Values Definition */
#define LOW   0
#define HIGH  1

//defintion pins
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
// enum
typedef enum{
	Return_OK,
	Return_NOK,
	Return_NULL,
}ErrorState_t;
ErrorState_t MDIO_StatusGetPinValue(u8 A_u8PortID, u8 A_u8PinID, u8* AP_u8ValuePointer);
//full_port
#define full_port 0xff
#define femp_port 0x00



#endif /* MDIO_INTERFACE_H_ */
