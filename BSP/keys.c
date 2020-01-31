#include "pbdata.h"

void KEY_Init(void)
{
    GPIO_Init(K1_PORT, K1_PIN, GPIO_MODE_IN_PU_IT);//初始化K1键盘管脚为浮动输入有中断功能
    EXTI_SetExtIntSensitivity(K1_EXTI_PORT, EXTI_SENSITIVITY_FALL_ONLY);//配置中断触发方式为仅下降沿触发
    ITC_SetSoftwarePriority(ITC_IRQ_PORTC,ITC_PRIORITYLEVEL_3 );//配置软件优先级为 2 
}

/*********************************************************************************
*   函 数 名: KEY_Down
*   功能说明: 键盘检测消斗
*   形    参：GPIO_TypeDef* GPIOx  输入要检测的端口
*             GPIO_Pin_TypeDef GPIO_Pin  输入要检测的引脚
*   返 回 值: 布尔类型 (true 按下，flase 弹起)
*********************************************************************************/
bool KEY_Down(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin)
{
  //检测是否有按键按下
  if(GPIO_ReadInputPin(GPIOx,GPIO_Pin)==0)//是否为低电平，低电平按下，高电平弹起
  {    
    delay_ms(20);//延时20毫秒消抖
    if(GPIO_ReadInputPin(GPIOx,GPIO_Pin)==0)//再一次检测键盘是否有按下
    {
      //低电平为真(等待)   高电平为假(退出WHILE循环)
      while(GPIO_ReadInputPin(GPIOx,GPIO_Pin)==0);
      return true;//函数返回真
    }
  }
  return false;//函数返回假
}
/*********************************************************************************
*   函 数 名: KEY_Demo
*   功能说明: 键盘输入检测
*   形    参：无
*   返 回 值: 无
*********************************************************************************/
void KEY_Press(void)
{
    if(KEY_Down(K1_PORT,K1_PIN)==true)
    {
        printf("K1/r/n");//此处添加里昂程序
        time_shutOLED_count=0;
        OLED_Display();
        TempGetAndSave();
        OLED_ON_FLAG=1;
    }
}