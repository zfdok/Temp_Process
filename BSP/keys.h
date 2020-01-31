#ifndef _KEYS_H  //宏定义，定义文件名称
#define _KEYS_H

/*---------------------------头文件引用--------------------------------------*/
#include "stm8s.h"//引用STM8头文件

/*---------------------------宏定义声明--------------------------------------*/
#define K1_PIN  GPIO_PIN_0   //定义GPIO_PIN_4引脚为K1_PIN，相当于重新命名。
#define K1_PORT GPIOC        //定义GPIOE端口为K1_PORT，相当于重新命名。
#define K1_EXTI_PORT EXTI_PORT_GPIOC//定义EXTI_PORT_GPIOE端口为K1_EXTI_PORT，相当于重新命名。


/*---------------------------函数声明--------------------------------------*/
void KEY_Init(void);  //LED初始化函数
bool KEY_Down(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin);
void KEY_Press(void);
#endif //定义文件名称结束