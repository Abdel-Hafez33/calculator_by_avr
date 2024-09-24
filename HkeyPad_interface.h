/*
 * HkeyPad_interface.h
 *
 *  Created on: Sep 21, 2024
 *      Author: Abdel Hafez
 */


#ifndef HKEYPAD_INTERFACE_H_
#define HKEYPAD_INTERFACE_H_
#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Calc.h"
//modes switches
#define pressed    0
#define notpressd  1
//define switches
#define not_key 0
#define key1    1
#define key2    2
#define key3    3
#define key4    4
#define key5    5
#define key6    6
#define key7    7
#define key8    8
#define key9    9
#define key10   10
#define key11   11
#define key12   12
#define key13   13
#define key14   14
#define key15   15
#define key16   16
//function prtotype 
void Hkpd_voidInitKeypad(void);
u8 Hkpd_u8GetKeyPressed (void);








#endif /* HKEYPAD_INTERFACE_H_ */
