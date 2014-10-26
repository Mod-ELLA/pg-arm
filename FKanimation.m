%% Clearing System
clc;
clear all;
%% Initialization for configuration
% Configuration in 2D space
% joint_angles includes all the joint angles
% arm_length includes all the arm lengths
% des_pos is the desired position of the end effector
joint_angles = [0;0;0;0;0];
arm_length = [1;1;1;1;1];
des_pos = [2;2];

%% FK method
% joints_pos: 2 by num_joints matrix records the position of all joints
num_joints = length(arm_length);
joints_pos = zeros(2,num_joints);
acc_matrix = eye(3);
for i=1:num_joints
    temp_angle = joint_angles(i);
    acc_matrix = acc_matrix * [cos(temp_angle) -sin(temp_angle) arm_length(i)
        sin(temp_angle) cos(temp_angle) 0
        0 0 1];
    joints_pos(:,i) = acc_matrix * [arm_length(i); 0; 1];
end
