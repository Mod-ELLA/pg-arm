function policy = initGaussPolicy(k,sigma,A, B, Q, R, eta, t, d_factor)
% Programmed by Jan Peters (jrpeters@usc.edu).
% Modified by Yunkai Cui
%
% policy = initGaussPolicy returns an initialized 
% Gauss policy for the given linear quadratic regulation problem. 
%
% Related: initDecisionBorderPolicy, initEpsGreedyGibbsPolicy

% Set policy type
policy.type  = 3;
      
% Initialize policy parameters
policy.theta.k = k;
policy.diag = 0;
if size(sigma,1) == 1 || size(sigma,2) == 1
    sigma = diag(sigma.^2); 
    policy.diag = 1;
end
policy.theta.sigma = sigma;
policy.A = A;
policy.b = B;
policy.Q = Q;
policy.R = R;
policy.eta = eta;
policy.t = t;
policy.discrete = d_factor;
policy.pdf_accuracy = 1/d_factor;
