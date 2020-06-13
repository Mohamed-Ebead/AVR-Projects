/*
 * KEYPAD_Prog.c
 *
 *  Created on: Aug 30, 2019
 *      Author: Mohamed_Ebead
 */


#include "STD_Types.h"
#include<util/delay.h>


#include "DIO_int.h"
#include "KEYPAD_int.h"


#define KPD_PORT  PORTD_DIO



u8 KPD_u8GetPressedKey(void){


	u8 NB =0 	;     //  returned pressed button number
	u8 i , j ;


	const u8 arr[4][4]= {{1,5,9,13},{2,6,10,14},{3,7,11,15},{4,8,12,16}};


//  input Rows loop
	for(i = 0 ;i <4 ;i ++){

		DIO_SetPinValue(KPD_PORT , i , LOW);

// Output coulomns loop
		for(j =4 ;j <8 ;j ++){

			if(!(DIO_GetPinValue(KPD_PORT, j ))){

				NB=arr[i][j - 4 ] ;

				 while (!(DIO_GetPinValue(KPD_PORT, j))) ;
				 _delay_ms(20);
			}
			else {

			}

		}

		DIO_SetPinValue(KPD_PORT , i , HIGH);
	}

	return NB ;

}
