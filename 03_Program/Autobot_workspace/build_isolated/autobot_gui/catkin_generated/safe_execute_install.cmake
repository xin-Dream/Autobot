execute_process(COMMAND "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/autobot_gui/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/autobot_gui/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
