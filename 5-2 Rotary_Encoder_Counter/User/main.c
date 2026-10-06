#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "OLED.h"
#include "Encoder.h"

int16_t Num;

int main(void)
{
	LED_Init();
	OLED_Init();
	Encoder_Init();
	while (1)
	{
		Num += Get_Encoder_Count();
		OLED_ShowSignedNum(1,1,Num,5);
		
		
		if (Num % 2 == 0)
		{
			LED_OFF(LED_2);
			LED_ON(LED_1);
		}
		else
		{
			LED_OFF(LED_1);
			LED_ON(LED_2);
		}
	}
}

