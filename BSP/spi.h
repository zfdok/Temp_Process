#ifndef _SPI_H  //宏定义，定义文件名称
#define _SPI_H

/*---------------------------头文件引用--------------------------------------*/
#include "stm8s.h"//引用STM8头文件

void SPI_Configuration(void);
u8 SPI_SendByte(u8 byte);

#endif 