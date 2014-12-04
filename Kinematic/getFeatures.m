function features = getFeatures(state)

global des_pos
% Returns a nx1 vector of feature values given the state
% In this function, the features are:
% joint angles; sine of joint angles; cosine of joint angles;
% tangent of joint angle; product of sine and cosine of the joint angles
joint_angles = reshape(state.angles,[],1);
features = joint_angles;
% features = [features; sin(joint_angles); cos(joint_angles); tan(joint_angles); sin(joint_angles).*cos(joint_angles)];
%features = [features; sin(joint_angles); cos(joint_angles)];
% Reduced the features to be a PD Controller
features = [features; 1];

%[x,y] = FK2D(state.angles,state.lengths);
%current_pos = [x(end);y(end)];
%features = [des_pos-current_pos];
%errors = bsxfun(@minus,[x',y'],des_pos);
%features = reshape(errors, numel(errors),1);

end