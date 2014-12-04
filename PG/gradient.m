function grad = gradient(state, model, des_pos)
% State is a struct:
%   state.lengths, state.angles
% Model:
%   Model is a nxm matrix of coefficients to compute w = M*I, where w is
%   angular velocities of the end effector (mx1) and I is a vector nx1 of feature values
% des_pos is a 1x2 vector for the desired goal coordinates
% Output:
%   a nxm matrix grad, where the partial derivative of rewardFunction
%   w.r.t M(i,j) is stored in grad(i,j)   
% http://www.scholarpedia.org/article/Policy_gradient_methods look at
% Finite-Difference Methods

features = getFeatures(state);
[n,m] = size(model);
deltaTheta = ones(n,m)*0.001; %  generate policy variation
grad = zeros(n,m);% Initial shape of grad matrix
% TODO: Can we vectorize this part to make it faster? -Ed
for i=1:n
    for j = 1:m
%         if i == 2 && j == 3
%             display('debugging point')
%         end
        modelRef1 = model;
        modelRef2 = model;
        modelRef1(i,j) = modelRef1(i,j)+deltaTheta(i,j);
        modelRef2(i,j) = modelRef2(i,j)-deltaTheta(i,j);% Generate reference model
        Jref1 = getReward(state,des_pos,FKvelocity(state,modelRef1*features));
        Jref2 = getReward(state,des_pos,FKvelocity(state,modelRef2*features));% Calculate the reference reward
        grad(i,j) = (Jref1-Jref2)/(2*deltaTheta(i,j));
    end 
end

end