/*
 * Timer0.h
 *
 * Created: 1/7/2023 3:24:09 AM
 *  Author: Youssef
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
#include "std_macros.h"
void Timer0_normal_init(void);

void Timer0_CTC_init(uint8_t max); 

void Timer0_freq_gen_init(uint8_t max);


#endif /* TIMER0_H_ */