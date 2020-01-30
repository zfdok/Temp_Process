/************************ 自定义公共头文件 **************************************/

#ifndef _PBDATA_H//宏定义，定义文件名称
#define _PBDATA_H


#include "stm8s.h"//引入STM8的头文件
#include <stdio.h>//需要引用这个头文件才能实现
#include "math.h"//需要引用这个头文件才能实现
#include "string.h"

#include "led.h"  //引用LED头文件
#include "uart1.h"//引用RS232头文件
#include "spi.h"
#include "w25qxx.h"
#include "OLEDI2C.h"
#include "OLED12864.h"
#include "DS18B20.h"
#include "tim4.h"



void delay_us(u16 nCount); //微秒延时程序
void delay_ms(u16 nCount); //毫秒延时程序
u16 Get_decimal(double dt,u8 deci);   //获得数值小数部分
void delay(u16 count);

#endif //定义文件名称结束


/************************ 论坛地址 www.zxkjmcu.com ******************************/