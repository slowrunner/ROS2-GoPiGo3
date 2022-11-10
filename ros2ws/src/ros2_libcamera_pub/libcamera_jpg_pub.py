import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
import cv2
import numpy as np
import subprocess

class LibcameraJPGpub(Node):
      def __init__(self):
         super().__init__('LibcameraJPGpub')
         self.publisher_ = self.create_publisher(Image, 'Image', 10)
         timer_period = 10  # seconds
         self.timer = self.create_timer(timer_period, self.timer_callback)
         self.i = 0
         self.im_list = []
         self.bridge = CvBridge()
         subprocess.check_output(['libcamera-jpeg --rotation 180 --brightness 0.1 --contrast 1.1 -o /home/ubuntu/ros2ws/src/ros2_libcamera_pub/image_to_pub.jpg'], stderr=subprocess.STDOUT, shell=True)

      def timer_callback(self):
         subprocess.check_output(['libcamera-jpeg --rotation 180 --width 1296 --height 730 --brightness 0.1 --contrast 1.1 -o /home/ubuntu/ros2ws/src/ros2_libcamera_pub/image_to_pub.jpg'], stderr=subprocess.STDOUT, shell=True)
         self.cv_image = cv2.imread('/home/ubuntu/ros2ws/src/ros2_libcamera_pub/image_to_pub.jpg') ### an RGB image 
         print("cv_image shape:", self.cv_image.shape[:2])
         self.np_image = np.array(self.cv_image)
         try:
           image_msg = self.bridge.cv2_to_imgmsg(self.np_image, "bgr8")
           self.publisher_.publish(image_msg)
           self.get_logger().info('Publishing an image')
         except Exception as e:
           print("timer_callback:",e)

def main(args=None):
    rclpy.init(args=args)
    libcamera_jpg_pub = LibcameraJPGpub()
    rclpy.spin(libcamera_jpg_pub)
    minimal_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
   main()
