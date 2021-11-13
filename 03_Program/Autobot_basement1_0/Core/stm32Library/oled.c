//
// Created by dream on 2021/6/11.
//

#include "oled.h"
#include "oled.h"
#include "stdlib.h"
#include "oledfont.h"

//////////////////////////////////////////////////////////////////////////////////

//STM32F407开发板
//OLED 驱动代码

//////////////////////////////////////////////////////////////////////////////////

//OLED的显存
//存放格式如下.
//[0]0 1 2 3 ... 127
//[1]0 1 2 3 ... 127
//[2]0 1 2 3 ... 127
//[3]0 1 2 3 ... 127
//[4]0 1 2 3 ... 127
//[5]0 1 2 3 ... 127
//[6]0 1 2 3 ... 127
//[7]0 1 2 3 ... 127
uint8_t OLED_GRAM[128][8];

//更新显存到LCD
void OLED_Refresh_Gram(void) {
    uint8_t i, n;
    for (i = 0; i < 8; i++) {
        OLED_WR_Byte(0xb0 + i, OLED_CMD);    //设置页地址（0~7）
        OLED_WR_Byte(0x00, OLED_CMD);      //设置显示位置—列低地址
        OLED_WR_Byte(0x10, OLED_CMD);      //设置显示位置—列高地址
        for (n = 0; n < 128; n++)
            OLED_WR_Byte(OLED_GRAM[n][i], OLED_DATA);
    }
}

//向SSD1306写入一个字节。
//dat:要写入的数据/命令
//cmd:数据/命令标志 0,表示命令;1,表示数据;
void OLED_WR_Byte(uint8_t dat, uint8_t cmd) {
    uint8_t i;
    OLED_RS = cmd; //写命令
    OLED_CS = 0;
    for (i = 0; i < 8; i++) {
        OLED_SCLK = 0;
        if (dat & 0x80)
            OLED_SDIN = 1;
        else
            OLED_SDIN = 0;
        OLED_SCLK = 1;
        dat <<= 1;
    }
    OLED_CS = 1;
    OLED_RS = 1;
}

//开启OLED显示
void OLED_Display_On(void) {
    OLED_WR_Byte(0X8D, OLED_CMD);  //SET DCDC命令
    OLED_WR_Byte(0X14, OLED_CMD);  //DCDC ON
    OLED_WR_Byte(0XAF, OLED_CMD);  //DISPLAY ON
}

//关闭OLED显示
void OLED_Display_Off(void) {
    OLED_WR_Byte(0X8D, OLED_CMD);  //SET DCDC命令
    OLED_WR_Byte(0X10, OLED_CMD);  //DCDC OFF
    OLED_WR_Byte(0XAE, OLED_CMD);  //DISPLAY OFF
}

//清屏函数,清完屏,整个屏幕是黑色的!和没点亮一样!!!
void OLED_Clear(void) {
    uint8_t i, n;
    for (i = 0; i < 8; i++)
        for (n = 0; n < 128; n++)
            OLED_GRAM[n][i] = 0X00;
    OLED_Refresh_Gram();  //更新显示
}

//画点
//x:0~127
//y:0~63
//t:1 填充 0,清空
void OLED_DrawPoint(uint8_t x, uint8_t y, uint8_t t) {
    uint8_t pos, bx, temp = 0;
    if (x > 127 || y > 63) return;  //超出范围了.
    pos = 7 - y / 8;
    bx = y % 8;
    temp = 1 << (7 - bx);
    if (t)
        OLED_GRAM[x][pos] |= temp;
    else
        OLED_GRAM[x][pos] &= ~temp;
}

//x1,y1,x2,y2 填充区域的对角坐标
//确保x1<=x2;y1<=y2 0<=x1<=127 0<=y1<=63
//dot:0,清空;1,填充
void OLED_Fill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t dot) {
    uint8_t x, y;
    for (x = x1; x <= x2; x++) {
        for (y = y1; y <= y2; y++)
            OLED_DrawPoint(x, y, dot);
    }
    OLED_Refresh_Gram();  //更新显示
}

//在指定位置显示一个字符,包括部分字符
//x:0~127
//y:0~63
//mode:0,反白显示;1,正常显示
//size:选择字体 12/16/24
void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t size,
                   uint8_t mode) {
    uint8_t temp, t, t1;
    uint8_t y0 = y;
    uint8_t csize = (size / 8 + ((size % 8) ? 1 : 0)) * (size / 2);    //得到字体一个字符对应点阵集所占的字节数
    chr = chr - ' ';        //得到偏移后的值
    for (t = 0; t < csize; t++) {
        if (size == 12)
            temp = asc2_1206[chr][t];        //调用1206字体
        else if (size == 16)
            temp = asc2_1608[chr][t];    //调用1608字体
        else if (size == 24)
            temp = asc2_2412[chr][t];    //调用2412字体
        else
            return;                                //没有的字库
        for (t1 = 0; t1 < 8; t1++) {
            if (temp & 0x80)
                OLED_DrawPoint(x, y, mode);
            else
                OLED_DrawPoint(x, y, !mode);
            temp <<= 1;
            y++;
            if ((y - y0) == size) {
                y = y0;
                x++;
                break;
            }
        }
    }
}

