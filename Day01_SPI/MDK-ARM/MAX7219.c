#include "MAX7219.h"
void Init_MAX7219(uint16_t deviceid)
{
    MX7219_Write(deviceid,0x09, 0x00); // 译码方式：BCD码
    MX7219_Write(deviceid,0x0a, 0x03); // 亮度
    MX7219_Write(deviceid,0x0b, 0x07); // 扫描界限；8个数码管显示
    MX7219_Write(deviceid,0x0c, 0x01); // 掉电模式：0，普通模式：1
    MX7219_Write(deviceid,0x0f, 0x00);
}
void MX7219_Write_Byte(uint8_t Data)
{
    HAL_SPI_Transmit(&hspi1, &Data, sizeof(Data), HAL_MAX_DELAY);
}
void MX7219_Write(uint16_t deviceid,uint8_t address, uint8_t Data)
{
    MAX7219_CS(deviceid,GPIO_PIN_RESET);
    MX7219_Write_Byte(address);
    MX7219_Write_Byte(Data);
    MAX7219_CS(deviceid,GPIO_PIN_SET);
}
void MAX7219_CS(uint16_t deviceid,GPIO_PinState PinState)
{   
    HAL_GPIO_WritePin(GPIOA, deviceid, PinState);
}
