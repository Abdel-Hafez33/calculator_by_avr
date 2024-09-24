/*
 * HLCD_Pogram.c
 *
 *  Created on: Sep 22, 2024
 *      Author: Abdel Hafez
 */
#include"HLCD_Config.h"
#include"HLCD_interface.h"
#include"HLCD_Private.h"
#include"MDIO_Interface.h"
#include <avr/delay.h>
#include "HkeyPad_interface.h"

void HLCD_VoidCSendCommand (u8 A_u8Command)
{
   //make rs zero for command
   MDIO_voidSetPinValue(port_control_lcd,RS,LOW);
   //make rw one to write data
   MDIO_voidSetPinValue(port_control_lcd,rw,LOW);
   //send data 
   MDIO_voidSetPortValue(port_data_lcd,A_u8Command);
   // make enable 1
   MDIO_voidSetPinValue(port_control_lcd,en,HIGH);
   //delay
   _delay_ms(2); 
   //make enable low
      MDIO_voidSetPinValue(port_control_lcd,en,LOW);
         _delay_ms(2); 
   

}
void HLCD_VoidCSendData (u8 A_u8Data)
{
   //make rs zero for command
   MDIO_voidSetPinValue(port_control_lcd,RS,HIGH);
   //make rw one to write data
   MDIO_voidSetPinValue(port_control_lcd,rw,LOW);
   //send data 
   MDIO_voidSetPortValue(port_data_lcd,A_u8Data);
   // make enable 1
   MDIO_voidSetPinValue(port_control_lcd,en,HIGH);
   //delay
   _delay_ms(2); 
   //make enable low
      MDIO_voidSetPinValue(port_control_lcd,en,LOW);

      _delay_ms(2); 


}
void HLCD_VoidInitLCD ()
{
    MDIO_voidSetPinDirection(port_control_lcd,RS,OUTPOT);
    MDIO_voidSetPinDirection(port_control_lcd,rw,OUTPOT);
    MDIO_voidSetPinDirection(port_control_lcd,en,OUTPOT);
    MDIO_voidSetPortDirection(port_data_lcd,full_port);


    _delay_ms(40);
    //function set 5x8 2lines
    HLCD_VoidCSendCommand(Function_Set_row2_5X8);
    	_delay_ms(40);

    //dispay
    HLCD_VoidCSendCommand(dispay_on_with_cursol);
	_delay_ms(40);

    //Clear display
    HLCD_VoidCSendCommand(display_clear);
	_delay_ms(40);

}

