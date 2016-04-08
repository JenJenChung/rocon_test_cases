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

add_executable(aadi_publisher src/aadi_publisher.cpp)
target_link_libraries(aadi_publisher ${catkin_LIBRARIES})
add_dependencies(aadi_publisher ${catkin_EXPORTED_TARGETS})

add_executable(aadi_subscriber src/aadi_subscriber.cpp)
target_link_libraries(aadi_subscriber ${catkin_LIBRARIES})
add_dependencies(aadi_subscriber ${catkin_EXPORTED_TARGETS})

add_executable(hub_subscriber src/hub_subscriber.cpp)
target_link_libraries(hub_subscriber ${catkin_LIBRARIES})
add_dependencies(hub_subscriber ${catkin_EXPORTED_TARGETS})

