#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>
#include <math.h>
#include "beginner_tutorials/Distancia.h"
bool Distancia(beginner_tutorials::Distancia::Request  &req,
                       beginner_tutorials::Distancia::Response &res)
{
    double turtle_x1 = req.x1;
    double turtle_y1 = req.y1;
    double turtle_x2 = req.x2;
    double turtle_y2 = req.y2;
 
    double dist = sqrt(std::pow(turtle_x2 - turtle_x1, 2) + std::pow(turtle_y2 - turtle_y1, 2));
 
    res.dis = dist;
 
    return  true;
}
int main(int argc, char **argv){

    ros::init(argc, argv, "distance_checker_plus");
    ros::NodeHandle nh;
    ros::ServiceServer server = 
		nh.advertiseService("Distancia",&Distancia);
//Create a client object for the spawn service. This
//needs to know the data type of the service and its name.
// Create a subscriber object.
    ros::ServiceClient spawnClient
		= nh.serviceClient<turtlesim::Spawn>("spawn");
//Create the request and response objects.
    turtlesim::Spawn::Request req;
    turtlesim::Spawn::Response resp;

    req.x = 5.5;
    req.y = 5.5;
    req.theta = M_PI/2;
    req.name = "turtle2";

    ros::service::waitForService("spawn", ros::Duration(5));
    bool success = spawnClient.call(req,resp);
    
    if(success){
	ROS_INFO_STREAM("Spawned a turtle named "
			<< resp.name);
    }else{
	ROS_ERROR_STREAM("Failed to spawn.");
    }
  ros::spin();

}