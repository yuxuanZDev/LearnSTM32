#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "LightSensor.h"

uint8_t KeyNum;

int main(void)
{
	
	LED_Init();
	LightSensor_Init();
	
	while (1)
	{
		if(LightSensor_Get() == 1)
		{
			LED_ON(LED_1);
		}
		else
		{
			LED_OFF(LED_1);
		}

	}
}

