#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	//使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	//初始化结构体
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;

	//使用刚刚定义的结构体初始化指定的gpio端口
	GPIO_Init(GPIOA, &GPIO_Initstructure);
	
	//GPIO_ResetBits(GPIOA, GPIO_Pin_0);
	//GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
	
	
	while (1)
	{
		//led亮500ms
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		Delay_ms(500);
		
		
		//使用占空比控制led以20%的亮度亮500ms
		for(int i = 0; i < 50; i++){
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		Delay_ms(2);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		Delay_ms(8);
		}
		
		//GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		//Delay_ms(500);
	}
}

