function xn = drawNextState(x,u,param)

    problemType=param.problemType;

	if(problemType==1)
            p=param.p;
      
            probTable = p(x,u,:);
            xn = drawFromTable(probTable);       
	elseif(problemType==2)   
             A = param.A; 
             b = param.b;
             N = param.N;

            if(size(x,2)==length(x)) 
                y(1:N,1)=x(1,1:N)'; 
                x=y; 
            end;

            xn = A*x + b*u;   	      
    elseif(problemType==3)
        switch param.problemID 
            case 'SM'
                xn=transitionSM(x,u,param);
        end
        else
            disp('ERROR: initialize problem.');
	end;      