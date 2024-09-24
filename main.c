/*
 * main.c
 *
 *  Created on: Sep 22, 2024
 *      Author: Abdel Hafez
 */
#include "MDIO_Interface.h"
#include"HLCD_interface.h"
#include "HLCD_Private.h"
#include "avr/delay.h"
#include "HkeyPad_interface.h"
void main()
{
    MDIO_voidSetPortDirection(PORTA,full_port);
    MDIO_voidSetPinDirection(PORTC,PIN0,OUTPOT);
     MDIO_voidSetPinDirection(PORTC,PIN1,OUTPOT);
    MDIO_voidSetPinDirection(PORTC,PIN2,OUTPOT);
    HLCD_VoidInitLCD();
    Hkpd_voidInitKeypad();
    u8 pressed_key=intial_counter;
    u8 num_character=intial_counter;
    char contor[16];
    u8 frist_operant=num0;
    u8 second_operant=num0;
    u8 result=num0;
    u8 counter=num0;


    while(1)
    {

        HLCD_Void_GetArrayAndNumOfElement(contor,&num_character,&result);
        
        Hlcd_Voidcalc(contor,num_character);
    

        while(pressed_key==key12)
        {
            pressed_key=Hkpd_u8GetKeyPressed();
        }
    

        
   

    }


}

