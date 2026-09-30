#ifndef __LED_H
#define __LED_H

typedef enum {
	LED_1,
	LED_2
} LED_Num_TypeDef;


void LED_Init(void);
void LED_ON(LED_Num_TypeDef led);
void LED_OFF(LED_Num_TypeDef led);
void LED_Turn(LED_Num_TypeDef led);
#endif
