//
// Created by joaopedro on 12/07/21.
//
/*
#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>

#include <object_recognition_skill_msgs/ObjectRecognitionSkillAction.h>

int main (int argc, char **argv)
{
    ros::init(argc, argv, "object_recognition_client_test");

    // create the action client
    // true causes the client to spin its own thread
    actionlib::SimpleActionClient<object_recognition_skill_msgs::ObjectRecognitionSkillAction> ac("/object_recognition/ObjectRecognitionSkill", true);

    ROS_INFO("Waiting for action server to start.");
    // wait for the action server to start
    ac.waitForServer(); //will wait for infinite time

    ROS_INFO("Action server started, sending goal.");
    // send a goal to the action
    object_recognition_skill_msgs::ObjectRecognitionSkillGoal goal;
    goal.clusterIndex = -1;
    ac.sendGoal(goal);

    //wait for the action to return
    bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));

    if (finished_before_timeout)
    {
        actionlib::SimpleClientGoalState state = ac.getState();
        ROS_INFO("Action finished: %s",state.toString().c_str());
    }
    else
        ROS_INFO("Action did not finish before the time out.");

    //exit
    return 0;
}
 */

//
// Created by joaopedro on 12/07/21.
//

#include <object_recognition_client/obj_localization_ros.h>

int main(int argc, char **argv) {


    char const* env_root_folder_path;

    env_root_folder_path =  getenv("MIMIC_GRASPING_SERVER_ROOT");

    if(env_root_folder_path == NULL) {
        ROS_ERROR_STREAM("The environment variable $MIMIC_GRASPING_SERVER_ROOT is not defined.");
        return false;
    }

    std::string root_folder_path_ = std::string(env_root_folder_path);

    ObjLocalizationROS o;

    o.setAppExec(root_folder_path_ + "/scripts/obj_localization_ros_init.sh");
    o.setAppTermination( root_folder_path_ + "/scripts/obj_localization_ros_close.sh");
    o.setAppConfigPath(root_folder_path_ + "/configs/plugin_object_localization_ros.json");
    o.setTargetName(root_folder_path_ + "/models/single_side_bracket.ply");

    if (!o.loadAppConfiguration() || !o.runApp()) {
        std::cout << o.getOutputString() << std::endl;
        return false;
    }

    Pose p;

    while (ros::ok()) {
        o.spin(250);
        o.requestData(p);
        ROS_INFO_STREAM("\n Child frame name: " << p.getName() << "\n Parent frame name: " << p.getParentName()
                                                << "\n Position [x,y,z]: [" <<
                                                p.getPosition().x() << ", " << p.getPosition().y() << ", "
                                                << p.getPosition().z() << "]\n Orientation [x,y,z,w]: [" <<
                                                p.getQuaternionOrientation().x() << ", "
                                                << p.getQuaternionOrientation().y() << ", "
                                                << p.getQuaternionOrientation().z() << ", "
                                                << p.getQuaternionOrientation().w() << "]");

    }

    o.spin(250);
    o.stopApp();
    return 0;
}