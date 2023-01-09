// /*
//  * ATMEGA_32_Drivers_SA_Course.c
//  *
//  * Created: 12/14/2022 5:48:13 AM
//  * Author : Youssef
//  */ 
// 
// 
// #include <avr/io.h>
// #include "../HAL_Drivers/LCD_Module/LCD.h"
// #include "../HAL_Drivers/Keypad_Module/keypad.h"
// #include "../HAL_Drivers/Seven_Segement/Seven_Segement.h"
// #include "../MCAL_Drivers/Timer0/Timer0.h"
// 
// int main(void)
// {
// 
//     //Timer0_normal_init(); // 8Mhz,C.C 1/8MHz , no prescaling, 256 tick overflow --> 256/8 -- 32 us (correct in protues) ---
// 
// 	Timer0_CTC_init(200); // 8Mhz,C.C 1/8MHz , no prescaling, 256 tick overflow --> 200/8 -- 25 us (correct in protues) ---
// 
// 	SET_BIT(DDRB,0);
// 
//     while (1) 
//     {
// 		
// 
//     }
// }
// 
// 
// // For one second 32 * N = 1000000 us (1 second) = 31250
// // After prescaling 32*1024 * N = 1000000 N = 31
// 
// 
// ISR(TIMER0_OVF_vect)
// {
// 	static uint16_t count = 0;
// 
// 	if (count == 31)
// 	{
// 		count = 0;
// 		TOGGLE_BIT(PORTB,0);
// 
// 	}
// 	else{
// 		count++;
// 
// 	}
// }
// 
// 
// ISR(TIMER0_COMP_vect)
// {
// 	TOGGLE_BIT(PORTB,0);
// }
