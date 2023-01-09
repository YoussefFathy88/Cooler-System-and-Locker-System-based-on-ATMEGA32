/*
 * Seven_Segement.c
 *
 * Created: 12/23/2022 10:02:25 AM
 *  Author: Youssef
 */ 
#include "Seven_Segement_cfg.h"
#include "Seven_Segement.h"

uint8_t ss_data[] = {0x40,0x79,0x24,0x30,0x19,0x12,0x2,0x78,0x0,0x10}; // Not real value
void Seven_Segement_Init(void){
	
	Seven_Segement_Port_Output();

}

/*
For Final Project
*/
void Seven_Segement_Write_Specific_Num(uint8_t num , uint8_t En){
	Seven_Segement_En1(0);	Seven_Segement_En2(0);	Seven_Segement_En3(0);	Seven_Segement_En4(0);

	switch (En){
		case 1:
		Seven_Segement_En1(1);
		break;
		case 2:
		Seven_Segement_En2(1);
		
		break;
		case 3:
		Seven_Segement_En3(1);
		
		break;
		case 4:
		Seven_Segement_En4(1);
		
		break;
		
		default:
		break;
	}
	
	Seven_Segement_PORT &= 0b100000000;
	Seven_Segement_PORT |= ss_data[num];
	//_delay_ms(1);

}

/*
Sameh Afifi Style
*/
void Seven_Segement_Write_Optimized(uint8_t num){	
	
	
	Seven_Segement_En2(0); //disable 7seg old
	Seven_Segement_En1(1); // Enable 7seg new
	
	Seven_Segement_PORT &= 0b100000000;
	Seven_Segement_PORT |= ss_data[num/10];
	
	
	_delay_ms(1);
    
	
	Seven_Segement_En1(0); //disable 7seg old
	Seven_Segement_En2(1); //Enable 7seg new
	Seven_Segement_PORT &= 0b100000000;
	Seven_Segement_PORT |= ss_data[num%10];

	_delay_ms(1);

}

/*
My Custom Function
*/
void Seven_Segement_Write (uint8_t num){
	Seven_Segement_En1(1);
	switch (num) {
		
		case 0:
		 // 0X40
		 Seven_Segement_PinA(LED_ON);
		 Seven_Segement_PinB(LED_ON);
		 Seven_Segement_PinC(LED_ON);
		 Seven_Segement_PinD(LED_ON);
		 Seven_Segement_PinE(LED_ON);
		 Seven_Segement_PinF(LED_ON);
		 Seven_Segement_PinG(~LED_ON);

		break;
		//01111001
		case 1:
		 Seven_Segement_PinA(~LED_ON);
		 Seven_Segement_PinB(LED_ON);
		 Seven_Segement_PinC(LED_ON);
		 Seven_Segement_PinD(~LED_ON);
		 Seven_Segement_PinE(~LED_ON);
		 Seven_Segement_PinF(~LED_ON);
		 Seven_Segement_PinG(~LED_ON);

		break;
		// 00100100
		case 2:
		 Seven_Segement_PinA(LED_ON);
		 Seven_Segement_PinB(LED_ON);
		 Seven_Segement_PinC(~LED_ON);
		 Seven_Segement_PinD(LED_ON);
		 Seven_Segement_PinE(LED_ON);
		 Seven_Segement_PinF(~LED_ON);
		 Seven_Segement_PinG(LED_ON);

		break;
		//00110000
		case 3:
		 Seven_Segement_PinA(LED_ON);
		 Seven_Segement_PinB(LED_ON);
		 Seven_Segement_PinC(LED_ON);
		 Seven_Segement_PinD(LED_ON);
		 Seven_Segement_PinE(~LED_ON);
		 Seven_Segement_PinF(~LED_ON);
		 Seven_Segement_PinG(LED_ON);

		break;
		
		case 4:
		//00011001
		 Seven_Segement_PinA(~LED_ON);
		 Seven_Segement_PinB(LED_ON);
		 Seven_Segement_PinC(LED_ON);
		 Seven_Segement_PinD(~LED_ON);
		 Seven_Segement_PinE(~LED_ON);
		 Seven_Segement_PinF(LED_ON);
		 Seven_Segement_PinG(LED_ON);

		break;
		
		case 5:
		//00010010
		 Seven_Segement_PinA(LED_ON);
		 Seven_Segement_PinB(~LED_ON);
		 Seven_Segement_PinC(LED_ON);
		 Seven_Segement_PinD(LED_ON);
		 Seven_Segement_PinE(~LED_ON);
		 Seven_Segement_PinF(LED_ON);
		 Seven_Segement_PinG(LED_ON);

		break;
		
		case 6:
		//00000010
		 Seven_Segement_PinA(LED_ON);
		 Seven_Segement_PinB(~LED_ON);
		 Seven_Segement_PinC(LED_ON);
		 Seven_Segement_PinD(LED_ON);
		 Seven_Segement_PinE(LED_ON);
		 Seven_Segement_PinF(LED_ON);
		 Seven_Segement_PinG(LED_ON);

		break;
		
		case 7:
		//01111000
		 Seven_Segement_PinA(LED_ON);
		 Seven_Segement_PinB(LED_ON);
		 Seven_Segement_PinC(LED_ON);
		 Seven_Segement_PinD(~LED_ON);
		 Seven_Segement_PinE(~LED_ON);
		 Seven_Segement_PinF(~LED_ON);
		 Seven_Segement_PinG(~LED_ON);

		break;
		
		case 8:
		// 00000000
		 Seven_Segement_PinA(LED_ON);
		 Seven_Segement_PinB(LED_ON);
		 Seven_Segement_PinC(LED_ON);
		 Seven_Segement_PinD(LED_ON);
		 Seven_Segement_PinE(LED_ON);
		 Seven_Segement_PinF(LED_ON);
		 Seven_Segement_PinG(LED_ON);

		break;
		
		case 9:
		// 00010000
		 Seven_Segement_PinA(LED_ON);
		 Seven_Segement_PinB(LED_ON);
		 Seven_Segement_PinC(LED_ON);
		 Seven_Segement_PinD(LED_ON);
		 Seven_Segement_PinE(~LED_ON);
		 Seven_Segement_PinF(LED_ON);
		 Seven_Segement_PinG(LED_ON);

		break;
		
		default:
		break;

	}
	
}
