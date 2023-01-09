/*
 * EEPROM.h
 *
 * Created: 12/17/2022 4:47:38 AM
 *  Author: Youssef
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include "std_macros.h"

void EEPROM_write (uint16_t,uint8_t);
uint8_t EEPROM_read (uint16_t);



#endif /* EEPROM_H_ */