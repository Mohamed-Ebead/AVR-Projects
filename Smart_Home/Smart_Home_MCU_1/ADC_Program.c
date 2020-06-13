/*
 * ADC_Program.c
 *
 *  Created on: Feb 5, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include "Configuration.h"
#include "interface.h"
#include "registers.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "ADC_Interface.h"



/************************************************************/

extern u8 u8AdcChannel  ;


void vid_ADC_vid_Initialize (void) {

	ADMUX_REG =  0b01100000 ;     // VR : AVCC , LEFT SHIFT

	SET_BIT(ADCSRA_REG,ADEN)  ;    // ENABLE ADC ,
	(ADCSRA_REG) &= ~((1 << (0))|(1 << (1))|(1 << (2)) ) ; // PRESCALER = 2

	SET_BIT(ADCSRA_REG,ADIE)  ;    // ENABLE ADC INTERRUPT ,

}

/************************************************************/

void U8_ADC_U8_Read (u8 channel) {

		u8AdcChannel = channel ;

		channel &= 0b00000111;        // channel from 0 : 7(0b111)  ,& to neglect any bit more than 7
		ADMUX_REG &= 0b11100000;      // to save higher 3 bits as they are and set the rest to 0
		ADMUX_REG |= channel;         // Take the target channel

		SET_BIT(ADCSRA_REG,ADSC)  ;     // start conversion

}

/************************************************************/

