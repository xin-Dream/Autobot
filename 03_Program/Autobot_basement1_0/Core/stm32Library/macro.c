//
// Created by dream on 2021/6/11.
//

#include "macro.h"

/*
 * --引用的官方类型-----------------------------------------------------------------------------------------
 */
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

//extern ADC_HandleTypeDef hadc1;
//
//extern UART_HandleTypeDef huart1;
//extern UART_HandleTypeDef huart2;

/*
 * --自定义的内部全局类型-----------------------------------------------------------------------------------------
 */


Sensor_TypeDef sensors;

extern UARTParams_TypeDef uart1_params;
extern UARTParams_TypeDef uart2_params;


void ParamsInit() {
    OLED_Init();

//    __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
//    HAL_UART_Receive_DMA(&huart1, (uint8_t *) uart1_params.receive_buff, BUFFER_SIZE);
//
//    __HAL_UART_ENABLE_IT(&huart2, UART_IT_IDLE);
//    HAL_UART_Receive_DMA(&huart2, (uint8_t *) uart2_params.receive_buff, BUFFER_SIZE);
//
//    HAL_ADC_Start_DMA(&hadc1, sensors.ADC_Buff, ADC_CHANNEL_NUMBER);

    HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_2);

    HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_1);
    HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_2);

    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
}



