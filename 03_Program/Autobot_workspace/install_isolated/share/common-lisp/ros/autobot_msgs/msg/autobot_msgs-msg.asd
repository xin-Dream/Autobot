
(cl:in-package :asdf)

(defsystem "autobot_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "IMU" :depends-on ("_package_IMU"))
    (:file "_package_IMU" :depends-on ("_package"))
  ))