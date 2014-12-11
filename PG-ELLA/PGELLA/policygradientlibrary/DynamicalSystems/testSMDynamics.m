%% Testing Simple Mass Dynamics: 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 1. Parameter Structure requiring: (1) Mass, (2) Spring Constant d, (3)
% Damping Constant (d), and (4) integration time dt.
clear; 
param.Mass=5; 
param.K=3; 
param.d=0.01; 
param.dt=.1;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Simulate the SM and plot variation of the state variables (i.e., x and
% v) with respect to time. 

T=50; % Total Running Time 
x_init=[5;0.01]; % Initial State
%counter=0;
for t=0:0.1:T
    
    if t==0 
        xn=x_init;
    end
    xn=transitionSM(xn,0,param); % No actions applied ... 
    
    plot(t,xn(1),'r*') 
    hold on 
    plot(t,xn(2),'b*') 
    drawnow
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
