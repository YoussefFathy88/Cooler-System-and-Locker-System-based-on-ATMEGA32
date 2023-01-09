/*
 * LCD.c
 *
 * Created: 12/14/2022 5:50:46 AM
 *  Author: Youssef
 */ 
#include "LCD.h"
#include "LCD_cfg.h"
void LCD_init(){
	LCD_PIN_Init();
	LCD_RW(0);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);

	LCD_write_command(0x2); // Enable 4-bit mode
	
	LCD_write_command(0x28); // enable write on both lines

	LCD_write_command(0x1); // clear LCD
	LCD_write_command(0x6); // make curser increment to right
	LCD_write_command(0x0C); // turn on the display
	_delay_ms(20);


}

void LCD_write_command(uint8_t command)
{
	LCD_RS(0);
	
	LCD_D7(GET_BIT(command,7));
	LCD_D6(GET_BIT(command,6));
	LCD_D5(GET_BIT(command,5));
	LCD_D4(GET_BIT(command,4));
	
	LCD_EN(1);
	_delay_ms(1);
	LCD_EN(0);
	
	LCD_D7(GET_BIT(command,3));
	LCD_D6(GET_BIT(command,2));
	LCD_D5(GET_BIT(command,1));
	LCD_D4(GET_BIT(command,0));

	LCD_EN(1);
	_delay_ms(1);
	LCD_EN(0);
	_delay_ms(1);


}

void LCD_write_char(uint8_t character){
	static uint8 number_of_char = 0;
	LCD_RS(1);
	
	LCD_D7(GET_BIT(character,7));
	LCD_D6(GET_BIT(character,6));
	LCD_D5(GET_BIT(character,5));
	LCD_D4(GET_BIT(character,4));	
	
	LCD_EN(1);
	_delay_ms(1);
	LCD_EN(0);
	
	LCD_D7(GET_BIT(character,3));
	LCD_D6(GET_BIT(character,2));
	LCD_D5(GET_BIT(character,1));
	LCD_D4(GET_BIT(character,0));

	LCD_EN(1);
	_delay_ms(1);
	LCD_EN(0);
	_delay_ms(1);

	number_of_char++;
	
	/*
	if(number_of_char == 8){
		LCD_write_command(0x14); //Move curser right by one character
	}
	else{
		LCD_write_command(0xc0);//Start from second line
	}
	*/
	//You shall make the cursor increment by one every time and
	//in case it the last line go to the bellow line

}


void LCD_write_string(uint8_t * string){
	for(uint8_t i = 0; string[i] != '\0'; i++)
	{
		LCD_write_char(string[i]);
	}
}
void LCD_write_num(uint16_t data){
	uint8_t arr[10];
	uint8_t arr_size = 0;
	while(data != 0)
		{
		// 1234 
		arr[arr_size++] = data%10;
		data = data/10; 
		}		
	for (uint8_t i = 0; i < arr_size; i++)
	{
		LCD_write_char(arr[arr_size-i-1] + 48);

	}
	
		
}