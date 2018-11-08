% ENG 142-04
% Alex Benasutti
% InClass MATLAB

data = xlsread('TemperatureData_Matlab.xlsx');
time = data(:,1);
T_Fah = data(:,2);
T_Cel = (5/9)*(T_Fah - 32);

%display data
max_temp = max(T_Cel)
min_temp = min(T_Cel)
mean_temp = mean(T_Cel)
std_temp = std(T_Cel)

figure %stem plot
stem(time,T_Cel)

figure %bar graph
bar(time,T_Cel),
title('Temperature by Alex'),
xlabel('Time, seconds'),
ylabel('Temperature, degrees C'),
grid



