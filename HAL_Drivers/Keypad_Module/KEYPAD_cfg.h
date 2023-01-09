/*
 * KEYPAD_cfg.h
 *
 * Created: 12/16/2022 5:50:17 AM
 *  Author: Youssef
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#define KEYPAD_init_Pins() DDRC = 0x0F; PORTC |= 0xF0 // Input A B C D Output1 2 3 4

#define	K0(VALUE) if (VALUE == 1) SET_BIT(PORTC,0); else CLEAR_BIT(PORTC,0)
#define	K1(VALUE) if (VALUE == 1) SET_BIT(PORTC,1); else CLEAR_BIT(PORTC,1)
#define	K2(VALUE) if (VALUE == 1) SET_BIT(PORTC,2); else CLEAR_BIT(PORTC,2)
#define	K3(VALUE) if (VALUE == 1) SET_BIT(PORTC,3); else CLEAR_BIT(PORTC,3)

#define	K4() GET_BIT(PINC,4)
#define	K5() GET_BIT(PINC,5)
#define	K6() GET_BIT(PINC,6)
#define	K7() GET_BIT(PINC,7)




#endif /* KEYPAD_CFG_H_ */