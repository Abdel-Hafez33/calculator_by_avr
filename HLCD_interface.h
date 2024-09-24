/*
 * HLCD_interface.h
 *
 *  Created on: Sep 22, 2024
 *      Author: Abdel Hafez
 */

#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_
#include"MDIO_Interface.h"
/*********************macros for comments*****************/
#define Function_Set_row1_5X8         0b00110000
#define Function_Set_row2_5X8         0b00111000
#define dispay_on_with_cursol         0b00001111
#define dispay_on_without_cursol      0b00001100
#define display_clear                 0b00000001
//functions
void HLCD_VoidCSendCommand (u8 A_u8Command);
void HLCD_VoidCSendData (u8 A_u8Data);
void HLCD_VoidInitLCD ();
void HLCD_VoidDisplay_String(const char* word,u8 A_u8rowNum,u8 A_u8colNum);
void HLCD_VoidGoto(u8 A_u8rowNum,u8 A_u8colNum);
void HLCD_VoidDisplaySpecialCharacter (u8 *P_u8pattern,u8 A_u8NumOfBlock,u8 A_u8ROW_Num,u8 A_u8COLNum );
void DisplayVariable (u16 A_u16var);
void HLCD_VoidKpdDisplay(u8 A_key_pressed,char *display_character);
void Hlcd_Voidcalc(char* contor,u8 num_character);
void HLCD_Void_GetArrayAndNumOfElement(char*contor  ,u8 *num_character,u8 *result);







//defination arabic characters

#define character1     ALEF 
//rows
#define row1      0
#define row2      1
#define col1      0
#define col2      1
#define col3      2
#define col4      3
#define col5      4
#define col6      5
#define col7      6
#define col8      7
#define col9      8
#define col10     9
#define col11     10
#define col12     11
#define col13     12
#define col14     13
#define col15     14
#define col16     15
//defination nambers
#define num0      0
#define num1      1
#define num2      2
#define num3      3
#define num4      4
#define num5      5
#define num6      6
#define num7      7
#define num8      8
#define num9      9










//
#define intial_counter 0



#endif /* HLCD_INTERFACE_H_ */
