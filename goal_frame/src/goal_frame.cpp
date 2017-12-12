#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>

ros::Publisher pub;

void
msg_cb (const geometry_msgs::PoseStamped& input)
{
  // Create a container for the data.
  geometry_msgs::PoseStamped output;

  // Do data processing here...
  output = input;
  output.header.stamp = ros::Time::now();
  output.header.frame_id = "map";

  // Publish the data.
  pub.publish (output);
}

int
main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "goal_frame");
  ros::NodeHandle nh;

  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("/goal_position_temp", 1, msg_cb);

  // Create a ROS publisher for the output point cloud
  pub = nh.advertise<geometry_msgs::PoseStamped> ("/move_base_simple/goal", 1);

  // Spin
  ros::spin ();
}


