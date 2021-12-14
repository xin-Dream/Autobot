//
// Created by dream on 2021/11/10.
//

#include "robot.h"
#include <ros.h>
#include "std_msgs/String.h"
#include "std_msgs/UInt8.h"


void led0(const std_msgs::UInt8 &msg);

ros::NodeHandle nh;
std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

ros::Subscriber<std_msgs::UInt8> led0_sub("led0", &led0);

char hello[] = "hello autobot";

void setup() {
	nh.initNode();
	nh.advertise(chatter);

	nh.subscribe(led0_sub);
}

void loop(void) {
	str_msg.data = hello;
	chatter.publish(&str_msg);
	nh.spinOnce();

	HAL_Delay(1000);
}

void led0(const std_msgs::UInt8 &msg) {
	if (msg.data == 49) {
		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);

		OLED_ShowNum(20, 12, 1, 6, 12);
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
	nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	nh.getHardware()->reset_rbuf();
}