clear;
clc;
close all;

%% =========================
% MAJORITY ELEMENT
% ==========================
data = readtable("q7_majorityElement.csv");

figure('Name', 'Majority Element Analysis', 'NumberTitle', 'off');
plot(data.Datasize, data.AvgAttempts, ...
    'LineWidth', 1.5, ...
    'DisplayName', 'Empirical Avg Attempts');
hold on;
plot(data.Datasize, data.TheoreticalExpected, '--r', ...
    'LineWidth', 1.5, ...
    'DisplayName', 'Theoretical Bound (<= 2.0)');

xlabel('Datasize');
ylabel('Average Attempts to Find Majority');
title('Randomized Majority Element: Attempts vs Data Size');
ylim([0, 3]);
legend('Location', 'best');
grid on;
hold off;