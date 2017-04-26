/* Author: Guillaume Walck */

#ifndef GRASP_VIEWER_H
#define GRASP_VIEWER_H

#include <string>
#include <moveit_msgs/Grasp.h>
#include <visualization_msgs/MarkerArray.h>
#include <geometry_msgs/PoseStamped.h>
#include <moveit/robot_state/robot_state.h>
#include <std_msgs/ColorRGBA.h>

class GraspViewer
{
  public:
      GraspViewer(const std::string ns, const std::string grasp_frame="grasp_frame");
      bool init();
      bool createGraspMarker(const std::string ee_name, const moveit_msgs::Grasp &grasp,
                             visualization_msgs::MarkerArray &marker_array,
                             std_msgs::ColorRGBA color);

  private:
      void createGraspFrameMarker(visualization_msgs::MarkerArray &marker_array, const geometry_msgs::PoseStamped &grasp_pose_stamped);
      void createDefaultGraspMarker(visualization_msgs::MarkerArray &marker_array, const geometry_msgs::PoseStamped &grasp_pose_stamped);
      std::string ns_;
      std::string grasp_frame_;
      std::string root_link_;
      moveit::core::RobotStatePtr robot_state_;
};

#endif
