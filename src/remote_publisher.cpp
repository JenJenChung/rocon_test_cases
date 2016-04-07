#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv)
{  
  ros::init(argc, argv, "remote_publisher") ;
  ros::NodeHandle nh ;
  
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("remote_topic", 50, true) ;
  
  geometry_msgs::Twist msg ;
  msg.linear.x = 0 ;
  msg.linear.y = 0 ;
  msg.linear.z = 0 ;
  msg.angular.x = 0 ;
  msg.angular.y = 0 ;
  msg.angular.z = 0 ;

  //publish the message
  pub.publish(msg);

  ros::spin();
  
  return 0 ;
}
