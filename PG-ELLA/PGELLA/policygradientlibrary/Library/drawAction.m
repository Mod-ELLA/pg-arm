function u = drawAction(policy, x,param);


	%problemType=param.problemType; 

   %if(policy.type==1 | policy.type==2)
   %	probTable = pi_theta(policy, x);
    %    u = drawFromTable(probTable);     
   %elseif(policy.type==3)
      u = normrnd(policy.theta.k'*x, policy.theta.sigma, 1, 1);
   %else
   %   disp('ERROR: take a correct policy.');
%	end;      