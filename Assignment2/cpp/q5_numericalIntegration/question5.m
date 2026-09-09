clear;
clc;
close all;

%% =========================
% NUMERICAL INTEGRATION
% ==========================

data = readtable("q5_numerical_integration.csv");

figure('Name', 'Numerical Integration', 'NumberTitle', 'off');

plot(data.Samples, data.EstimatedIntegral, ...
    'LineWidth', 1.5, ...
    'DisplayName', 'Monte Carlo Estimate');

hold on;

% Theoretical value: pi
yline(pi, '--', ...
    'DisplayName', 'Theoretical = \pi');

xlabel('Number of Samples');
ylabel('Value of Integral');
title('Numerical Integration: \int_0^2 \surd(4 - x^2) dx');

ylim([2.8, 3.5]);
legend('Location', 'best');
grid on;

hold off;