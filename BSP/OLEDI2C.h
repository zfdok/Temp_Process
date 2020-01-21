/************************************************************************/

#ifndef _OLEDI2C_H  //宏定义，定义文件名称
#define _OLEDI2C_H
#include "stm8s.h"//引用STM8头文件

void I2C_init(void);
void I2C_SDA_DDR(u8 ddr);
void I2C_Start(void);
void I2C_Stop(void);
u8 I2C_WBit(u8 data);
void I2C_FindSlaver(u8 address);

#define PORT_I2C_SCL                GPIOE
#define PIN_I2C_SCL                 GPIO_PIN_1

#define PORT_I2C_SDA                GPIOE        
#define PIN_I2C_SDA                 GPIO_PIN_2

#endif //定义文件名称结束