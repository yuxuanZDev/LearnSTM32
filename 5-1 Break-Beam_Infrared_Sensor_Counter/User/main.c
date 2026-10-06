#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "OLED.h"
#include "CountSensor.h"


uint8_t KeyNum;

int main(void)
{
	OLED_Init();
	CountSensor_Init();
	OLED_ShowString(1, 1, "Count:");
	while (1)
	{
		OLED_ShowNum(2, 1, CountSensor_Get(), 5);
	}
}

