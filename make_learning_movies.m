function make_learning_movies(policies,state,dest,iterations)
max_exploration = iterations;
dest_pos = dest;
ks = cat(3,policies.backup.k, policies.samples.k,policies.theta.k);

for ik = 1:size(ks,3)
    % Reset Joint Angle
    theta = zeros(length(state.angles),1);
    state.angles = theta;
    % Initit state and policy
    trail_state = state;
    trail_policy = policies;
    trail_policy.theta.k = ks(:,:,ik);
    for i = 1:max_exploration
        x = getFeatures(trail_state);
        u = drawAction(trail_policy,x);
        tmp_state = drawNextState(trail_policy, trail_state.angles,u);
        sign = (tmp_state > 0).*2-1;
        trail_state.angles = sign.*mod(abs(tmp_state),2*pi);

        FKanimate(trail_state.angles, dest_pos, trail_state.lengths, i);
    end
end
