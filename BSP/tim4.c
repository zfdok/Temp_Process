#include "pbdata.h"

void TIM4_Init(void)
{
    TIM4_TimeBaseInit(TIM4_PRESCALER_16,100);//初始化定时器4
    TIM4_ARRPreloadConfig(ENABLE);//使能自动重装
    TIM4_ITConfig(TIM4_IT_UPDATE , ENABLE);//数据更新中断
    TIM4_Cmd(ENABLE);//开定时器
} 