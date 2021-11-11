//
// Created by dream on 2021/6/11.
//

#ifndef INC_002_ARENA_MOTORCONTROL_H
#define INC_002_ARENA_MOTORCONTROL_H

#include "macro.h"


typedef struct {
	//编码器
	int L_encode_Dir;
	int R_encode_Dir;
	uint32_t L_encode;
	uint32_t R_encode;
	uint32_t lastCap;
	uint32_t simSpeed;        //电机模拟速度，无单位，60/1000对应100

	int speed;

	int motion_flag;

	float turn_coff;

} Motor_TypeDef;

/*
 * --函数----------------------------------------------------------------------------------------
 */


void motor_control(int L_speed, int R_speed);

void encode_read(TIM_HandleTypeDef L_tim, TIM_HandleTypeDef R_tim);

int limit_range(int speed, int limit_num);
#endif //INC_002_ARENA_MOTORCONTROL_H
