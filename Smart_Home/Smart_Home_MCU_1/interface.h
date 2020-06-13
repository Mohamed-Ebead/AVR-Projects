/*
 * interface.h
 *
 *   Created on: 20 January 2020
 *      Author: Mohamed Ebead
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_









/**********************************************************/

void vid_DIO_vid_SetDioDirections (void) ;
/* This function handles DIO pins
 * , sets input and output pins
 * and initializes PORTS initial values
 */
/**********************************************************/

void UpdateFanSpeed (void) ;

/**********************************************************/


void UpdateLightIlluminance (void) ;


/**********************************************************/
void UpdateAlertStatus (void) ;


/**********************************************************/







#endif /* INTERFACE_H_ */
