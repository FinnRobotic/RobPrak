import rclpy
from rclpy.node import Node

from prak_msgs.msg import RobotState
from prak_msgs.msg import ActuatorRequest


class TestPlannerNode(Node):
    def __init__(self):
        super().__init__('test_planner_node')

        # Subscribe to the aggregated robot state
        self.sub_state = self.create_subscription(
            RobotState,
            '/planner/state',
            self.cb_state,
            10
        )

        # Publish actuator requests for the driver
        self.pub_actuator = self.create_publisher(
            ActuatorRequest,
            '/driver/actuator_request',
            10
        )

        # Only handle the first state message
        self._handled_first_state = False

        self.get_logger().info(
            'TestPlannerNode started, waiting for first /planner/state message...'
        )

    def cb_state(self, msg: RobotState):
        if self._handled_first_state:
            # Ignore further messages, we only want to move once
            return

        self._handled_first_state = True

        # Assume tcp_pose is already in a base-related frame (e.g. base_link)
        tcp_pose = msg.tcp_pose

        self.get_logger().info(
            f"Received RobotState: frame_id='{tcp_pose.header.frame_id}', "
            f"tcp position: x={tcp_pose.pose.position.x:.3f}, "
            f"y={tcp_pose.pose.position.y:.3f}, "
            f"z={tcp_pose.pose.position.z:.3f}"
        )

        # Create ActuatorRequest: move TCP 10 cm down in z
        req = ActuatorRequest()
        req.header.stamp = self.get_clock().now().to_msg()
        # Use the same frame as the tcp_pose (should be base/base_link)
        req.header.frame_id = tcp_pose.header.frame_id

        # We want to use the pose, not joint angles
        req.use_angles = False

        # Copy current tcp pose into request.pose
        req.pose = tcp_pose.pose

        # Move 0.10 m down in z
        req.pose.position.z -= 0.10

        self.get_logger().info(
            f"Sending ActuatorRequest: move TCP down by 0.10 m in frame '{req.header.frame_id}'. "
            f"New z = {req.pose.position.z:.3f}"
        )

        # Publish the request once
        self.pub_actuator.publish(req)

        self.get_logger().info(
            "ActuatorRequest published, test planner will ignore further state messages."
        )


def main():
    rclpy.init()
    node = TestPlannerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
