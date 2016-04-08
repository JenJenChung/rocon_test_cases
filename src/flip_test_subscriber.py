#!/usr/bin/python
import rospy
import os
import gateway_msgs.msg as gateway_msgs
import gateway_msgs.srv as gateway_srvs
import rocon_gateway

rospy.init_node('flip_test_subscriber')

remote_gateway = "Hub Gateway"
flip_service = rospy.ServiceProxy('/gateway/flip', gateway_srvs.Remote)
req = gateway_srvs.RemoteRequest()
req.cancel = False
req.remotes = []
rule = gateway_msgs.Rule()
rule.name = '/hub_topic'
rule.type = gateway_msgs.ConnectionType.SUBSCRIBER
rule.node = '/aadi_subscriber'
req.remotes.append(gateway_msgs.RemoteRule(remote_gateway,rule))
rospy.loginfo("Flip : [%s,%s,%s,%s]."%(remote_gateway, rule.name, rule.type, rule.node))

resp = flip_service(req)
if resp.result != 0:
    rospy.logerr("Flip : %s"%resp.error_message)

rospy.loginfo("Finished flipping connection.")
