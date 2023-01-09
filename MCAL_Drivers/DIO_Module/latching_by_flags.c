
/*
#include "std_macros.h"
uint8_t flag = 0;
*/
/*
int main(void)
{

	CLEAR_BIT(DDRB_,0); // Pin 0 is input
	SET_BIT(PORTB_,0); // Pull up resistance
	SET_BIT(DDRB_,1); // Pin 1 portb B is output


    while (1) 
    {

		if (GET_BIT(PINB_,0) == 0 && flag == 0)
		{
			_delay_us(10);
			TOGGLE_BIT(PORTB_,1);
			flag = 1;
			_delay_ms(1000);
		}
		

		else if (GET_BIT(PINB_,0) == 0 && flag == 1)
		{
			TOGGLE_BIT(PORTB_,1);
			flag = 0;
			_delay_ms(1000);

		}

    }
}

*/