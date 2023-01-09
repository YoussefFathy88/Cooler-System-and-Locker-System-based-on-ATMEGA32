/*
 * Seven_Segement.h
 *
 * Created: 12/23/2022 10:02:39 AM
 *  Author: Youssef
 */ 


#ifndef SEVEN_SEGEMENT_H_
#define SEVEN_SEGEMENT_H_

#include "std_macros.h"


void Seven_Segement_Init(void);

void Seven_Segement_Write (uint8_t);

void Seven_Segement_Write_Optimized(uint8_t num);

void Seven_Segement_Write_Specific_Num(uint8_t num , uint8_t En);


#endif /* SEVEN_SEGEMENT_H_ */