/*
#include "std_macros.h"
//#include <avr/interrupt.h> // This is very important
uint8_t flag = 0;

int main(void)
{
	
	CLEAR_BIT(DDRD,3); // PORTD Pin 3 is input
	SET_BIT(PORTD,3); // Pull up resistance
	SET_BIT(DDRD,4); // Pin 3 output


	// Enable General Interrupt is status register
	SET_BIT(SREG,7);
	
	//Enable the Rising edge of INT1 from MCU Control register
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	
	//Enable Periphral Interrupt from General Interrupt Control Register
	
	SET_BIT(GICR,INT1);


	
	while (1)
	{

		
	}

}
ISR(INT1_vect)
{
	TOGGLE_BIT(PORTD,4);
}
*/