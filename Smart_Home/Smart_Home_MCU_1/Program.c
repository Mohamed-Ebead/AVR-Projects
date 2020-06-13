/*
 * Program.c
 *
 *   Created on: 20 January 2020
 *      Author: Mohamed Ebead
 */


#include "STD_TYPES.h"
#include "Configuration.h"
#include "interface.h"
#include "registers.h"
#include "BIT_MATH.h"
#include "interface.h"
#include "APP_Config.h"

#include "DIO_int.h"
#include "ADC_interface.h"


extern u16 u16Temp ;
extern u8 u8Lumen ;
extern u8 u8_TMP_Read ;
extern u8 u8_LDR_Read ;
extern u8 u8AlarmStatus ;

/************************************************************/


void vid_DIO_vid_SetDioDirections (void) {

/*********************** Analog Input *************************/
	DIO_SetPinDirection (PORTA_DIO,TEMP_SENSOR,INPUT) ;
	DIO_SetPinDirection (PORTA_DIO,LDR,INPUT) ;

/******************** Input External Interrupt **********************/
	DIO_SetPinDirection (PORTD_DIO,PIR1,INPUT) ;
	DIO_SetPinDirection (PORTD_DIO,PIR2,INPUT) ;

/*********************** Digital Input *************************/

	DIO_SetPinDirection (PORTB_DIO,GAS,INPUT) ;


/********************** Digital Output ************************/
	DIO_SetPinDirection (PORTB_DIO,DOOR1,OUTPUT) ;
	DIO_SetPinDirection (PORTB_DIO,DOOR2,OUTPUT) ;
	DIO_SetPinDirection (PORTB_DIO,LED,OUTPUT) ;


/************************ PWM Output *************************/
	DIO_SetPinDirection (PORTB_DIO,FAN,OUTPUT) ;
	DIO_SetPinDirection (PORTD_DIO,LIGHT,OUTPUT) ;


/************************ PORTS INITIALIZATION *************************/

	DIO_SetPinValue(PORTD_DIO , PIR1 , HIGH);
	DIO_SetPinValue(PORTD_DIO , PIR2 , HIGH);
	DIO_SetPinValue(PORTB_DIO , GAS , HIGH) ;
	DIO_SetPinValue(PORTB_DIO , LED , LOW) ;

}


/************************************************************/

void UpdateFanSpeed (void) {

	u16 u16Volt = 0 ;

	U8_ADC_U8_Read(TEMPERATURE_SENSOR)  ;
	// analog = ((digital * V ref )/2^resolution)
	u16Volt =( ( ( (u32)u8_TMP_Read *  1500UL) ) / 255UL )  ;
	u16Temp = u16Volt/10 ;



if      (u16Temp<=20)                  {OCR0_REG = 0 ; }
else if ((u16Temp>20)&&(u16Temp<=27))  {OCR0_REG = 127 ; }
else if ((u16Temp>27)&&(u16Temp<=30))  {OCR0_REG = 200 ; }
else                                   { OCR0_REG=255 ; }

}

/************************************************************/

void UpdateLightIlluminance (void) {

	U8_ADC_U8_Read(LDR_SENSOR)  ;

	u8Lumen  = u8_LDR_Read ;


	if (u8_LDR_Read <= 64 )                       {OCR2_REG = 0 ;}    // bulb off
	else if (u8_LDR_Read >64 && u8_LDR_Read<128 ) {OCR2_REG = 128  ; }    // half max bulb lighting
	else                                          {OCR2_REG = 255 ; }   // max bulb lighting

}


/************************************************************/

void UpdateAlertStatus (void) {


if (DIO_GetPinValue(PORTB_DIO,GAS)) {
	DIO_SetPinValue(PORTB_DIO , LED , HIGH) ;        // led ON
	u8AlarmStatus = 1 ;

}
else {
	DIO_SetPinValue(PORTB_DIO , LED , LOW) ;       // led OFF
	u8AlarmStatus = 0 ;

}



}


