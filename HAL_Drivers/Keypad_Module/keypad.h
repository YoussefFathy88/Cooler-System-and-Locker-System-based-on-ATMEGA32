/*
 * keypad.h
 *
 * Created: 12/15/2022 7:07:04 PM
 *  Author: Youssef
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_macros.h"

void KEYPAD_init(void);
int8_t KEYPAD_Read(void); // Scanning for keypad and return -1 in case of no button is founded
#endif /* KEYPAD_H_ */