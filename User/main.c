#include "led.h"
#include "delay.h"
#include "sys.h"
#include "cJSON.h"
#include "usart.h"
#include "ADC.h"

//cjson移植地址:http://blog.csdn.net/yannanxiu/article/details/52712078

int main(void)
{
    u8 t;
    u8 len;
    //u16 times=0;
    u16 Adcx;
    float temp;

    SystemInit();//系统时钟等初始化
    delay_init(72);	     //延时初始化
    NVIC_Configuration();//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
    uart_init(9600);//串口初始化为960
    Adc_Init();
    LED_Init();
    printf("\n您发送的消息为:\n");

    while(1) {
        printf("Version: %s\n", cJSON_Version());
        if(USART_RX_STA&0x80) {
            len=USART_RX_STA&0x3f;//得到此次接收到的数据长度
            printf("\n您发送的消息为:\n");
            for(t=0; t<len; t++) {
                USART1->DR=USART_RX_BUF[t];
                while((USART1->SR&0X40)==0);//等待发送结束
            }
            printf("\n\n");//插入换行
            USART_RX_STA=0;
        } else {

            Adcx = Get_Adc(ADC_Channel_0);
            temp=(100.0-(float)Adcx*(100.0/4096));
            printf("\n\n");
            printf("%.1f%%\n\n",temp);
            printf("\n\n");
            delay_ms(500);
        }
    }

}

