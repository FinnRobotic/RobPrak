cmake_minimum_required(VERSION 3.8)
project(test_moveit_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Globale C++-Version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(moveit_ros_planning_interface REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(shape_msgs REQUIRED)        # <--- das hat bei dir gefehlt
find_package(Eigen3 REQUIRED)

# ---------------- hello_moveit ----------------

add_executable(hello_moveit src/hello_moveit.cpp)

target_include_directories(hello_moveit PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)

ament_target_dependencies(hello_moveit
  rclcpp
  moveit_ros_planning_interface
  geometry_msgs
)

# ---------------- spiral_moveit ----------------

add_executable(spiral_moveit src/spiral_moveit.cpp)

ament_target_dependencies(spiral_moveit
  rclcpp
  moveit_ros_planning_interface
  geometry_msgs
)

target_link_libraries(spiral_moveit
  Eigen3::Eigen
)

# ---------------- obstacle_test ----------------

add_executable(obstacle_test src/obstacle.cpp)

ament_target_dependencies(obstacle_test
  rclcpp
  moveit_ros_planning_interface
  geometry_msgs
  shape_msgs
)

# ---------------- install ----------------

install(TARGETS
  hello_moveit
  obstacle_test
  spiral_moveit
  DESTINATION lib/${PROJECT_NAME}
)

# ---------------- tests (unverändert) ----------------

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
