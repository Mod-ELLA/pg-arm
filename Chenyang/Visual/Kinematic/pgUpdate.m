function M_t_plus_1 = pgUpdate(M_t, grad, step)
% Update the Model given the gradient
% M_t           : a model matrix; m by n
% grad          : a matrix of gradient of J at theta_t; m by n
% step          : update step size; a positive scalar
% M_t_plus_1    : updated model matrix; m by n
if nargin == 2
    step = 0.001;
end
M_t_plus_1 = M_t + step*grad;
end