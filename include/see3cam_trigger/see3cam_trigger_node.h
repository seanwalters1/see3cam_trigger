#ifndef SEE3CAM_TRIGGER_NODE_H
#define SEE3CAM_TRIGGER_NODE_H

#include <ros/ros.h>
#include <stdio.h>
#include <unistd.h>

#define GPIO_EXPORT_FILE                   "/sys/class/gpio/export"
#define TRIGGER_GPIO_FILE_DIRECTION_STRING "/sys/class/gpio/gpio166/direction"
#define TRIGGER_GPIO_FILE_VALUE_STRING     "/sys/class/gpio/gpio166/value"
#define TRIGGER_PULSE_DURATION_US          2000

int main (int, char**);
void callbackTimer (const ros::TimerEvent&);

#endif // SEE3CAM_TRIGGER_NODE_H
