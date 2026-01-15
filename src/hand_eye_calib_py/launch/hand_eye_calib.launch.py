from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    pkg_share = get_package_share_directory('hand_eye_calib_py')
    params_file = os.path.join(pkg_share, 'config', 'hand_eye_calib.yaml')

    return LaunchDescription([
        Node(
            package='hand_eye_calib_py',
            executable='hand_eye_calib_node',
            name='hand_eye_calib_node',
            output='screen',
            parameters=[params_file],
        )
    ])