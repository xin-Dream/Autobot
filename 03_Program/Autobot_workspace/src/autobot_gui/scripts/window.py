#!/usr/bin/python
# coding:utf-8
import sys

import rospy
from PyQt5.QtCore import *
from PyQt5.QtWidgets import QMainWindow, QApplication

from custombutton import CustomButton
from autobotUI import *

from geometry_msgs.msg import Twist


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

    def startTimer(self):
        self.timer1.start(1000)

    def updateProcessBar(self):
        self.linear, self.angular = self.fsvjoy_widget.get_info()
        self.linear_number.setText(str(self.linear))
        self.angular_number.setText(str(self.angular))

        twist = Twist()
        twist.linear.x = self.linear
        twist.angular.z = -self.angular
        self.publisher.publish(twist)


if __name__ == '__main__':
    rospy.init_node("autobot_control")

    app = QApplication(sys.argv)

    window = AutobotWindow()

    window.show()

    sys.exit(app.exec_())
