#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include <ros/ros.h>
#include <pca9685_msgs/ServoState.h>
#include <sensor_msgs/JointState.h>

#define N_CHANNELS 5

class Controller {
	public:
		Controller();
		void controller();

	private:
		ros::NodeHandle node;
        ros::Subscriber sub_joint_positions;

		ros::Publisher pub_servo_position;
        ros::Publisher joint_msg_pub;

        int channels[N_CHANNELS];
        double current_position[N_CHANNELS];
        double target_position[N_CHANNELS];
        double target_velocity[N_CHANNELS];
        double init_position[N_CHANNELS];
        int servo_type [N_CHANNELS];
        double servo_offset [N_CHANNELS];
        int servo_needs_hold [N_CHANNELS];
        int servo_hold [N_CHANNELS];

        void chatterTargetJoints (const sensor_msgs::JointStatePtr &target_jnts);
};


#endif /* CONTROLLER_HPP_ */