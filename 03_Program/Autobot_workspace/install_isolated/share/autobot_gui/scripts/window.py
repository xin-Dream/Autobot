#!/usr/bin/python
# coding:utf-8
import sys
import os

import rospy
from PyQt5.QtCore import *
from PyQt5.QtWidgets import QMainWindow, QApplication

from custombutton import CustomButton
from autobotUI import *

from geometry_msgs.msg import Twist
from autobot_msgs.msg import IMU


class AutobotWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, parent=None):
        super(AutobotWindow, self).__init__(parent)
        self.setupUi(self)

        # 设置窗口名称与大小
        self.setWindowTitle("Autobot")

        # 申明一个时钟控件
        self.timer1 = QTimer(self)
        self.timer1.timeout.connect(self.updateProcessBar)

        # 获得摇杆信息
        self.linear, self.angular = self.fsvjoy_widget.get_info()

        self.timer1.start(100)

        # self.settopicButton.clicked.connect(self.setPublisher)

        self.flag = 0

        # 创建Publisher
        twist_topic_name = "/cmd_vel"
        self.publisher = rospy.Publisher(twist_topic_name, Twist, queue_size=100)

        self.opensimulation.clicked.connect(lambda: self.open_simulation())

    def startTimer(self):
        self.timer1.start(1000)

    def open_simulation(self):
        os.system("roslaunch autobot_simulation autobot_simulation.launch")

    def updateProcessBar(self):
        self.linear, self.angular = self.fsvjoy_widget.get_info()
        self.linear_number.setText(str(self.linear))
        self.angular_number.setText(str(self.angular))

        self.acc_x.setText(str(acc_x))
        self.acc_y.setText(str(acc_y))
        self.acc_z.setText(str(acc_z))

        self.angular_x.setText(str(angular_x))
        self.angular_y.setText(str(angular_y))
        self.angular_z.setText(str(angular_z))

        self.angle_x.setText(str(angle_x))
        self.angle_y.setText(str(angle_y))
        self.angle_z.setText(str(angle_z))

        self.temperature.setText(str(temperature))

        twist = Twist()
        twist.linear.x = self.linear
        twist.angular.z = -self.angular
        self.publisher.publish(twist)


class workThread(QThread):
    def __init__(self):
        super(workThread, self).__init__()

    def run(self):
        imu_topic_name = "Autobot_IMU"
        sub = rospy.Subscriber(imu_topic_name, IMU, self.doIMU, queue_size=100)
        rospy.spin()

    def doIMU(self, IMU):
        global acc_x, acc_y, acc_z
        global angular_x, angular_y, angular_z
        global angle_x, angle_y, angle_z
        global temperature

        angular_x = round(IMU.angular_velocity.x, 2)
        angular_y = round(IMU.angular_velocity.y, 2)
        angular_z = round(IMU.angular_velocity.z, 2)

        acc_x = round(IMU.linear_acceleration.x, 2)
        acc_y = round(IMU.linear_acceleration.y, 2)
        acc_z = round(IMU.linear_acceleration.z, 2)

        angle_x = round(IMU.angle.x, 2)
        angle_y = round(IMU.angle.y, 2)
        angle_z = round(IMU.angle.z, 2)

        temperature = round(IMU.temperature, 2)


if __name__ == '__main__':
    rospy.init_node("autobot_control")

    workThread = workThread()
    workThread.start()

    app = QApplication(sys.argv)

    window = AutobotWindow()

    window.show()

    sys.exit(app.exec_())
