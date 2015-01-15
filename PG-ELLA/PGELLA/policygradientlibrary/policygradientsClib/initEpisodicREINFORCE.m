function [param,policy]=initEpisodicREINFORCE(N,M)
param.N=N;
param.M=M; % Action dimensions 1 for now 
param.gamma=.9;
policy.theta.k=rand(N,1);
policy.theta.sigma=rand(1,1);
policy.type=3;
