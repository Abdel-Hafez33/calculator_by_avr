/*

 * MDIO_Program.c
 *
 *  Created on: Sep 8, 2024
 *      Author: Abdel Hafez
 */
#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Calc.h"
#include "MDIO_Private.h"
#include "MDIO_Regester.h"
#include "MDIO_Config.h"
#include "MDIO_Interface.h"


	void MDIO_voidSetPinDirection (u8 A_u8Portnumber, u8 A_u8Pinnumber , u8 A_u8DIRICTION )
	{

        if(A_u8Portnumber < PORTA || A_u8Portnumber > PORTD){
			/* Wrong PORT */
	}else if(A_u8Pinnumber < PIN0 || A_u8Pinnumber > PIN7){
			/* Wrong PIN */
	}else if (A_u8DIRICTION < INPUT || A_u8DIRICTION > OUTPOT){
			/* Wrong Direction */
	}else{
		
          switch (A_u8Portnumber){
			case PORTA:
			switch (A_u8DIRICTION)
			{
				case OUTPOT:
				Set_Bit(u8DDRA_Regester,A_u8Pinnumber);
                break;

				case INPUT:
				Clr_Bit (u8DDRA_Regester,A_u8Pinnumber);

				break;
			}
			break;

            case PORTB:
			switch (A_u8DIRICTION)
			{
				case OUTPOT:
				Set_Bit(u8DDRB_Regester,A_u8Pinnumber);
                break;

				case INPUT:
				Clr_Bit (u8DDRB_Regester,A_u8Pinnumber);

				break;
			}
			break;

			case PORTC:
			switch (A_u8DIRICTION)
			{
				case OUTPOT:
				Set_Bit(u8DDRC_Regester,A_u8Pinnumber);
                break;

				case INPUT:
				Clr_Bit (u8DDRC_Regester,A_u8Pinnumber);

				break;
			}
			break;

			case PORTD:
			switch (A_u8DIRICTION)
			{
				case OUTPOT:
				Set_Bit(u8DDRD_Regester,A_u8Pinnumber);
                break;

				case INPUT:
				Clr_Bit (u8DDRD_Regester,A_u8Pinnumber);

				break;
			}
			break;
			
		  }
		}
	}



	

	void MDIO_voidSetPinValue(u8 A_u8PortID, u8 A_u8PinID, u8 A_u8Value){
	if(A_u8PortID < PORTA || A_u8PortID > PORTD){
			/* Wrong PORT */
	}else if(A_u8PinID < PIN0 || A_u8PinID > PIN7){
			/* Wrong PIN */
	}else if (A_u8Value < LOW || A_u8Value > HIGH){
			/* Wrong Value */
	}else{

		switch (A_u8PortID){

		case PORTA:
			switch(A_u8Value){
				case LOW:
					Clr_Bit(u8PORTA_Regester, A_u8PinID);
					break;
				case HIGH:
					Set_Bit(u8PORTA_Regester, A_u8PinID);
					break;
			}
			break;
		case PORTB:
			switch(A_u8Value){
				case LOW:
					Clr_Bit(u8PORTB_Regester , A_u8PinID);
					break;
				case HIGH:
					Set_Bit(u8PORTB_Regester , A_u8PinID);
					break;
			}
			break;
		case PORTC:
			switch(A_u8Value){
				case LOW:
					Clr_Bit(u8PORTC_Regester , A_u8PinID);
					break;
				case HIGH:
					Set_Bit(u8PORTC_Regester , A_u8PinID);
					break;
			}
			break;
		case PORTD:
			switch(A_u8Value){
				case LOW:
					Clr_Bit(u8PORTD_Regester , A_u8PinID);
					break;
				case HIGH:
					Set_Bit(u8PORTD_Regester , A_u8PinID);
					break;
			}
			break;
		}
	}
}

		
	ErrorState_t MDIO_StatusGetPinValue(u8 A_u8PortID, u8 A_u8PinID, u8* AP_u8ValuePointer) {

	ErrorState_t L_StatusRet = Return_OK;

	if ((A_u8PortID < PORTA) || (A_u8PortID > PORTD)) {

		/* Wrong Port */
		L_StatusRet = Return_NOK;


	} else if ((A_u8PinID < PIN0) || (A_u8PinID > PIN7)) {

		/* Wrong Pin */
		L_StatusRet = Return_NOK;


	} else {

		switch (A_u8PortID) {

		case PORTA:*AP_u8ValuePointer = Get_Bit(u8PINA_Regester, A_u8PinID); break;

		case PORTB:*AP_u8ValuePointer = Get_Bit(u8PINB_Regester, A_u8PinID); break;

		case PORTC:*AP_u8ValuePointer = Get_Bit(u8PINC_Regester, A_u8PinID); break;

		case PORTD:*AP_u8ValuePointer = Get_Bit(u8PIND_Regester, A_u8PinID); break;

		}

		

	}

	return L_StatusRet;

}
		void MDIO_voidSetPortDirection(u8 A_u8PortID,  u8 A_u8direction)
		{
		
			
				switch(A_u8PortID)
				{ 
					case PORTA:
					 u8DDRA_Regester=A_u8direction; break;
						
					case PORTB:
				    u8DDRB_Regester=A_u8direction; break;

						
				case PORTC:
				    u8DDRC_Regester=A_u8direction; break;
                case PORTD:
				    u8DDRD_Regester=A_u8direction; break;

                    default:
                    break;
				}

		}
		void MDIO_voidSetPortValue(u8 A_u8PortID,  u8 A_u8value)
		{
		
			
				switch(A_u8PortID)
				{ 
					case PORTA: u8PORTA_Regester=A_u8value; break;
					case PORTB: u8PORTB_Regester=A_u8value; break;
					case PORTC: u8PORTC_Regester=A_u8value; break;
					case PORTD: u8PORTD_Regester=A_u8value; break;
					
                    default:
                    break;
				}

		}
		void MDIO_voidTogglePin(u8 A_u8PortID,  u8 A_u8PinNumber)
		{
			switch (A_u8PortID)
			{
				case PORTA: Tog_Bit(u8PORTA_Regester,A_u8PinNumber); break;
				case PORTB: Tog_Bit(u8PORTB_Regester,A_u8PinNumber); break;
				case PORTC: Tog_Bit(u8PORTC_Regester,A_u8PinNumber); break;
				case PORTD: Tog_Bit(u8PORTD_Regester,A_u8PinNumber); break;
				default :
				break;


			}
		}


