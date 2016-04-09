#include "ros/ros.h"
#include "std_msgs/String.h"
#include "ros/console.h"

ros::Publisher pub ;

void remoteCallback(const std_msgs::String& msg)
{
    ROS_INFO_STREAM("Message received from aadi gate: " << msg.data) ;
    std_msgs::String cmd ;
    cmd.data = msg.data + " and hello from hub" ;
    
    pub.publish(cmd) ;
}

int main(int argc, char **argv)
{  
  ros::init(argc, argv, "hub_subscriber") ;
  ros::NodeHandle nh ;
  
  pub = nh.advertise<std_msgs::String>("hub_topic", 10, true) ;
  
  ros::Subscriber sub = nh.subscribe("/aadi_topic", 10, &remoteCallback) ;

  ros::spin();
  
  return 0 ;
}
