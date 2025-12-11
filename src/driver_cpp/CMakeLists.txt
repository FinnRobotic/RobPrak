cmake_minimum_required(VERSION 3.20)
project(driver_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)

find_package(geometry_msgs REQUIRED)
find_package(prak_msgs REQUIRED)

find_package(moveit_ros_planning_interface REQUIRED)

find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)

# Optional: threads for std::thread usage (Action server)
find_package(Threads REQUIRED)

###########
# Targets #
###########

# Actuator driver (MoveIt + TF + ActuatorRequest)
add_executable(actuator_driver_node
  src/actuator_driver_node.cpp
)

ament_target_dependencies(actuator_driver_node
  rclcpp
  geometry_msgs
  prak_msgs
  moveit_ros_planning_interface
  tf2_ros
  tf2_geometry_msgs
)

# Actuator action server
add_executable(actuator_action_server
  src/action_driver.cpp
)

ament_target_dependencies(actuator_action_server
  rclcpp
  rclcpp_action
  prak_msgs
)

# Link pthread for threads (some systems need this explicitly)
target_link_libraries(actuator_action_server
  Threads::Threads
)

#############
# Install   #
#############

install(
  TARGETS
    actuator_driver_node
    actuator_action_server
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
