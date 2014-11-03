function [X, Y] = FK2D(angles, lengths)
    %% FK method
    % angles: 1xm vector of joint angles in degrees
    % lengths: 1xm vector of link lengths (must be same units)
    % Assumption: all link lengths increment in the X-direction only
    % joints_pos: 2 by num_joints matrix records the position of all joints
    assert(length(angles) == length(lengths));

    num_joints = length(angles);
    X = zeros(1,num_joints);
    Y = zeros(1,num_joints);
    acc_matrix = eye(3);
    temp_lengths = [0 lengths];
    
    for i=1:num_joints
        temp_angle = angles(i);
        F = [cosd(temp_angle) -sind(temp_angle) temp_lengths(i)
             sind(temp_angle) cosd(temp_angle) 0
             0 0 1];
        acc_matrix = acc_matrix * F;
        joints_pos = acc_matrix * [lengths(i); 0; 1]; %3x1
        X(i) = joints_pos(1);
        Y(i) = joints_pos(2);
    end
end