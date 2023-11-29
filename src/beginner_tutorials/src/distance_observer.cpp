#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <math.h>
#include "beginner_tutorials/Distancia.h"

bool dist = false;

// Global position variables (x and y) for both turtles
float turtle_x1;
float turtle_x2;
float turtle_y1;
float turtle_y2;
// Create an object of the type of the distance computation service
void turtle1PoseCallback(const turtlesim::Pose& msg)
{
// Store the pose x and y values of turtle1 to the global variables created above
    turtle_x1 = msg.x;
    turtle_y1 = msg.y;
}
void turtle2PoseCallback(const turtlesim::Pose& msg)
{
// Store the pose x and y values of turtle2 to the global variables created above
    turtle_x2 = msg.x;
    turtle_y2 = msg.y;
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "distance_observer_node");
    ros::NodeHandle nh;
    // Subscription to the pose topics for turtle1 and turtle2
    ros::Subscriber sub1 = nh.subscribe("turtle1/pose", 1000,
        &turtle1PoseCallback);
    ros::Subscriber sub2 = nh.subscribe("turtle2/pose", 1000,
        &turtle2PoseCallback);
    //Needed for this node to execute succesfully. Use this line as it is, if the service of the previous exercise is called
    // Create the handler for the distance computation services
    // Crate the service client object
    ros::ServiceClient Client = nh.serviceClient<beginner_tutorials::Distancia>("Distancia");
    beginner_tutorials::Distancia srv;
    // Set the frequency of the loop for achiving the required 0.5 repetition of the node execution
    srand(time(0));
    // ros::Rate loop_rate(?);
    ros::Rate rate(0.2);
while (ros::ok())
{
    srv.request.x1 = turtle_x1;
    srv.request.y1 = turtle_y1;
    srv.request.x2 = turtle_x2;
    srv.request.y2 = turtle_y2;

// Update the turtle 1 and 2 poses to the service object
// Call the distance computation service
    if(Client.call(srv)){
        ROS_INFO("Distancia: %f", srv.response.dis);
    }
    else{
        ROS_INFO("Error");
    }
    ros::spinOnce();
    rate.sleep();
}
return 0;
}