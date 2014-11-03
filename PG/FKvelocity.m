function V = FKvelocity(state, angularVelocities)
% Need to compute the Jacobian
% Given the state struct, and angular velocities
% (rad/time) compute the end effector velocity V
% Return the end effector velocity V in a 2-by-1 vector
%%
% numOfArms = length(state.lengths);
% tempV = [0;0];
% for i = 1:numOfArms
%     relativeVel = [-state.lengths(i)*angularVelocities(i)*sin(state.angles(i));
%                     state.lengths(i)*angularVelocities(i)*cos(state.angles(i))];
%     tempV = tempV+relativeVel;
% end
% V = tempV;

[X,Y] = FK2D(state.angles,state.lengths);
state.angles = state.angles+angularVelocities*0.01;
[X1,Y1] = FK2D(state.angles,state.lengths);
V = ([X(end);Y(end)]-[X1(end);Y1(end)])/0.01;
    
end