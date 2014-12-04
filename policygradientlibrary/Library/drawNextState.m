function xn = drawNextState(policy,x,u)
% Programmed by Jan Peters. 
% Modified by Yunkai Cui
%
% xn = drawNextState(x,u) draws the next state from the transition
% function given state x and action u. The LQR next state is deterministic
% and can be determined by xn=Ax+bu; the discrete next state has to
% be drawn from the transition table. Do not forget to initialize 
% the problem beforehand.
%
% Related: initializeLQRProblem, initializeDiscreteProblem, 
%          drawStartState

if(policy.type==1||policy.type==2)
    probTable = policy.p(x,u,:);
    xn = drawFromTable(probTable);       
elseif(policy.type==3)
    x_dot = policy.A*x + policy.b*u;
    xn = x + x_dot*policy.t;   	      
else
    disp('ERROR: initialize problem.');
end;      