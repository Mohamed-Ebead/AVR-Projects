/*
 * EXT_INT_ISR.c
 *
 *  Created on: Feb 11, 2020
 *      Author: Mohamed  Ebead
 */


#include <avr/interrupt.h>
#include <util/delay.h>
#include "STD_Types.h"

#include "DIO_int.h"
#include "Configuration.h"








// use one variable for laylool



extern u8 u8PeopleInside ;

/**************************************************************************/

// MAKE ISR SHORTER (CALL BACK FUN )

ISR(INT0_vect) {

	DIO_SetPinValue(PORTB_DIO, DOOR1 , HIGH);       // OPEN DOOR
	DIO_SetPinValue(PORTB_DIO, DOOR2, LOW);
	_delay_ms (3000) ;


	DIO_SetPinValue(PORTB_DIO, DOOR1, LOW);           // CLOSE DOOR
	DIO_SetPinValue(PORTB_DIO, DOOR2, HIGH);
	_delay_ms (3000) ;


	DIO_SetPinValue(PORTB_DIO, DOOR1, LOW);          // IDLE
	DIO_SetPinValue(PORTB_DIO, DOOR2, LOW);

	u8PeopleInside ++ ;

}

/**************************************************************************/

ISR(INT1_vect) {

	DIO_SetPinValue(PORTB_DIO, DOOR1 , HIGH);       // OPEN DOOR
	DIO_SetPinValue(PORTB_DIO, DOOR2, LOW);
	_delay_ms (3000) ;


	DIO_SetPinValue(PORTB_DIO, DOOR1, LOW);           // CLOSE DOOR
	DIO_SetPinValue(PORTB_DIO, DOOR2, HIGH);
	_delay_ms (3000) ;


	DIO_SetPinValue(PORTB_DIO, DOOR1, LOW);          // IDLE
	DIO_SetPinValue(PORTB_DIO, DOOR2, LOW);


	// EDIT SEQUENE
	if (u8PeopleInside!=0) {
	u8PeopleInside -- ;
	}

	else {
		u8PeopleInside = 0 ;
	}

}




/************************************************************/

