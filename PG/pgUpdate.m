function M_t_plus_1 = pgUpdate(M_t, grad, step)
% Update the Model given the gradient
% M_t           : a model matrix, m by n
% grad          : a vector of gradient of J at theta, nm by 1
% step          : update step size
% M_t_plus_1    : updated model matrix, m by n
if nargin == 2
    step = 0.001;
end
m = size(M_t,1);
n = size(M_t,2);
M_t_plus_1 = reshape(M_t',1,[]) + step*grad';
M_t_plus_1 = reshape(M_t_plus_1, n, m)';
end