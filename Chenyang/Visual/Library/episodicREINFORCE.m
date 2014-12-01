function dJdtheta = episodicREINFORCE(policy, data)

	global N gamma AllReward
   
   dJdtheta = zeros(size(DlogPiDTheta(policy, data(1).x(:,1), data(1).u(:,1))));

	for Trials = 1 : max(size(data))
		dSumPi = zeros(size(DlogPiDTheta(policy, data(Trials).x(:,1), data(Trials).u(:,1))));
		sumR   = 0;
   
      for Steps = 1 : max(size(data(Trials).u))
         dSumPi = dSumPi + DlogPiDTheta(policy, data(Trials).x(:,Steps), data(Trials).u(:,Steps));
         sumR   = sumR   + gamma^(Steps-1)*data(Trials).r(:,Steps);
      end; 
      dJdtheta = dJdtheta + dSumPi * sumR;
   end;
   AllReward = [AllReward sumR];
   sumR
   if(gamma==1)
      dJdtheta = dJdtheta / i;
	else      
      dJdtheta = (1-gamma)*dJdtheta / max(size(data));
	end;    