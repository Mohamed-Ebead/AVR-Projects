/*
 * LCD_Prog.c
 *
 *  Created on: Aug 24, 2019
 *      Author: Mohamed_Ebead
 */


#include "STD_Types.h"
#include <util/delay.h>
#include "DIO_int.h"

#include "LCD_int.h"
#include "LCD_Config.h"


/****************************************************************/
void LCD_vidWriteCommand (u8 u8CmdCpy) {
	  // Set RS = 0
	  DIO_SetPinValue(Ctrl_PORT , RS, LOW);

	  // Set R/W = 0
	  DIO_SetPinValue(Ctrl_PORT , RW, LOW);

	  // Set EN = 0
	  DIO_SetPinValue(Ctrl_PORT , E, HIGH);

	  DIO_SetPortValue (Buff_PORT,u8CmdCpy);

	  // set EN to 1 after settting command
	  // pulse
	  DIO_SetPinValue(Ctrl_PORT , E, LOW);
	  _delay_ms(10);
	  DIO_SetPinValue(Ctrl_PORT , E, HIGH);

  }


/****************************************************************/


void LCD_vidInitialize(void){


	/****************  LCD Configuration  *****************/

			  // SET VDD TO D0   5 Volt (D0 >> VDD)
			  DIO_SetPinDirection (Ctrl_PORT, VDD , HIGH);

			  //  RS >> D1
			  DIO_SetPinDirection (Ctrl_PORT, RS, HIGH);

			  //  R/W >> D2
			  DIO_SetPinDirection (Ctrl_PORT, RW, HIGH);

			  //  Enable >> D3
			   DIO_SetPinDirection (Ctrl_PORT, E, HIGH);


			  //SET PORTC AS OUTPUT (PORTC >> DB0...DB7)
			  DIO_SetPortDirection (Buff_PORT, 0XFF);



	  /***************************************************************/

	 // set VDD @ A0 to 5 volt
	  DIO_SetPinValue(Ctrl_PORT , VDD, HIGH);
	  _delay_ms(50);



	 // FUNCTION SET
	  LCD_vidWriteCommand (0b00111000);//0X38  // N=0 1 line 0b00110000
	  _delay_ms (10);


	  // DISPLAY ON/OFF CONTROL
	  LCD_vidWriteCommand (0b00001111);
	 //  LCD_vidWriteCommand (0b00001100); //0X0C
	  _delay_ms (10);

	  // DISPLAY CLEAR
	 	  LCD_vidWriteCommand (0b00000001);
	 	  _delay_ms (10);

	  // Entry mode set
	  LCD_vidWriteCommand (0b00000110);//0X06
	  _delay_ms (20);

}


/****************************************************************/

void LCD_vidWriteCharacter(u8 u8DataCpy){
	 // Set RS to HIGH
		DIO_SetPinValue(Ctrl_PORT, RS , HIGH);

		// Set R/W to LOW
		DIO_SetPinValue(Ctrl_PORT, RW , LOW);

		// Set E to HIGH
		DIO_SetPinValue(Ctrl_PORT, E , HIGH);

		// Load Command on Data bus
		DIO_SetPortValue(Buff_PORT, u8DataCpy);

		// Set E to LOW
		DIO_SetPinValue(Ctrl_PORT, E, LOW);

		// Wait for E to settle
		_delay_ms(10);

		// Set E to HIGH
		DIO_SetPinValue(Ctrl_PORT, E, HIGH);

		// Delay to let the LCD Display the character
		_delay_ms(10);

}


/****************************************************************/

void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index){

	// Local loop index

		u8 iteration=0;

		for (iteration=0; ((iteration<u8Index)&&(pu8StringCpy[iteration] != '\0')) ; iteration++)
		{
			/* Write Character on LCD */
			LCD_vidWriteCharacter(pu8StringCpy[iteration]);

			/* Delay to let the LCD show the character */
			_delay_ms(10);
		}
}

/****************************************************************/


void LCD_vidClear(void)
{
	LCD_vidWriteCommand (0x01);		/* clear display */
	LCD_vidWriteCommand (0x02);		/* cursor at home position */
}

/****************************************************************/

void Gotoxy (u8 X,u8 Y){
	if (X>0 && X<=16)
		{
		    switch(Y)
		    {
			    case 1:
			    	LCD_vidWriteCommand(X+127);
			    break;
			    case 2:
			    	LCD_vidWriteCommand(X+191);
			    break;
			    default:
			    break;
		    }
		}

}

/********************************************************/

void LCDWriteInteger(u16 val , u16 field_length)
{
	/***************************************************************
	This function writes a integer type value to LCD module

	Arguments:
	1)int val	: Value to print

	2)unsigned int field_length :total length of field in which the value is printed
	must be between 1-5 if it is -1 the field length is no of digits in the val

	****************************************************************/

	u16 str[5]={0,0,0,0,0};
	u16 i=4,j=0;

	//Handle negative integers
	if(val<0)
	{
		LCD_vidWriteCharacter('-');   //Write Negative sign
		val=val*(-1);     //convert to positive
	}
	else
	{
		LCD_vidWriteCharacter(' ');
	}

	while(val)
	{
		str[i]=val%10;
		val=val/10;
		i--;
	}

	if(field_length==-1)
		while(str[j]==0) j++;
	else
		j=5-field_length;

	for(i=j;i<5;i++)
	{
		LCD_vidWriteCharacter('0'+str[i]);
	}
}


/********************************************************/

void vid_SeparateResult(u32 u32Result , u8 * u8ArrayResult) {

	u8ArrayResult[0]= ( (u32Result / 10000) % 10 ) + 48 ;
	u8ArrayResult[1]= ( (u32Result / 1000) % 10 ) + 48 ;
	u8ArrayResult[2]= ( (u32Result / 100) % 10 ) + 48 ;
	u8ArrayResult[3]= ( (u32Result / 10) % 10 ) + 48 ;
	u8ArrayResult[4]=   (u32Result  % 10 ) + 48 ;

}


/********************************************************/
