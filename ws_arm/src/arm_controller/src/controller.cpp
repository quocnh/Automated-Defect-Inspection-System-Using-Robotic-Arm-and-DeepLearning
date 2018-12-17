#include "controller.hpp"


Controller::Controller()
{
    
  
    // sub_joint_positions = node.subscribe("arm_controller/target_joint_positions", 100, &Controller::chatterTargetJoints, this);

    // joint_msg_pub = node.advertise<sensor_msgs::JointState>("arm_controller/uarm_joint_publisher", 1);

    pub_servo_position = node.advertise<pca9685_msgs::ServoState>("pca9685/servostate_to_controller", 100);
    ros::Duration(1).sleep(); // optional, to make sure no message gets lost
    ROS_INFO("Servo controller is ready...");
}

int channels[N_CHANNELS];
double current_position[N_CHANNELS];
double target_position[N_CHANNELS];
double target_velocity[N_CHANNELS];
double init_position[N_CHANNELS];
int servo_type [N_CHANNELS];
double servo_offset [N_CHANNELS];
int servo_needs_hold [N_CHANNELS];
int servo_hold [N_CHANNELS];

void chatterTargetJoints (const sensor_msgs::JointStatePtr &msg){
    ROS_INFO("Recieved arm position msg size [%ld]", (long int)msg->name.size());

    // const std::string  joints[N_CHANNELS] = {
    //     "joint_1",
    //     "joint_2",
    //     "joint_3",
    //     "joint_4",
    //     "joint_5"
    // };
    ROS_INFO("[%s] [%f] [%f]", msg->name[0].c_str(), msg->position[0], msg->velocity[0]);

    // for( int i = 0; i < msg->name.size(); i++)
    // {
    //     ROS_INFO("[%s] [%f] [%f]", msg->name[i].c_str(), msg->position[i], msg->velocity[i]);
    //     // for( int j = 0; j < N_CHANNELS; j++)
    //     // {
    //     //     if(msg->name[i] == joints[j])
    //     //     {
    //     //         ROS_INFO("[%s] [%f] [%f]", joints[j].c_str(), msg->position[i], msg->velocity[i]);
    //     //         // target_position[j] = msg->position[i];
    //     //         // target_velocity[j] = msg->velocity[i];
    //     //     }
    //     // }
    // }
}

void Controller::controller()
{
    ROS_INFO("arm controller");
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "arm_controller");
    Controller c;
    c.controller();

    ros::NodeHandle n;
    // ros::Subscriber sub = n.subscribe("five_dof_arm/joint_states", 10000, callback);
    ros::Subscriber sub = n.subscribe("/command/joint_states", 100, chatterTargetJoints);
    
    ros::spin();
    return 0;
}
