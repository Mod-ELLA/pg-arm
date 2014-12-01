global N Ninput A b Q R my0 pos0 S0 gamma armlength state problemType des_pos

%% Initialize angles, armlength, policy k, sigma, type
N = 2;
my0 = rand(N,1)*2*pi;
my0 = [0;0];
armlength = [1;1];
%pos0 = FK2D(Theta0,armlength);
des_pos = [1;1.5];
%S0 = 0.0001*eye(N);
deltaT = 0.01;
A = eye(N);
b = deltaT*eye(N);

% Reward matrix Q and scalar R�
Q = 1;
R = 0.1;
state.lengths = armlength;
state.angles = my0;
gamma = 0.9;
problemType = 2;

stateVector = getFeatures(state);
stateLength = length(stateVector);
policy = initGaussPolicy;
policy.theta.k = rand(N,stateLength);
policy.theta.sigma = 0.1;
policy.type = 4;

alpha = 0.5;



maxIter = 100;
maxStep = 1000;
trailNum = 100;
data=struct([]);
timestep = 0.01;
%data = repmat(struct('x',zeros(length(stateVector),maxStep),'u',zeros(N,maxStep),'r',zeros(1,maxStep)),trailNum,1);
for i=1:maxIter
    close all;
    i
    for trail = 1:trailNum
        state.lengths = armlength;
        state.angles = my0;
        data(trail).policy = policy;
        for step=1:maxStep
            if trail==1
                FKanimate(state.angles, des_pos, state.lengths, step);
            end
            x = getFeatures(state);
            u = drawAction(policy,x);
            %u = ccdAction(state);
            state.angles = drawNextState(state.angles,u);
            state.angles = mod(state.angles,2*pi);
            r = getReward(state,des_pos,u,0,10,1);
            data(trail).x(:,step) = x;
            data(trail).u(:,step) = u;
            data(trail).r(:,step) = r;
        end
        trail
    end
    djdtheta = episodicREINFORCE(policy,data);
    dtheta = reshape(djdtheta(1:end-1),N,stateLength);
    norm(dtheta)
    policy.theta.sigma = policy.theta.sigma + alpha*djdtheta(end)/norm(dtheta);
    policy.theta.sigma = max(policy.theta.sigma,0.0001);
    %policy.theta.k = policy.theta.k + alpha*reshape(djdtheta(1:end-1),N,stateLength);
   
    policy.theta.k = policy.theta.k + alpha*dtheta/norm(dtheta);
    policy.theta.k
    policy.theta.sigma

    
end


