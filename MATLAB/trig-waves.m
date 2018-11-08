x = 0:0.2:2*pi;
y1 = sin(x);
y2 = cos(x);
figure; plot(x,y1,x,y2)
title('sine and cosine waves')
xlabel('x')
ylabel('sine or cosine')
legend('sine','cosine')
grid on