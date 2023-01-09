/*
 * std_macros.h
 *
 * Created: 12/14/2022 12:52:49 AM
 *  Author: Youssef
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h> // This is very important


typedef unsigned long uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;
typedef signed long int32;
typedef signed short int16;
typedef signed char int8;



#define SET_BIT(var,bit) (var |= (1<<bit))
#define CLEAR_BIT(var,bit) (var &= ~(1<<bit))
#define TOGGLE_BIT(var,bit) (var ^= (1<<bit))
#define GET_BIT(var,bit) ((var>>bit) & 1)




#endif /* STD_MACROS_H_ */