/************************ �Զ��幫��ͷ�ļ� **************************************/

#ifndef _PBDATA_H//�궨�壬�����ļ�����
#define _PBDATA_H


#include "stm8s.h"//����STM8��ͷ�ļ�
#include <stdio.h>//��Ҫ�������ͷ�ļ�����ʵ��
#include "math.h"//��Ҫ�������ͷ�ļ�����ʵ��
#include "string.h"

#include "led.h"  //����LEDͷ�ļ�
#include "uart1.h"//����RS232ͷ�ļ�
#include "spi.h"
#include "w25qxx.h"
#include "OLEDI2C.h"
#include "OLED12864.h"
#include "DS18B20.h"
#include "tim4.h"



void delay_us(u16 nCount); //΢����ʱ����
void delay_ms(u16 nCount); //������ʱ����
u16 Get_decimal(double dt,u8 deci);   //�����ֵС������
void delay(u16 count);

#endif //�����ļ����ƽ���


/************************ ��̳��ַ www.zxkjmcu.com ******************************/