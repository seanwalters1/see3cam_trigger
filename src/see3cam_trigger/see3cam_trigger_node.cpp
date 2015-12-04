#include "see3cam_trigger/see3cam_trigger_node.h"

FILE *fp;

int main (int argc, char** argv) {
  ros::init (argc, argv, "see3cam_trigger_node");
  ros::NodeHandle nh ("~");
  bool oneshot = false;
  int rateHz = 30;
  nh.param("rate_hz", rateHz, rateHz);
  ros::Duration period = ros::Duration (double (1) / double (rateHz));
  ros::Timer timer = nh.createTimer (period, callbackTimer, oneshot);

  if ((fp = fopen (GPIO_EXPORT_FILE, "w")) == NULL) {
	  ROS_INFO("Cannot open export file.");
	  exit (1);
  }
  ROS_INFO("Opened export file.");
  fprintf (fp, "166");

  ROS_INFO("Wrote trigger pin to export file.");
  if ((fp = fopen(TRIGGER_GPIO_FILE_DIRECTION_STRING, "a")) == NULL) {
	  ROS_INFO("Cannot open trigger gpio direction file.");
	  exit (1);
  }
  ROS_INFO("Opened trigger pin direction file.");

  fprintf (fp, "out");
  fclose (fp);
  ROS_INFO("Wrote trigger pin direction to file.");

  ros::spin ();

  return 0;
}

void callbackTimer (const ros::TimerEvent& event) {
  if ((fp = fopen(TRIGGER_GPIO_FILE_VALUE_STRING, "a")) == NULL){
	  ROS_INFO("Cannot open trigger gpio value file.");
  } else {
	fprintf (fp, "1"); // Active low trigger
	fclose (fp);
  }

  usleep (TRIGGER_PULSE_DURATION_US);

  if ((fp = fopen(TRIGGER_GPIO_FILE_VALUE_STRING, "a")) == NULL){
	  ROS_INFO("Cannot open trigger gpio value file.");
  } else {
	fprintf (fp, "0");
	fclose (fp);
  }
}
