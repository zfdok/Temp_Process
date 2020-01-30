#include "pbdata.h"//引入自定义公共头文件

void BSP_Configuration(void);//硬件初始化函数声明

/***********************************************************************
*   函 数 名: main
*   功能说明: c程序入口
*   形    参：无
*   返 回 值: 错误代码(无需处理)
***********************************************************************/
int main(void)
{
  BSP_Configuration();//硬件驱动初始化函数
  W25QXX_Demo();
  while(1)//主程序循环，反复执行循环体里的语句
  {
    
  }
}
/***********************************************************************
*   函 数 名: BSP_Configuration
*   功能说明: 初始化硬件设备。只需要调用一次。该函数配置CPU寄存器和外设的寄存器并初始化一些全局变量。
*   形    参：无
*   返 回 值: 无
***********************************************************************/
void BSP_Configuration(void)
{  
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);//时钟速度为内部16M，1分频，
  UART1_Congfiguration();//调用串口1初始化函数
  LED_Init();//调用LED初始化函数
  SPI_Configuration();
  W25QXX_GPIO();
  I2C_init();
  TIM4_Init();
  
  OLED_init();
  OLED_Welcome();
  delay_ms(2000);
  OLED_Display();
  rim();//打开总中断
}

/*断言函数：它的作用是在编程的过程中为程序提供参数检查*/
#ifdef USE_FULL_ASSERT
void assert_failed(u8* file,u32 line)
{
  while(1)
  {
  }
}
#endif