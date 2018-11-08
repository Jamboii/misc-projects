r = 0:0.2:10; %Declare radius with 0.2 increments
v = (4.*pi.*r.^3)/3; %Declare volume with element-by-element multiplication
figure; plot(r,v,'bo--'), %Plot r as x-axis, v as y-axis with blue dashed lines
title('Sphere Volume Based on Radius'), %title
xlabel('Radius'), ylabel('Volume') %label axes