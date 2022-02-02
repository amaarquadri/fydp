#include "bmb_utilities/MessageUtilities.h"
#include <bmb_msgs/SensorMeasurements.h>
#include <bmb_msgs/AircraftState.h>
#include <bmb_msgs/ControlInputs.h>
#include <bmb_math/Vector.h>
#include <bmb_math/Vector3.h>

namespace bmb_utilities {

Vector<double, 18> as_vector(const bmb_msgs::SensorMeasurements& msg) {
  Vector<double, 18> vec;
  vec[bmb_msgs::SensorMeasurements::PRESSURE] = msg.pressure_reading.fluid_pressure;
  vec[bmb_msgs::SensorMeasurements::RAIL_ANGLE] = msg.rail_detection.angle;
  vec[bmb_msgs::SensorMeasurements::RAIL_WIDTH] = msg.rail_detection.pixel_width;
  vec[bmb_msgs::SensorMeasurements::RAIL_x] = msg.rail_detection.pixel_x;
  vec[bmb_msgs::SensorMeasurements::RAIL_y] = msg.rail_detection.pixel_y;
  vec[bmb_msgs::SensorMeasurements::RAIL_FOUND] = msg.rail_detection.found;
  vec[bmb_msgs::SensorMeasurements::PIXEL_vx] = msg.optical_flow_reading.x_pixel_velocity;
  vec[bmb_msgs::SensorMeasurements::PIXEL_vy] = msg.optical_flow_reading.y_pixel_velocity;
  vec[bmb_msgs::SensorMeasurements::IMU_q0] = msg.imu_reading.orientation.w;
  vec[bmb_msgs::SensorMeasurements::IMU_q1] = msg.imu_reading.orientation.x;
  vec[bmb_msgs::SensorMeasurements::IMU_q2] = msg.imu_reading.orientation.y;
  vec[bmb_msgs::SensorMeasurements::IMU_q3] = msg.imu_reading.orientation.z;
  vec[bmb_msgs::SensorMeasurements::IMU_wx] = msg.imu_reading.angular_velocity.x;
  vec[bmb_msgs::SensorMeasurements::IMU_wy] = msg.imu_reading.angular_velocity.y;
  vec[bmb_msgs::SensorMeasurements::IMU_wz] = msg.imu_reading.angular_velocity.z;
  vec[bmb_msgs::SensorMeasurements::IMU_ax] = msg.imu_reading.linear_acceleration.x;
  vec[bmb_msgs::SensorMeasurements::IMU_ay] = msg.imu_reading.linear_acceleration.y;
  vec[bmb_msgs::SensorMeasurements::IMU_az] = msg.imu_reading.linear_acceleration.z;
  vec[bmb_msgs::SensorMeasurements::LAT] = msg.gps_reading.latitude;
  vec[bmb_msgs::SensorMeasurements::LONG] = msg.gps_reading.longitude;
  vec[bmb_msgs::SensorMeasurements::ALT] = msg.gps_reading.altitude;
  return vec;
}

bmb_msgs::SensorMeasurements as_msg(const Vector<double, 18>& sensor_measurements) {
  bmb_msgs::SensorMeasurements msg;
  msg.pressure_reading.fluid_pressure = sensor_meausrements[bmb_msgs::SensorMeasurements::PRESSURE];
  msg.rail_detection.angle = sensor_meausrements[bmb_msgs::SensorMeasurements::RAIL_ANGLE];
  msg.rail_detection.pixel_width = sensor_meausrements[bmb_msgs::SensorMeasurements::RAIL_WIDTH];
  msg.rail_detection.pixel_x = sensor_meausrements[bmb_msgs::SensorMeasurements::RAIL_x];
  msg.rail_detection.pixel_y = sensor_meausrements[bmb_msgs::SensorMeasurements::RAIL_y];
  msg.rail_detection.found = sensor_meausrements[bmb_msgs::SensorMeasurements::RAIL_FOUND];
  msg.optical_flow_reading.x_pixel_velocity = sensor_meausrements[bmb_msgs::SensorMeasurements::PIXEL_vx];
  msg.optical_flow_reading.y_pixel_velocity = sensor_meausrements[bmb_msgs::SensorMeasurements::PIXEL_vy];
  msg.imu_reading.orientation.w = sensor_meausrements[bmb_msgs::SensorMeasurements::IMU_q0];
  msg.imu_reading.orientation.x = sensor_meausrements[bmb_msgs::SensorMeasurements::IMU_q1];
  msg.imu_reading.orientation.y = sensor_meausrements[bmb_msgs::SensorMeasurements::IMU_q2];
  msg.imu_reading.orientation.z = sensor_meausrements[bmb_msgs::SensorMeasurements::IMU_q3];
  msg.imu_reading.angular_velocity.x = sensor_meausrements[bmb_msgs::SensorMeasurements::IMU_wx];
  msg.imu_reading.angular_velocity.y = sensor_meausrements[bmb_msgs::SensorMeasurements::IMU_wy];
  msg.imu_reading.angular_velocity.z = sensor_meausrements[bmb_msgs::SensorMeasurements::IMU_wz];
  msg.imu_reading.linear_acceleration.x = sensor_meausrements[bmb_msgs::SensorMeasurements::IMU_ax];
  msg.imu_reading.linear_acceleration.y = sensor_meausrements[bmb_msgs::SensorMeasurements::IMU_ay];
  msg.imu_reading.linear_acceleration.z = sensor_meausrements[bmb_msgs::SensorMeasurements::IMU_az];
  msg.gps_reading.latitude = sensor_meausrements[bmb_msgs::SensorMeasurements::LAT];
  msg.gps_reading.longitude = sensor_meausrements[bmb_msgs::SensorMeasurements::LONG];
  msg.gps_reading.altitude = sensor_meausrements[bmb_msgs::SensorMeasurements::ALT];
  return msg;
}

Vector<double, 13> as_vector(const bmb_msgs::AircraftState& msg) {
  Vector<double, 13> vec;
  vec[bmb_msgs::AircraftState::PX] = msg.pose.position.x;
  vec[bmb_msgs::AircraftState::PY] = msg.pose.position.y;
  vec[bmb_msgs::AircraftState::PZ] = msg.pose.position.z;
  vec[bmb_msgs::AircraftState::Q0] = msg.pose.orientation.w;
  vec[bmb_msgs::AircraftState::Q1] = msg.pose.orientation.x;
  vec[bmb_msgs::AircraftState::Q2] = msg.pose.orientation.y;
  vec[bmb_msgs::AircraftState::Q3] = msg.pose.orientation.z;
  vec[bmb_msgs::AircraftState::VX] = msg.twist.linear.x;
  vec[bmb_msgs::AircraftState::VY] = msg.twist.linear.y;
  vec[bmb_msgs::AircraftState::VZ] = msg.twist.linear.z;
  vec[bmb_msgs::AircraftState::WX] = msg.twist.angular.x;
  vec[bmb_msgs::AircraftState::WY] = msg.twist.angular.y;
  vec[bmb_msgs::AircraftState::WZ] = msg.twist.angular.z;
  return vec;
}

bmb_msgs::AircraftState as_msg(const Vector<double, 13>& aircraft_state) {
  bmb::msgs::AircraftState msg;
  msg.pose.position.x = aircraft_state[bmb_msgs::AircraftState::PX];
  msg.pose.position.y = aircraft_state[bmb_msgs::AircraftState::PY];
  msg.pose.position.z = aircraft_state[bmb_msgs::AircraftState::PZ];
  msg.pose.orientation.w = aircraft_state[bmb_msgs::AircraftState::Q0];
  msg.pose.orientation.x = aircraft_state[bmb_msgs::AircraftState::Q1];
  msg.pose.orientation.y = aircraft_state[bmb_msgs::AircraftState::Q2];
  msg.pose.orientation.z = aircraft_state[bmb_msgs::AircraftState::Q3];
  msg.twist.linear.x = aircraft_state[bmb_msgs::AircraftState::VX];
  msg.twist.linear.y = aircraft_state[bmb_msgs::AircraftState::VY];
  msg.twist.linear.z = aircraft_state[bmb_msgs::AircraftState::VZ];
  msg.twist.angular.x = aircraft_state[bmb_msgs::AircraftState::WX];
  msg.twist.angular.y = aircraft_state[bmb_msgs::AircraftState::WY];
  msg.twist.angular.z = aircraft_state[bmb_msgs::AircraftState::WZ];
  return msg;
}

Vector3<double> as_vector(const bmb_msgs::ControlInputs& msg) {
  Vector3<double> vec;
  vec[bmb_msgs::ControlInputs::PROPELLER] = msg.propellor_voltage;
  vec[bmb_msgs::ControlInputs::RIGHT_AILERON] = msg.right_aileron_angle;
  vec[bmb_msgs::ControlInputs::ELEVATOR] = msg.elevator_angle;
  return vec;
}

bmb_msgs::ControlInputs as_msg(const Vector3<double>& control_inputs) {
  bmb_msgs::ControlInputs msg;
  msg.propellor_voltage = vec[bmb_msgs::ControlInputs::PROPELLER];
  msg.right_aileron_angle = vec[bmb_msgs::ControlInputs::RIGHT_AILERON];
  msg.elevator_angle = vec[bmb_msgs::ControlInputs::ELEVATOR];
  return msg;
}

}  // namespace bmb_utilities