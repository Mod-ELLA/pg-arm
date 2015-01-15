function data = obtainData(policy, L, H,param);

% Programmed by Jan Peters. 
%
% data = obtainData(policy, L, H) obtains H trajectories of 
% length L using policy and returns them in the correct data
% format.
%
% data = obtainData(policy, L) obtains 1 trajectory of 
% length L using policy and returns them in the correct data
% format.
%
% Related: initializeLQRProblem, initializeDiscreteProblem, 
%          drawNextState, rewardFnc, 

if strcmpi(param.ProblemID,'Quad')
    if nargin==2  % default 
        H=1; 
    end
    for trials=1:H % Loop over trials 
        data(trials).policyOne=policy.policyOne;
        data(trials).policyTwo=policy.policyTwo;
        %data(trials).policyThree=policy(3).PolThree;
        %data(trials).policyFour=policy(4).PolFour;
        
        data(trials).x(:,1)=drawStartState(param);
        disp(['Sampling @ Iteration: ', num2str(trials)]);
        for steps=1:L % Loop Over Steps 
            % Draw Four Actions 
            %disp(['Sampling @ Steps: ', num2str(steps)]);
            u1=drawAction(policy.policyOne,data(trials).x(:,steps));
            u2=drawAction(policy.policyTwo,data(trials).x(:,steps));
            %u3=drawAction(policy(3).PolThree,data(trials).x(:,steps));
            %u4=drawAction(policy(4).PolFour,data(trials).x(:,steps));
            
            %data(trials).u(:,steps)=[u1;u2;u3;u4];
            data(trials).u(:,steps)=[u1;u2];
            data(trials).r(steps)=rewardFnc(data(trials).x(:,steps),data(trials).u(:,steps),param);
            data(trials).x(:,steps+1)=drawNextState(data(trials).x(:,steps),data(trials).u(:,steps),param);
        end
       % clc;
    end
    

else
    if nargin==2
      H=1;
   end;   
   
	% Perform H episodes
   for trials=1:H
      % Save associated policy
      data(trials).policy = policy;
      
   	% Draw the first state
	   data(trials).x(:,1) = drawStartState(param);

   	% Perform a trial of length L
	   for steps=1:L 
         % Draw an action from the policy
      	data(trials).u(steps)   = drawAction(policy, data(trials).x(:,steps));
      
      	% Obtain the reward from the 
      	data(trials).r(steps)   = rewardFnc(data(trials).x(:,steps), data(trials).u(steps),param);   

			% Draw next state from environment      
   	   data(trials).x(:,steps+1) = drawNextState(data(trials).x(:,steps), data(trials).u(steps),param);   
   	end;
   end  
end
      