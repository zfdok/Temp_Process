#include "pbdata.h"//�����Զ��幫��ͷ�ļ�

void BSP_Configuration(void);//Ӳ����ʼ����������

/***********************************************************************
*   �� �� ��: main
*   ����˵��: c�������
*   ��    �Σ���
*   �� �� ֵ: �������(���账��)
***********************************************************************/
int main(void)
{
  BSP_Configuration();//Ӳ��������ʼ������
  W25QXX_Demo();
  while(1)//������ѭ��������ִ��ѭ����������
  {
    
  }
}
/***********************************************************************
*   �� �� ��: BSP_Configuration
*   ����˵��: ��ʼ��Ӳ���豸��ֻ��Ҫ����һ�Ρ��ú�������CPU�Ĵ���������ļĴ�������ʼ��һЩȫ�ֱ�����
*   ��    �Σ���
*   �� �� ֵ: ��
***********************************************************************/
void BSP_Configuration(void)
{  
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);//ʱ���ٶ�Ϊ�ڲ�16M��1��Ƶ��
  UART1_Congfiguration();//���ô���1��ʼ������
  LED_Init();//����LED��ʼ������
  SPI_Configuration();
  W25QXX_GPIO();
  I2C_init();
  TIM4_Init();
  
  OLED_init();
  OLED_Welcome();
  delay_ms(2000);
  OLED_Display();
  rim();//�����ж�
}

/*���Ժ����������������ڱ�̵Ĺ�����Ϊ�����ṩ�������*/
#ifdef USE_FULL_ASSERT
void assert_failed(u8* file,u32 line)
{
  while(1)
  {
  }
}
#endif