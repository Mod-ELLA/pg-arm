function [policy]=performActionPGELLA(model,taskIndex)

        thetaTask=model(1).L*model(1).S(:,taskIndex);
        policy.theta.k=thetaTask; 
        policy.theta.sigma=rand(); 
        policy.type=3; 