// This program publishes randomly-generated velocity
// messages for turtlesim.
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>  // For geometry_msgs::Twist
#include <stdlib.h> // For rand() and RAND_MAX
#include <turtlesim/Pose.h>
#include <iomanip> // for std::setprecision and std::fixed
bool safe = false;

void turtlepose(const turtlesim::Pose& msg) {
  ROS_INFO_STREAM(std::setprecision(2) << std::fixed
    << "position=(" <<  msg.x << "," << msg.y << ")"
    << " direction=" << msg.theta);
    
}

int main(int argc, char **argv) {
  // Initialize the ROS system and become a node.
  ros::init(argc, argv, "safe_zone_vel_publisher");
  ros::NodeHandle nh;

  //create a subscriber object
  ros::Subscriber sub = nh.subscribe("turtle1/pose", 1000,
    &turtlepose);
  // Create a publisher object.
 
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>(
    "turtle1/cmd_vel", 1000);
  
  // Seed the random number generator.
  srand(time(0));

  // Loop at 2Hz until the node is shut down.
  ros::Rate rate(2);
  while(ros::ok()) {
    //subscripon y obtecion de los datos por la variable poseturtle dentro del while para actualizarse siempre
    turtlesim::Pose::ConstPtr poseturtle = ros::topic::waitForMessage<turtlesim::Pose>("turtle1/pose");
    // Create and fill in the message.  The other four
    // fields, which are ignored by turtlesim, default to 0.
    geometry_msgs::Twist msg;
    if(poseturtle->x>=3 && poseturtle->x<=8 && poseturtle->y>=3 && poseturtle->y<=8){
      msg.linear.x = 1;
      msg.angular.z = 2*double(rand())/double(RAND_MAX) - 1;
      pub.publish(msg);
    }
    else{
      msg.linear.x = double(rand())/double(RAND_MAX);
      msg.angular.z = 2*double(rand())/double(RAND_MAX) - 1;
      pub.publish(msg);
    }
    

    // Publish the message.
    

    // Send a message to rosout with the details.
    ROS_INFO_STREAM("Sending random velocity command:"
      << " linear=" << msg.linear.x
      << " angular=" << msg.angular.z);

    // Wait until it's time for another iteration.
    rate.sleep();
  }
}
