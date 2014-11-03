function features = getFeatures(state)
% Returns a nx1 vector of feature values given the state
% In this function, the features are:
% joint angles; sine of joint angles; cosine of joint angles;
% tangent of joint angle; product of sine and cosine of the joint angles
joint_angles = reshape(state.angles,[],1);
features = joint_angles;
features = [features; sin(joint_angles); cos(joint_angles); tan(joint_angles); sin(joint_angles).*cos(joint_angles)];
end