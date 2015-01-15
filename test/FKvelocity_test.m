function FKvelocity_test()
% This function will run tests on the 'FKvelocity' function
% TODO: This function needs to be implemented
%% Test 1 with 1 linkage
test_state.lengths = [0.5];
test_state.angles = [0];
if FKvelocity(test_state, 0.2) ~= 0.1
    display(FKvelocity(test_state, 0.2));
    error('Failed in the test case #1: 1 link');
end
%% Test 2 with 2 linkage