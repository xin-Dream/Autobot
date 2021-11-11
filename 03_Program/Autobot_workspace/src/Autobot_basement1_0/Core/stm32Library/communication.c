//
// Created by dream on 2021/6/11.
//

#include "communication.h"
#include "main.h"


#if defined(USART_ENABLE)

//======================================================================================
//函数定义

void myuartDMA_callback(UART_HandleTypeDef *huart, DMA_HandleTypeDef hdma_usart1_rx);

void JY60_Callback(UART_HandleTypeDef *huart);

//使用DMA，串口空闲中断收发数据


extern DMA_HandleTypeDef hdma_usart1_rx;

/*
* 在USART1_IRQHandler()中添加本函数，用来处理串口空闲中断
*
* 在main函数添加如下函数：
* __HAL_UART_ENABLE_IT(&huart2, UART_IT_IDLE);
HAL_UART_Receive_DMA(&huart2, (uint8_t*) uart1.receive_buff, BUFFER_SIZE);
*/

void myuart_DMA(UART_HandleTypeDef *huart) {
	if (huart->Instance == USART1) {
		if (RESET != __HAL_UART_GET_FLAG(huart, UART_FLAG_IDLE))  //判断是不是串口空闲中断
		{
			__HAL_UART_CLEAR_IDLEFLAG(huart);                      //清楚串口空闲中断标志
			//			printf("/r/n  detecting /r/n");

			//			HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
		}

	}
	if (huart->Instance == USART2) {
		if (RESET != __HAL_UART_GET_FLAG(huart, UART_FLAG_IDLE))  //判断是不是串口空闲中断
		{
			__HAL_UART_CLEAR_IDLEFLAG(huart);                      //清楚串口空闲中断标志
			//			printf("/r/n  detecting /r/n");

			//			HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
		}

	}

}

//=====================================================================================
//自定义回调函数
UARTParams_TypeDef uart1_params;
UARTParams_TypeDef uart2_params;

void myuartDMA_callback(UART_HandleTypeDef *huart, DMA_HandleTypeDef hdma_usart1_rx) {
	HAL_UART_DMAStop(huart);


	uint8_t data_length = BUFFER_SIZE - __HAL_DMA_GET_COUNTER(&hdma_usart1_rx); //计算收到数据的长度

	//	printf("length: %d\r\n", data_length);

	HAL_UART_Transmit(huart, uart1_params.receive_buff, data_length, 0x200); //测试用，发出接收到的数据
	//	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);

	//添加处理接收数据的代码，接收数据存在receive_buff内

	//--------------------------------------------------
	memset(uart1_params.receive_buff, 0, data_length);                       //清零接收缓冲区
	data_length = 0;

	HAL_UART_Receive_DMA(huart, (uint8_t *) uart1_params.receive_buff, BUFFER_SIZE); //重新开启DMA传输，每次255字节数
}


extern UART_HandleTypeDef huart2;
extern DMA_HandleTypeDef hdma_usart2_rx;

UARTParams_TypeDef uart2_params;

/*
 * IMU模块串口接收数据
 * 数据头0x55
 */


extern Sensor_TypeDef sensors;

void JY60_Callback(UART_HandleTypeDef *huart) {
	HAL_UART_DMAStop(huart);

	uint8_t data_length = BUFFER_SIZE - __HAL_DMA_GET_COUNTER(&hdma_usart2_rx); //计算收到数据的长度
	//
	//	printf("length: %d", data_length);

	//	HAL_UART_Transmit(&huart1, uart2.receive_buff, data_length, 0x200); //测试用，发出接收到的数据

	//添加处理接收数据的代码，接收数据存在receive_buff内
	if (uart2_params.receive_buff[0] == 0x55) {
		switch (uart2_params.receive_buff[23]) {

			//			case 0x51:	//加速度包
			//				a[0] = (receive_buff2[3] << 8 | receive_buff2[2]);
			//				a[1] = (receive_buff2[5] << 8 | receive_buff2[4]);
			//				a[2] = (receive_buff2[7] << 8 | receive_buff2[6]);
			//				Temperature = (receive_buff2[9] << 8 | receive_buff2[8]);
			//				break;
			//
			//			case 0x52:	//角速度包
			//				w[0] = (receive_buff2[3] << 8 | receive_buff2[2]);
			//				w[1] = (receive_buff2[5] << 8 | receive_buff2[4]);
			//				w[2] = (receive_buff2[7] << 8 | receive_buff2[6]);
			//				Temperature = (receive_buff2[9] << 8 | receive_buff2[8]);
			//				break;

			case 0x53:    //角度包
				//				angle[0] = (receive_buff2[3] << 8 | receive_buff2[2]);
				//				angle[1] = (receive_buff2[5] << 8 | receive_buff2[4]);
				//				angle[2] = (receive_buff2[7] << 8 | receive_buff2[6]);

				//每次收到33个十六进制数据，角度包位于后11位
				memcpy(&sensors.Angle, &uart2_params.receive_buff[24], 8);

				//				PITCH = (float) stcAngle.Angle[0] / 32768 * 180;
				//				ROLL = (float) stcAngle.Angle[1] / 32768 * 180;
				//				HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
				sensors.PITCH = sensors.Angle[0];
				sensors.ROLL = sensors.Angle[1];
				sensors.YAW = sensors.Angle[2];

				break;
		}
	}

	//--------------------------------------------------
	memset(uart2_params.receive_buff, 0, data_length);                       //清零接收缓冲区
	data_length = 0;

	HAL_UART_Receive_DMA(huart, (uint8_t *) uart2_params.receive_buff, 255); //重新开启DMA传输，每次255字节数

}

//=====================================================================================
//以中断的形式处理串口数据，不常用
//注意在使用该回调函数时，需在主函数内开启第一次中断
//**HAL_UART_Receive_IT(&huart1, (uint8_t *)msg, 1); //开启第一次中断
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//	UNUSED(huart);
//	uint8_t ret=HAL_OK;
//	uint8_t res=0;
//
//	msg++;
//	if(msg==msg_buff+MAX_RECV_LEN)
//	{
//		msg=msg_buff;
//	}
//	do
//	{
//		ret=HAL_UART_Receive_IT(huart,(uint8_t*)msg,1);
//	}while(ret!=HAL_OK);
//
//	if(*(msg-1)=='\n')
//	{
//		res=*(msg_buff);
//		switch(res)
//		{
//		}
//		memset(msg_buff,0,sizeof(msg_buff)); //清空缓存区
//		msg=msg_buff;
//		(huart)->pRxBuffPtr = msg;
//	}
//}


//=====================================================================================
//printf重定义
#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
 set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

PUTCHAR_PROTOTYPE {
	/* Place your implementation of fputc here */
	/* e.g. write a character to the USART6 and Loop until the end of transmission */
//  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
//
//  return ch;
	while ((USART1->SR & 0X40) == 0); //循环发送,直到发送完毕
	USART1->DR = (uint8_t) ch;
	return ch;
}


//=====================================================================================

#endif