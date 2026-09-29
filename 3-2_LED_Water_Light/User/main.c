#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	//使能gpioA的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	//初始化结构体
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_3 ;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;

	//使用刚刚定义的结构体初始化指定的gpio端口
	GPIO_Init(GPIOA, &GPIO_Initstructure);

	
	while (1)
	{
		GPIO_Write(GPIOA, 0x0001);	//0b 0000 0000 0000 0001
		Delay_ms(500);
		GPIO_Write(GPIOA, ~0x0001);	//0b 0000 0000 0000 0001
		Delay_ms(500);
		
		GPIO_Write(GPIOA, 0x0008);	//0b 0000 0000 0000 1000
		Delay_ms(500);
		GPIO_Write(GPIOA, ~0x0008);	//0b 0000 0000 0000 1000
		Delay_ms(500);
	}
}

