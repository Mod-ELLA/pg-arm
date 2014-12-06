disp('Installing policy gradient libary...')
%% Add paths of libraries
if ispc
    addpath(genpath([pwd,'\PG']));
    addpath(genpath([pwd,'\policygradientlibrary']));
elseif isunix
    addpath(genpath([pwd,'/PG']));
    addpath(genpath([pwd,'/policygradientlibrary']));
end
disp('Done!');