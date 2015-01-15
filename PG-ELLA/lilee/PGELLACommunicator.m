classdef PGELLACommunicator < handle
    
    properties (Access = protected)
        Node = [];                  % ROS node.
        PGELLAInputSub = [];            % ROS subscriber for state/action/rewards
        PGELLAOutputPub = [];
        PGELLAInitPolicySub = [];
        
        LinearVelPolicyMsg = [];
        AngularVelPolicyMsg= [];
        
        States1 = [];
        States2 = [];
        Actions1 = [];              % linear_vel actions
        Actions2 = [];              % angular_vel actions
        Rewards = [];
        Policy1 = [];
        Policy2 = [];
        Param = [];
        LearningRate = []
        LearningRate1 = []          % array of learning rates for linear_vel policy
        LearningRate2 = []          % array of learning rates for angular_vel policy
        numLearningRates = []       % Number of learning rates
        
        numEpisodesTilUpdate = []   % Update policies after numEpisodesTilUpdate episodes
        numEpisodes = []             % Number of episodes since last update
        
    end
    
    methods (Access = public)
        function h = PGELLACommunicator(handles)
            % Constructor.
            
            % Create the ROS node.
            global rosMasterIp;
            global localhostIp;
            h.Node = rosmatlab.node('MATLAB', rosMasterIp, 11311, 'rosIP', localhostIp);
            
            % Initialize variables
            h.numEpisodesTilUpdate = 15;
            h.numEpisodes = 0;
            
            % Publishers
            h.PGELLAOutputPub = h.Node.addPublisher('/PGELLA_output', 'geometry_msgs/Transform');
            
            % Create a message.
            h.LinearVelPolicyMsg = rosmatlab.message('geometry_msgs/Transform', h.Node);
            h.AngularVelPolicyMsg = rosmatlab.message('geometry_msgs/Transform', h.Node);
            
            % Learning rates
            h.LearningRate = 0.00001;
            h.LearningRate1 = [0.00000001, 0.0000001, 0.000001, 0.00001, 0.0001, 0.001];
            h.LearningRate2 = [0.00000001, 0.0000001, 0.000001, 0.00001, 0.0001, 0.001];
            h.numLearningRates = length(h.LearningRate2);
            
            for i=1:h.numLearningRates
                h.Policy1(i).theta.k = zeros(2,1);
                h.Policy1(i).theta.sigma = rand();
                h.Policy1(i).type = 3;

                h.Policy2(i).theta.k = zeros(2,1);
                h.Policy2(i).theta.sigma = rand();
                h.Policy2(i).type = 3;
            end
            
            % Parameters for episodicREINFORCE
            h.Param.N = 2;
            h.Param.M = 1;
            h.Param.gamma = 0.9;
            
            h.States1 = zeros(2,1);
            h.States2 = zeros(2,1);
            h.Rewards = 0;
            h.Actions1 = 0;
            h.Actions2 = 0;
            
            % Subscribers
            h.PGELLAInputSub = h.Node.addSubscriber('/PGELLA_input', 'geometry_msgs/Transform', 1);
            h.PGELLAInputSub.setOnNewMessageListeners({@h.PGELLAinputCallback});
            
            h.PGELLAInitPolicySub = h.Node.addSubscriber('/PGELLA_init_policy', 'geometry_msgs/Transform', 50);
            h.PGELLAInitPolicySub.setOnNewMessageListeners({@h.PGELLAinitpolicyCallback});
            
        end
        
        
        
        function delete(h)
             % Destructor.
             
            delete(h.Node);
        end       
    end
    
    methods (Access = protected)
        
        function PGELLAinitpolicyCallback (h, message)
            % Set initial theta.
            
            translation = message.getTranslation();
            rotation = message.getRotation();
            
            numPolicy = translation.getY();
            if (numPolicy == 0)
                return;
            end
            
            if (translation.getZ() == 0)
                h.Policy1(numPolicy).theta.k = transpose([rotation.getX(), rotation.getY()])
                h.Policy1(numPolicy).theta.sigma = translation.getX();
            else
                h.Policy2(numPolicy).theta.k = transpose([rotation.getX(), rotation.getY()])
                h.Policy2(numPolicy).theta.sigma = translation.getX();
            end
            
            numPolicy
            h.Policy1(numPolicy).theta.k
            h.Policy2(numPolicy).theta.k
            
        end
        
        function PGELLAinputCallback (h, message)
            % Collect trajectories, and compute new policy when episode
            % ends.
            
            translation = message.getTranslation();
            rotation = message.getRotation();
            
            h.Actions1(1,end+1) = translation.getX();  % linear_vel
            h.Actions2(1,end+1) = translation.getY();  % angular_vel
            h.Rewards(1,end+1) = translation.getZ();   % reward
            
            % linear_vel = k1*d + k2*|a|
            h.States1(1,end+1) = rotation.getX();
            h.States1(2,end) = abs(rotation.getY());
            
            % angular_vel = k1/d + k2*a
            h.States2(1,end+1) = rotation.getX();
            h.States2(2,end) = rotation.getY();;
            
            if (rotation.getW() == 1)
                % Terminal state
                
                h.numEpisodes = h.numEpisodes+1;
                
                if (h.numEpisodes == h.numEpisodesTilUpdate)
                    % Update policies
                    h.numEpisodes = 0;
                    
                    data1.u = h.Actions1(2:end);
                    data2.u = h.Actions2(2:end);
                    data1.r = h.Rewards(2:end);
                    data2.r = h.Rewards(2:end);

                    data1.x = h.States1(:, 2:end);
                    data2.x = h.States2(:, 2:end);

                    for i=1:h.numLearningRates
                        [dJdtheta]=episodicREINFORCE(h.Policy1(i), data1, h.Param);
                        h.Policy1(i).theta.k = h.Policy1(i).theta.k + h.LearningRate1(i) * dJdtheta(1:h.Param.N,1);
                        h.Policy1(i).theta.sigma = h.Policy1(i).theta.sigma + h.LearningRate1(i)*dJdtheta(h.Param.N+1,1) * h.Policy1(i).theta.sigma^2;

                        [dJdtheta]=episodicREINFORCE(h.Policy2(i), data2, h.Param);
                        h.Policy2(i).theta.k = h.Policy2(i).theta.k + h.LearningRate2(i) * dJdtheta(1:h.Param.N,1);
                        h.Policy2(i).theta.sigma = h.Policy2(i).theta.sigma + h.LearningRate2(i)*dJdtheta(h.Param.N+1,1) * h.Policy2(i).theta.sigma^2;
                    end

                    % publish to ROS; send new policy
                    translation = rosmatlab.message('geometry_msgs/Vector3', h.Node);
                    rotation = rosmatlab.message('geometry_msgs/Quaternion', h.Node);

                    for i=1:h.numLearningRates

                        translation.setX(h.Policy1(i).theta.sigma);
                        translation.setY(i);
                        translation.setZ(0); % linear_vel: msg.translation.z = 0
                        rotation.setX(h.Policy1(i).theta.k(1,:));
                        rotation.setY(h.Policy1(i).theta.k(2,:));
                        %rotation.setZ(0);
                        %rotation.setW(0);
                        h.LinearVelPolicyMsg.setRotation(rotation);
                        h.LinearVelPolicyMsg.setTranslation(translation);
                        h.PGELLAOutputPub.publish(h.LinearVelPolicyMsg);

                        translation.setX(h.Policy2(i).theta.sigma);
                        translation.setY(i);
                        translation.setZ(1);  % angular_vel: msg.translation.z = 1
                        rotation.setX(h.Policy2(i).theta.k(1,:));
                        rotation.setY(h.Policy2(i).theta.k(2,:));
                        %rotation.setZ(0);
                        %rotation.setW(0);
                        h.LinearVelPolicyMsg.setRotation(rotation);
                        h.LinearVelPolicyMsg.setTranslation(translation);
                        h.PGELLAOutputPub.publish(h.LinearVelPolicyMsg);
                    end

                    % Clear trajectory
                    h.States1 = zeros(2,1);
                    h.States2 = zeros(2,1);
                    h.Actions1 = 0;
                    h.Actions2 = 0;
                    h.Rewards = 0;
                end
            end
            
            
        end
    end
    
end
