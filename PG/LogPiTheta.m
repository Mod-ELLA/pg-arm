function log_prob = LogPiTheta(x,u,policy)
% Programmed by Yubkai Cui
% This is a numerical approach
% x is the current state
% u is the currrent action
% policy is the struct of the gaussian policy
Accuracy = 0.0001*ones(size(u));
p = mvncdf([u + Accuracy, u - Accuracy]',(policy.theta.k*x)', policy.theta.sigma);
pi_theta = p(1) - p(2);
log_prob = log(pi_theta);
