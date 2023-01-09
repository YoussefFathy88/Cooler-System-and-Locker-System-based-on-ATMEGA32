/*
 * ATMEGA_32_Drivers_SA_Course.c
 *
 * Created: 12/14/2022 5:48:13 AM
 * Author : Youssef
 */ 

/*
#include <avr/io.h>
#include "../HAL_Drivers/LCD_Module/LCD.h"
#include "../HAL_Drivers/Keypad_Module/keypad.h"
#include "../HAL_Drivers/Seven_Segement/Seven_Segement.h"

int main(void)
{
	LCD_init();
	KEYPAD_init();
	Seven_Segement_Init();
	uint8_t num = 15;

    while (1) 
    {
		
	//	To see the number by pooling do this without timer
		
		for(int i =0; i<125;i++){
		Seven_Segement_Write_Specific_Num(num/10 , 1);
		
		Seven_Segement_Write_Specific_Num(num%10 , 2);
		}
		num++;
		

    }
}
*/