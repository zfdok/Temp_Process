#ifndef _KEYS_H  //�궨�壬�����ļ�����
#define _KEYS_H

/*---------------------------ͷ�ļ�����--------------------------------------*/
#include "stm8s.h"//����STM8ͷ�ļ�

/*---------------------------�궨������--------------------------------------*/
#define K1_PIN  GPIO_PIN_0   //����GPIO_PIN_4����ΪK1_PIN���൱������������
#define K1_PORT GPIOC        //����GPIOE�˿�ΪK1_PORT���൱������������
#define K1_EXTI_PORT EXTI_PORT_GPIOC//����EXTI_PORT_GPIOE�˿�ΪK1_EXTI_PORT���൱������������


/*---------------------------��������--------------------------------------*/
void KEY_Init(void);  //LED��ʼ������
bool KEY_Down(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin);
void KEY_Press(void);
#endif //�����ļ����ƽ���