function V = FKvelocity(angles, lengths, angularVelocities)
% Need to compute the Jacobian
% Given joint angles, linkage lengths, and angular velocities
% (rad/time) compute the end effector velocity V
% Return the end effector velocity V in a 2-by-1 vector
%%
numOfArms = length(lengths);
tempV = [0;0];
for i = 1:numOfArms
    relativeVel = [-lengths(i)*angularVelocities(i)*sind(angles(i));
                    lengths(i)*angularVelocities(i)*cosd(angles(i))];
    tempV = tempV+relativeVel;
end
V = tempV;

end