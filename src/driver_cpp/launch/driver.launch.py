from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    pkg_share = get_package_share_directory('driver_cpp')


    static_tf_yaml = os.path.join(
        pkg_share, 'config', 'static_tf.yaml'
    )

    actuator_driver = Node(
        package='driver_cpp',
        executable='actuator_driver_node',
        name='actuator_driver',
        output='screen',
    )



    static_tf_publisher = Node(
        package='driver_cpp',
        executable='static_tf_from_yaml',
        name='static_tf_publisher',
        output='screen',
        parameters=[
            {
                'yaml_file': static_tf_yaml
            }
        ],
    )

    return LaunchDescription([
        actuator_driver,
        static_tf_publisher,
    ])
