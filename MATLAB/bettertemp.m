time=[0.0,0.5,1.0,1.5,2.0,2.5,3.0];
temps=[105,126,119,129,132,140,160];
average = mean(temps);
plot(time,temps),title('Temperature Measurements'),
xlabel('Time,minutes'),
ylabel('Temperature,degree F'),grid