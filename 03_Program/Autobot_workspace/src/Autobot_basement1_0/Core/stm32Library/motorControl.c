//
// Created by dream on 2021/6/11.
//

#include "motorControl.h"


extern TIM_HandleTypeDef htim3;

Motor_TypeDef motor;

/*
 * --函数-----------------------------------------------------------------------------------------
 */


/**
 * @brief encode read motor Function
 * @param motorSide:left/right speed:0-1000
 * @retval None
 */

void encode_read(TIM_HandleTypeDef L_tim, TIM_HandleTypeDef R_tim) {

	motor.L_encode = __HAL_TIM_GET_COUNTER(&L_tim);
	motor.R_encode = __HAL_TIM_GET_COUNTER(&R_tim);

	motor.L_encode_Dir = __HAL_TIM_IS_TIM_COUNTING_DOWN(&L_tim);
	motor.R_encode_Dir = __HAL_TIM_IS_TIM_COUNTING_DOWN(&R_tim);

//	if (motor.L_encode_Dir && motor.L_encode != 0) {
//		motor.L_encode = limit_range((60000 - motor.L_encode), (MAXSPEED * 0.7));
//	}
//
//	if (motor.R_encode_Dir && motor.R_encode != 0) {
//		motor.R_encode = limit_range((60000 - motor.R_encode), (MAXSPEED * 0.7));
//	}

	__HAL_TIM_SET_COUNTER(&L_tim, 0);
	__HAL_TIM_SET_COUNTER(&R_tim, 0);
}

/**
 * @brief Motor Control Function
 * @param motorSide:left/right speed:0-1000
 * @retval None
 */
void motor_control(int L_speed, int R_speed) {
//	L_speed = limit_range(L_speed, MAXSPEED);
//	R_speed = limit_range(R_speed, MAXSPEED);

	if (L_speed < 0) {
		L_speed = -L_speed;
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0);
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, L_speed);
	} else if (L_speed >= 0) {
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, L_speed);
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0);
	}

	if (R_speed < 0) {
		R_speed = -R_speed;
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, R_speed);
	} else if (L_speed >= 0) {
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, R_speed);
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);
	}
}

/**
 * @brief limit max speed Function
 * @param set speed
 * @return speed in limit range
 * @retval None
 */
int limit_range(int speed, int limit_num) {
	if (speed > limit_num) {
		speed = limit_num;
	}
	if (speed < -limit_num) {
		speed = -limit_num;
	}
	return speed;
}

/*
 * PID控制器-------------------------------------------------------------------------------------
 */
int PID_Control(int SetPoint, int CurrentPoint, PID_TypeDef pid_params) {
	int result;

	pid_params.LastError = CurrentPoint - SetPoint;
	pid_params.SumError += pid_params.LastError;

	result = pid_params.LastError * pid_params.Proportion +
			pid_params.SumError * pid_params.Integral +
			(pid_params.LastError - pid_params.PrevError) * pid_params.Derivative;

	pid_params.PrevError = pid_params.LastError;

	return result;
}
