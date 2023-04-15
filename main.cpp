#include"include/gpio.h"
#include<ros/ros.h>
#include<std_msgs/Int8.h>

using namespace ECC_gpio;

int main(int argc,char **argv)
{
        ros::init(argc,argv,"pin_publisher");
        ros::NodeHandle n;
        ros::Rate rate(1);

        ros::Publisher pub=n.advertise<std_msgs::Int8>("/pin_66",10);
        GPIO g(66);
        g.gpioPinInit(66,INPUT,INPUT_PULLUP);
        int value_66=(g.gpioReadPin(66));
        std_msgs::Int8 value;
        value.data=value_66;
        while(ros::ok())
        {
                pub.publish(value);
                rate.sleep();
                ROS_INFO("DATA IS BEING PUBLISHED");
        }
}