void HLCD_VoidDisplay_String(const char* word,u8 A_u8rowNum,u8 A_u8colNum)
{
    u8 local_address=equation_local_address;
    //if after 0x15 go to row 2
    if ((local_address<0x40)&&(local_address>0x15))
    {
             HLCD_VoidGoto(1,0);
    }
    //wrong location go to row1
 if ((local_address>0x67))
    {
             HLCD_VoidGoto(0,0);
    }

    u8 counter=intial_counter;
    HLCD_VoidGoto(A_u8rowNum,A_u8colNum);


    for (counter=intial_counter;word[counter]!='\0';counter++)
    {
        if (local_address==15)
        {
         HLCD_VoidGoto(1,0);
         local_address=0x40;
        }
        if (local_address==0x50)
        {
          HLCD_VoidGoto(0,0);
          local_address=0;

        }
        HLCD_VoidCSendData(word[counter]);
        local_address++;
    }
   
    
}
void HLCD_VoidGoto(u8 A_u8rowNum,u8 A_u8colNum)
{
    u8 local_address=equation_local_address+128;
    HLCD_VoidCSendCommand(local_address);
}
void HLCD_VoidDisplaySpecialCharacter (u8 *P_u8pattern,u8 A_u8NumOfBlock,u8 A_u8ROW_Num,u8 A_u8COLNum )
{
    //calculate block address
    u8 L_u8Loction_Address_In_Cgrom =block_bits*A_u8NumOfBlock;
    u8 L_u8location_ponter_in_block=intial_counter;
    //go to cgram
    HLCD_VoidCSendCommand(L_u8Loction_Address_In_Cgrom+set_pin6_on);
    //write in cgram
    for(L_u8location_ponter_in_block=intial_counter;L_u8location_ponter_in_block<block_bits;L_u8location_ponter_in_block++)
    {
          HLCD_VoidCSendData(P_u8pattern[L_u8location_ponter_in_block]);
    }
    //go to ddram
    HLCD_VoidGoto(A_u8ROW_Num,A_u8COLNum);
    //write in ddram number block to access cgram
    HLCD_VoidCSendData(A_u8NumOfBlock);



}
void DisplayVariable (u16 A_u16var)
{
    u8 *array_of_character;
    s8 counter=intial_counter;
    u8 counter_element=intial_counter;
    array_of_character=(u8*)malloc(8*sizeof(A_u16var));
    if (A_u16var==0)
    {
        HLCD_VoidCSendData('0');
    }
    while (A_u16var!=0)
    {
        array_of_character[counter_element]=(A_u16var%10);
        A_u16var=A_u16var/10;
        counter_element++;
    }
    
    for(counter=(counter_element-1);counter>=intial_counter;counter--)
    {
        switch(array_of_character[counter])
    {
        case num0 :  HLCD_VoidCSendData('0');break;
        case num1 :  HLCD_VoidCSendData('1');break;
        case num2 :  HLCD_VoidCSendData('2');break;
        case num3 :  HLCD_VoidCSendData('3');break;
        case num4 :  HLCD_VoidCSendData('4');break;
        case num5 :  HLCD_VoidCSendData('5');break;
        case num6 :  HLCD_VoidCSendData('6');break;
        case num7 :  HLCD_VoidCSendData('7');break;
        case num8 :  HLCD_VoidCSendData('8');break;
        case num9 :  HLCD_VoidCSendData('9');break;
        default:break;
        


    }
    }

}
void HLCD_VoidKpdDisplay(u8 A_key_pressed,char *display_character)
{

switch(A_key_pressed)
{
 case key1 : HLCD_VoidCSendData('7'); *display_character=7; break; 
 case key2 : HLCD_VoidCSendData('4'); *display_character=4; break; 
 case key3 : HLCD_VoidCSendData('1'); *display_character=1; break; 
 case key4 :  HLCD_VoidCSendCommand(display_clear); _delay_ms(40); HLCD_VoidGoto(row1,col1); break; 
 case key5 : HLCD_VoidCSendData('8'); *display_character=8; break; 
 case key6 : HLCD_VoidCSendData('5'); *display_character=5; break; 
 case key7 : HLCD_VoidCSendData('2'); *display_character=2; break; 
 case key8 : HLCD_VoidCSendData('0'); *display_character=0; break; 
 case key9 : HLCD_VoidCSendData('9'); *display_character=9; break; 
 case key10: HLCD_VoidCSendData('6'); *display_character=6; break; 
 case key11: HLCD_VoidCSendData('3'); *display_character=3; break; 
 case key12: HLCD_VoidCSendData('='); *display_character='=';break; 
 case key13: HLCD_VoidCSendData('/'); *display_character='/'; break; 
 case key14: HLCD_VoidCSendData('*'); *display_character='*'; break; 
 case key15: HLCD_VoidCSendData('-'); *display_character='-'; break; 
 case key16: HLCD_VoidCSendData('+'); *display_character='+'; break;  

}
}
//calculate func 
void Hlcd_Voidcalc(char* contor,u8 num_character)
{
    u8 frist_operant=0;
    u8 second_operant=0;
    u8 result=0;
    u8 counter=0;
    for (counter=0;counter<(num_character-1);counter++)
{
    if (contor[counter]=='+')
    {
        second_operant=intial_counter;
        frist_operant=result;
        u8 flag_mlti_division=intial_counter;
    
    
        while(counter<(num_character-2))
        {
            if(contor[counter+1]=='+')
            {

                result=second_operant+frist_operant;
                frist_operant=result;
                second_operant=intial_counter;
                counter++;


            }
            else if(contor[counter+1]=='-')
            {
                
               
                break;


            }
            else if (contor[counter+1]=='*')
            {
                u8 third_operant=intial_counter;
                counter++;
                flag_mlti_division=1;
                while((contor[counter+1]!='*')&&(contor[counter+1]!='+')&&(contor[counter+1]!='-')&&(contor[counter+1]!='/')&&(contor[counter+1]!='='))
                {
                      third_operant=third_operant*10+contor[counter+1];
                      counter++;
                }
                result=third_operant*second_operant+frist_operant;
               

                break;
            }
            else if (contor[counter+1]=='/')
            {
                u8 third_operant=intial_counter;
                counter++;
                flag_mlti_division=1;
                while((contor[counter+1]!='*')&&(contor[counter+1]!='+')&&(contor[counter+1]!='-')&&(contor[counter+1]!='/')&&(contor[counter+1]!='='))
                {
                      third_operant=third_operant*10+contor[counter+1];
                      counter++;
                }
                result=second_operant/third_operant+frist_operant;
               

                break;
            }
            
            
            else {
            second_operant=second_operant*10+contor[counter+1];
            counter++;
            }
        }
        if (flag_mlti_division==intial_counter){
       
        result=second_operant+frist_operant;
        }
        }
        // suptraction
        else if (contor[counter]=='-')
    {
        second_operant=intial_counter;
        frist_operant=result;
        u8 flag_mlti_division=intial_counter;
    
    
        while(counter<(num_character-2))
        {
            if(contor[counter+1]=='+')
            {

                break;


            }
            else if(contor[counter+1]=='-')
            {
                
                
               
                result=frist_operant-second_operant;
                frist_operant=result;
                second_operant=intial_counter;
                counter++;


            }
            else if (contor[counter+1]=='*')
            {
                u8 third_operant=intial_counter;
                counter++;
                flag_mlti_division=1;
                while((contor[counter+1]!='*')&&(contor[counter+1]!='+')&&(contor[counter+1]!='-')&&(contor[counter+1]!='/')&&(contor[counter+1]!='='))
                {
                      third_operant=third_operant*10+contor[counter+1];
                      counter++;
                }
                result=-(third_operant*second_operant)+frist_operant;
               

                break;
            }
            else if (contor[counter+1]=='/')
            {
                u8 third_operant=intial_counter;
                counter++;
                flag_mlti_division=1;
                while((contor[counter+1]!='*')&&(contor[counter+1]!='+')&&(contor[counter+1]!='-')&&(contor[counter+1]!='/')&&(contor[counter+1]!='='))
                {
                      third_operant=third_operant*10+contor[counter+1];
                      counter++;
                }
                result=-(second_operant/third_operant)+frist_operant;
               

                break;
            }
            
            
            else {
            second_operant=second_operant*10+contor[counter+1];
            counter++;
            }
        }
        if (flag_mlti_division==intial_counter){
       
        result=frist_operant-second_operant;
        }
        }
        //multiplay
        else  if (contor[counter]=='*')
    {
        second_operant=0;
        frist_operant=result;
    
    
        while(counter<(num_character-2))
        {if(contor[counter+1]=='+')
            {

                break;


            }
            else if(contor[counter+1]=='-')
            {

                break;


            }
             else if (contor[counter+1]=='*')
            {
                u8 third_operant=intial_counter;
                counter++;
               
                while((contor[counter+1]!='*')&&(contor[counter+1]!='+')&&(contor[counter+1]!='-')&&(contor[counter+1]!='/')&&(contor[counter+1]!='='))
                {
                      third_operant=third_operant*10+contor[counter+1];
                      counter++;
                }
                result=(third_operant*second_operant)*frist_operant;
                frist_operant=result;
                second_operant=num1;
               

                break;
            }
            else if (contor[counter+1]=='/')
            {
                u8 third_operant=intial_counter;
                counter++;
            
                while((contor[counter+1]!='*')&&(contor[counter+1]!='+')&&(contor[counter+1]!='-')&&(contor[counter+1]!='/')&&(contor[counter+1]!='='))
                {
                      third_operant=third_operant*10+contor[counter+1];
                      counter++;
                }
                result=frist_operant*(second_operant/third_operant);
                frist_operant=result;
                second_operant=num1;
               

                break;
            }
            
            else{
            
            second_operant=second_operant*10+contor[counter+1];
            counter++;
            }
            
        }
        result=frist_operant*second_operant;
        
        }
        //division
        else  if (contor[counter]=='/')
    {
        second_operant=0;
        frist_operant=result;
    
    
        while(counter<(num_character-2))
        {if(contor[counter+1]=='+')
            {

                break;


            }
            else if(contor[counter+1]=='-')
            {

                break;


            }
             else if (contor[counter+1]=='*')
            {
                u8 third_operant=intial_counter;
                counter++;
               
                while((contor[counter+1]!='*')&&(contor[counter+1]!='+')&&(contor[counter+1]!='-')&&(contor[counter+1]!='/')&&(contor[counter+1]!='='))
                {
                      third_operant=third_operant*10+contor[counter+1];
                      counter++;
                }
                result=frist_operant/second_operant*third_operant;
                frist_operant=result;
                second_operant=num1;
               

                break;
            }
            else if (contor[counter+1]=='/')
            {
                u8 third_operant=intial_counter;
                counter++;
            
                while((contor[counter+1]!='*')&&(contor[counter+1]!='+')&&(contor[counter+1]!='-')&&(contor[counter+1]!='/')&&(contor[counter+1]!='='))
                {
                      third_operant=third_operant*10+contor[counter+1];
                      counter++;
                }
                result=frist_operant/second_operant/third_operant;
                frist_operant=result;
                second_operant=num1;
               

                break;
            }
            
            else{
            
            second_operant=second_operant*10+contor[counter+1];
            counter++;
            }
            
        }
        result=frist_operant/second_operant;
        
        }
    else {
    result=contor[counter]+result*10;
    }
    if (contor[counter+1]=='=')
    {
        DisplayVariable(result);
    }
}
}
//func get array of character
void HLCD_Void_GetArrayAndNumOfElement(char*contor  ,u8 *num_character,u8 *result)
{
        u8 pressed_key=intial_counter;
        u8 num_of_character=num0;
        while (pressed_key!=key12)
        {
       if( pressed_key=Hkpd_u8GetKeyPressed()){
          if(pressed_key==key4)
          {
        HLCD_VoidCSendCommand(display_clear); 
        _delay_ms(40); 
        HLCD_VoidGoto(row1,col1); 
        num_of_character=0;
        result=0;
        } 
        else{
        HLCD_VoidKpdDisplay(pressed_key,&contor[num_of_character]);
        num_of_character++;
        }
       }
        }
        *(num_character)=num_of_character;

}


