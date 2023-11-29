#include <ros/ros.h>
#include <geometry_msgs/Twist.h>  // For geometry_msgs::Twist
#include <stdlib.h> // For rand() and RAND_MAX
#include <turtlesim/Pose.h>
#include <iomanip> // for std::setprecision and std::fixed
#include <turtlesim/Spawn.h>

void Subvel(const geometry_msgs::Twist& msg) {
  ROS_INFO_STREAM(std::setprecision(2) << std::fixed
    << "velocity=(" <<  msg.linear.x << "," << " angular=" << msg.linear.z);
    
}

int main(int argc, char **argv){

    ros::init(argc, argv, "move_second_turtle");
    ros::NodeHandle nh;

    ros::ServiceClient spawnClient
		= nh.serviceClient<turtlesim::Spawn>("spawn");
    ros::Subscriber subvel = nh.subscribe("turtle1/cmd_vel", 1000, &Subvel);
    ros::spin();
}