/*
 * DIO.h

 *
 *  Created on: Aug 18, 2023
 *      Author: hp
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_
#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"
#include "../../lib/Definitions.h"



void MDIO_voidSetPinDirection(u8 A_u8PortNum,u8 A_u8PinNum,u8 A_u8PinDirection);
void MDIO_voidSetPinValue(u8 A_u8PortNum,u8 A_u8PinNum,u8 A_u8PinValue);
void MDIO_voidTogglePin(u8 A_u8PortNum,u8 A_u8PinNum);
u8 MDIO_u8GetPinValue(u8 A_u8PortNum,u8 A_u8PinNum);

void MDIO_voidSetPortDirection(u8 A_u8PortNum,u8 A_u8PortDirection);
void MDIO_voidSetPortValue(u8 A_u8PortNum,u8 A_u8PortValue);


#endif /* MCAL_DIO_DIO_H_ */
