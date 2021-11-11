# STM32Library



# 1 前言

> 整理了在单片机开发中自己常用的一部分函数，主要用在基于HAL库的stm32。目的是想在使用单片机的过程中逐步完善这个库，避免重复造轮子。

# 2 程序说明

## 2.1 macro

> 宏文件



+ void ParamsInit()

## 2.2 communication

> 通讯部分函数：stm32中通讯相关的函数，如蓝牙、WiFi、CAN等

+ void myuart_DMA(UART_HandleTypeDef *huart)
  + 函数功能：
  + 输入参数：
  + 输出参数：
  + 注意事项：
+ void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
+ void myuartDMA_callback(UART_HandleTypeDef *huart)
+ void JY60_Callback(UART_HandleTypeDef *huart)
+ PUTCHAR_PROTOTYPE

## 2.3 motorControl

> 电机控制函数

控制电机相关的底层函数，如直流减速电机、步进电机、舵机、伺服电机等

+ void encode_read(TIM_HandleTypeDef L_tim, TIM_HandleTypeDef R_tim)
+ void remoteControl()
+ void motor_control(int L_speed, int R_speed)

## 2.4 oled

> OLED显示函数

+ void OLED_Refresh_Gram(void)
+ void OLED_WR_Byte(uint8_t dat, uint8_t cmd)
+ void OLED_Display_On(void)
+ void OLED_Display_Off(void)
+ void OLED_Clear(void)
+ void OLED_DrawPoint(uint8_t x, uint8_t y, uint8_t t)
+ void OLED_Fill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t dot)
+ void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t size, uint8_t mode)
+ uint32_t mypow(uint8_t m, uint8_t n)
+ void OLED_ShowNum(uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t size)
+ void OLED_ShowString(uint8_t x, uint8_t y, const uint8_t *p, uint8_t size)
+ void OLED_Init(void)

## 2.5 algorithm

> 一些算法

+ uint32_t my_32abs(uint32_t number)
  + 函数功能：对unsigned int32的数据取绝对值
  + 输入参数：需要取绝对值的数据
  + 输出参数：取绝对值后的数据
  + 注意事项：无
+ int my_abs(int number)
  + 函数功能：对unsigned int32的数据取绝对值
  + 输入参数：需要取绝对值的数据
  + 输出参数：取绝对值后的数据
  + 注意事项：无
+ float filter(float alpha, float adc_now, float adc_pre)
  + 函数功能：一阶低通滤波器
  + 输入参数：
  + 输出参数：
  + 注意事项：

## 2.6 Arena

> 用在武术擂台机器人中的一部分函数

## 2.7 ros_serial

> 与ROS结合的部分函数

