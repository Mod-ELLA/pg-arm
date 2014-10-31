% High-level PG function
max_iter = 1000;
step_thresh = 0.001;

% Needs to attempt to learn M by repeatedly calling pgUpdate, for at most
% max_iter iterations or until converges (nothing updates by more than
% step_thresh)