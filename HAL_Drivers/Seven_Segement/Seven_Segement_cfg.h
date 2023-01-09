/*
 * Seven_Segement_cfg.h
 *
 * Created: 12/23/2022 10:05:33 AM
 *  Author: Youssef
 */ 


#ifndef SEVEN_SEGEMENT_CFG_H_
#define SEVEN_SEGEMENT_CFG_H_


#define LED_ON 0

#define Seven_Segement_PORT PORTD
#define Seven_Segement_Port_Output() DDRD = 0xFF; PORTD |= 0x01111111; SET_BIT(DDRB,7);SET_BIT(DDRB,6);
#define Seven_Segement_PinA(NUM) if (NUM == 0) CLEAR_BIT(PORTD,0); else SET_BIT(PORTD,0);
#define Seven_Segement_PinB(NUM) if (NUM == 0) CLEAR_BIT(PORTD,1); else SET_BIT(PORTD,1);
#define Seven_Segement_PinC(NUM) if (NUM == 0) CLEAR_BIT(PORTD,2); else SET_BIT(PORTD,2);
#define Seven_Segement_PinD(NUM) if (NUM == 0) CLEAR_BIT(PORTD,3); else SET_BIT(PORTD,3);
#define Seven_Segement_PinE(NUM) if (NUM == 0) CLEAR_BIT(PORTD,4); else SET_BIT(PORTD,4);
#define Seven_Segement_PinF(NUM) if (NUM == 0) CLEAR_BIT(PORTD,5); else SET_BIT(PORTD,5);
#define Seven_Segement_PinG(NUM) if (NUM == 0) CLEAR_BIT(PORTD,6); else SET_BIT(PORTD,6);

#define Seven_Segement_En1(NUM) if (NUM == 0) CLEAR_BIT(PORTB,6); else SET_BIT(PORTB,6);
#define Seven_Segement_En2(NUM) if (NUM == 0) CLEAR_BIT(PORTB,7); else SET_BIT(PORTB,7);
#define Seven_Segement_En3(NUM) if (NUM == 0) CLEAR_BIT(PORTB,5); else SET_BIT(PORTB,5);
#define Seven_Segement_En4(NUM) if (NUM == 0) CLEAR_BIT(PORTB,4); else SET_BIT(PORTB,4);



#endif /* SEVEN_SEGEMENT_CFG_H_ */