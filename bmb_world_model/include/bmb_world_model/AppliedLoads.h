#pragma once

#include <bmb_math/Wrench.h>
#include <bmb_math/Vector.h>
#include <bmb_math/Matrix.h>
#include <bmb_msgs/ControlInputs.h>
#include <bmb_world_model/Constants.h>
#include <bmb_differentiation/runtime/Expression.h>
#include <bmb_msgs/ControlInputs.h>
#include <bmb_msgs/AircraftState.h>

class AppliedLoads {
public:
    void update(const bmb_msgs::ControlInputs &control_inputs);

    [[nodiscard]] Wrench<double> getAppliedLoads(const bmb_msgs::AircraftState& state) const;

    [[nodiscard]] Matrix<double, 6, bmb_msgs::AircraftState::SIZE>
    getAppliedLoadsJacobian(const bmb_msgs::AircraftState& state) const;

private:
    static const Matrix<ExprPtr, 3, 4> QUAT_TO_WEIGHT_JAC_EXPR;

    bmb_msgs::ControlInputs current_control_inputs{0, 0, 0};
    bmb_msgs::ControlInputs last_control_inputs{0, 0, 0};
    double last_propeller_ang_vel = 0;

    [[nodiscard]] double getPropellerAngVelocity() const;

    [[nodiscard]] Wrench<double> getPropellerLoads() const;

    [[nodiscard]] Wrench<double> getRightAileronLoads(const double& velocity) const;

    [[nodiscard]] Wrench<double> getLeftAileronLoads(const double& velocity) const;

    [[nodiscard]] Wrench<double> getElevatorLoads(const double& velocity) const;

    static Wrench<double> getEnvironmentalLoads(const bmb_msgs::AircraftState& state);
};
