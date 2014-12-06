%% This is a full gradient update implementation
% Programed by Yunkai Cui
% This is a testing of all the function implementation
run init
%% Initialization
% Initialize system
N = 4; % number of links
linkages = ones(N,1)*0.1;   % legnth of links
dest_pos = [0.2; 0.3];     % Desired position
theta = zeros(N,1);         % Initial joint angle
state.lengths = linkages;
state.angles = theta;
% discount = 0.99;
discount = 1;

% Initialize Gaussian Policy Model
k = 2*rand(N, N+1) - 1;
sigma = 0.001*rand(N,1);
% system dynamic function: \dot{x} = A*x + B*u
A = zeros(N); % System dynamic
B = eye(N); % System dynamic
Q = eye(2); % weight of distance on reward
R = eye(N); % weight of angular velocity in reward
eta = 0.01; % importance factor of angular velocity
t = 0.01;
discretize = 10000;
policy = initGaussPolicy(k,sigma,A, B, Q, R, eta, t, discretize);

% Initialize simulation
max_exploration = 300; % depends on discount^max_exploration
trail_num = 200;        % number of trails to try
max_updates = 1000;
update_factor = 1.0/max_exploration/2;   % This last dividor is crucial important

% Turn on the profiler
profile on
% Turn on parallel computing pool
delete(gcp);
poolobj = parpool;
%% Begin gradient updating
rewards_expectation = zeros(max_updates,1);
policy.samples.k = zeros(N, N+1, floor(max_updates/50));
for it = 1:max_updates
%% Begin multi trail exploration
    g_rf_first = zeros(size(policy.theta.k));
    g_rf_second = zeros(size(policy.theta.k));
    b_his_1 = zeros(trail_num);
    b_his_2 = zeros(trail_num);
    average_reward = 0;
    parfor tr = 1:trail_num
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
            % Calculate use point wise linear
            % gradient_log_pi = DlogPiDthetaLinearApproximation(x,u,trail_policy);
            % Calculate use gaussian function
            gradient_log_pi = DlogPiDTheta(trail_policy, x,u);
            accum_dlogpi_dtheta = accum_dlogpi_dtheta + gradient_log_pi.k;
        end
        % This line is only useful in the average non-discount reward case
%         accum_reward = accum_reward/max_exploration;
    %     b_num = b_num + reshape(accum_dlogpi_dtheta,1,[])*reshape(accum_dlogpi_dtheta,[],1)*accum_reward;
    %     b_den = b_den + reshape(accum_dlogpi_dtheta,1,[])*reshape(accum_dlogpi_dtheta,[],1);
        g_rf_first = g_rf_first + accum_dlogpi_dtheta*accum_reward;
        g_rf_second = g_rf_second + accum_dlogpi_dtheta;
        b_his_1(tr) = reshape(accum_dlogpi_dtheta,1,[])*reshape(accum_dlogpi_dtheta,[],1)*accum_reward;
        b_his_2(tr) = reshape(accum_dlogpi_dtheta,1,[])*reshape(accum_dlogpi_dtheta,[],1);
        average_reward = average_reward + accum_reward;
    end
    b = mean(b_his_1)/mean(b_his_2);
    Gk = g_rf_first - g_rf_second*b;
    Gk = Gk/trail_num;
    if max(max(abs(Gk)))*update_factor > 0.1
        Gk = Gk/(max(max(abs(Gk)))/0.1);
    else
        Gk = Gk*update_factor;
    end
    policy.theta.k = policy.theta.k + Gk;
    policy.theta.k
    if mod(it,50) == 0
        policy.samples.k(:,:,floor(it/50)) = policy.theta.k;
    end
    rewards_expectation(it) = average_reward/trail_num;
    rewards_expectation(it)
%     angular_v = drawAction(policy,getFeatures(state));
%     state.angles = mod(drawNextState(policy, state.angles,angular_v),2*pi);
    % run simulation
%     FKanimate(state.angles, dest_pos, state.lengths, it,0);
end
%% End of updates
% save('rewards_record_3','rewards_expectation','policy');
delete(poolobj);
profile off
profile viewer