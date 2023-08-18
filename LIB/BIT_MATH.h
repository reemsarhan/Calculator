/*
 * BIT_MATH.h

 *
 *  Created on: Aug 18, 2023
 *      Author: hp
 */

#ifndef MCAL_BIT_MATH_H_
#define MCAL_BIT_MATH_H_



#define SET_BIT(Reg, bit_num) Reg |= (1 << (bit_num))

#define CLR_BIT(Reg, bit_num) Reg &= ~(1 << (bit_num))

#define TOOGLE_BIT(Reg, bit_num) Reg ^= (1 << (bit_num))

#define GET_BIT(Reg, bit_num) (Reg >> bit_num) & 0x01

#define SET_BYTE(Reg,Value)    Reg=Value

#endif /* MCAL_BIT_MATH_H_ */
