/* ADC_Interrupt.c
 *
 *  Created on: Feb 5, 2020
 *      Author: Mohamed  Ebead
 */

#include "STD_TYPES.h"
#include <avr/interrupt.h>
#include "APP_Config.h"
#include "Registers.h"
#include "interface.h"


extern u8 u8AdcChannel ;
extern u8 u8_TMP_Read ;
extern u8 u8_LDR_Read ;



ISR(ADC_vect){

	if (u8AdcChannel == TEMPERATURE_SENSOR ) {
		u8_TMP_Read = ADCH_REG ;
	}
	else if (u8AdcChannel == LDR_SENSOR) {
		u8_LDR_Read = ADCH_REG ;
	}
	else {

	}

}
