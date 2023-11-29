#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>
float x = 0;
float z = 0;
void Turtle_vel_1(const geometry_msgs::Twist& msg) {
  ROS_INFO_STREAM(std::setprecision(2) << std::fixed
    << "velocidad x, y=" <<  msg.linear.x
    << " directangular=" << msg.angular.z);
    x = msg.linear.x;
    z = msg.angular.z;
}
// Callback function of the subscriber
int main(int argc, char** argv) {
    ros::init(argc, argv, "opposite_velocity_publisher");
    ros::NodeHandle nh;
    // Spawning a new turtle
    ros::ServiceClient spawnClient
            = nh.serviceClient<turtlesim::Spawn>("spawn");
    ros::Subscriber subvel = nh.subscribe("turtle1/cmd_vel", 1000, &Turtle_vel_1);
    //Create the request and response objects.
    turtlesim::Spawn::Request req;
    turtlesim::Spawn::Response resp;

    req.x = 5.5;
    req.y = 5.5;
    req.theta = M_PI;
    req.name = "second_turtle";

    ros::service::waitForService("spawn", ros::Duration(5));
    bool success = spawnClient.call(req,resp);

    if(success){
    ROS_INFO_STREAM("Spawned a turtle named "
            << resp.name);
    }else{
    ROS_ERROR_STREAM("Failed to spawn.");
    }
// Publisher of the opposite velocities for the second turtle
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>(
    "second_turtle/cmd_vel", 1000);
    srand(time(0));

  // Loop at 2Hz until the node is shut down.
    ros::Rate rate(1);
    
    while (ros::ok()) {
        geometry_msgs::Twist msg;
        msg.linear.x = -(x);
        msg.angular.z = -(z);
        pub.publish(msg);
        ROS_INFO_STREAM("sentido invertido second_turtle:"
      << " linear=" << msg.linear.x
      << " angular=" << msg.angular.z);
      x = 0;
      z = 0;
        ros::spinOnce();
        rate.sleep();
    }
// Subscriber for the first-turtle-velocities topic
return 0;
}