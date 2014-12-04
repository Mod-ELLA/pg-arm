function u = drawAction(policy, x)
% Programmed by Jan Peters. 
% Modified by Yunkai Cui
%
% u = drawAction(policy, x) draws the action from the policy 
% given state x.
%
% Related: initializeLQRProblem, initializeDiscreteProblem, 
%          drawStartState, drawNextState

if(policy.type==1 || policy.type==2)
    probTable = pi_theta(policy, x);
    u = drawFromTable(probTable);     
elseif(policy.type==3)
  if size(policy.theta.k*x,1) ~= size(policy.theta.sigma,1)
      error('drawAction: Dimension mismatched');
  end
  u = mvnrnd((policy.theta.k*x)', policy.theta.sigma)';
else
  disp('ERROR: take a correct policy.');
end;      