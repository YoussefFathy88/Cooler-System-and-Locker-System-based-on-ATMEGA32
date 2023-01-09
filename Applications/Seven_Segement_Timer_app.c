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
// volatile uint8_t num = 0;
// 
// int main(void)
// {
// 
//   //  Timer0_normal_init(); // 8Mhz,C.C 1/8MHz , no prescaling, 256 tick overflow --> 256/8 -- 32 us (correct in protues) ---
// 	
// 	Timer0_CTC_init(240); // 8Mhz,C.C 1/8MHz ------>  30.125 us ---> 1 tick (expected) (241 * (1/8))
// 
// 	Seven_Segement_Init();
// 
// 	SET_BIT(DDRB,0);
//     while (1) 
//     { }
// }
// 
// 
// // For one second 32 * N = 1000000 us (1 second) = 31250
// // After prescaling 32*1024 * N = 1000000 N = 31
// 
// 
// ISR(TIMER0_OVF_vect)
// {
// 		Seven_Segement_Write_Specific_Num(num/10 , 1);
// 		
// 		Seven_Segement_Write_Specific_Num(num%10 , 2);
// 
// }
// 
// 
// 
// // Max 240 , clock 1/8mhh     1000 us = 1/8 * 240 * N  ----> N = 33
// // I don't know the reason of switch but without switching it was working 
// 
// 
// // 250000 = 240/8 * N 
// 
// // Increment X each 250 but the problem in the upper delay is the  context switching so wi will make it by the timer also 
// // 250,000 = 240/8 * N //8333
// 
// 
// // 8Mhz Clock cycle 1/8 cc 241 -- 30.125 * N = 500*1000 (0.5 second)  , 30.125 comes from (240+1)/8
// 
// // Due to 7-segement the delay appears *2 !! may be due to the crystal frequency is not fast enough or something like that but no problem.
// 
// ISR(TIMER0_COMP_vect)
// {
// 	static uint16_t count = 0;
// 	static uint16_t switch_seven_Segement = 0;	
// 	static uint16_t count_delay = 0;
// 
// 	
// 	if (count_delay == 16597) // 0.5 second 
// 	{
// 		TOGGLE_BIT(PORTB,0);
// 		if (num == 100){
// 			num = 0;
// 		}
// 		num++;
// 		count_delay = 0;
// 
// 	}
// 	else{
// 		count_delay++;
// 
// 	}
// 	
// // Delay 1ms 
// 
// 	if (count == 33)
// 	{
// 		count = 0;
// 		// This part slow the system 
// 		if (switch_seven_Segement == 0){
// 			// We doesn't open both to give each one the time to open and close (1ms) so our eyes doesn't see but this delay can be made at the end of the 7-segement function I commented it from the main function 
// 			// And this was the reason of the problem
// 			Seven_Segement_Write_Specific_Num(num/10 , 1);
// 			switch_seven_Segement = 1; 
// 		}
// 		else{
// 			Seven_Segement_Write_Specific_Num(num%10 , 2);
// 			switch_seven_Segement = 0;
// 
// 		}
// 
// 	}
// 	else{
// 		count++;
// 
// 	}
// 
// 
// 
// }
// 
// /*
// 
//   1. Some optimizations if count = 33 -- i am sure that 1 ms pass so i can make inside it count_delay++ and check if count_delay = 250 , and make it uint8 instead of uint16 nice one.
// 
// */
// 
// 
// // Each 30 us 1 Tick ----> each 250 ms 250,000 us = 30 * N ?