#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"

uint8_t KeyNum;

int main(void)
{

	LED_Init();
	Key_Init();
	
	while (1)
	{
		KeyNum = Key_GetNum();
		
		if(KeyNum == 1)
		{
			LED_Turn(LED_1);
		}
		if(KeyNum == 2)
		{
			LED_Turn(LED_2);
		}

	}
}

