cmake_minimum_required(VERSION 2.8.3)
project(see3cam_trigger)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES see3cam_trigger
  CATKIN_DEPENDS roscpp
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(see3cam_trigger_node src/see3cam_trigger/see3cam_trigger_node.cpp)

target_link_libraries(see3cam_trigger_node
  ${catkin_LIBRARIES}
)