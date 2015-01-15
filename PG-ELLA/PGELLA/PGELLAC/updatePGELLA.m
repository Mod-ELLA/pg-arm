function [model]=updatePGELLA(data,model,taskIndex,pg_Param,policies)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Still model.T .. needs update --> Check if you have a new task ...
% Perform policy update step 
model(1).T=model(1).T+1; % Every time this guy is called there is a new task ... 
learningRate=pg_Param(taskIndex).learningrate;

dJdTheta=episodicREINFORCE(policies(taskIndex).policy,data,pg_Param(taskIndex).param);
% Update Policy Parameters
policies(taskIndex).policy.theta.k=policies(taskIndex).policy.theta.k ...
                                     +learningRate*dJdTheta(1:pg_Param(taskIndex).param.N,1);
% Commented out for now ..                                  
policies(taskIndex).policy.theta.sigma=policies(taskIndex).policy.theta.sigma ...
                                        +policies(taskIndex).policy.theta.sigma.^2*learningRate*dJdTheta(pg_Param(taskIndex).param.N+1,1);
% Compute the Hessian 
D=computeHessianTurtule(data,policies(taskIndex).policy); % we might need to sample again
%D=ones(2,2);
HessianArray(taskIndex).D=D;
ParameterArray(taskIndex).alpha=policies(taskIndex).policy.theta.k; 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% PG-ELLA Updates
% Update L & S(:taskIndex)
[model]=PGELLAUpdate(model,HessianArray,ParameterArray,taskIndex);





