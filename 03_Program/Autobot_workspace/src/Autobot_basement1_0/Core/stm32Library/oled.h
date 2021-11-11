//
// Created by dream on 2021/6/11.
//

#ifndef INC_002_ARENA_OLED_H
#define INC_002_ARENA_OLED_H

#include "stdlib.h"
#include "macro.h"

//////////////////////////////////////////////////////////////////////////////////

//STM32F407开发板
//OLED 驱动代码

//////////////////////////////////////////////////////////////////////////////////


//OLED模式设置
//4线串行模式


//-----------------OLED端口定义----------------
#define OLED_CS 	PBout(12)
#define OLED_RST  	PBout(14)
#define OLED_RS 	PCout(5)


//使用4线串行接口时使用
#define OLED_SCLK 	PBout(13)
#define OLED_SDIN 	PBout(15)

#define OLED_CMD  	0		//写命令
#define OLED_DATA 	1		//写数据
//OLED控制用函数
void OLED_WR_Byte(uint8_t dat,uint8_t cmd);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Refresh_Gram(void);

void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(uint8_t x,uint8_t y,uint8_t t);
void OLED_Fill(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t dot);
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t size,uint8_t mode);
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size);
void OLED_ShowString(uint8_t x,uint8_t y,const uint8_t *p,uint8_t size);
//void OLED_Show(void);

#endif //INC_002_ARENA_OLED_H
