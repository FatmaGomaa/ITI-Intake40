function TrafficLights()
figure
xlim([-50, 50]);
ylim([0, 100]);
rectangle('Position',[-15 20 30 50],'FaceColor',[0 0 0],'Curvature',.3)
hold on
rectangle('Position',[-2 5 5 15],'FaceColor',[.8 .8 .8])
hold on
rectXpoints = [-2 -2 3 3 -2];
rectYpoints = [13 16 20 17 13];
fill(rectXpoints,rectYpoints,[1 1 0])
hold on 
rectXpoints = [-2 -2 3 3 -2];
rectYpoints = [5 8 13 9 5];
fill(rectXpoints,rectYpoints,[1 1 0])
hold on 

for i=1:1:10
rectangle('Position',[-6 55 12 12],'FaceColor',[1 0 0],'Curvature',[1 1])
rectangle('Position',[-6 40 12 12],'FaceColor',[0.5 .5 0],'Curvature',[1 1])
rectangle('Position',[-6 25 12 12],'FaceColor',[0 .5 0],'Curvature',[1 1])
pause(1)
rectangle('Position',[-6 55 12 12],'FaceColor',[.5 0 0],'Curvature',[1 1])
rectangle('Position',[-6 40 12 12],'FaceColor',[1 1 0],'Curvature',[1 1])
rectangle('Position',[-6 25 12 12],'FaceColor',[0 .5 0],'Curvature',[1 1])
pause(1)
rectangle('Position',[-6 55 12 12],'FaceColor',[.5 0 0],'Curvature',[1 1])
rectangle('Position',[-6 40 12 12],'FaceColor',[.5 .5 0],'Curvature',[1 1])
rectangle('Position',[-6 25 12 12],'FaceColor',[0 1 0],'Curvature',[1 1])
pause(1)
end

end


%subplot(1,3,2)
%axis([-50 50 0 50])