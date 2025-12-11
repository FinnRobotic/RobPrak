from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    namespace = LaunchConfiguration('namespace')

    return LaunchDescription([
        DeclareLaunchArgument(
            'namespace',
            default_value='planner',
            description='Namespace of the state node'
        ),

        Node(
            package='planner_py',     
            executable='state_node',    
            name='state_node',
            namespace=namespace,         
            output='screen',
        )
    ])
