#include "stm32f10x.h"                  // Device header

int16_t Encoder_Count;	//rotary encode count

/**
  * @brief  Initializes the rotary encoder on PA1 and PA2 using EXTI falling-edge interrupts.
  * @param	None
  * @retval	None
  */
void Encoder_Init(void)
{
	//配置外设时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	//配置gpio
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//配置afio
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource1);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource2);
	
	//配置exti
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line1 | EXTI_Line2;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);
	
	//配置nvic
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	

	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStructure);
}

/**
 * 	@brief	Returns the accumulated encoder count and resets it to zero.
 * 	@param  None
 * 	@retval Encoder count accumulated since the previous call.
 */
int16_t Get_Encoder_Count(void)
{
	int16_t Temp;
	Temp = Encoder_Count;
	Encoder_Count = 0;
	return Temp;
}

/**
  * @brief  Handles the EXTI1 interrupt for the rotary encoder.
  * @param	None
  * @retval	None
  */
void EXTI1_IRQHandler (void)
{
	if (EXTI_GetITStatus(EXTI_Line1) == SET)
	{
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2) == 0)
		{
			Encoder_Count --;
		}
		EXTI_ClearITPendingBit(EXTI_Line1);
	}
}

/**
  * @brief  Handles the EXTI2 interrupt for the rotary encoder.
  * @param	None
  * @retval	None
  */
void EXTI2_IRQHandler (void)
{
	if (EXTI_GetITStatus(EXTI_Line2) == SET)
	{
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1) == 0)
		{
			Encoder_Count ++;
		}
		EXTI_ClearITPendingBit(EXTI_Line2);
	}
}
