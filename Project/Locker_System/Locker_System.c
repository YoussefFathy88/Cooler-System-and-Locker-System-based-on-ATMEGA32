/*
*/

#include "../../HAL_Drivers/LCD_Module/LCD.h"
#include "../../HAL_Drivers/Keypad_Module/keypad.h"
#include "../../HAL_Drivers/Seven_Segement/Seven_Segement.h"
#include "../../MCAL_Drivers/EEPROM_Module/EEPROM.h"
#include "Locker_System_cfg.h"

int main(){
	
	
	LCD_init();
	KEYPAD_init();
	Led_Init();
	
	
	uint16_t lockerPassword = EEPROM_read(20)*100 + EEPROM_read(21);
	 
	int32_t num1 = -1;
	uint16_t currentPassword;
	uint8_t openState = 1; // Door is initially opened
	int8 keypadValue;
	uint8 resetPassword = 0;
	while (1)
	{
 		keypadValue = KEYPAD_Read(); 
			 		 
		 if (keypadValue == '/'){
			resetPassword = 0; 
			Led(1);

			_delay_ms(3000);
			
			Led(0);
			
			LCD_write_command(0x01); //Clear display
			
			
			LCD_write_string((uint8_t * )"New Pw:");
			
			// First number
			num1 = -1;
			while(num1 == -1){
				num1 = KEYPAD_Read();
			}
			while (KEYPAD_Read() != -1);

			num1 = num1 - 48; // convert to it's real int value
			LCD_write_char('*');

			lockerPassword = (num1*1000); //It's integar not hex take care from this point

			// Second Number
			num1 = -1;
			while(num1 == -1){
				num1 = KEYPAD_Read();
				
			}
			while (KEYPAD_Read() != -1);

			num1 = num1 - 48; // convert to it's real int value
			LCD_write_char('*');

			lockerPassword += (num1 * 100) ;
			
			// Third Number
			num1 = -1;
			while(num1 == -1){
				num1 = KEYPAD_Read();
			}
			
			while (KEYPAD_Read() != -1); // WAITING until the pressing removed
			num1 = num1 - 48; // convert to it's real int value
			LCD_write_char('*');
								
			lockerPassword += (num1 * 10);
			
			// Fourth number
			num1 = -1;
			while(num1 == -1){
				num1 = KEYPAD_Read();
			}
			while (KEYPAD_Read() != -1);
			num1 = num1 - 48; // convert to it's real int value
			LCD_write_char('*');

			lockerPassword += num1 ;
					
			_delay_ms(500);
			
			LCD_write_command(0x01);
			LCD_write_string((uint8_t *) "Your new PW:");
			LCD_write_num(lockerPassword);
			
			EEPROM_write(20,lockerPassword/100);
			EEPROM_write(21,lockerPassword%100);
		 }
		 else  if (keypadValue == 'X'){
			resetPassword = 0;
			openState = 0;
			Led(1);
			_delay_ms(500);
			Led(0);
			
			while (KEYPAD_Read() != -1);
			LCD_write_command(0x01);
			LCD_write_string((uint8_t * )"Door Is Locked ");
		 }
		 
		 
		 else if (keypadValue != -1 && openState == 0) {
			resetPassword = 0;
		
			LCD_write_command(0x01); //Clear display
		
			while (KEYPAD_Read() != -1);

			num1 = keypadValue - 48; // convert to it's real int value
			LCD_write_char('*');

			currentPassword = (num1*1000); //It's integar not hex take care from this point

			// Second Number
			num1 = -1;
			while(num1 == -1){
				num1 = KEYPAD_Read();
			
			}
			while (KEYPAD_Read() != -1);

			num1 = num1 - 48; // convert to it's real int value
			LCD_write_char('*');

			currentPassword += (num1 * 100) ;
		
			// Third Number
			num1 = -1;
			while(num1 == -1){
				num1 = KEYPAD_Read();
			}
		
			while (KEYPAD_Read() != -1); // WAITING until the pressing removed
			num1 = num1 - 48; // convert to it's real int value
			LCD_write_char('*');
		
			currentPassword += (num1 * 10);
		
			// Fourth number
			num1 = -1;
			while(num1 == -1){
				num1 = KEYPAD_Read();
			}
			while (KEYPAD_Read() != -1);
			num1 = num1 - 48; // convert to it's real int value
			LCD_write_char('*');

			currentPassword += num1 ;
		
			_delay_ms(500);
		
			LCD_write_command(0x01);
			if(currentPassword == lockerPassword){
				LCD_write_command(0x01); //Clear display
				LCD_write_string((uint8_t *) "Door is Opened");
				openState = 1;
			}
			else{
				LCD_write_command(0x01); //Clear display
				LCD_write_string((uint8_t *) "Try again");
				
				Led(1);
				_delay_ms(250);
				Led(0);

			}
			
			}
			else if (keypadValue == '0' && openState == 1) {
				while (KEYPAD_Read() != -1);
				resetPassword++;
				if (resetPassword == 6){
					LCD_write_command(0x01); //Clear display
					LCD_write_string((uint8_t *) "Password reset");
					lockerPassword = 0x0000;
					Led(1);
					_delay_ms(1000);
					Led(0);
				}

			}
			else if (keypadValue != -1){
				while (KEYPAD_Read() != -1);
				resetPassword = 0;
				


			}
	}
}
