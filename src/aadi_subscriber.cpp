#include "ros/ros.h"
#include "std_msgs/String.h"
#include "ros/console.h"

ros::Publisher pub ;

void hubCallback(const std_msgs::String& msg)
{
    ROS_INFO_STREAM("Message received from hub gate: " << msg.data) ;
    std_msgs::String cmd ;
    cmd.data = msg.data ;
    
    pub.publish(cmd) ;
}

int main(int argc, char **argv)
{  
  ros::init(argc, argv, "aadi_subscriber") ;
  ros::NodeHandle nh ;
  
  pub = nh.advertise<std_msgs::String>("received_hub_topic", 10, true) ;
  
  ros::Subscriber sub = nh.subscribe("hub_topic", 10, &hubCallback) ;

  ros::spin();
  
  return 0 ;
}
