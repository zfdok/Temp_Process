#include "pbdata.h"

void KEY_Init(void)
{
    GPIO_Init(K1_PORT, K1_PIN, GPIO_MODE_IN_PU_IT);//��ʼ��K1���̹ܽ�Ϊ�����������жϹ���
    EXTI_SetExtIntSensitivity(K1_EXTI_PORT, EXTI_SENSITIVITY_FALL_ONLY);//�����жϴ�����ʽΪ���½��ش���
    ITC_SetSoftwarePriority(ITC_IRQ_PORTC,ITC_PRIORITYLEVEL_3 );//����������ȼ�Ϊ 2 
}

/*********************************************************************************
*   �� �� ��: KEY_Down
*   ����˵��: ���̼������
*   ��    �Σ�GPIO_TypeDef* GPIOx  ����Ҫ���Ķ˿�
*             GPIO_Pin_TypeDef GPIO_Pin  ����Ҫ��������
*   �� �� ֵ: �������� (true ���£�flase ����)
*********************************************************************************/
bool KEY_Down(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin)
{
  //����Ƿ��а�������
  if(GPIO_ReadInputPin(GPIOx,GPIO_Pin)==0)//�Ƿ�Ϊ�͵�ƽ���͵�ƽ���£��ߵ�ƽ����
  {    
    delay_ms(20);//��ʱ20��������
    if(GPIO_ReadInputPin(GPIOx,GPIO_Pin)==0)//��һ�μ������Ƿ��а���
    {
      //�͵�ƽΪ��(�ȴ�)   �ߵ�ƽΪ��(�˳�WHILEѭ��)
      while(GPIO_ReadInputPin(GPIOx,GPIO_Pin)==0);
      return true;//����������
    }
  }
  return false;//�������ؼ�
}
/*********************************************************************************
*   �� �� ��: KEY_Demo
*   ����˵��: ����������
*   ��    �Σ���
*   �� �� ֵ: ��
*********************************************************************************/
void KEY_Press(void)
{
    if(KEY_Down(K1_PORT,K1_PIN)==true)
    {
        printf("K1/r/n");//�˴�����ﰺ����
        time_shutOLED_count=0;
        OLED_Display();
        TempGetAndSave();
        OLED_ON_FLAG=1;
    }
}