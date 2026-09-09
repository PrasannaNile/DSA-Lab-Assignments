clc;
clear;
close all;


%% ============================================================
%  HIGHLY INVERSIONAL DATA
% =============================================================

data = readtable('q2_comparisonHighlyRandom.csv');

inputSize = data{:, 1};
compNES   = data{:, 2};
compES    = data{:, 3};

figure;

plot(inputSize, compNES, 'LineWidth', 1.5);
hold on;
plot(inputSize, compES, 'LineWidth', 1.5);

xlabel('Input Size');
ylabel('Number of Comparisons');
title('Bubble Sort - Highly Inversional Data');

legend('Without Early Stopping', ...
       'With Early Stopping', ...
       'Location', 'northwest');

grid on;


%% ============================================================
%  NEARLY SORTED DATA
% =============================================================

data = readtable('q2_comparisonNearlySorted.csv');

inputSize = data{:, 1};
compNES   = data{:, 2};
compES    = data{:, 3};

figure;

plot(inputSize, compNES, 'LineWidth', 1.5);
hold on;
plot(inputSize, compES, 'LineWidth', 1.5);

xlabel('Input Size');
ylabel('Number of Comparisons');
title('Bubble Sort - Nearly Sorted Data');

legend('Without Early Stopping', ...
       'With Early Stopping', ...
       'Location', 'northwest');

grid on;


%% ============================================================
%  SORTED DATA
% =============================================================

data = readtable('q2_comparisonAlreadySorted.csv');

inputSize = data{:, 1};
compNES   = data{:, 2};
compES    = data{:, 3};

figure;

plot(inputSize, compNES, 'LineWidth', 1.5);
hold on;
plot(inputSize, compES, 'LineWidth', 1.5);

xlabel('Input Size');
ylabel('Number of Comparisons');
title('Bubble Sort - Sorted Data');

legend('Without Early Stopping', ...
       'With Early Stopping', ...
       'Location', 'northwest');

grid on;