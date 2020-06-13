/***************************************************************/
/************* Author		: Ahmed Mamdouh		****************/
/************* Created on	: FEB 18, 2019		****************/
/**************** Version 		: V01			****************/
/***************************************************************/
/************************** Description ************************/
/***************************----------- ************************/
/***********file contains all Macros to be used by
 * the developer of this component only ************************/
/***************************************************************/
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_



/*****************UART Registers Addresses********************/

#define UBRRL	*((volatile u8 *)(0x29))
#define UBRRH	*((volatile u8 *)(0x40))

#define UCSRA 	*((volatile u8 *)(0x2B))
#define UCSRB 	*((volatile u8 *)(0x2A))
#define UCSRC 	*((volatile u8 *)(0x40))

#define UDR 	*((volatile u8 *)(0x2C))


#endif /* UART_PRIVATE_H_ */
