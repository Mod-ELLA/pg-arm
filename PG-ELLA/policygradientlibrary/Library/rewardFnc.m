function rew = rewardFnc(x, u,param)

	problemType=param.problemType;

	if(problemType==1)
            r=param.r;
            rew = r(x,u);
        elseif(problemType==2)
            Q=param.Q;
            R=param.R;
            rew = -0.5*x'*Q*x - 0.5*u'*R*u;
        elseif (problemType==3)
            switch param.problemID 
                case 'SM'
                    rew=rewardSM(x,u,param);
            end
        end;   
      