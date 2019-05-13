#ifndef __LED_H
#define __LED_H	 
#include "stm32f10x.h"


//LED端口定义
#define LED_Hint_Red                PBout(5)
#define LED_Normal_Operation_Green  PBout(6)

void LED_Init(void);//初始化

		 	 				    
#endif
