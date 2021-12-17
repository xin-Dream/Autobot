import rospy
from PyQt5.QtCore import *
from PyQt5.QtWidgets import QMainWindow, QApplication

from autobot_msgs.msg import IMU


class readdata_Thread(QThread):
    update_angular = pyqtSignal(float)
    def __init__(self):
        super(readdata_Thread, self).__init__()

    def run(self):
        while True:
            imu_topic_name = "Autobot_IMU"
            sub_imu = rospy.Subscriber(imu_topic_name, IMU, self.duIMU, queue_size=100)
            rospy.spin()

    def doIMU(self, IMU):
        self.update_angular.emit(round(IMU.angular_velocity.x, 2))
