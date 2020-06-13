/*
 * App.c
 *
 *  Created on: 20 January 2020
 *      Author: Mohamed Ebead
 */



#include "STD_Types.h"
#include <util/delay.h>

#include "ADC_Interface.h"
#include "interface.h"
#include "EXT_INT_INTERFACE.H"
#include "Timer0_interface.h"
#include "Timer2_interface.h"
#include "UART_interface.h"


/****************************************************************/


u8 u8AdcChannel = 0 ;
u8 u8_TMP_Read = 0 ;
u8 u8_LDR_Read = 0 ;


u16 u16Temp = 0 ;
u8 u8Lumen = 0 ;          // each Lamp lumen = 255 lumen


u8 u8PeopleInside = 0 ;
u8 u8AlarmStatus = 0 ;



/****************************************************************/




void main (void) {


	vid_DIO_vid_SetDioDirections () ;

	vid_ADC_vid_Initialize () ;

	vid_Timer0_vid_InitializePWM () ;

	vid_Timer2_vid_InitializePWM () ;

	vid_ExtInt0_vid_InitializeExtInt () ;

	vid_ExtInt1_vid_InitializeExtInt () ;

	vid_UART_vid_Initialize();



	while (1) {



    UpdateFanSpeed () ;
    UpdateLightIlluminance () ;
    UpdateAlertStatus () ;




    asm ("CLI") ;       //disable global interrupt




    vid_UART_vid_SendChar('a') ;    // alert 2nd uc to recieve Temp
    _delay_ms(250) ;
    vid_UART_vid_SendChar((u8)u16Temp);
    _delay_ms(250) ;

    vid_UART_vid_SendChar('b') ;      // alert 2nd uc to recieve lamp Lumen
    _delay_ms(250) ;
    vid_UART_vid_SendChar(u8Lumen);
    _delay_ms(250) ;


   vid_UART_vid_SendChar('c') ;        // alert 2nd uc to recieve number of people inside
   _delay_ms(250) ;
   vid_UART_vid_SendChar(u8PeopleInside);
   _delay_ms(250) ;


   vid_UART_vid_SendChar('d') ;        // alert 2nd uc to recieve alarm status
   _delay_ms(250) ;
   vid_UART_vid_SendChar(u8AlarmStatus);
   _delay_ms(250) ;

    asm ("SEI") ;      // enable global interrupt


	}


}






