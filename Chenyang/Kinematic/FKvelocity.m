function V = FKvelocity(state, angularVelocities)
% Need to compute the Jacobian
% Given the state struct, and angular velocities
% (rad/time) compute the end effector velocity V
% Return the end effector velocity V in a 2-by-1 vector
%%
numOfArms = length(state.lengths);
temp_omega = 0;
vel = [0;0;0];
rotation = eye(3);
for i = 1:numOfArms
    temp_omega = temp_omega + angularVelocities(i);
    omega_matrix = [0 -temp_omega 0
                    temp_omega 0 0
                    0 0 0];
    temp_angle = state.angles(i);
    F = [cos(temp_angle) -sin(temp_angle) 0
         sin(temp_angle) cos(temp_angle) 0
         0 0 1];
    rotation = rotation * F;
    vel = vel + omega_matrix * rotation * [state.lengths(i);0;0];
end
V = vel(1:2);
    
end