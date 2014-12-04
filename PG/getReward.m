function r = getReward(state, des_pos, end_velocity, t, K, smooth_factors)
% end_velocity  : velocity vector, 2 by 1
% t             : time reference factor, will have an effect on the final reward;
% suggested to equal to the simulation update time step
% r_c           : reward constant, is the reward gain; scalar
% smooth_factor : used to limit the maximum possible reward
% Returns a scalar reward, can use the state to compute the current position
%% Initialization
if nargin == 3
    t = 0.001;
    K = [10, 10, 5];
    smooth_factors = [0.1,0.02,0.1];
elseif nargin == 4
    K = [10, 10, 5];
    smooth_factors = [0.1,0.02,0.1];
elseif nargin == 5
    K = [10, 10, 5];
    smooth_factors = [0.1,0.02,0.1];
end
a = smooth_factors(1);
b = smooth_factors(2);
c = smooth_factors(3);
%% Get the current position of the end effector
[x, y] = FK2D(state.angles, state.lengths);
current_pos = [x(end); y(end)];
%% Calculate the reward based on the estimated position
est_pos = current_pos + end_velocity*t;
distance = norm(des_pos - est_pos);
% r = r_c/(smooth_factor + distance);
%% Calculate the total time spend for reaching the final point
Dis_unit_vec = des_pos - current_pos;
Current_Dis = norm(des_pos - current_pos);
Dis_unit_vec = Dis_unit_vec/Current_Dis;
vel_proj = dot(end_velocity,Dis_unit_vec);
t_est = Current_Dis/vel_proj + c;   % this c is a smooth factor
%% Calculate the L2 norm of the angular velocity vector
v_theta = state.angular_velocities;
L_theta = norm(v_theta);
%% Final reward function
r = K(1)/(a + distance) + K(2)*distance/t_est + K(3)*distance/(b + L_theta);
end