//m^n函数
uint32_t mypow(uint8_t m, uint8_t n) {
    uint32_t result = 1;
    while (n--)
        result *= m;
    return result;
}

//显示2个数字
//x,y :起点坐标
//len :数字的位数
//size:字体大小
//mode:模式	0,填充模式;1,叠加模式
//num:数值(0~4294967295);
void OLED_ShowNum(uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t size) {
    uint8_t t, temp;
    uint8_t enshow = 0;
    for (t = 0; t < len; t++) {
        temp = (num / mypow(10, len - t - 1)) % 10;
        if (enshow == 0 && t < (len - 1)) {
            if (temp == 0) {
                OLED_ShowChar(x + (size / 2) * t, y, ' ', size, 1);
                continue;
            } else
                enshow = 1;

        }
        OLED_ShowChar(x + (size / 2) * t, y, temp + '0', size, 1);
    }
}

//显示字符串
//x,y:起点坐标
//size:字体大小
//*p:字符串起始地址
void OLED_ShowString(uint8_t x, uint8_t y, const uint8_t *p, uint8_t size) {
    while ((*p <= '~') && (*p >= ' '))                                //判断是不是非法字符!
    {
        if (x > (128 - (size / 2))) {
            x = 0;
            y += size;
        }
        if (y > (64 - size)) {
            y = x = 0;
            OLED_Clear();
        }
        OLED_ShowChar(x, y, *p, size, 1);
        x += size / 2;
        p++;
    }

}

//初始化SSD1306

void OLED_Init(void) {
//	GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitTypeDef GPIO_InitStruct = {0};

//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOC, ENABLE);//使能PB,PC时钟
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    //使用4线SPI 串口模式

    GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14
//			| GPIO_Pin_15;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;						//普通输出模式
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;						//推挽输出
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;					//100MHz
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;							//上拉
//	GPIO_Init(GPIOB, &GPIO_InitStructure);								//初始化
//
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;						//普通输出模式
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;						//推挽输出
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;					//100MHz
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;							//上拉
//	GPIO_Init(GPIOC, &GPIO_InitStructure);								//初始化

    OLED_SDIN = 1;
    OLED_SCLK = 1;

    OLED_CS = 1;
    OLED_RS = 1;

    OLED_RST = 0;                                //显示  系统复位
    HAL_Delay(100);
    OLED_RST = 1;
    HAL_Delay(100);

    OLED_WR_Byte(0xAE, OLED_CMD); //关闭显示
    OLED_WR_Byte(0xD5, OLED_CMD); //设置时钟分频因子,震荡频率
    OLED_WR_Byte(80, OLED_CMD);   //[3:0],分频因子;[7:4],震荡频率
    OLED_WR_Byte(0xA8, OLED_CMD); //设置驱动路数
    OLED_WR_Byte(0X3F, OLED_CMD); //默认0X3F(1/64)
    OLED_WR_Byte(0xD3, OLED_CMD); //设置显示偏移
    OLED_WR_Byte(0X00, OLED_CMD); //默认为0

    OLED_WR_Byte(0x40, OLED_CMD); //设置显示开始行 [5:0],行数.

    OLED_WR_Byte(0x8D, OLED_CMD); //电荷泵设置
    OLED_WR_Byte(0x14, OLED_CMD); //bit2，开启/关闭
    OLED_WR_Byte(0x20, OLED_CMD); //设置内存地址模式
    OLED_WR_Byte(0x02, OLED_CMD); //[1:0],00，列地址模式;01，行地址模式;10,页地址模式;默认10;
    OLED_WR_Byte(0xA1, OLED_CMD); //段重定义设置,bit0:0,0->0;1,0->127;
    OLED_WR_Byte(0xC0, OLED_CMD); //设置COM扫描方向;bit3:0,普通模式;1,重定义模式 COM[N-1]->COM0;N:驱动路数
    OLED_WR_Byte(0xDA, OLED_CMD); //设置COM硬件引脚配置
    OLED_WR_Byte(0x12, OLED_CMD); //[5:4]配置

    OLED_WR_Byte(0x81, OLED_CMD); //对比度设置
    OLED_WR_Byte(0xEF, OLED_CMD); //1~255;默认0X7F (亮度设置,越大越亮)
    OLED_WR_Byte(0xD9, OLED_CMD); //设置预充电周期
    OLED_WR_Byte(0xf1, OLED_CMD); //[3:0],PHASE 1;[7:4],PHASE 2;
    OLED_WR_Byte(0xDB, OLED_CMD); //设置VCOMH 电压倍率
    OLED_WR_Byte(0x30, OLED_CMD); //[6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc;

    OLED_WR_Byte(0xA4, OLED_CMD); //全局显示开启;bit0:1,开启;0,关闭;(白屏/黑屏)
    OLED_WR_Byte(0xA6, OLED_CMD); //设置显示方式;bit0:1,反相显示;0,正常显示
    OLED_WR_Byte(0xAF, OLED_CMD); //开启显示

    OLED_Clear();

}
