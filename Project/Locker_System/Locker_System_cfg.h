/*
 * Locker_System_cfg.h
 *
 * Created: 12/24/2022 5:32:33 PM
 *  Author: Youssef
 */ 


#ifndef LOCKER_SYSTEM_CFG_H_
#define LOCKER_SYSTEM_CFG_H_


#define Led_Init()	SET_BIT(DDRB,0); // Let Buzzer in PortA pin
#define Led(X) if(X == 1) SET_BIT(PORTB,0); else CLEAR_BIT(PORTB,0); 


#endif /* LOCKER_SYSTEM_CFG_H_ */