cmake_minimum_required(VERSION 2.8.3)
project(pointcloud_denoising_cpp)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    pcl_ros
    sensor_msgs
)

catkin_package()

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(denoising src/denoising.cpp)
target_link_libraries(denoising ${catkin_LIBRARIES} )
