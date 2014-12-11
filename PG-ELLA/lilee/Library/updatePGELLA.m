function [model,HessianArray,ParameterArray]=updatePGELLA(data,model,taskIndex,pg_Param,policies,HessianArray,ParameterArray)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Still model.T .. needs update --> Check if you have a new task ...,HessianArray,ParameterArray
% Perform policy update step 
model(1).T=model(1).T+1; % Ev.thetaery time this guy is called there is a new task ... ,HessianArray,ParameterArray
learningRate=pg_Param(taskIndex).learningrate;

dJdTheta=episodicREINFORCE(policies(taskIndex).policy,data,pg_Param(taskIndex).param);
% Update Policy Parameters
policies(taskIndex).policy.theta.k=policies(taskIndex).policy.theta.k ...
                                     +learningRate*dJdTheta(1:pg_Param(taskIndex).param.N,1);
% Commented out for now ..                                  
%policies(taskIndex).policy.theta.sigma=policies(taskIndex).policy.theta.sigma ...
%                                        +policies(taskIndex).policy.theta.sigma.^2*learningRate*dJdTheta(pg_Param(taskIndex).param.N+1,1);
%policies(taskIndex).policy.theta.k
%pause

% Compute the Hessian 
D=computeHessiaSM(data,policies(taskIndex).policy.theta.sigma); % we might need to sample again
%D=eye(2,2);
HessianArray(taskIndex).D=D;
ParameterArray(taskIndex).alpha=policies(taskIndex).policy.theta.k;

%HessianArray(taskIndex).D
%ParameterArray(taskIndex).alpha
%pause
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% PG-ELLA Updates
% Update L & S(:taskIndex)
[model]=PGELLAUpdate(model,HessianArray,ParameterArray,taskIndex);






