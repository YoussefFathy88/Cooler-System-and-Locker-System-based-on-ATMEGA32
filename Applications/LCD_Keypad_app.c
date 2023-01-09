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
// 
// int main(void)
// {
// 	LCD_init();
// 	KEYPAD_init();
//     while (1) 
//     {
// 		
// 		int8_t x = KEYPAD_Read();
// 		if(x != -1){
// 			LCD_write_command(0x80); 
// 			LCD_write_char(x);
// 		}
//     }
// }
