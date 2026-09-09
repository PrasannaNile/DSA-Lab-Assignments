clear;
clc;
close all;

%% Read benchmark CSV
data = readtable("primality_error.csv");

trials = data.Trials;
empirical_error = data.EmpiricalErrorRate;clear;
clc;
close all;

%% 1. Read CSV Data
data = readtable("primality_error.csv");

trials = data.Trials;
empirical_error = data.EmpiricalErrorRate;
theoretical_bound = data.TheoreticalBound;

%% 2. Plot on Semilogarithmic Scale
fig = figure('Name', 'Primality Test Error Decay', 'NumberTitle', 'off', 'Color', 'w');

% Mask points where empirical error > 0 for log-plotting
validIdx = empirical_error > 0;

semilogy(trials(validIdx), empirical_error(validIdx), 'b-o', ...
    'LineWidth', 1.8, 'MarkerSize', 7, 'MarkerFaceColor', 'b', ...
    'DisplayName', 'Empirical Error (M = 10,000)');
hold on;

semilogy(trials, theoretical_bound, '--r', ...
    'LineWidth', 1.6, ...
    'DisplayName', 'Theoretical Bound (0.5^k)');

% Add a visual marker/text indicating 0 error beyond k = 4
yline(1/10000, ':k', 'LineWidth', 1.2, ...
    'DisplayName', 'Resolution Limit (1 / 10,000)');

xlabel('Number of Random Trials (k)', 'FontSize', 11, 'FontWeight', 'bold');
ylabel('Error Probability P(False Positive)', 'FontSize', 11, 'FontWeight', 'bold');
title('Fermat Primality Test: Error Decay vs. Trial Count (Composite n = 91)', ...
    'FontSize', 12, 'FontWeight', 'bold');

xlim([1, max(trials)]);
ylim([1e-5, 1.0]);

grid on;
set(gca, 'GridAlpha', 0.25, 'Box', 'on', 'TickDir', 'in');
legend('Location', 'northeast', 'FontSize', 10);
hold off;
theoretical_bound = data.TheoreticalBound;

%% Plot on Semilogarithmic Scale
fig = figure('Name', 'Primality Correctness Analysis', 'NumberTitle', 'off', 'Color', 'w');

semilogy(trials, empirical_error, 'b-o', 'LineWidth', 1.5, 'MarkerFaceColor', 'b', ...
    'DisplayName', 'Empirical Error P(False Positive)');
hold on;
semilogy(trials, theoretical_bound, '--r', 'LineWidth', 1.5, ...
    'DisplayName', 'Theoretical Worst-Case Bound (0.5^k)');

% Formatting
title('Fermat Primality Test: Correctness & Error Decay Analysis', ...
    'FontSize', 12, 'FontWeight', 'bold', 'Color', 'k');
xlabel('Number of Random Trials (k)', 'FontSize', 11, 'Color', 'k');
ylabel('Probability of Error (Log Scale)', 'FontSize', 11, 'Color', 'k');

xlim([1, max(trials)]);
ylim([1e-5, 1.0]);

set(gca, 'Box', 'on', 'TickDir', 'in', 'LineWidth', 1.0, ...
         'XColor', 'k', 'YColor', 'k', 'Color', 'w');
grid on;
set(gca, 'GridAlpha', 0.2);

legend('Location', 'northeast', 'FontSize', 10);
hold off;