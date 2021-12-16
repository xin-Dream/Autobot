//
// Created by dream on 2021/8/20.
//

#include <robot.h>
#include <ros.h>
#include "macro.h"
#include <autobot_msgs/IMU.h>

ros::NodeHandle nh;

// 发布IMU消息
autobot_msgs::IMU imu_msg;

ros::Publisher Autobot_IMU("Autobot_IMU", &imu_msg);
extern Sensor_TypeDef sensors;

void setup(void) {
    nh.initNode();

    nh.advertise(Autobot_IMU);

}

void loop(void) {

    OLED_SHOW();

//    imu_msg.PITCH=(float) sensors.PITCH/ 32768 * 180;
//    imu_msg.ROLL=(float) sensors.ROLL/ 32768 * 180;
//    imu_msg.YAW=(float) sensors.YAW/ 32768 * 180;
    imu_msg.angular_velocity.x = sensors.Angular[0] / 32768.0 * 16 * 9.8;
    imu_msg.angular_velocity.y = sensors.Angular[1] / 32768.0 * 16 * 9.8;
    imu_msg.angular_velocity.z = sensors.Angular[2] / 32768.0 * 16 * 9.8;

    imu_msg.linear_acceleration.x = sensors.Acceleration[0] / 32768.0 * 2000;
    imu_msg.linear_acceleration.y = sensors.Acceleration[1] / 32768.0 * 2000;
    imu_msg.linear_acceleration.z = sensors.Acceleration[2] / 32768.0 * 2000;

    imu_msg.angle.x = (sensors.Angle[0] / 32768.0 * 180);
    imu_msg.angle.y = sensors.Angle[1] / 32768.0 * 180;
    imu_msg.angle.z = sensors.Angle[2] / 32768.0 * 180;

    imu_msg.temperature = sensors.Angle[3] / 340 + 36.53;
//    Arena_imu.publish(&imu_msg);

    Autobot_IMU.publish(&imu_msg);

    nh.spinOnce();

}
