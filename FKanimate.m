function V = FKanimate(angles, des_pos, arm_lengths)
%% Initialization for configuration
% Configuration in 2D space
% angles includes all the joint angles, where each row is a single frame of
% the animation
% arm_lengths includes all the arm lengths
% des_pos is the desired position of the end effector

N_FRAMES = size(angles,1);
N_JOINTS = size(angles,2);

AXIS = sum(arm_lengths);

assert(N_JOINTS == length(arm_lengths));

if nargin < 3
    arm_lengths = ones(N_JOINTS);
end

for frame=1:N_FRAMES
    [X,Y] = FK2D(angles(frame,:), arm_lengths);
    % Init with 0,0 for plotting
    X = [0 X];
    Y = [0 Y];
    
    plot(X,Y);
    axis([-AXIS AXIS -AXIS AXIS]);
    hold on;
    plot(des_pos(1), des_pos(2), 'o');
    hold off;
    pause(0.25);
end

end