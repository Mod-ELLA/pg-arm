function policy=initSMpolicy(param)

policyType=param.polType;
% TODO: Support other policies 

if strcmpi(policyType,'Gauss')
   policy=initGaussPolicy(param);
else
    error('Undefined Policy Type')
end
