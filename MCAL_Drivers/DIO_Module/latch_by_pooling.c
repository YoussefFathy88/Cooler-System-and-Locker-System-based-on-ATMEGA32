/*
#include "std_macros.h"
uint8_t flag = 0;

int main(void)
{
	
	CLEAR_BIT(DDRB_,0); // Pin 0 is input
	SET_BIT(PORTB_,0); // Pull up resistance	
	SET_BIT(DDRB_,1); // Pin 1 portb B is output

	
	while (1)
	{

		while(GET_BIT(PINB,0) == 1);
		
		TOGGLE_BIT(PORTB,1);
				
		while(GET_BIT(PINB,0) == 0);

		TOGGLE_BIT(PORTB,1);

		_delay_ms(10);
			
	}

}
*/