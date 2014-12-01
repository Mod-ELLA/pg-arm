function u = ccdAction(state)

global des_pos N
c = 0.25;
[x,y] = FK2D(state.angles,state.lengths);
x = [0,x];
y = [0,y];
u = zeros(N,1);
error = des_pos-[x(end);y(end)];
error = [error;0];
for i=1:N
    rin = [x(end);y(end)] - [x(i);y(i)];
    rin = [rin;0];
    
    
    u(i) = c*norm(cross(rin,error))/dot(rin,rin+error);
    if cross(rin,error)<0
        u(i) = -u(i);
    end
    %u(i) = min(1,u(i));
    
end
u(2) = -u(2);
end
