#include "stm32f10x.h"                  // Device header
#include "LED.h"

/**
  * @brief	Initialize GPIO pins for LED control.
  * @param	None
  * @retval	None
  */
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	//PA0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//PC13
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_0);
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
}

/**
  * @brief	Turn on the selected LED.
  * @param	led: Specifies the LED to be turned on.
  * 		this parameter can be one of the following values:
  *				@arg LED_1
  *             @arg LED_2
  * @retval	None
  */
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

/**
  * @brief	Turn off the selected LED.
  * @param	led: Specifies the LED to be turned on.
  * 		this parameter can be one of the following values:
  *				@arg LED_1
  *             @arg LED_2
  * @retval	None
  */
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

/**
  * @brief	Toggle the selected LED.
  * @param	led: Specifies the LED to be turned on.
  * 		this parameter can be one of the following values:
  *				@arg LED_1
  *             @arg LED_2
  * @retval	None
  */
void LED_Turn(LED_Num_TypeDef led)
{
	switch(led)
	{
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
		default :
			return;
	}
}
