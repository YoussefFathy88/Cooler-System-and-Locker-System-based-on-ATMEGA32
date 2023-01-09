// /*
//  * Calculator.c
//  *
//  * Created: 12/17/2022 1:51:09 AM
//  *  Author: Youssef
//  */ 
// 
// 
// #include "../HAL_Drivers/LCD_Module/LCD.h"
// #include "../HAL_Drivers/Keypad_Module/keypad.h"
// int main()
// {
// 	KEYPAD_init();
// 	LCD_init();
// 	int8_t num1 = -1;
// 	int8_t num2 = -1;
// 	int16_t num3;
// 	int8_t operator = -1;
// 	int8_t equal_operator = -1;
// 	uint8_t flag = 0;
// 	while(1){
// 				
// 		while(num1 == -1){
// 			num1 = KEYPAD_Read();
// 
// 		}
// 		LCD_init(); // Restart the calculator after pressing new number
// 		LCD_write_char(num1);
// 		while(KEYPAD_Read() != -1);
// 		while(operator == -1){
// 			operator = KEYPAD_Read();
// 
// 		}
// 
// 		LCD_write_char(operator);
// 		while(KEYPAD_Read() != -1);
// 		while(num2 == -1){
// 			num2 = KEYPAD_Read();
// 
// 		}
// 		LCD_write_char(num2);
// 		while(KEYPAD_Read() != -1);
// 		
// 		while (equal_operator != '='){
// 		equal_operator = KEYPAD_Read();
// 		}
// 		LCD_write_char('=');
// 		equal_operator = -1;
// 		while(KEYPAD_Read() != -1);
// 		switch(operator)
// 		{
// 			case '+':
// 			num3 = (num1-48) + (num2-48); // -48 because of ASCII 
// 			break;
// 				
// 			case '-':
// 			num3 = (num1-48) - (num2-48);
// 			break;
// 			
// 			case 'X':
// 			num3 = (num1-48) * (num2-48);
// 			break;
// 			
// 			case '/':
// 			num3 = (num1-48) / (num2-48);
// 			break;
// 	
// 			default:
// 			flag = 1;
// 			uint8_t string [] = "Invalid operation" ;
// 			LCD_write_string(string);
// 			break;
// 		}
// 		if (flag != 1){
// 			flag = 0;
// 			LCD_write_num(num3);
// 			
// 		}
// 		num1 = -1;
// 		num2 = -1;
// 		operator = -1;
// 
// 
// 
// 		
// 		
// 		
// 		
// 	}
// 	return -1;
// }
