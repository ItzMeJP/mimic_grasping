cmake_minimum_required(VERSION 3.16)
project(mimic_grasping
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

find_package(Eigen3 REQUIRED) # To matrix operations
find_package(Boost REQUIRED COMPONENTS system thread timer)

## Add other libs that does not have an find_package
add_library(ht_manipulation SHARED IMPORTED GLOBAL)
set_property(TARGET ht_manipulation PROPERTY IMPORTED_LOCATION "/usr/local/lib/ht_manipulation/libpose.so")
add_library(plugin_system_management SHARED IMPORTED GLOBAL)
set_property(TARGET plugin_system_management PROPERTY IMPORTED_LOCATION "/usr/local/lib/plugin_system_management/libplugin_system_management.so")

# Just to debug the generated plugin
add_library(debug_plugin SHARED IMPORTED GLOBAL)
set_property(TARGET debug_plugin PROPERTY IMPORTED_LOCATION "/home/joaopedro/ros_ws/ws_picking/src/mimic_grasping/plugins/libobject_localization_ros.so")

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

add_library(object_localization_ros SHARED #Shared is to export it latter
        src/object_recognition_client/obj_localization_ros.cpp
        )

target_link_libraries(object_localization_ros
        plugin_system_management
        ht_manipulation
        ${CMAKE_THREAD_LIBS_INIT}
        ${catkin_LIBRARIES}
        Eigen3::Eigen
        Boost::thread
        Boost::timer
        jsoncpp
        )

set_target_properties(object_localization_ros PROPERTIES
        #VERSION ${PROJECT_VERSION}
        PUBLIC_HEADER "include/object_recognition_client/obj_localization_ros.h"
        )

configure_file(install_configurations/obj_localization_ros.pc.in obj_localization_ros.pc @ONLY)

install(TARGETS object_localization_ros
        LIBRARY DESTINATION ${PLUGINS_DIR_FOLDER}
        PUBLIC_HEADER DESTINATION ${CMAKE_BINARY_DIR}/public_headers/plugins)

install(FILES ${CMAKE_BINARY_DIR}/obj_localization_ros.pc
        DESTINATION ${CMAKE_BINARY_DIR}/pkgconfig)

add_executable(object_recognition_client_test src/node.cpp)

target_link_libraries(
        object_recognition_client_test
        object_localization_ros
        ${catkin_LIBRARIES}
        #debug_plugin
        #plugin_system_management
        #ht_manipulation
        #${CMAKE_THREAD_LIBS_INIT}
        #Eigen3::Eigen
        #Boost::thread
        #Boost::timer
)

add_executable(sub_test src/sub_node.cpp)

target_link_libraries(sub_test
        object_localization_ros
        ${catkin_LIBRARIES}
        #debug_plugin
        #plugin_system_management
        #ht_manipulation
        #${CMAKE_THREAD_LIBS_INIT}
        #Eigen3::Eigen
        #Boost::thread
        #Boost::timer
)


