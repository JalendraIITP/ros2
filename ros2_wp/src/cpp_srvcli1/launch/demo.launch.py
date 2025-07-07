from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        ExecuteProcess(
            cmd=["ros2", "run", "cpp_srvcli1", "client", "7", "3", "2"],
            name="client_process",
            output="screen"
        ),
        Node(
            package="cpp_srvcli1",
            executable="server",
            name="server_node",
            output="screen"
        )
    ])
