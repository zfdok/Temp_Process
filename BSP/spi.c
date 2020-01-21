#include "pbdata.h"

void SPI_Configuration(void)
{
    SPI_Init(SPI_FIRSTBIT_MSB,SPI_BAUDRATEPRESCALER_4,SPI_MODE_MASTER,SPI_CLOCKPOLARITY_LOW,SPI_CLOCKPHASE_1EDGE,SPI_DATADIRECTION_2LINES_FULLDUPLEX,SPI_NSS_SOFT,0x07);
    SPI_Cmd(ENABLE);
}

u8 SPI_SendByte(u8 byte)
{
    while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
    SPI_SendData(byte);
    
    while(SPI_GetFlagStatus(SPI_FLAG_RXNE)==RESET);
    return SPI_ReceiveData();
}
