#pragma once

#include "Vector3.h"

template<typename T>
struct Accel {
    Vector3<T> linear;
    Vector3<T> angular;

    Accel<T> operator+(const Accel<T> &other) {
        return {Vector3<T>{linear + other.linear}, Vector3<T>{angular + other.angular}};
    }

    Accel<T> operator-(const Accel<T> &other) {
        return {Vector3<T>{linear - other.linear}, Vector3<T>{angular - other.angular}};
    }

    Accel<T> operator*(const T &scalar) {
        return {Vector3<T>{linear * scalar}, Vector3<T>{angular * scalar}};
    }

    Accel<T> operator/(const double &scalar) {
        return {Vector3<T>{linear / scalar}, Vector3<T>{angular / scalar}};
    }

    void operator+=(const Accel<T> &other) {
        linear += other.linear;
        angular += other.angular;
    }

    void operator-=(const Accel<T> &other) {
        linear -= other.linear;
        angular -= other.angular;
    }

    void operator*=(const T &scalar) {
        linear *= scalar;
        angular *= scalar;
    }

    void operator/=(const double &scalar) {
        linear /= scalar;
        angular /= scalar;
    }

    T &operator[](const size_t &index) {
        return index < 3 ? linear[index] : angular[index - 3];
    }

    T operator[](const size_t& index) const {
        return index < 3 ? linear[index] : angular[index - 3];
    }
};