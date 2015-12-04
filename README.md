# see3cam_trigger

In order to access Jetson GPIO without root, copy udev file and add the following to /etc/rc.local before the exit:
chown -R ubuntu:ubuntu /sys/class/gpio
