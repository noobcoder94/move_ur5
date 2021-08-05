#include <ros/ros.h>
#include <ros/package.h>
#include <std_msgs/String.h>
#include <math.h>
#include <std_msgs/Float64.h>
#include <control_msgs/JointControllerState.h>


const int Joints = 6;

void get_shoulder_pan_joint_position(const control_msgs::JointControllerState::ConstPtr& ctr_msg) {
	double q1 = ctr_msg->process_value;
	ROS_INFO("q0: %f",q1);
}

void get_shoulder_lift_joint_position(const control_msgs::JointControllerState::ConstPtr& ctr_msg) {
	double q3 = ctr_msg->process_value;
	ROS_INFO("q1: %f",q3);
}

void get_elbow_joint_position(const control_msgs::JointControllerState::ConstPtr& ctr_msg) {
	double q0 = ctr_msg->process_value;
	ROS_INFO("q2: %f",q0);
}

void get_wrist_1_joint_position(const control_msgs::JointControllerState::ConstPtr& ctr_msg) {
	double q2 = ctr_msg->process_value;
	ROS_INFO("q3: %f",q2);
}

void get_wrist_2_joint_position(const control_msgs::JointControllerState::ConstPtr& ctr_msg) {
	double q4 = ctr_msg->process_value;
	ROS_INFO("q4: %f",q4);
}

void get_wrist_3_joint_position(const control_msgs::JointControllerState::ConstPtr& ctr_msg) {
	double q5 = ctr_msg->process_value;
	ROS_INFO("q5: %f",q5);
}



int main(int argc, char **argv)
{

	ros::init(argc, argv, "ur5_task1");
	
	ros::NodeHandle nh;
	
	ros::Rate loop_rate(10);

	//ros::Subscriber shoulder_pan_joint_sub = nh.subscribe("/shoulder_pan_joint_position_controller/state", 1000, get_shoulder_pan_joint_position);
	//ros::Subscriber shoulder_lift_joint_sub = nh.subscribe("/shoulder_lift_joint_position_controller/state", 1000, get_shoulder_lift_joint_position);
	//ros::Subscriber elbow_joint_sub = nh.subscribe("/elbow_joint_position_controller/state", 1000, get_elbow_joint_position);
	//ros::Subscriber wrist_1_joint_sub = nh.subscribe("/wrist_1_joint_position_controller/state", 1000, get_wrist_1_joint_position);
	//ros::Subscriber wrist_2_joint_sub = nh.subscribe("/wrist_2_joint_position_controller/state", 1000, get_wrist_2_joint_position);
	//ros::Subscriber wrist_3_joint_sub = nh.subscribe("/wrist_3_joint_position_controller/state", 1000, get_wrist_3_joint_position);


ros::Publisher arm_joint_pub[6]; 
	arm_joint_pub[0] = nh.advertise<std_msgs::Float64>("/shoulder_pan_joint_position_controller/command", 1000);
	arm_joint_pub[1] = nh.advertise<std_msgs::Float64>("/shoulder_lift_joint_position_controller/command", 1000);
	arm_joint_pub[2] = nh.advertise<std_msgs::Float64>("/elbow_joint_position_controller/command", 1000);
	arm_joint_pub[3] = nh.advertise<std_msgs::Float64>("/wrist_1_joint_position_controller/command", 1000);
	arm_joint_pub[4] = nh.advertise<std_msgs::Float64>("/wrist_2_joint_position_controller/command", 1000);
	//arm_joint_pub[5] = nh.advertise<std_msgs::Float64>("/wrist_3_joint_position_controller/command", 1000);
	
	


	double i = 0;
	while(ros::ok())
	{
				
		std_msgs::Float64 angle;
		
		angle.data = sin(i);
		arm_joint_pub[0].publish(angle);
		arm_joint_pub[1].publish(angle);
		arm_joint_pub[2].publish(angle);
		arm_joint_pub[3].publish(angle);
		arm_joint_pub[4].publish(angle);
		//arm_joint_pub[5].publish(angle);
		ros::spinOnce();
		loop_rate.sleep();
		i+=0.08;	
	}
	ros::shutdown();
	return 0;

}
