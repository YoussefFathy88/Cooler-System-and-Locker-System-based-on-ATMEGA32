/*
 * EEPROM.c
 *
 * Created: 12/17/2022 4:47:24 AM
 *  Author: Youssef
 */ 

#include "EEPROM.h"
void EEPROM_write (uint16_t address,uint8_t data)
{
  
   while(GET_BIT(EECR,EEWE) != 0);
   // This step grantee that their is no more writing
   // in previous step 
   
   //while(GET_BIT(SPMEN,0) !=0); // Bootloader (flashing)

   EEARH = (address >> 8) & 0xFF;
   EEARL = address & 0xFF;
   
   //EEAR = address atmel studio handle this
   EEDR = data;

   SET_BIT(EECR,EEMWE); // Master write enable
			
	SET_BIT(EECR,EEWE); 
   //Remain one untill the writing finsh and after finshing 
   //the HW automatically make it zero.
}

uint8_t EEPROM_read (uint16_t address)
{
   while(GET_BIT(EECR,EEWE) != 0); // Just to grantee that their is not writing
   EEARH = (address >> 8) & 0xFF;
   EEARL = address & 0xFF;
   SET_BIT(EECR,EERE); // Enable reading
   return EEDR;
	
}
