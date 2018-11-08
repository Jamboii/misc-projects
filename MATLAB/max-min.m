minmax = zeros(2,100);
for trial = 1:100
  x = randi([-10,10],50,50); %Random integers -10 through 10
  avg = zeros(1,50); %50 column average# array to display after loop
  for col = 1:50
      c = x(:,col); %Select a new column of x
      avg(1,col) = mean(c(c>0)); %Average of positive #s in each column
  end
  disp(avg)
  minmax(1,trial) = min(avg); minmax(2,trial) = max(avg);
end
Av = sprintf('Average min: %s\nAverage max: %d',mean(minmax(1,:)),mean(minmax(2,:)));
Ab = sprintf('\nAbsolute min: %s\nAbsolute max: %d',min(minmax(1,:)),max(minmax(2,:)));
disp(Av); disp(Ab);

  