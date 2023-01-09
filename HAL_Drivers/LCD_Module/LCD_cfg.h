/*
 * LCD_cfg.h
 *
 * Created: 12/16/2022 5:47:21 AM
 *  Author: Youssef
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define LCD_PIN_Init() DDRA = 0xFF;
#define LCD_D7(VALUE) if (VALUE == 1) SET_BIT(PORTA,0); else CLEAR_BIT(PORTA,0)
#define LCD_D6(VALUE) if (VALUE == 1) SET_BIT(PORTA,1); else CLEAR_BIT(PORTA,1)
#define LCD_D5(VALUE) if (VALUE == 1) SET_BIT(PORTA,2); else CLEAR_BIT(PORTA,2)
#define LCD_D4(VALUE) if (VALUE == 1) SET_BIT(PORTA,3); else CLEAR_BIT(PORTA,3)
#define LCD_EN(VALUE) if (VALUE == 1) SET_BIT(PORTA,4); else CLEAR_BIT(PORTA,4)
#define LCD_RW(VALUE) if (VALUE == 1) SET_BIT(PORTA,5); else CLEAR_BIT(PORTA,5)
#define LCD_RS(VALUE) if (VALUE == 1) SET_BIT(PORTA,6); else CLEAR_BIT(PORTA,6)




#endif /* LCD_CFG_H_ */