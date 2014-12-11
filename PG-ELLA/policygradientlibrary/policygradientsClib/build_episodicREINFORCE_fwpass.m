function build_episodicREINFORCE_fwpass(pol,dat,par)
policy=pol
data=dat 
param=par
%pause
%policy=pol;
%data=dat;
%param=par; 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Init episodicREINFORCE params 
display('==== compiling forward pass function ====')

codegen episodicREINFORCE  -args {policy,data,param} -o episodicREINFORCE -launchreport


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%