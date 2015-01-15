%% Generating Systems
clear all;
nSystems=5; 
Pparam.ProblemID='SM';
Pparam.MassMin=1; 
Pparam.MassMax=3; 
Pparam.Mink=1; 
Pparam.Maxk=3; 
Pparam.Maxd=0.2;
Pparam.Mind=0.1; 
Pparam.IncreaseDiffculty=0; 
xGs=rand(2,nSystems);
Pparam.xG=xGs; 
my0=rand(2,nSystems);
Pparam.my0=my0;
[pg_Param,policies]=generateSystems(nSystems,Pparam); % Generating nSystems 
for i=1:nSystems
    pg_Param(i).learningrate=0.1; 
    HessianArray(i).D=eye(2,2); 
    ParameterArray(i).alpha=zeros(2,1);
end
%% Init-PG-ELLA
K=1;
T=5; % number of tasks
model.L=rand(2,K); % dxk, where d=2, k=1
model.S=zeros(K,T);
model.mu_one = 0.1;
model.T = 0; % number of tasks
model.learningrate = 0.001;
%% Learn PG-ELLA
for i=1:T
[data]=obtainData(policies(i).policy, 10, 20, pg_Param(i).param);    
[model,HessianArray,ParameterArray]=updatePGELLA(data,model,i,pg_Param...
                                            ,policies,HessianArray,ParameterArray);
end
%% Test PG-ELLA
% Initialize PG Policies 
clear PG_policy
clear PGELLA_policy 
clear rPG 
clear rPELLA
for i=1:5
    pol=initSMpolicy(pg_Param(i).param);
    PG_policy(i).policy=pol; 
    PGELLA_policy(i).policy=performActionPGELLA(model,i);
end
nIterations=500;
% Test learning 
for i=1:5
    figure(i)
    for k=1:nIterations
        [dataPG]=obtainData(PG_policy(i).policy,50,10,pg_Param(i).param);
        dJdthetaPG=episodicREINFORCE(PG_policy(i).policy,dataPG,pg_Param(i).param); 
        %dJdthetaPG=episodicNaturalActorCritic(PG_policy(i).policy,dataPG,pg_Param(i).param); 
        PG_policy(i).policy.theta.k=PG_policy(i).policy.theta.k+pg_Param(i).learningrate*dJdthetaPG(1:2,:);
        [dataPGELLA]=obtainData(PGELLA_policy(i).policy,50,10,pg_Param(i).param);
        dJdthetaPGELLA=episodicREINFORCE(PGELLA_policy(i).policy,dataPGELLA,pg_Param(i).param); 
        PGELLA_policy(i).policy.theta.k=PGELLA_policy(i).policy.theta.k+pg_Param(i).learningrate*dJdthetaPG(1:2,:);
        for l=1:size(dataPG,2)
            rPG(l,:)=sum(dataPG(l).r); 
            rPGELLA(l,:)=sum(dataPGELLA(l).r); 
        end
            plot(k,mean(rPG),'k*')
            hold on 
            plot(k,mean(rPGELLA),'r+');
            drawnow
    end
end



