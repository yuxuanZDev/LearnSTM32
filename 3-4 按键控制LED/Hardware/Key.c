#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;	//默认返回0
	
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0 | GPIO_Pin_11) == 0)
	{
		Delay_ms(20);	//消除按下抖动
		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0 | GPIO_Pin_11) == 0);	//松手才返回1
		Delay_ms(20);	//消除松开抖动
		KeyNum = 1;
	}

	return KeyNum;
}

