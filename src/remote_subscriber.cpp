#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

ros::Publisher pub ;

void hubCallback(const geometry_msgs::Twist& msg)
{
    geometry_msgs::Twist cmd ;
    cmd.linear.x = msg.linear.x ;
    cmd.linear.y = msg.linear.y ;
    cmd.linear.z = msg.linear.z ;
    cmd.angular.x = msg.angular.x ;
    cmd.angular.y = msg.angular.y ;
    cmd.angular.z = msg.angular.z ;
    
    pub.publish(cmd) ;
}

int main(int argc, char **argv)
{  
  ros::init(argc, argv, "remote_subscriber") ;
  ros::NodeHandle n1 ;
  ros::NodeHandle n2 ;
  
  ros::Publisher pub = n1.advertise<geometry_msgs::Twist>("/aadi1/received_hub_topic", 50, true) ;
  
  ros::Subscriber sub = n2.subscribe("/aadi1/hub_topic", 10, &hubCallback) ;

  ros::spin();
  
  return 0 ;
}
