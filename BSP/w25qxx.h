#ifndef _W25QXX_H  //宏定义，定义文件名称
#define _W25QXX_H

/*---------------------------头文件引用--------------------------------------*/
#include "stm8s.h"//引用STM8头文件

/*---------------------------宏定义声明--------------------------------------*/
#define W25Q_CS_PIN GPIO_PIN_5
#define W25Q_CS_PORT GPIOE

//如果想用其他管脚控制LED,那么只需更改上面对应的端口与引脚编号即可

#define W25Q_CS_L GPIO_WriteLow(W25Q_CS_PORT,W25Q_CS_PIN); 
#define W25Q_CS_H GPIO_WriteHigh(W25Q_CS_PORT,W25Q_CS_PIN);


//指令表
#define W25X_WriteEnable		0x06 
#define W25X_WriteDisable		0x04 
#define W25X_ReadStatusReg		0x05 
#define W25X_WriteStatusReg		0x01 
#define W25X_ReadData			0x03 
#define W25X_FastReadData		0x0B 
#define W25X_FastReadDual		0x3B 
#define W25X_PageProgram		0x02 
#define W25X_BlockErase			0xD8 
#define W25X_SectorErase		0x20 
#define W25X_ChipErase			0xC7 
#define W25X_PowerDown			0xB9 
#define W25X_ReleasePowerDown	        0xAB 
#define W25X_DeviceID			0xAB 
#define W25X_ManufactDeviceID	        0x90 
#define W25X_JedecDeviceID		0x9F 

void W25QXX_GPIO(void);
void W25QXX_Demo(void);
#endif 