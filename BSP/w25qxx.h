#ifndef _W25QXX_H  //�궨�壬�����ļ�����
#define _W25QXX_H

/*---------------------------ͷ�ļ�����--------------------------------------*/
#include "stm8s.h"//����STM8ͷ�ļ�

/*---------------------------�궨������--------------------------------------*/
#define W25Q_CS_PIN GPIO_PIN_5
#define W25Q_CS_PORT GPIOE

//������������ܽſ���LED,��ôֻ����������Ӧ�Ķ˿������ű�ż���

#define W25Q_CS_L GPIO_WriteLow(W25Q_CS_PORT,W25Q_CS_PIN); 
#define W25Q_CS_H GPIO_WriteHigh(W25Q_CS_PORT,W25Q_CS_PIN);


//ָ���
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