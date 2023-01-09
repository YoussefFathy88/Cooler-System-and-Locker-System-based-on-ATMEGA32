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
// #include "../MCAL_Drivers/EEPROM_Module/EEPROM.h"
// int main(void)
// {
// 	LCD_init();
// 	KEYPAD_init();
// 	uint8 x = EEPROM_read(20);
//     while (1) 
//     {
// 		LCD_write_command(0x1); //Clear LCD
// 		LCD_write_num(x++);
// 		EEPROM_write(20,x);
// 		_delay_ms(300);
// 		
//     }
// }
