import rclpy
from rclpy.node import Node
import numpy as np

# Für die Transformationen (Pose)
from geometry_msgs.msg import PoseStamped
# Für die Umwandlung von Quaternionen in Rotationsmatrizen
from tf_transformations import quaternion_matrix 
# Für die eigentliche Kalibrierungslogik (NumPy-Funktionen, scipy)
from scipy.spatial.transform import Rotation as R

from std_msgs.msg import Bool
from prak_msgs.msg import ActuatorRequest

# -------------------------------------------------------------
# Konstanten
# -------------------------------------------------------------
REQUIRED_POSES = 15 # Anzahl der benötigten Messpaare

# -------------------------------------------------------------
# Haupt-Node-Klasse
# -------------------------------------------------------------

class HandEyeCalibrationNode(Node):
    """
    ROS 2 Node zum initialen Zugriff auf Roboter- und Tracking-Daten.
    """
    def __init__(self):
        super().__init__('hand_eye_calibration_node')
        self.get_logger().info('Hand-Auge-Kalibrierungs-Node initialisiert.')

        # -------------------------------------------------------------
        # 1. Daten-Zwischenspeicher (für die Callback-Funktionen)
        # -------------------------------------------------------------
        self.robot_ee_poses = []          # Liste zur Speicherung der gesammelten 4x4 Matrizen
        self.tracking_pattern_poses = []  # Liste zur Speicherung der gesammelten 4x4 Matrizen

        self.last_robot_pose = None       # Speichert die letzte PoseStamped Nachricht
        self.last_tracking_pose = None    # Speichert die letzte PoseStamped Nachricht

        self.is_collecting = True
        self.reached = False
    
        
        # -------------------------------------------------------------
        # 2. ROS-Abonnements (Zugriff auf Topics)
        # -------------------------------------------------------------

        # Abonnement für Roboter-Endeffektor-Pose
        self.robot_sub = self.create_subscription(
            PoseStamped,
            '/robot/end_effector_pose',
            self.robot_pose_callback,
            10
        )
        self.get_logger().info('Abonniert Topic für Roboter-Pose: /robot/end_effector_pose')


        # Abonnement für Tracking-Muster-Pose
        self.tracking_sub = self.create_subscription(
            PoseStamped,
            '/vrpn_mocap/NAME/pose', # <--- TRACKING TOPIC ANPASSEN
            self.tracking_pose_callback,
            10
        )
        self.get_logger().info('Abonniert Topic für Tracking-Pose: /vrpn_mocap/NAME/pose')
        
        # Abonnement für Pose Reached
        self.pose_reached_sub = self.create_subscription(
            Bool,
            '/driver/pose_reached', 
            self.pose_reached_callback,
            10
        )
        self.get_logger().info('Abonniert Topic für Pose Reached :/driver/pose_reached ')
        
        self.actuator_req_pub = self.create_publisher(
            ActuatorRequest,
            '/driver/actuator_request',
            10
        )
    
        self.collect_timer = self.create_timer(0.250, self.check_and_collect_data)
    # -------------------------------------------------------------
    # 4. Callback-Funktionen (Empfangen der Daten)
    # -------------------------------------------------------------
    
    def robot_pose_callback(self, msg: PoseStamped):
        """Wird aufgerufen, wenn eine neue Roboter-Pose empfangen wird."""
        if self.reached:
            self.last_robot_pose = msg
        else:
            self.last_robot_pose = None

        
    def tracking_pose_callback(self, msg: PoseStamped):
        """Wird aufgerufen, wenn eine neue Tracking-Pose empfangen wird."""
        if self.reached:
            self.last_tracking_pose = msg
        else:
            self.last_tracking_pose = None
    
    def pose_reached_callback(self, msg: Bool):
        """Wird aufgerufen, wenn der Roboter seine position erreicht hat"""

        self.reached = msg.data

        if not msg.data:
            self.request_new_pose()
        
    def request_new_pose(self):
        """
        Sendet eine neue zufällige Ziel-Pose im Base-Frame an den ActuatorDriver.
        """

        req = ActuatorRequest()

        # -----------------------------
        # Header
        # -----------------------------
        req.header.stamp = self.get_clock().now().to_msg()
        req.header.frame_id = "base"   # 🔑 WICHTIG

        req.use_angles = False

        # -----------------------------
        # Zufällige Position (m)
        # -----------------------------
        # Konservativer Arbeitsraum vor dem Roboter
        req.pose.position.x = np.random.uniform(0.35, 0.70)
        req.pose.position.y = np.random.uniform(-0.30, 0.30)
        req.pose.position.z = np.random.uniform(0.20, 0.60)

        # -----------------------------
        # Zufällige Orientierung
        # -----------------------------
        # Zufällige Roll/Pitch/Yaw
        roll  = np.random.uniform(-np.pi, np.pi)
        pitch = np.random.uniform(-np.pi / 2.0, np.pi / 2.0)
        yaw   = np.random.uniform(-np.pi, np.pi)

        quat = R.from_euler('xyz', [roll, pitch, yaw]).as_quat()

        req.pose.orientation.x = quat[0]
        req.pose.orientation.y = quat[1]
        req.pose.orientation.z = quat[2]
        req.pose.orientation.w = quat[3]

        self.reached = False

        self.actuator_req_pub.publish(req)

        self.get_logger().info(
            "Neue zufällige Pose im Base-Frame angefordert "
            f"(x={req.pose.position.x:.2f}, "
            f"y={req.pose.position.y:.2f}, "
            f"z={req.pose.position.z:.2f})"
        )
        
        
    # -------------------------------------------------------------
    # 5. Konvertierung von PoseStamped zu NumPy 4x4 Matrix (Ihre Funktion)
    # -------------------------------------------------------------

    def posestamped_to_matrix(self, msg: PoseStamped) -> np.ndarray:
        """Konvertiert PoseStamped Nachricht in 4x4 homogene Transformationsmatrix."""
        # Translation (Position)
        p = msg.pose.position
        translation = np.array([p.x, p.y, p.z])
        
        # Rotation (Orientierung)
        q = msg.pose.orientation
        # tf_transformations erwartet [x, y, z, w]
        quaternion = [q.x, q.y, q.z, q.w] 

        # 1. Erzeugt eine 4x4 Matrix mit der Rotationsmatrix in der oberen linken 3x3 Ecke
        rotation_matrix_4x4 = quaternion_matrix(quaternion)
        
        # 2. Fügt den Translationsvektor in die vierte Spalte (Spalten-Index 3) ein
        matrix = rotation_matrix_4x4
        matrix[:3, 3] = translation 

        # Die Matrix sieht nun so aus:
        return matrix
    
    # -------------------------------------------------------------
    # 6. Steuerung der Messdatensammlung (Trigger)
    # -------------------------------------------------------------
    
    def check_and_collect_data(self):

        if not self.is_collecting or not self.reached:
            return

        if self.last_robot_pose is None or self.last_tracking_pose is None:
            self.get_logger().info("Warte auf synchronisierte Daten...")
            return
        
        self.reached = False

        # 1. Konvertiere beide Posen mit der posestamped_to_matrix Funktion
        T_robot_4x4 = self.posestamped_to_matrix(self.last_robot_pose)
        T_tracking_4x4 = self.posestamped_to_matrix(self.last_tracking_pose) 

        # 2. Speichere die Posen
        self.robot_ee_poses.append(T_robot_4x4)
        self.tracking_pattern_poses.append(T_tracking_4x4)

        current_count = len(self.robot_ee_poses)
        self.get_logger().info(f" Messpaar gesammelt. Aktuelle Anzahl: {current_count} / {REQUIRED_POSES}")
        
        # Zurücksetzen, um nur neue Daten zu sammeln
        self.last_robot_pose = None
        self.last_tracking_pose = None

        # 3. Kalibrierung auslösen
        if current_count >= REQUIRED_POSES:
            self.is_collecting = False
            self.get_logger().warn("Genug Messungen gesammelt. Starte Kalibrierung...")
            
            self.perform_calibration() 
            
            self.get_logger().info('Kalibrierung abgeschlossen. Node wird beendet.')
            rclpy.shutdown()
        else:
            self.request_new_pose()
            
    # -------------------------------------------------------------
    # 7. Kalibrierungs-Hauptfunktion (Wird als nächstes gefüllt)
    # -------------------------------------------------------------
    def convertMatrix4Calibration(self, robot_matrix: np.ndarray, tracking_matrix: np.ndarray):
        """
        Erstellt die Matrix A (12x24) und den Vektor b (12 langes Array) für ein einzelnes Messpaar.
        """
        
        # Extrahiere Rotation des Trackings (3x3)
        # Hinweis: tracking_matrix ist jetzt ein 4x4 numpy array, kein list-objekt mehr
        rTracking = tracking_matrix[0:3, 0:3] 
        tTracking = tracking_matrix[0:3, 3]
        # B ist die Roboter-Matrix
        B = robot_matrix

        # Hier wird eine Block-Matrix erstellt. rTracking (3x3) wird mit den Skalaren aus B multipliziert.
        # Das Ergebnis ist eine große Matrix.
        # Hilfsvariable für Nullmatrix
        Z = np.zeros((3, 3))

        # --- LINKER TEIL DER MATRIX (12x12) ---

        # Bild Zeile 1 nutzt B Spalte 1: B_1,1, B_2,1, B_3,1  -> Python: B[0,0], B[1,0], B[2,0]
        row1 = np.hstack([ rTracking * B[0,0], rTracking * B[1,0], rTracking * B[2,0], Z ])
        row2 = np.hstack([ rTracking * B[0,1], rTracking * B[1,1], rTracking * B[2,1], Z ])
        row3 = np.hstack([ rTracking * B[0,2], rTracking * B[1,2], rTracking * B[2,2], Z ])  
        row4 = np.hstack([ rTracking * B[0,3], rTracking * B[1,3], rTracking * B[2,3], rTracking ])

        # Linken 12x12 Block zusammensetzen
        A_left = np.vstack([row1, row2, row3, row4])

        # --- RECHTER TEIL (-E12 anfügen) ---
        E12_neg = -1 * np.eye(12)
        # Endgültiges Zusammensetzen (horizontal)
        matrix_A = np.hstack([A_left, E12_neg])        # Ergebnis A ist nun eine 12x24 Matrix
        
        
        # Zweites Rückgabeobjekt:B

        # Oberer Teil: 9 Nullen (Z_9x1)
        zeros_9 = np.zeros(9)
        
        # Unterer Teil: Negative Translation von A (Tracking)
        # -T[Ai]
        neg_translation = -1 * tTracking
        
        vector_b = np.hstack([zeros_9, neg_translation])
        
        return matrix_A,vector_b

    def perform_calibration(self):
        """
        Sammelt A und b für alle Messungen, baut das globale System und löst es.
        """
        self.get_logger().info('perform_calibration: Starte Aufbau des Gleichungssystems...')
        
        list_A = [] # Liste für alle 12x24 Matrizen
        list_b = [] # Liste für alle 12x1 Vektoren
        
        num_measurements = len(self.robot_ee_poses)
        
        # 1. Iteration über alle Messungen
        for i in range(num_measurements):
            # Posen holen
            T_robot = self.robot_ee_poses[i]
            T_tracking = self.tracking_pattern_poses[i]
            
            # Konvertierung aufrufen (liefert Matrix A und Vektor b)
            # Ai shape: (12, 24)
            # bi shape: (12,) 
            Ai, bi = self.convertMatrix4Calibration(T_robot, T_tracking)
            
            list_A.append(Ai)
            list_b.append(bi)

        generated_count = len(list_A)
        self.get_logger().info(f'{generated_count} Matrizenpaare generiert.')
        
        if generated_count == 0:
            self.get_logger().error("Keine Matrizen generiert! Abbruch.")
            return

        # 2. Stacking: Alles untereinander schreiben
        # np.vstack stapelt vertikal -> aus N mal (12x24) wird (12*N x 24)
        A_total = np.vstack(list_A)
        
        # np.concatenate hängt 1D-Arrays hintereinander -> aus N mal (12) wird (12*N)
        b_total = np.concatenate(list_b)
        
        self.get_logger().info(f'Globales System erstellt. A: {A_total.shape}, b: {b_total.shape}')
        
        # 3. Lösen des Systems (Ax = b) mittels Least Squares
        # Da das System überbestimmt ist (mehr Zeilen als Unbekannte), suchen wir die "beste" Lösung.
        self.get_logger().info('Löse Gleichungssystem mittels Least Squares...')
        
        # x_sol ist der Lösungsvektor mit 24 Elementen
        # residuals gibt an, wie gut die Lösung passt (Fehlerquadratsumme)
        sol, residuals, rank, s = np.linalg.lstsq(A_total, b_total, rcond=None)
        
        self.get_logger().info('Lösung gefunden!')
        self.get_logger().info(f'Lösungsvektor x (die ersten 5 Werte): {sol[:5]}...')
        
        # HIER: Interpretation deiner Lösung
        # Da du eine eigene Methode hast, musst du diesen 24-elementigen Vektor 
        # nun wieder in deine gesuchte Transformationsmatrix (oder Parameter) umwandeln.
        # Zum Beispiel:
        x_sol = sol[0:12]
        y_sol = sol[12:24]
        x_lenght = len(x_sol)
        y_lenght = len(y_sol)
        
        for i in range(x_lenght):
            print(f"x{i}: {x_sol[i]}")
        for i in range(y_lenght):    
            print(f"y{i}: {y_sol[i]}")
            
        return
        
    
# -------------------------------------------------------------
# 8. Standard ROS 2 Main-Funktion
# -------------------------------------------------------------
    
def main(args=None):
    rclpy.init(args=args)
    node = HandEyeCalibrationNode()
    
    try:
        rclpy.spin(node)
    except Exception as e:
        node.get_logger().error(f"Fehler im Node: {e}")
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

if __name__ == '__main__':
    main()