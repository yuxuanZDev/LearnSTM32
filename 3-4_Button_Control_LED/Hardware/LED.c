#include "stm32f10x.h"                  // Device header
#include "LED.h"

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_InitTypeDef GPIO_InitStricture;
	//PA0
	GPIO_InitStricture.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStricture.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStricture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStricture);
	
	//PC13
	GPIO_InitStricture.GPIO_Pin = GPIO_Pin_13;
	GPIO_Init(GPIOC, &GPIO_InitStricture);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_0);
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
}

void LED_ON(LED_Num_TypeDef led)
{
	switch (led)
	{
		case LED_1 :
			GPIO_ResetBits(GPIOA, GPIO_Pin_0);
			break;
		case LED_2 :
			GPIO_ResetBits(GPIOC, GPIO_Pin_13);	
			break;
		default:
			break;
	}
}

void LED_OFF(LED_Num_TypeDef led)
{
	switch (led)
	{
		case LED_1 :
			GPIO_SetBits(GPIOA, GPIO_Pin_0);
			break;
		case LED_2 :
			GPIO_SetBits(GPIOC, GPIO_Pin_13);	
			break;
		default:
			break;
	}
}

void LED_Turn(LED_Num_TypeDef led)
{
	switch(led)
	{
		case LED_2 :
			if( GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_13) == 0)
			{
				GPIO_SetBits(GPIOC, GPIO_Pin_13);
			}
			else
			{
				GPIO_ResetBits(GPIOC, GPIO_Pin_13);
			}
			break;
		case LED_1 :
			if( GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_0) == 0)
			{
				GPIO_SetBits(GPIOA, GPIO_Pin_0);
			}
			else
			{
				GPIO_ResetBits(GPIOA, GPIO_Pin_0);
			}
			break;
		default :
			return;
	}
}
