from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    pkg_share = get_package_share_directory('your_package')
    params_file = os.path.join(pkg_share, 'config', 'hand_eye_calibration.yaml')

    return LaunchDescription([
        Node(
            package='your_package',
            executable='hand_eye_calibration_node',
            name='hand_eye_calibration_node',
            output='screen',
            parameters=[params_file],
        )
    ])