function [r]=rewardSM(x,u,param)
xG=param.xG; % Set the goal 
deltax=x-xG;
r=norm(deltax);