
/*
 * UART_prog.c
 *
 *  Created on: Oct 4, 2019
 *      Author: Mohamed  Ebead
 */




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
