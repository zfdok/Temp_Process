#include "pbdata.h"

void TIM4_Init(void)
{
    TIM4_TimeBaseInit(TIM4_PRESCALER_16,100);//��ʼ����ʱ��4
    TIM4_ARRPreloadConfig(ENABLE);//ʹ���Զ���װ
    TIM4_ITConfig(TIM4_IT_UPDATE , ENABLE);//���ݸ����ж�
    TIM4_Cmd(ENABLE);//����ʱ��
} 