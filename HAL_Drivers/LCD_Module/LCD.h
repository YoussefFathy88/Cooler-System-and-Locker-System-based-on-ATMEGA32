/*
 * LCD.h
 *
 * Created: 12/14/2022 5:50:59 AM
 *  Author: Youssef
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "std_macros.h"




void LCD_init(void);

void LCD_write_command(uint8_t);

void LCD_write_char(uint8_t);

void LCD_write_string(uint8_t *);

void LCD_write_num(uint16_t data); // Decimal number
// hint 1024 convert it to 1 --> ASCII 0 --> ASCI ...


#endif /* LCD_H_ */