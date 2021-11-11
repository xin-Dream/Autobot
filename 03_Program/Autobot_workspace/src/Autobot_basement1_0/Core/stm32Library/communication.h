//
// Created by dream on 2021/6/11.
//

#ifndef INC_002_ARENA_COMMUNICATION_H
#define INC_002_ARENA_COMMUNICATION_H


#include "macro.h"




//======================================================================================


//=====================================================================================

#if defined(USART_ENABLE)

void myuart_DMA(UART_HandleTypeDef *huart);

#endif
//=====================================================================================


#define MAX_RECV_LEN    1024
#define BUFFER_SIZE     255

typedef struct {
	//串口中断用参数
	uint8_t msg_buff[MAX_RECV_LEN];
	uint8_t *msg;

	//DMA+空闲中断用参数
	uint8_t receive_buff[BUFFER_SIZE];

} UARTParams_TypeDef;


#endif //INC_002_ARENA_COMMUNICATION_H
