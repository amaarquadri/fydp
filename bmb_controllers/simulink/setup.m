clear; clc; close all;
mass = 3.615;
I_xx = 12.327;
I_yy = 1.711;
I_zz = 12.659;
lift_m = 1.39627650007691;
lift_b = 0.204721453757253;
g = 9.81;
v = sqrt(mass * g / lift_b); % for altitude PID
roll_m = 0.0547822725108043;
drag_b = 0.0595573697856826;
elevator_m = 0.0842508724650606;
body_pitch_b = 0.0015675980775375;
body_pitch_m = -0.250343385330279;
initial_roll = asin(-body_pitch_b / body_pitch_m); % for pitch PID
rudder_m = 0.00362774034506748;
