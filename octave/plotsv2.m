pkg load io

data = dlmread('../src/astronaut-data.csv', ',', 1, 1);

figure;
plot(data(:,3), 'r-o');
title('Heart Rate');
xlabel('Day');
ylabel('Heart Rate bpm');
grid on;

figure;
plot(data(:,4),'-x');
title('Respiratory Rate');
xlabel('Days');
ylabel('Respiratory Rate bpm');
grid on;

figure;
plot(data(:,5),'--*');
title('Blood sugar');
xlabel('Days');
ylabel('Blood suagr mg/dl');
grid on;

figure;
plot(data(:,6),'g:+');
title('Oxygen in blood');
xlabel('Days');
ylabel('SpO2');
grid on;

figure;
plot(data(:,7),':o');
title('Temperature');
xlabel('Days');
ylabel('Temperature C');
grid on;

figure;
plot(data(:,9),'m:+');
xlabel('Days');
ylabel('Risk points');
grid on;
