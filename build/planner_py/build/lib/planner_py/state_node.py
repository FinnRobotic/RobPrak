import rclpy
from rclpy.node import Node

from prak_msgs.msg import RobotState, JointStateStamped

from geometry_msgs.msg import PoseStamped
from sensor_msgs.msg import JointState





class StateNode(Node):


    def __init__(self):
        super().__init__('state_node')


        self.sub_joints = self.create_subscription(
            JointState,
            '/joint_states',
            self.cb_joints,
            10
        )

        self.sub_tcp = self.create_subscription(
            PoseStamped,
            '/tcp_pose_broadcaster/pose',
            self.cb_tcp,
            10
        )



        self.pub_state = self.create_publisher(
            RobotState,
            '/planner/state',
            10
        )
        self.state = RobotState()
        self.state.header.frame_id = 'base_link'


        self.state_timer = self.create_timer(0.1, self.cb_state_timer)


    def cb_tcp(self, msg: PoseStamped):
        self.state.tcp_pose = msg



    def cb_joints(self, msg: JointState):
        
        joint_state = JointStateStamped()

        joint_state.stamp = msg.header.stamp

        for i in range(len(msg.name)):
            
            if msg.name[i] == 'elbow_joint':
                joint_state.joint_state.elbow_joint = msg.position[i]

            elif msg.name[i] == 'shoulder_lift_joint':
                joint_state.joint_state.shoulder_lift_joint = msg.position[i]
            elif msg.name[i] == 'shoulder_pan_joint':
                joint_state.joint_state.shoulder_pan_joint = msg.position[i]
            elif msg.name[i] == 'wrist_1_joint':
                joint_state.joint_state.wrist_1_joint = msg.position[i]
            elif msg.name[i] == 'wrist_2_joint':
                joint_state.joint_state.wrist_2_joint = msg.position[i]
            elif msg.name[i] == 'wrist_3_joint':
                joint_state.joint_state.wrist_3_joint = msg.position[i]

        self.state.joint_state = joint_state


    def cb_state_timer(self):
        self.state.header.stamp = self.get_clock().now().to_msg()

        self.pub_state.publish(self.state)




def main():
    rclpy.init()
    node = StateNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
