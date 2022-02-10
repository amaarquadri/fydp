#include "bmb_controllers/LocalPathPlannerNode.h"
#include <bmb_controllers/DubinsPath.h>
#include <bmb_controllers/PIDFFController.h>
#include <bmb_controllers/PurePursuit.h>
#include <bmb_msgs/AircraftState.h>
#include <bmb_msgs/ReferenceCommand.h>
#include <bmb_msgs/StateCommand.h>
#include <bmb_utilities/ControllerGains.h>
#include <bmb_world_model/Constants.h>
#include <ros/ros.h>
#include <cmath>

LocalPathPlannerNode::LocalPathPlannerNode(ros::NodeHandle& nh,
                                           const double& update_frequency)
    : update_frequency(update_frequency),
      altitude_pid(
          PIDFFController<double>{ALTITUDE_GAIN, 1 / update_frequency}) {
  // initialize subscribers
  aircraft_state_sub_ = nh.subscribe(
      "aircraft_state", 1, &LocalPathPlannerNode::aircraftStateCallback, this);
  reference_command_sub_ =
      nh.subscribe("reference_command", 1,
                   &LocalPathPlannerNode::referenceCommandCallback, this);

  // initialize publishers
  state_command_pub_ = nh.advertise<bmb_msgs::StateCommand>("state_command", 1);
}

void LocalPathPlannerNode::aircraftStateCallback(
    const bmb_msgs::AircraftState& msg) {
  latest_aircraft_state = msg;
}

void LocalPathPlannerNode::referenceCommandCallback(
    const bmb_msgs::ReferenceCommand& msg) {
  latest_reference_command = msg;
  update_dubins_path = true;
}

bmb_msgs::StateCommand LocalPathPlannerNode::getStateCommand() {
  State current_state{latest_aircraft_state};
  State goal{latest_reference_command};

  if (update_dubins) {
    path =
        DubinsPath<double>::create(current_state, goal, MIN_RADIUS_CURVATURE);
    update_dubins = false;
  }
  auto [should_replan, angular_vel] = pursuer.pursue(current_state);
  if (should_replan) {
    path =
        DubinsPath<double>::create(current_state, goal, MIN_RADIUS_CURVATURE);
    std::tie(should_replan, angular_vel) = pursuer.pursue(current_state);
#if DEBUG
    assert(!should_replan);
#endif
  }

  const double& x_vel = latest_aircraft_state.twist.linear.x;
  const double vertical_force = altitude_pid.update(
      latest_aircraft_state.pose.position.z, ref_cmd.altitude);
  const double horizontal_force =
      MASS * x_vel * angular_vel;  // Centripetal force
  const double net_force = std::hypot(horizontal_force, vertical_force);
  // TODO: calculate max lift, verify feasibility, calculate StateCommand

  bmb_msgs::StateCommand state_command;
  return state_command;
}

void LocalPathPlannerNode::spin() {
  ros::Rate rate{update_frequency};
  while (ros::ok()) {
    ros::spinOnce();
    state_command_pub_.publish(getStateCommand(latest_aircraft_state));
    rate.sleep();
  }
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "bmb_local_path_planner");
  ros::NodeHandle nh;
  LocalPathPlannerNode node{nh, 1};
  node.spin();
}
