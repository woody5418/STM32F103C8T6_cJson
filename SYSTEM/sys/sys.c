#include "sys.h"


//系统时钟初始化		   

void NVIC_Configuration(void)
{
    //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	
}
