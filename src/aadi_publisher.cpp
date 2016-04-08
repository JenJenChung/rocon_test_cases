#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{  
  ros::init(argc, argv, "aadi_publisher") ;
  ros::NodeHandle nh ;
  
  ros::Publisher pub = nh.advertise<std_msgs::String>("aadi_topic", 10, true) ;
  
  std_msgs::String msg ;
  msg.data = "Hello from AADI" ;

  //publish the message
  pub.publish(msg);

  ros::spin();
  
  return 0 ;
}
