%% This is a test of one trail
% Programed by Yunkai Cui
% This is a testing of all the function implementation
run init
%% Initialization
% Initialize system
N = 2; % number of links
linkages = ones(N,1)*0.1;   % legnth of links
dest_pos = [0.1; 0.1];     % Desired position
theta = zeros(N,1);         % Initial joint angle
state.lengths = linkages;
state.angles = theta;
discount = 0.99;

% Initialize Gaussian Policy Model
% k = rand(N, N+1);
% k = [10.4661   10.0807  -13.4672;
%    11.8824   10.1551  -13.9065];
k = [-6 0 0; 0 -6 6*pi/2];
sigma = 0.001*rand(N,1);
% system dynamic function: \dot{x} = A*x + B*u
A = zeros(N); % System dynamic
B = eye(N); % System dynamic
Q = eye(2); % weight of distance on reward
R = eye(N); % weight of angular velocity in reward
eta = 0.01;    % importance factor of angular velocity
t = 0.01;
discretize = 10000;
policy = initGaussPolicy(k,sigma,A, B, Q, R, eta, t, discretize);

% Initialize simulation
max_exploration = 300; % depends on discount^max_exploration

%% Begin One Trail Exploration
trail_state = state;
trail_policy = policy;
a_l = 1;
accum_reward = 0;
accum_dlogpi_dtheta = zeros(size(policy.theta.k));
for i = 1:max_exploration
    x = getFeatures(trail_state);
    u = drawAction(trail_policy,x);
    tmp_state = drawNextState(trail_policy, trail_state.angles,u);
    sign = (tmp_state > 0).*2-1;
    trail_state.angles = sign.*mod(abs(tmp_state),2*pi);
    reward = getRewardLQR(trail_state, dest_pos, trail_policy, u);
    accum_reward = accum_reward + a_l*reward;
    a_l = a_l*discount;
    gradient_log_pi = DlogPiDthetaLinearApproximation(x,u,trail_policy);
%     gradient_log_pi.k
    accum_dlogpi_dtheta = accum_dlogpi_dtheta + gradient_log_pi.k;
    % run simulation
    FKanimate(trail_state.angles, dest_pos, trail_state.lengths, i);
end
accum_dlogpi_dtheta
accum_reward