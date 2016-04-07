#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

ros::Publisher pub ;

void remoteCallback(const geometry_msgs::Twist& msg)
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
  ros::init(argc, argv, "hub_subscriber") ;
  ros::NodeHandle n1 ;
  ros::NodeHandle n2 ;
  
  ros::Publisher pub = n1.advertise<geometry_msgs::Twist>("/aadi1/hub_topic", 50, true) ;
  
  ros::Subscriber sub = n2.subscribe("/aadi1/remote_topic", 10, &remoteCallback) ;

  ros::spin();
  
  return 0 ;
}
