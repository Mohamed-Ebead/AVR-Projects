/*
 * App.c
 *
 *  Created on: 20 January 2020
 *      Author: Mohamed Ebead
 */

#include "DIO_int.h"
#include "Registers.h"

#include "STD_Types.h"


void main (void) {


	UART_Init();

	u8 res=0;

		DIO_VidSetPortDirection(PORTA_DIO,0xFF);

		while(1)
		{
			res=UART_GetChar();
			if (res == 'a')
			{
				DIO_VidSetPortValue(PORTA_DIO,0xFF);
			}
			else if (res == 'b')
			{
				DIO_VidSetPortValue(PORTA_DIO,0x00);

			}

		}
}

