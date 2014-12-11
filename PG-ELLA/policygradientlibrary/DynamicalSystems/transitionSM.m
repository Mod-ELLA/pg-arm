function xn=transitionSM(x,u,param)
% Function implementing the SM system (Section 2.1) in the document
A=[0 1; -param.K/param.Mass -param.d./param.Mass];
b=[0; 1./param.Mass];
xndot=A*x+b*u; 
% Integrate xndot using simple Euler integration
xn=x+param.dt*xndot; 


