clear
clc
close all

time1 = load('time1.dat');
time2 = load('time2.dat');
time3 = load('time3.dat');
time4 = load('time4.dat');
time5 = load('time5.dat');

x = [1,2,3,4,5,10,15,20,25,30,35,40,50,60];
figure
% subplot(6,2,1)
plot(x,time1(:,3))
hold on
plot(x,time2(:,3))
hold on
plot(x,time3(:,3))
hold on
plot(x,time4(:,3))
hold on
plot(x,time5(:,3))
hold on
xlabel('nof primes')
ylabel('time [s]')
legend('10x10','50x50','100x100','150x150','200x200')
title('time for modular Gauss')
figure
% subplot(6,2,1)
plot(x,time1(:,5))
hold on
plot(x,time2(:,5))
hold on
plot(x,time3(:,5))
hold on
plot(x,time4(:,5))
hold on
plot(x,time5(:,5))
hold on
xlabel('nof primes')
ylabel('time [s]')
legend('10x10','50x50','100x100','150x150','200x200')
title('time for garner_gmp')
figure
% subplot(6,2,1)
plot(x,time1(:,6))
hold on
plot(x,time2(:,6))
hold on
plot(x,time3(:,6))
hold on
plot(x,time4(:,6))
hold on
plot(x,time5(:,6))
hold on
xlabel('nof primes')
ylabel('time [s]')
legend('10x10','50x50','100x100','150x150','200x200')
title('time complete')