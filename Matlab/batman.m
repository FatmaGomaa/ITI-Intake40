function batman()
figure
zeta = linspace((0*pi/180),(135*pi/180),360);
r =15
x = r*cos(zeta);
y = r*sin(zeta);
plot(x,y,'r')
hold on
plot(-x-70,y,'r')

theta = linspace((45*pi/180),(180*pi/180),360);
r =15
x = r*cos(theta);
y = r*sin(theta);
plot(x-20,y,'r')
hold on
plot(-x-50,y,'r')

theta = linspace((-90*pi/180),(90*pi/180),360);
r =50
x = r*cos(theta);
y = r*sin(theta);
plot(x+15,y+50,'r')
hold on
plot(-x-85,y+50,'r')

theta = linspace((-135*pi/180),(40*pi/180),360);
r =25
x = r*cos(theta);
y = r*sin(theta);
plot(x-5,y+85,'r')
hold on
plot(-x-65,y+85,'r')

lineXpoints = [-22 -25 -22];
lineYpoints = [67 100 67];
hold on
plot(lineXpoints,lineYpoints,'r')

lineXpoints = [-47 -45 -47];
lineYpoints = [67 100 67];
hold on
plot(lineXpoints,lineYpoints,'r')

lineXpoints = [-25 -30 -25];
lineYpoints = [100 85 100];
hold on
plot(lineXpoints,lineYpoints,'r')

lineXpoints = [-45 -40 -45];
lineYpoints = [100 85 100];
hold on
plot(lineXpoints,lineYpoints,'r')

lineXpoints = [-30 -40 -30];
lineYpoints = [85 85 85];
hold on
plot(lineXpoints,lineYpoints,'r')

xlim([-150, 100]);
ylim([-80, 200]);
end