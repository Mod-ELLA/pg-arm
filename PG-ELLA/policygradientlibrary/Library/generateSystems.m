function [SystemParameters,SystemPolicies]=generateSystems(nSystems,Pparam)

problem=Pparam.ProblemID; 

switch problem 
    case 'SM'
        if Pparam.IncreaseDiffculty==1
            MassMin=Pparam.MassMin; 
            MassMax=Pparam.MassMax;
            Mink=Pparam.Mink; 
            Maxk=Pparam.Maxk; 
            Mind=Pparam.Mind; 
            Maxd=Pparam.Maxd; 
            MassArray=MassMin:((MassMax-MassMin)/nSystems):MassMax; 
            KArray=Mink:((Maxk-Mink)/nSystems):Maxk; 
            DArray=Mind:((Maxd-Mind)/nSystems):Maxd;
            for i=1:nSystems
                param.N=2; 
                param.M=1;  
                %param.Mass=MassArray(i);
                param.Mass=MassMin;
                param.k=KArray(i); 
                %param.d=DArray(i); 
                param.d=Mind; 
                param.rewardType='Pos';
                param.xG=Pparam.xG(:,i); 
                param.problemType=3; 
                param.polType='Gauss';
                param.my0=Pparam.my0(:,i); 
                %param.S0=Pparam.S0; 
                param.S0=0.01*eye(2); 
                param.ProblemID='SM';
                param.polInit='random';
                param.gamma=0.9; 
                param.TaskId=i;
                policy=initSMpolicy(param); 
                SystemParameters(i).param=param; 
                SystemPolicies(i).policy=policy; 
            
            end
            
        else
            for i=1:nSystems
                display('Running Random ')
            param.UseELLA=0;     
            param.N=2; 
            param.M=1; 
            param.Mass=(Pparam.MassMax-Pparam.MassMin)*rand()+Pparam.MassMin;
            param.k=(Pparam.Maxk-Pparam.Mink)*rand()+Pparam.Mink;
            param.d=(Pparam.Maxd-Pparam.Mind)*rand()+Pparam.Mind;
            param.rewardType='Pos';
            param.xG=Pparam.xG(:,i); 
            param.problemType=3; 
            param.polType='Gauss';
            param.my0=Pparam.my0(:,i); 
            %param.S0=Pparam.S0; 
            param.S0=0.01*eye(2); 
            param.ProblemID='SM';
            param.polInit='random';
            param.gamma=0.9; 
            param.TaskId=i;
            param.dt=0.01; 
            policy=initSMpolicy(param); 
            SystemParameters(i).param=param; 
            SystemPolicies(i).policy=policy; 
            end
        end
    case 'MC'
    case 'CP'
        for i=1:nSystems
            param.UseELLA=0;     
        param.N=4; 
        param.M=1; 
        param.mc=(Pparam.MassCartMax-Pparam.MassCartMax)*rand()+Pparam.MassCartMin; 
        param.mp=(Pparam.MassPoleMax-Pparam.MassPoleMin)*rand()+Pparam.MassPoleMin;
        param.I=(Pparam.InertiaMax-Pparam.InertiaMin)*rand()+Pparam.InertiaMin; 
        param.l=(Pparam.MaxLength-Pparam.MinLength)*rand()+Pparam.MinLength; 
        param.g=9.81; 
        param.d=(Pparam.Maxd-Pparam.Mind)*rand()+Pparam.Mind; 
        param.rewardType='Distance';
        param.xG=Pparam.xG(:,i);
        param.my0=Pparam.my0(:,i); 
        param.S0=0.001*eye(4);
        param.TaskId=i;
        param.problemType=3;
        param.ProblemID='CP';
        param.polInit='random';
        param.polType='Gauss';
        param.gamma=0.9;
        policy=initCPpolicy(param);
        SystemParameters(i).param=param; 
        SystemPolicies(i).policy=policy; 
        end
    case '3CP'
        
        for i=1:nSystems
            param.N=8; 
            param.M=1;  
            param.m0=2.4; 
            param.m1=1.323; 
            param.m2=1.389;
            param.m3=0.8655; 
            param.L1=(Pparam.L1Max-Pparam.L1Min)*rand()+Pparam.L1Min; 
            param.L2=(Pparam.L2Max-Pparam.L2Min)*rand()+Pparam.L2Min; 
            param.L3=(Pparam.L3Max-Pparam.L3Min)*rand()+Pparam.L3Min; 
            param.l1=0.2449; 
            param.l2=0.193; 
            param.l3=0.3405; 
            param.J1=0.0119; 
            param.J2=0.0069*10^-3; 
            param.J3=0.0291; 
            param.f0=13.611; 
            param.f1=0.0045; 
            param.f2=0.0045; 
            param.f3=0.0045; 
            param.Ks=9.722; 
            param.g=9.81; 
            param.rewardType='Distance';
            param.xG=Pparam.xG(:,i);
            param.my0=Pparam.my0(:,i); 
            param.S0=0.001*eye(8);
            param.TaskId=i;
            param.UseELLA=0; 
            param.polType='Gauss';
            param.problemType=3;
            param.ProblemID='3CP';
            param.polInit='random';
            param.gamma=0.9;
            policy=init3CPpolicy(param);
            SystemParameters(i).param=param; 
            SystemPolicies(i).policy=policy; 
        end
        
        
    case 'Quad'
         for i=1:nSystems
             param.N=6; 
             param.M=1; 
             param.polInit='Gauss';
             param.ProblemID='Quad';
             param.polInit='LQR';
             param.gamma=0.9; 
             param.rewardType='Distance';
             %param.polType=3;
             param.problemType=3; 
             param.xG=Pparam.xG(:,i);
             param.my0=Pparam.my0(:,i); 
             param.S0=0.00001*eye(6);
             param.TaskId=i;
             param.UseELLA=0; 
             param.polType='Gauss';
             param.Ixx=(Pparam.MaxIxx-Pparam.MinIxx)*rand()+Pparam.MinIxx;
             param.Iyy=(Pparam.MaxIyy-Pparam.MinIyy)*rand()+Pparam.MinIyy;
             param.Izz=(Pparam.MaxIzz-Pparam.MinIzz)*rand()+Pparam.MinIzz;
             param.l=(Pparam.Maxl-Pparam.Minl)*rand()+Pparam.Minl;
             param.Jr=(Pparam.MaxJr-Pparam.MinJr)*rand()+Pparam.MinJr;
             policy=initQuadpolicy(param);
             
             SystemParameters(i).param=param; 
             SystemPolicies(i).policy=policy;
             
             

         end
        
end




