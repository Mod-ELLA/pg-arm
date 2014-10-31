function grad = gradient(state, model, des_pos)
% State is a struct:
%   state.lengths, state.angles
% Model:
%   Model is a nxm matrix of coefficients to compute w = M*I, where w is
%   angular velocities of the end effector (mx1) and I is a vector nx1 of feature values
% des_pos is a 1x2 vector for the desired goal coordinates
% http://www.scholarpedia.org/article/Policy_gradient_methods look at
% Finite-Difference Methods
end