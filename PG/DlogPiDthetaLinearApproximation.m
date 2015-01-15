function gradient_of_log_pi = DlogPiDthetaLinearApproximation(x,u,policy,type)
% type: defult: only updated k;
%       1: update variance as well;
if nargin == 3
    type = 0;
end
epsilon = policy.pdf_accuracy;
%% First, caculate gradient of K
num = size(policy.theta.k,1)*size(policy.theta.k,2);
increment_mat = epsilon*rand(size(policy.theta.k,1), size(policy.theta.k,2), 2*num);
log_prob = LogPiTheta(x,u,policy);
delta_log_prob = zeros(2*num,1);
for i = 1:2*num
    current_policy = policy;
    current_policy.theta.k = current_policy.theta.k + increment_mat(:,:,i);
    delta_log_prob(i) = LogPiTheta(x,u,current_policy) - log_prob;
end
vector_stack = reshape(increment_mat,num,[],1);
% Linearized around the current parameters
% gradient_of_log_pi.k = epsilon*reshape((vector_stack*vector_stack')\vector_stack*delta_log_prob,size(policy.theta.k,1),size(policy.theta.k,2));
gradient_of_log_pi.k = reshape((vector_stack*vector_stack')\vector_stack*delta_log_prob,size(policy.theta.k,1),size(policy.theta.k,2));
%% Next, caculate gradient of sigma
% This is only neccessary when variance is the policy parameter
% Consider disable this to speed up
if type == 1
    if policy.diag == 1
        num = size(policy.theta.sigma,1);
        increment_vec = (0.001)^2*epsilon*rand(num, 2*num);
        delta_log_prob = zeros(2*num,1);
        for i = 1:2*num
            current_policy = policy;
            current_policy.theta.sigma = current_policy.theta.sigma + diag(increment_vec(:,i));
            delta_log_prob(i) = LogPiTheta(x,u,current_policy) - log_prob;
        end
%         gradient_of_log_pi.sigma = epsilon*diag((increment_vec*increment_vec')\increment_vec*delta_log_prob);
        gradient_of_log_pi.sigma = diag((increment_vec*increment_vec')\increment_vec*delta_log_prob);
    else
        num = size(policy.theta.sigma,1)*size(policy.theta.sigma,2);
        increment_vec = (0.001)^2*epsilon*rand(size(policy.theta.sigma,1),size(policy.theta.sigma,2), 2*num);
        delta_log_prob = zeros(2*num,1);
        for i = 1:2*num
            current_policy = policy;
            current_policy.theta.sigma = current_policy.theta.sigma + increment_vec(:,:,i);
            delta_log_prob(i) = LogPiTheta(x,u,current_policy) - log_prob;
        end
        vector_stack = reshape(increment_vec,num,[],1);
%         gradient_of_log_pi.sigma = epsilon*reshape((vector_stack*vector_stack')\vector_stack*delta_log_prob,size(policy.theta.sigma,1),size(policy.theta.sigma,2));
        gradient_of_log_pi.sigma = reshape((vector_stack*vector_stack')\vector_stack*delta_log_prob,size(policy.theta.sigma,1),size(policy.theta.sigma,2));
    end
end

