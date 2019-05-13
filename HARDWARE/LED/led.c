#include "stm32f10x.h"
#include "led.h"

//初始化PB5和PB6为输出口.并使能这两个口的时钟		    
//LED IO初始化
void LED_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;		
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能PA端口时钟	
	
	GPIO_InitStructure.GPIO_Pin = (GPIO_Pin_15|GPIO_Pin_14);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOB,(GPIO_Pin_15|GPIO_Pin_14));	//PA.8 输出低
}





