#include "pbdata.h"

void I2C_init(void)
{
    GPIO_Init(PORT_I2C_SCL, PIN_I2C_SCL, GPIO_MODE_OUT_PP_LOW_FAST);
}
void I2C_SDA_DDR(u8 ddr)
{
    if (ddr)
    {
      GPIO_Init(PORT_I2C_SDA, PIN_I2C_SDA, GPIO_MODE_OUT_PP_LOW_FAST);
    }
    else
    {
      GPIO_Init(PORT_I2C_SDA, PIN_I2C_SDA, GPIO_MODE_IN_FL_NO_IT);
    }
}
void I2C_Start(void)
{
    I2C_SDA_DDR(1);
    GPIO_WriteHigh(PORT_I2C_SDA, PIN_I2C_SDA);
    GPIO_WriteHigh(PORT_I2C_SCL, PIN_I2C_SCL);
    delay_us(1);
    GPIO_WriteLow(PORT_I2C_SDA, PIN_I2C_SDA);
    delay_us(1);
    GPIO_WriteLow(PORT_I2C_SCL, PIN_I2C_SCL);
    delay_us(1);
}
void I2C_Stop(void)
{
    I2C_SDA_DDR(1);
    GPIO_WriteLow(PORT_I2C_SDA, PIN_I2C_SDA);
    GPIO_WriteLow(PORT_I2C_SCL, PIN_I2C_SCL);
    delay_us(1);
    GPIO_WriteHigh(PORT_I2C_SCL, PIN_I2C_SCL);
    delay_us(1);
    GPIO_WriteHigh(PORT_I2C_SDA, PIN_I2C_SDA);
    delay_us(1);
}
u8 I2C_WBit(u8 data)
{
    u8 num=0,iic_wbit_ACK=0;
    I2C_SDA_DDR(1);
    for (num = 0X80;num!=0;num >>= 1)
    {
        if(data & num) {GPIO_WriteHigh(PORT_I2C_SDA, PIN_I2C_SDA);}
        else {GPIO_WriteLow(PORT_I2C_SDA, PIN_I2C_SDA);}
        delay_us(1);
        GPIO_WriteHigh(PORT_I2C_SCL, PIN_I2C_SCL);        //GPIO_WriteHigh(PORT_I2C_SCL, PIN_I2C_SCL);保持数据，从端采集
        delay_us(1);
        GPIO_WriteLow(PORT_I2C_SCL, PIN_I2C_SCL);        //GPIO_WriteLow(PORT_I2C_SCL, PIN_I2C_SCL);又可以改写SDA数据了
        delay_us(1);
    }
    GPIO_WriteHigh(PORT_I2C_SDA, PIN_I2C_SDA);
    delay_us(1);
    I2C_SDA_DDR(0);
    GPIO_WriteHigh(PORT_I2C_SCL, PIN_I2C_SCL);
    delay_us(1);
    iic_wbit_ACK=GPIO_ReadInputPin(PORT_I2C_SDA, PIN_I2C_SDA);
    delay_us(1);
    GPIO_WriteLow(PORT_I2C_SCL, PIN_I2C_SCL);
    return iic_wbit_ACK;
}
/*********************寻找IIC从机************************************/
void I2C_FindSlaver(u8 address)
{
    u8 ACK=0;
    printf("测试IIC寻址at24c02:\r\n");
    I2C_Start();
    ACK=I2C_WBit(0XA0);
    if (ACK)
    {
        printf("there's no slaver at 0x%x\r\n",address);
    }
    else
    {
        printf("FIND a slaver at 0x%x!\r\n",address);
    }
}