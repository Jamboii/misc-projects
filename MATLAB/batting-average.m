ba1908 = [.276 .272 .3 .266 .241 .231 .222 .236 .243 .279 .26 .292 .2 .25 .3];
ba2016 = [.216 .292 .272 .238 .292 .238 .276 .23 .273 .282 .229 .259 .27 .252 .277];
plot(1:15,sort(ba1908),'r.-',1:15,sort(ba2016),'g.-'), %X-axis ranges 1-15, each Y-axis is a sorted array
xlabel('Rank'), ylabel('Batting Average'), %Label axes
legend('1908 Cubs', '2016 Cubs'), %Create legend
xlim([1 15]); %Limit x-axis to remove unwanted space