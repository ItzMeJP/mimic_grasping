# Mimic grasping ROS interface package

<a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-nd/4.0/88x31.png" />

* [Description](#Description)
* [Dependencies](#Dependencies)
* [Installation](#Installation)
* [Usage](#Usage)


## <a name="Description"></a>1. Description

This package allows the mimic_grasping_server to communicate with ROS pipelines. This is a multipurpose wrapper package. Supported ROS pipelines:

1. [Object Recognition](https://github.com/carlosmccosta/object_recognition)

## <a name="Dependencies"></a> Dependencies
1. [ROS](http://wiki.ros.org/ROS/Installation)
2. [Catkin Tools](https://catkin-tools.readthedocs.io/en/latest/installing.html)
3. [Phoxi Camera](https://github.com/carlosmccosta/phoxi_camera)
4. [Photoneo Skill](https://gitlab.inesctec.pt/pmrebelo/photoneo_skill)
5. [Dynamic Robot Localization](https://github.com/carlosmccosta/dynamic_robot_localization)
6. [Object Recognition](https://github.com/carlosmccosta/object_recognition)
7. [Point Cloud IO](https://github.com/carlosmccosta/point_cloud_io)


## <a name="Installation"></a> Installation
Setup all dependencies (follow each README and tutorial).

Clone the repository:
```

```
Compile the ROS package with [catkin tools](https://catkin-tools.readthedocs.io/en/latest/installing.html):

```
roscd mimic_grasping_ros_interface
catkin build
```

## <a name="Usage"></a> Usage
### Object recognition interface




The work was based on [this](https://github.com/caiorss/sample-cpp-plugin).

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
<br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/">Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License</a>.
