from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    pkg_share = get_package_share_directory('driver_cpp')

    obstacles_params = os.path.join(pkg_share, 'config', 'obstacles.yaml')

    actuator_driver = Node(
        package='driver_cpp',
        executable='actuator_driver_node',
        name='actuator_driver',
        output='screen',
        # optional: parameters=[...]
    )

    obstacle_publisher = Node(
        package='driver_cpp',
        executable='obstacle_publisher',
        name='obstacle_publier',
        output='screen',
        parameters=[obstacles_params],
    )

    return LaunchDescription([
        actuator_driver,
        obstacle_publisher,
    ])