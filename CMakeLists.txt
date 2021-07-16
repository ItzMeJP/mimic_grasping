cmake_minimum_required(VERSION 3.16)
project(mimic_grasping_ros_interface_package
        VERSION 15.07.2021
        DESCRIPTION
        "")

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

include(GNUInstallDirs)

get_filename_component(CURRENT_DIR ./ ABSOLUTE)

#set (INSTALL_PLUGIN_SYSTEM_MANAGEMENT_IN_ROOT True)
set(PLUGINS_DIR_FOLDER ${CURRENT_DIR}/plugins)


## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
        roscpp
        object_recognition_skill_server
        geometry_msgs
        #photoneo_skill_server
        #point_cloud_io
        #tf
        #zed_wrapper
        )


catkin_package(
        CATKIN_DEPENDS
        #  INCLUDE_DIRS include
        #  LIBRARIES mimic_grasping
        #  CATKIN_DEPENDS object_recognition_skill_server point_cloud_io tf zed_wrapper #photoneo_skill_server
        #  DEPENDS system_lib
)

include_directories(
        include
        ${catkin_INCLUDE_DIRS}
)
