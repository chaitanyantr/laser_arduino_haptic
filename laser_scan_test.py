#! /usr/bin/env python

import rospy
from sensor_msgs.msg import LaserScan
from std_msgs.msg import UInt16 
import time

def callback(msg):
	global scan_data
	scan_data = (msg.ranges)

rospy.init_node('scan_values')
sub = rospy.Subscriber('scan', LaserScan, callback)
left_pub = rospy.Publisher('/haptic_left', UInt16, queue_size = 1)
front_pub = rospy.Publisher('/haptic_front', UInt16, queue_size = 1)
right_pub = rospy.Publisher('/haptic_right', UInt16, queue_size = 1)
back_pub = rospy.Publisher('/haptic_back', UInt16, queue_size = 1)

min_deg = -150
max_deg = 150 
num_seg = 601

### Converting this into a line
m = (num_seg - 1)/(max_deg - min_deg)
c = -m * (min_deg)
left_ind = m * (-135) + c
front_ind = m * (-45) + c
right_ind = m * (45) + c
back_ind = m * (135) + c
time.sleep(5)
# print(scan_data)

# left_arr=  scan_data[left_ind:front_ind]
# front_arr=  scan_data[front_ind:right_ind]
# right_arr=  scan_data[right_ind:back_ind]
# back_arr =  scan_data[back_ind::] + scan_data[0:left_ind]

# print("left_arr", min(left_arr))
# print("right_arr", min(right_arr))
# print("front_arr", min(front_arr))
# print("back_arr", min(back_arr))

flag_left = UInt16()
flag_right = UInt16()
flag_back = UInt16()
flag_front = UInt16()


threshold_dist = 2
while(not rospy.is_shutdown()):

	left_arr=  scan_data[left_ind:front_ind]
	front_arr=  scan_data[front_ind:right_ind]
	right_arr=  scan_data[right_ind:back_ind]
	back_arr =  scan_data[back_ind::] + scan_data[0:left_ind]

	print("left_arr", min(left_arr))
	print("right_arr", min(right_arr))
	print("front_arr", min(front_arr))
	print("back_arr", min(back_arr))

	if min(left_arr)<2:
		flag_left.data = 1
		left_pub.publish(flag_left)
	else:
		flag_left.data = 0
		left_pub.publish(flag_left)



	if min(right_arr)<2:
		flag_right.data = 1
		right_pub.publish(flag_right)
	else:
		flag_right.data = 0
		right_pub.publish(flag_right)



	if min(back_arr)<2:
		flag_back.data = 1
		back_pub.publish(flag_back)
	else:
		flag_back.data = 0
		back_pub.publish(flag_back)




	if min(front_arr)<2:
		flag_front.data = 1
		front_pub.publish(flag_front)
	else:
		flag_front.data = 0
		front_pub.publish(flag_front)

	time.sleep(1)

rospy.spin()