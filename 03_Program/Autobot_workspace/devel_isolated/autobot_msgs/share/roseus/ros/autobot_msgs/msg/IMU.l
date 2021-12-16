;; Auto-generated. Do not edit!


(when (boundp 'autobot_msgs::IMU)
  (if (not (find-package "AUTOBOT_MSGS"))
    (make-package "AUTOBOT_MSGS"))
  (shadow 'IMU (find-package "AUTOBOT_MSGS")))
(unless (find-package "AUTOBOT_MSGS::IMU")
  (make-package "AUTOBOT_MSGS::IMU"))

(in-package "ROS")
;;//! \htmlinclude IMU.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass autobot_msgs::IMU
  :super ros::object
  :slots (_linear_acceleration _angular_velocity _angle _temperature ))

(defmethod autobot_msgs::IMU
  (:init
   (&key
    ((:linear_acceleration __linear_acceleration) (instance geometry_msgs::Vector3 :init))
    ((:angular_velocity __angular_velocity) (instance geometry_msgs::Vector3 :init))
    ((:angle __angle) (instance geometry_msgs::Vector3 :init))
    ((:temperature __temperature) 0.0)
    )
   (send-super :init)
   (setq _linear_acceleration __linear_acceleration)
   (setq _angular_velocity __angular_velocity)
   (setq _angle __angle)
   (setq _temperature (float __temperature))
   self)
  (:linear_acceleration
   (&rest __linear_acceleration)
   (if (keywordp (car __linear_acceleration))
       (send* _linear_acceleration __linear_acceleration)
     (progn
       (if __linear_acceleration (setq _linear_acceleration (car __linear_acceleration)))
       _linear_acceleration)))
  (:angular_velocity
   (&rest __angular_velocity)
   (if (keywordp (car __angular_velocity))
       (send* _angular_velocity __angular_velocity)
     (progn
       (if __angular_velocity (setq _angular_velocity (car __angular_velocity)))
       _angular_velocity)))
  (:angle
   (&rest __angle)
   (if (keywordp (car __angle))
       (send* _angle __angle)
     (progn
       (if __angle (setq _angle (car __angle)))
       _angle)))
  (:temperature
   (&optional __temperature)
   (if __temperature (setq _temperature __temperature)) _temperature)
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Vector3 _linear_acceleration
    (send _linear_acceleration :serialization-length)
    ;; geometry_msgs/Vector3 _angular_velocity
    (send _angular_velocity :serialization-length)
    ;; geometry_msgs/Vector3 _angle
    (send _angle :serialization-length)
    ;; float64 _temperature
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Vector3 _linear_acceleration
       (send _linear_acceleration :serialize s)
     ;; geometry_msgs/Vector3 _angular_velocity
       (send _angular_velocity :serialize s)
     ;; geometry_msgs/Vector3 _angle
       (send _angle :serialize s)
     ;; float64 _temperature
       (sys::poke _temperature (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Vector3 _linear_acceleration
     (send _linear_acceleration :deserialize buf ptr-) (incf ptr- (send _linear_acceleration :serialization-length))
   ;; geometry_msgs/Vector3 _angular_velocity
     (send _angular_velocity :deserialize buf ptr-) (incf ptr- (send _angular_velocity :serialization-length))
   ;; geometry_msgs/Vector3 _angle
     (send _angle :deserialize buf ptr-) (incf ptr- (send _angle :serialization-length))
   ;; float64 _temperature
     (setq _temperature (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get autobot_msgs::IMU :md5sum-) "c042b8627ba8a889d53ed18c948dae0d")
(setf (get autobot_msgs::IMU :datatype-) "autobot_msgs/IMU")
(setf (get autobot_msgs::IMU :definition-)
      "
geometry_msgs/Vector3 linear_acceleration
geometry_msgs/Vector3 angular_velocity
geometry_msgs/Vector3 angle

float64 temperature
================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
")



(provide :autobot_msgs/IMU "c042b8627ba8a889d53ed18c948dae0d")


