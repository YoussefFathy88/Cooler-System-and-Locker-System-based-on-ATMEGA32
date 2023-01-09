/*
 * keypad.c
 *
 * Created: 12/15/2022 7:06:53 PM
 *  Author: Youssef
 */ 
#include "keypad.h"
#include "KEYPAD_cfg.h"
uint8_t const keypad_matrix[] = {'7','8','9','/',
	'4','5','6','X',
	'1','2','3','-',
	'C','0','=','+'};
void KEYPAD_init(void){
	KEYPAD_init_Pins();
}
int8_t KEYPAD_Read(void){

	K0(0);K1(1);K2(1);K3(1); //Because my targeet that to see the pull up 5 reached 0 or no
	
	if(K4() == 0){
		return keypad_matrix[0];
	}
	if(K5() == 0){
		return keypad_matrix[1];
	}
	if(K6() == 0){
		return keypad_matrix[2];
	}
	if(K7() == 0){
		return keypad_matrix[3];
	}

	_delay_ms(5);
	K0(1);K1(0);K2(1);K3(1);
	
	if(K4() == 0){
		return keypad_matrix[4];
	}
	if(K5() == 0){
		return keypad_matrix[5];
	}
	if(K6() == 0){
		return keypad_matrix[6];
	}
	if(K7() == 0){
		return keypad_matrix[7];
	}

	_delay_ms(5);
	K0(1);K1(1);K2(0);K3(1);
	
	if(K4() == 0){
		return keypad_matrix[8];
	}
	if(K5() == 0){
		return keypad_matrix[9];
	}
	if(K6() == 0){
		return keypad_matrix[10];
	}
	if(K7() == 0){
		return keypad_matrix[11];
	}

	_delay_ms(5);
	K0(1);K1(1);K2(1);K3(0);
	
	if(K4() == 0){
		return keypad_matrix[12];
	}
	if(K5() == 0){
		return keypad_matrix[13];
	}
	if(K6() == 0){
		return keypad_matrix[14];
	}
	if(K7() == 0){
		return keypad_matrix[15];
	}
	_delay_ms(5);

	return -1;	
}