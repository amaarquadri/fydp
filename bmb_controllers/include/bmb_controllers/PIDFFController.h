#pragma once

#include <bmb_math/Polynomial.h>
#include <bmb_math/TransferFunction.h>
#include <bmb_utilities/ControllerGains.h>

template <typename T>
class PIDFFController {
  ControllerGains gains;
  TransferFunction<T, 2, 2> I;
  TransferFunction<T, 2, 2> D;

 public:
  PIDFFController(const ControllerGains& gains, const double& dt)
      : gains(gains) {
    // TODO: combine into single transfer function
    I = gains.ki * TransferFunction<T, 2, 2>{Polynomial<T, 2>{dt / 2, dt / 2},
                                             Polynomial<T, 2>{-1, 1},
                                             true};  // discrete version of 1/s
    D = gains.kd * TransferFunction<T, 2, 2>{
                       Polynomial<T, 2>{-2 * gains.N, 2 * gains.N},
                       Polynomial<T, 2>{gains.N * dt - 2, gains.N * dt + 2},
                       true};  // discrete version of Ns/(s + N)
  }

  T update(const T& actual, const T& expected) {
    const double error = actual - expected;
    return gains.kp * error + I.next_output(error) + D.next_output(error) + gains.kff * actual;
  }
};