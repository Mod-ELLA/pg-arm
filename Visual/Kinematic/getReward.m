function r = getReward(state, des_pos, end_velocity, t, r_c, smooth_factor)
% end_velocity  : velocity vector, 2 by 1
% t             : time reference factor, will have an effect on the final reward;
% suggested to equal to the simulation update time step
% r_c           : reward constant, is the reward gain; scalar
% smooth_factor : used to limit the maximum possible reward
% Returns a scalar reward, can use the state to compute the current position
%% Initialization
if nargin == 3
    t = 0.001;
    r_c = 2;
    smooth_factor = 0.1;
elseif nargin == 4
    r_c = 2;
    smooth_factor = 0.1;
elseif nargin == 5
    smooth_factor = 0.1;
end
%% Get the current position of the end effector
[x, y] = FK2D(state.angles, state.lengths);
current_pos = [x(end); y(end)];
%% Calculate the reward based on the estimated position
est_pos = current_pos + end_velocity*t;
%distance = norm(des_pos - est_pos);
%r = r_c/(smooth_factor + distance);
distance = norm(des_pos - current_pos);
%norm(end_velocity)
r = -r_c*distance^2 - smooth_factor*norm(end_velocity)^2;
end