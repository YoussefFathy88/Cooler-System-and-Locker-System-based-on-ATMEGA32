/*
 * Timer0.c
 *
 * Created: 1/7/2023 3:23:54 AM
 *  Author: Youssef
 */ 

#include "Timer0.h"

void Timer0_normal_init(void){
	
	
	// Optimzed way 
	TCCR0 = (1<<FOC0) | (1<<CS00) | (1<<CS02); // prescaler 1024 
	
	// The remaming will be zero automatically because no |=
	/*
	SET_BIT(TCCR0,F0C0);
	
	// Enable Normal mode
	CLEAR_BIT(TCCR0,WGM01);
	CLEAR_BIT(TCCR0,WGM00);




	// 0C0 discooned for Normal mode
	CLEAR_BIT(TCCR0,COM01);
	CLEAR_BIT(TCCR0,COM00);

	// Prescalling (No prescalling)
	SET_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);

	*/

	
	// Enable peripheral interrupt
	SET_BIT(TIMSK,TOIE0);

	// Enable General Interrupt is status register
	SET_BIT(SREG,7);


}

void Timer0_CTC_init(uint8_t max){

	TCCR0 = (1 << FOC0) | (1 << WGM01) | (1<<CS00);
	
	/*
	SET_BIT(TCCR0,FOC0);
	
	// Enable Normal mode
	SET_BIT(TCCR0,WGM01);
	CLEAR_BIT(TCCR0,WGM00);




	// (Frequency mode) Toggle oc0 ON COMPARE MATCH -- In freq mode
	
	CLEAR_BIT(TCCR0,COM01);
	
	SET_BIT(TCCR0,COM00);  //

	// Prescalling (No prescalling)
	SET_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
	*/
	
	//Add the maximum value in compare register
	OCR0 = max;



	
	// Enable peripheral interrupt
	SET_BIT(TIMSK,OCIE0);

	// Enable General Interrupt is status register 
	SET_BIT(SREG,7);

}

void Timer0_freq_gen_init(uint8_t max)
{
	SET_BIT(DDRB,3); // Make the pin output
	
	TCCR0 = (1 << FOC0) | (1 << WGM01) | (1<<CS00) | (1<<COM00);
	
	//Add the maximum value in compare register
	OCR0 = max;

	// Enable peripheral interrupt
	SET_BIT(TIMSK,OCIE0);

	// Enable General Interrupt is status register 
	SET_BIT(SREG,7);

}