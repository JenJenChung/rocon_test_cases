cmake_minimum_required(VERSION 2.8.3)
project(rocon_test_cases)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
)
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES rocon_test_cases
#  CATKIN_DEPENDS roscpp rospy
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(remote_publisher src/remote_publisher.cpp)
target_link_libraries(remote_publisher ${catkin_LIBRARIES})
add_dependencies(remote_publisher ${catkin_EXPORTED_TARGETS})

add_executable(hub_subscriber src/hub_subscriber.cpp)
target_link_libraries(hub_subscriber ${catkin_LIBRARIES})
add_dependencies(hub_subscriber ${catkin_EXPORTED_TARGETS})

add_executable(remote_subscriber src/remote_subscriber.cpp)
target_link_libraries(remote_subscriber ${catkin_LIBRARIES})
add_dependencies(remote_subscriber ${catkin_EXPORTED_TARGETS})

