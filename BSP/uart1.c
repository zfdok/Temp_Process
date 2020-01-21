#include "pbdata.h"
/*********************************************************************************
*   �� �� ��: UART1_Congfiguration
*   ����˵��: UART1 ���ú���
*   ��    �Σ���
*   �� �� ֵ: ��
*********************************************************************************/
void UART1_Congfiguration(void)
{
    //���ô��ڲ���Ϊ��������115200��8λ����λ��1λֹͣλ����У�飬��ֹͬ�����䣬�������շ���
    UART1_Init((u32)115200,UART1_WORDLENGTH_8D,UART1_STOPBITS_1,UART1_PARITY_NO,UART1_SYNCMODE_CLOCK_DISABLE,UART1_MODE_TXRX_ENABLE);
    UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);//ʹ�ܽ����ж�
    UART1_Cmd(ENABLE);//ʹ��UART1
}
/*********************************************************************************
*   �� �� ��: UART1_Send_Byte
*   ����˵��: UART1�������ݺ���
*   ��    �Σ�u8 byte  һ�η���һ���ֽ�
*   �� �� ֵ: ��
*********************************************************************************/
void UART1_Send_Byte(u8 byte)
{
    UART1_SendData8(byte);//UART1����8λ����
    while(UART1_GetFlagStatus(UART1_FLAG_TXE)==RESET);//�ȴ��������
}

void UART1_Printf_Demo(void)
{
  double d4=(double)145.23412;
  printf("%d.%d\r\n",(u16)d4,Get_decimal(d4,4));
  printf("%d.%d\r\n",(u16)d4,Get_decimal(d4,2));
  while(1);
}


//printf����
#ifdef __GNUC__
    #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
    #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

PUTCHAR_PROTOTYPE //����һ���ַ�Э��
{
/* ��Printf���ݷ������� */
  UART1_SendData8((unsigned char) ch);
  while (!(UART1->SR & UART1_FLAG_TXE));//�������δ��ɣ� //��־λδ��λ����ѭ���ȴ�
  return (ch);
}


/************************ ��̳��ַ www.zxkjmcu.com ******************************/