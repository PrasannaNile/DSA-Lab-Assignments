clear;
clc;
close all;
%% =========================
% SORTED DATASET
% ==========================
sortedData = readtable("q8_RandQuickVSQuickHoare.csv");
figure('Name', 'Hoare Partitioning', 'NumberTitle', 'off');
plot(sortedData.Datasize, sortedData.RandQuickComp, ...
    'LineWidth', 1.5, ...
    'DisplayName', 'RandQuickComp');
hold on;
plot(sortedData.Datasize, sortedData.QuickComp, ...
    'LineWidth', 1.5, ...
    'DisplayName', 'QuickComp');
xlabel('Datasize');
ylabel('Comparisons');
title('Randomized Quick vs Standard Quick (Sorted)');
legend('Location', 'best');
grid on;
hold off;
%% =========================
% UNSORTED DATASET
% ==========================
unsortedData = readtable("q8_RandQuickVSQuickLomuto.csv");
figure('Name', 'Lomuto Partitioning', 'NumberTitle', 'off');
plot(unsortedData.Datasize, unsortedData.RandQuickComp, ...
    'LineWidth', 1.5, ...
    'DisplayName', 'RandQuickComp');
hold on;
plot(unsortedData.Datasize, unsortedData.QuickComp, ...
    'LineWidth', 1.5, ...
    'DisplayName', 'QuickComp');
xlabel('Datasize');
ylabel('Comparisons');
title('Randomized Quick vs Standard Quick (Unsorted)');
legend('Location', 'best');
grid on;
hold off;