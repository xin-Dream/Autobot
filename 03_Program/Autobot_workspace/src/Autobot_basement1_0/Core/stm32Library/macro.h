//
// Created by dream on 2021/6/11.
//

#ifndef INC_002_ARENA_MACRO_H
#define INC_002_ARENA_MACRO_H

/*
 * --头文件-----------------------------------------------------------------------------------------
 */

#include "main.h"
#include "oled.h"
#include "string.h"
#include "stdio.h"
#include "motorControl.h"
#include "communication.h"
#include "algorithm.h"

#include "robot.h"
/*
 * --函数-----------------------------------------------------------------------------------------
 */

// 开启串口功能，具体函数在commuication文件中
#define USART_ENABLE

void OLED_SHOW();

/*
 * --函数-----------------------------------------------------------------------------------------
 */
void ParamsInit();






/*
 * --定义结构体-----------------------------------------------------------------------------------------
 */
/**
  * @brief Uart Parm Init structure definition
  */




/**
  * @brief JY60 Params Init structure definition
  */
#define ADC_CHANNEL_NUMBER  10
typedef struct {

	uint16_t PITCH;
	uint16_t ROLL;
	uint16_t YAW;
	short Angle[3];
	short T;

	uint32_t ADC_Buff[ADC_CHANNEL_NUMBER];
	uint32_t Range_around[4];
	uint32_t Range_forward[2];
	uint32_t Range_below[2];
	uint32_t Gray[3];

	int motion_flag;
} Sensor_TypeDef;

/**
  * @brief PID Params Init structure definition
  */
typedef struct {
	__IO int32_t SetPoint;        //设定目标 Desired Value
	__IO float SumError;        //误差累计
	__IO float Proportion;    //比例常数 Proportional Const
	__IO float Integral;        //积分常数 Integral Const
	__IO float Derivative;    //微分常数 Derivative Const
	__IO int LastError;        //Error[-1]
	__IO int PrevError;        //Error[-2]

} PID_TypeDef;


/**
  * @brief motor Params Init structure definition
  */


//
//#define MAXSPEED    600
//
//#define forward     1
//#define backward    2
//#define left        3
//#define right       4
//#define stop        5
//#define wait        6
//
//#define roll        7
//#define start_judge 8


/* 四舍五入 */
//将浮点数x四舍五入为int32_t
#define ROUND_TO_INT32(x)   ((int32_t)(x)+0.5f)>=(x)? ((int32_t)(x)):((uint32_t)(x)+1)


/*
 * -------------------------------------------------------------------------------------------
 */
//位带操作,实现51类似的GPIO控制功能
//具体实现思想,参考<<CM3权威指南>>第五章(87页~92页).M4同M3类似,只是寄存器地址变了.
//IO口操作宏定义
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum))
//IO口地址映射
#define GPIOA_ODR_Addr    (GPIOA_BASE+20) //0x40020014
#define GPIOB_ODR_Addr    (GPIOB_BASE+20) //0x40020414
#define GPIOC_ODR_Addr    (GPIOC_BASE+20) //0x40020814
#define GPIOD_ODR_Addr    (GPIOD_BASE+20) //0x40020C14
#define GPIOE_ODR_Addr    (GPIOE_BASE+20) //0x40021014
#define GPIOF_ODR_Addr    (GPIOF_BASE+20) //0x40021414
#define GPIOG_ODR_Addr    (GPIOG_BASE+20) //0x40021814
#define GPIOH_ODR_Addr    (GPIOH_BASE+20) //0x40021C14
#define GPIOI_ODR_Addr    (GPIOI_BASE+20) //0x40022014

#define GPIOA_IDR_Addr    (GPIOA_BASE+16) //0x40020010
#define GPIOB_IDR_Addr    (GPIOB_BASE+16) //0x40020410
#define GPIOC_IDR_Addr    (GPIOC_BASE+16) //0x40020810
#define GPIOD_IDR_Addr    (GPIOD_BASE+16) //0x40020C10
#define GPIOE_IDR_Addr    (GPIOE_BASE+16) //0x40021010
#define GPIOF_IDR_Addr    (GPIOF_BASE+16) //0x40021410
#define GPIOG_IDR_Addr    (GPIOG_BASE+16) //0x40021810
#define GPIOH_IDR_Addr    (GPIOH_BASE+16) //0x40021C10
#define GPIOI_IDR_Addr    (GPIOI_BASE+16) //0x40022010

//IO口操作,只对单一的IO口!
//确保n的值小于16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //输出
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //输入

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //输出
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //输入

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //输出
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //输入

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //输出
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //输入

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //输出
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //输入

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //输出
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //输入

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //输出
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //输入

#define PHout(n)   BIT_ADDR(GPIOH_ODR_Addr,n)  //输出
#define PHin(n)    BIT_ADDR(GPIOH_IDR_Addr,n)  //输入

#define PIout(n)   BIT_ADDR(GPIOI_ODR_Addr,n)  //输出
#define PIin(n)    BIT_ADDR(GPIOI_IDR_Addr,n)  //输入

#endif //INC_002_ARENA_MACRO_H
