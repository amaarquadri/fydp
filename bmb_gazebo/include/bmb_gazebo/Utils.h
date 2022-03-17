#pragma once

#include <bmb_math/Quaternion.h>
#include <bmb_math/Vector3.h>
#include <ignition/math/Vector3.hh>

template <typename T>
ignition::math::Vector3<T> bmbToIgnitionVector3(const Vector3<T>& vec) {
  ignition::math::Vector3<T> result;
  result.X(vec.x);
  result.Y(vec.y);
  result.Z(vec.z);
  return result;
}

template <typename T, typename V>
void ignitionToGeometryVector3(const T& src, V& dest) {
  dest.x = src.X();
  dest.y = src.Y();
  dest.z = src.Z();
}

template <typename T>
Vector3<T> ignitionToBMBVector3(const T& src) {
  return Vector3<T>{src.X(), src.Y(), src.Z()};
}

template <typename T, typename V>
void ignitionToGeometryQuaternion(const T& src, V& dest) {
  dest.w = src.W();
  dest.x = src.X();
  dest.y = src.Y();
  dest.z = src.Z();
}

template <typename T>
Quaternion<T> ignitionToBMBQuaternion(const T& src) {
  return Quaternion<T>{src.W(), src.X(), src.Y(), src.Z()};
}
