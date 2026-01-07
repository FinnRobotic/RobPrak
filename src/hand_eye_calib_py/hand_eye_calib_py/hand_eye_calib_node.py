import rclpy
from rclpy.node import Node
import numpy as np
from geometry_msgs.msg import PoseStamped
from tf_transformations import quaternion_matrix
from scipy.spatial.transform import Rotation as R
from std_msgs.msg import Bool
from prak_msgs.msg import ActuatorRequest
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
import time


# QoS compatible with VRPN publisher
qos_profile = QoSProfile(
    reliability=ReliabilityPolicy.BEST_EFFORT,
    history=HistoryPolicy.KEEP_LAST,
    depth=1
)


class HandEyeCalibrationNode(Node):

    def __init__(self):
        super().__init__('hand_eye_calibration_node')

        # ----------------------------
        # Parameters
        # ----------------------------
        self.declare_parameter('required_poses', 15)

        self.declare_parameter('topics.robot_pose', '/tcp_pose_broadcaster/pose')
        self.declare_parameter('topics.tracking_pose', '/vrpn_mocap/Table_1/pose')
        self.declare_parameter('topics.pose_reached', '/driver/pose_reached')
        self.declare_parameter('topics.actuator_request', '/driver/actuator_request')

        # Random workspace bounds (meters)
        self.declare_parameter('workspace.x_min', 0.35)
        self.declare_parameter('workspace.x_max', 0.70)
        self.declare_parameter('workspace.y_min', -0.30)
        self.declare_parameter('workspace.y_max', 0.30)
        self.declare_parameter('workspace.z_min', 0.20)
        self.declare_parameter('workspace.z_max', 0.60)

        # Timers (seconds)
        self.declare_parameter('timers.collect_period_s', 0.25)
        self.declare_parameter('timers.first_pose_timer_period_s', 0.5)
        self.declare_parameter('timers.first_pose_min_delay_s', 1.0)
        self.declare_parameter('reached_stability_time_s', 0.5)


        # Read parameters
        self.required_poses = int(self.get_parameter('required_poses').value)

        self.topic_robot_pose = str(self.get_parameter('topics.robot_pose').value)
        self.topic_tracking_pose = str(self.get_parameter('topics.tracking_pose').value)
        self.topic_pose_reached = str(self.get_parameter('topics.pose_reached').value)
        self.topic_actuator_request = str(self.get_parameter('topics.actuator_request').value)

        self.x_min = float(self.get_parameter('workspace.x_min').value)
        self.x_max = float(self.get_parameter('workspace.x_max').value)
        self.y_min = float(self.get_parameter('workspace.y_min').value)
        self.y_max = float(self.get_parameter('workspace.y_max').value)
        self.z_min = float(self.get_parameter('workspace.z_min').value)
        self.z_max = float(self.get_parameter('workspace.z_max').value)

        self.collect_period_s = float(self.get_parameter('timers.collect_period_s').value)
        self.first_pose_timer_period_s = float(self.get_parameter('timers.first_pose_timer_period_s').value)
        self.first_pose_min_delay_s = float(self.get_parameter('timers.first_pose_min_delay_s').value)

        self.get_logger().info('Hand-Eye calibration node initialized.')
        self.get_logger().info(
            f"Params: required_poses={self.required_poses}, "
            f"robot_pose_topic='{self.topic_robot_pose}', "
            f"tracking_pose_topic='{self.topic_tracking_pose}', "
            f"pose_reached_topic='{self.topic_pose_reached}', "
            f"actuator_request_topic='{self.topic_actuator_request}'"
        )
        self.get_logger().info(
            f"Workspace: x=[{self.x_min}, {self.x_max}], "
            f"y=[{self.y_min}, {self.y_max}], "
            f"z=[{self.z_min}, {self.z_max}]"
        )

        # Collected pose pairs
        self.robot_ee_poses = []
        self.tracking_pattern_poses = []

        self.last_robot_pose = None
        self.last_tracking_pose = None
        self.raw_robot_pose = None
        self.raw_tracking_pose = None

        self.is_collecting = True
        self.reached = False
        self.reached_stable = False
        self.reached_stability_time = float(
            self.get_parameter('reached_stability_time_s').value
        )
        self.get_logger().info(f"Pose stability time: {self.reached_stability_time:.2f} s")

        self.stability_timer = None

        # Robot TCP pose
        self.robot_sub = self.create_subscription(
            PoseStamped,
            self.topic_robot_pose,
            self.robot_pose_callback,
            10
        )
        self.get_logger().info(f"Subscribed to robot pose topic: {self.topic_robot_pose}")

        # Tracking system pose
        self.tracking_sub = self.create_subscription(
            PoseStamped,
            self.topic_tracking_pose,
            self.tracking_pose_callback,
            qos_profile
        )
        self.get_logger().info(f"Subscribed to tracking pose topic: {self.topic_tracking_pose}")

        # Pose reached flag
        self.pose_reached_sub = self.create_subscription(
            Bool,
            self.topic_pose_reached,
            self.pose_reached_callback,
            10
        )
        self.get_logger().info(f"Subscribed to pose reached topic: {self.topic_pose_reached}")

        # Actuator command publisher
        self.actuator_req_pub = self.create_publisher(
            ActuatorRequest,
            self.topic_actuator_request,
            10
        )
        self.get_logger().info(f"Publishing actuator requests to: {self.topic_actuator_request}")

        self.first_pose_sent = False
        self.start_time = time.time()
        self.create_timer(self.first_pose_timer_period_s, self.send_first_pose)


    def send_first_pose(self):
        if self.first_pose_sent:
            return
        if time.time() - self.start_time < self.first_pose_min_delay_s:
            return

        self.get_logger().info("Sending first target pose.")
        self.request_new_pose()
        self.first_pose_sent = True


    def robot_pose_callback(self, msg):
        self.raw_robot_pose = msg
        if self.reached_stable:
            self.last_robot_pose = msg
        else:
            self.last_robot_pose = None



    def tracking_pose_callback(self, msg):
        self.raw_tracking_pose = msg
        if self.reached_stable:
            self.last_tracking_pose = msg
        else:
            self.last_tracking_pose = None


    def pose_reached_callback(self, msg):
        self.reached = msg.data

        if self.reached:
            # Start (or restart) the one-shot stability timer
            self.reached_stable = False

            if self.stability_timer is not None:
                self.stability_timer.cancel()
                self.stability_timer = None

            self.stability_timer = self.create_timer(
                self.reached_stability_time,
                self.on_reached_stable
            )
        else:
            # Reset everything
            self.reached_stable = False
            if self.stability_timer is not None:
                self.stability_timer.cancel()
                self.stability_timer = None

            self.request_new_pose()


    def on_reached_stable(self):
        # One-shot timer
        if self.stability_timer is not None:
            self.stability_timer.cancel()
            self.stability_timer = None

        # Only proceed if we still consider the robot "reached"
        if not self.reached or not self.is_collecting:
            return

        self.reached_stable = True

        # Promote raw poses to the "accepted" poses
        self.last_robot_pose = self.raw_robot_pose
        self.last_tracking_pose = self.raw_tracking_pose

        self.get_logger().info(
            f"Pose has been stable for {self.reached_stability_time:.2f}s. Collecting measurement."
        )

        self.check_and_collect_data()


    def request_new_pose(self):
        req = ActuatorRequest()
        req.header.stamp = self.get_clock().now().to_msg()
        req.header.frame_id = "base"
        req.use_angles = False

        # Random position inside configured workspace
        req.pose.position.x = np.random.uniform(self.x_min, self.x_max)
        req.pose.position.y = np.random.uniform(self.y_min, self.y_max)
        req.pose.position.z = np.random.uniform(self.z_min, self.z_max)

        # Random orientation
        roll  = np.random.uniform(-np.pi, np.pi)
        pitch = np.random.uniform(-np.pi / 2, np.pi / 2)
        yaw   = np.random.uniform(-np.pi, np.pi)

        quat = R.from_euler('xyz', [roll, pitch, yaw]).as_quat()
        req.pose.orientation.x = quat[0]
        req.pose.orientation.y = quat[1]
        req.pose.orientation.z = quat[2]
        req.pose.orientation.w = quat[3]

        self.reached = False
        self.actuator_req_pub.publish(req)

        self.get_logger().info(
            f"Requested new random pose "
            f"(x={req.pose.position.x:.2f}, "
            f"y={req.pose.position.y:.2f}, "
            f"z={req.pose.position.z:.2f})"
        )


    def posestamped_to_matrix(self, msg):
        p = msg.pose.position
        q = msg.pose.orientation

        matrix = quaternion_matrix([q.x, q.y, q.z, q.w])
        matrix[:3, 3] = [p.x, p.y, p.z]
        return matrix


    def check_and_collect_data(self):
        if not self.is_collecting or not self.reached:
            self.get_logger().info("Check and Collect Data called, but already collecting or not reached.")
            return

        if self.last_robot_pose is None or self.last_tracking_pose is None:
            self.get_logger().info("Waiting for synchronized poses...")
            return

        self.reached = False

        self.robot_ee_poses.append(self.posestamped_to_matrix(self.last_robot_pose))
        self.tracking_pattern_poses.append(self.posestamped_to_matrix(self.last_tracking_pose))

        current_count = len(self.robot_ee_poses)
        self.get_logger().info(f"Pose pair collected: {current_count}/{self.required_poses}")

        self.last_robot_pose = None
        self.last_tracking_pose = None

        if current_count >= self.required_poses:
            self.is_collecting = False
            self.get_logger().warn("Required number of measurements reached. Starting calibration.")
            self.perform_calibration()
            self.get_logger().info("Calibration finished. Shutting down node.")
            rclpy.shutdown()
        else:
            self.request_new_pose()


    def convertMatrix4Calibration(self, robot_matrix, tracking_matrix):
        rTracking = tracking_matrix[0:3, 0:3]
        tTracking = tracking_matrix[0:3, 3]
        B = robot_matrix
        Z = np.zeros((3, 3))

        row1 = np.hstack([rTracking * B[0,0], rTracking * B[1,0], rTracking * B[2,0], Z])
        row2 = np.hstack([rTracking * B[0,1], rTracking * B[1,1], rTracking * B[2,1], Z])
        row3 = np.hstack([rTracking * B[0,2], rTracking * B[1,2], rTracking * B[2,2], Z])
        row4 = np.hstack([rTracking * B[0,3], rTracking * B[1,3], rTracking * B[2,3], rTracking])

        A_left = np.vstack([row1, row2, row3, row4])
        A = np.hstack([A_left, -np.eye(12)])
        b = np.hstack([np.zeros(9), -tTracking])
        return A, b
    
    def _vec12_to_T(self, v12: np.ndarray) -> np.ndarray:
        """
        Interpret a 12-vector as a homogeneous transform:
        first 9 entries -> 3x3 rotation (row-major),
        last 3 entries  -> translation.
        """
        v12 = np.asarray(v12).reshape(-1)
        Rm = v12[:9].reshape(3, 3)
        t = v12[9:12].reshape(3,)
        T = np.eye(4)
        T[:3, :3] = Rm
        T[:3, 3] = t
        return T


    def _format_T(self, T: np.ndarray, name: str) -> None:
        """
        Pretty-print homogeneous transform, plus Euler angles and translation.
        Euler order: xyz, degrees.
        """
        T = np.asarray(T)

        self.get_logger().info(f"{name} (homogeneous 4x4):\n{np.array2string(T, precision=6, suppress_small=True)}")

        Rm = T[:3, :3]
        t = T[:3, 3]

        # For debug display: project rotation to nearest proper rotation matrix
        # (does NOT change the solved values, only the printed interpretation)
        try:
            U, _, Vt = np.linalg.svd(Rm)
            R_ortho = U @ Vt
            if np.linalg.det(R_ortho) < 0:
                U[:, -1] *= -1
                R_ortho = U @ Vt
        except Exception:
            R_ortho = Rm

        euler_deg = R.from_matrix(R_ortho).as_euler('xyz', degrees=True)

        self.get_logger().info(
            f"{name} translation [m]: "
            f"x={t[0]:.6f}, y={t[1]:.6f}, z={t[2]:.6f}"
        )
        self.get_logger().info(
            f"{name} Euler xyz [deg] (from orthonormalized R): "
            f"roll={euler_deg[0]:.3f}, pitch={euler_deg[1]:.3f}, yaw={euler_deg[2]:.3f}"
        )

    def perform_calibration(self):
        self.get_logger().info("Building global equation system.")

        list_A, list_b = [], []

        for T_robot, T_track in zip(self.robot_ee_poses, self.tracking_pattern_poses):
            A, b = self.convertMatrix4Calibration(T_robot, T_track)
            list_A.append(A)
            list_b.append(b)

        self.get_logger().info(f"{len(list_A)} measurement matrices generated.")

        A_total = np.vstack(list_A)
        b_total = np.concatenate(list_b)

        self.get_logger().info(f"Global system shape: A={A_total.shape}, b={b_total.shape}")
        self.get_logger().info("Solving least-squares system...")

        sol, residuals, rank, s = np.linalg.lstsq(A_total, b_total, rcond=None)

        self.get_logger().info("Solution found.")

        # Least-squares diagnostics
        res_str = "[]"
        if residuals is not None and len(residuals) > 0:
            res_str = np.array2string(residuals, precision=6, suppress_small=True)

        self.get_logger().info(f"lstsq diagnostics: residuals={res_str}, rank={rank}")
        self.get_logger().info(f"singular values (first 10): {np.array2string(s[:10], precision=6, suppress_small=True)}")

        # Split into x and y (each 12 params)
        x = sol[:12]
        y = sol[12:24]

        # Interpret as homogeneous transforms
        Tx = self._vec12_to_T(x)
        Ty = self._vec12_to_T(y)

        # Pretty print transforms + Euler + translation
        self._format_T(Tx, "X")
        self._format_T(Ty, "Y")

        # Keep your original prints if you still want the raw values
        for i in range(12):
            print(f"x{i}: {sol[i]}")
        for i in range(12):
            print(f"y{i}: {sol[12+i]}")

def main(args=None):
    rclpy.init(args=args)
    node = HandEyeCalibrationNode()
    try:
        rclpy.spin(node)
    except Exception as e:
        node.get_logger().error(f"Node error: {e}")
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()

