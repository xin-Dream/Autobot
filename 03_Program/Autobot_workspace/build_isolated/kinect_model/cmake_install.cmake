# Install script for directory: /home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/src/kinect_model

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated" TYPE PROGRAM FILES "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/kinect_model/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated" TYPE PROGRAM FILES "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/kinect_model/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated/setup.bash;/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated" TYPE FILE FILES
    "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/kinect_model/catkin_generated/installspace/setup.bash"
    "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/kinect_model/catkin_generated/installspace/local_setup.bash"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated/setup.sh;/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated" TYPE FILE FILES
    "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/kinect_model/catkin_generated/installspace/setup.sh"
    "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/kinect_model/catkin_generated/installspace/local_setup.sh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated/setup.zsh;/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated" TYPE FILE FILES
    "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/kinect_model/catkin_generated/installspace/setup.zsh"
    "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/kinect_model/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/install_isolated" TYPE FILE FILES "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/kinect_model/catkin_generated/installspace/.rosinstall")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/kinect_model/catkin_generated/installspace/kinect_model.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_model/cmake" TYPE FILE FILES
    "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/kinect_model/catkin_generated/installspace/kinect_modelConfig.cmake"
    "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/kinect_model/catkin_generated/installspace/kinect_modelConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_model" TYPE FILE FILES "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/src/kinect_model/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_model/config" TYPE DIRECTORY FILES "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/src/kinect_model/config/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_model/launch" TYPE DIRECTORY FILES "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/src/kinect_model/launch/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_model/meshes" TYPE DIRECTORY FILES "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/src/kinect_model/meshes/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinect_model/urdf" TYPE DIRECTORY FILES "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/src/kinect_model/urdf/")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/kinect_model/gtest/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/dream/01-data/005_Autobot/Autobot/03_Program/Autobot_workspace/build_isolated/kinect_model/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
