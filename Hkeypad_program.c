/*
 * Hkeypad_program.c
 *
 *  Created on: Sep 21, 2024
 *      Author: Abdel Hafez
 */
#include"MDIO_Interface.h"
#include "HkeyPad_interface.h"
#include "HKeypad_config.h"
#include "Hkeypad_private.h"

u8 row_array[4]={row1,row2,row3,row4};
u8 colum_array[4]={colum1,colum2,colum3,colum4};
void Hkpd_voidInitKeypad(void)
{
    u8 counter =intial_counter;
     //make row input pull up
    for(counter;counter<num_row;counter++)
    {
        MDIO_voidSetPinDirection(row_port,row_array[counter],INPUT);
        MDIO_voidSetPinValue(row_port,row_array[counter],HIGH);
    }
    //make colum  high
    counter=intial_counter;
    for(counter;counter<num_colum;counter++)
    {
         MDIO_voidSetPinDirection(colum_port,colum_array[counter],OUTPOT);
         MDIO_voidSetPinValue(colum_port,colum_array[counter],HIGH);
    }

    
}
u8 Hkpd_u8GetKeyPressed (void)
{
    u8 row_counter   =intial_counter;
    u8 colum_counter =intial_counter;
    u8 staues_key    =notpressd;
    u8 pressed_key   =not_key;
    for(colum_counter=intial_counter;colum_counter<num_colum;colum_counter++)
    {
        MDIO_voidSetPinValue(colum_port,colum_array[colum_counter],LOW);
        for(row_counter=intial_counter;row_counter<num_row;row_counter++)
        {
            MDIO_StatusGetPinValue(row_port,row_array[row_counter],&staues_key);
            while (staues_key==pressed)
            {
                pressed_key=PressedKeyEqn;
            MDIO_StatusGetPinValue(row_port,row_array[row_counter],&staues_key);
            }
        }
        MDIO_voidSetPinValue(colum_port,colum_array[colum_counter],HIGH);

    }
    return pressed_key;
    
}
