function der = DlogPiDTheta(policy, x,u)
% Programmed by Jan Peters (jrpeters@usc.edu).
% Modified by Yunkai Cui
% Not sure the calculation of the type 3 is correct or not
%
% der = DlogPiDTheta(policy, x,u) returns the derivative of the policy with respect
% to all the parameters in state x and with action u.  

if(policy.type == 1)
     N = size(policy.P,1);
     M = size(policy.P,2);
     der = zeros(N*(M-1),1);    
     if(u==M)
         actions = selDecBor(x,1):selDecBor(x,M-1);
         der(actions,1) = - 1 / (1 - sum(policy.theta(actions)));
      else
         der(selDecBor(x,u),1) = 1 / policy.theta(selDecBor(x,u));
      end;   
elseif(policy.type == 2) 
  der = zeros(N*M,1);
  for i=1:M
     der(selGibbs(x,i),1) = -pi_theta(policy, x, i)/policy.eps;
  end;   
  der(selGibbs(x,u)) = (1 - pi_theta(policy, x, u))/policy.eps;
elseif(policy.type == 3) 
  % Have no idea the meaning of this calculation
  sigma = max(policy.theta.sigma,0.00001*ones(size(policy.theta.sigma)));
  k   = policy.theta.k;
  der.k = (u-k*x)*x'/(sigma'*sigma);
  der.sigma = ((u-k*x)'*(u-k*x)-sigma'*sigma)*sigma/(sigma'*sigma)^2;   
end;   
