function r = getRewardLQR(state, des_pos, policy, u)
% Programed by Yunkai Cui
% u  : velocity vector, n by 1
% Returns a scalar reward, can use the state to compute the current position
%% Get the current position of the end effector
[x, y] = FK2D(state.angles, state.lengths);
current_pos = [x(end); y(end)];
%% Calculate the reward based on the Linear Quadratic Function
x_error = des_pos - current_pos;
% Defined follows wikipedia:http://en.wikipedia.org/wiki/Linear-quadratic_regulator
r = - x_error'*policy.Q*x_error/policy.eta - policy.eta*u'*policy.R*u;