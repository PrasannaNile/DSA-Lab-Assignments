clear;
clc;
close all;

%% Open and parse file
filename = "monte_carlo_output.csv";
fid = fopen(filename, 'r');
if fid == -1
    error('Cannot open file: %s', filename);
end

% Skip header line
fgetl(fid);

% Format: int, (double, double) , double
data = textscan(fid, '%d, (%f, %f) , %f');
fclose(fid);

pointIndex = data{1};
xCoord     = data{2};
yCoord     = data{3};
estimatePI = data{4};

%% =========================================================================
% GRAPH 1: Pi Convergence vs. Iterations
%% =========================================================================
figure('Name', 'Monte Carlo Pi Convergence', 'NumberTitle', 'off');
plot(pointIndex, estimatePI, 'b-', 'LineWidth', 1.2, ...
    'DisplayName', 'Estimated \pi');
hold on;

% Theoretical line
yline(pi, '--r', 'LineWidth', 1.5, ...
    'DisplayName', ['Theoretical \pi \approx ' num2str(pi, '%.5f')]);

xlabel('Total Points Sampled (N)');
ylabel('Estimated \pi Value');
title('Monte Carlo Estimation of \pi Convergence');
ylim([2.0, 4.2]);
legend('Location', 'best');
grid on;
hold off;

%% =========================================================================
% GRAPH 2: Geometric Quarter-Circle Scatter Plot
%% =========================================================================
figure('Name', 'Sampled Points Distribution', 'NumberTitle', 'off');

% Plot a representative subset if points exceed 5,000 to keep rendering fast
maxPlotPoints = min(length(xCoord), 5000);
scatter(xCoord(1:maxPlotPoints), yCoord(1:maxPlotPoints), 8, 'b', 'filled', ...
    'DisplayName', 'Inside Quarter Circle');
hold on;

% Draw quarter circle boundary
theta = linspace(0, pi/2, 200);
plot(cos(theta), sin(theta), 'r-', 'LineWidth', 2.0, ...
    'DisplayName', 'Boundary (x^2 + y^2 = 1)');

axis equal;
xlim([0, 1]);
ylim([0, 1]);
xlabel('X Coordinate');
ylabel('Y Coordinate');
title('Monte Carlo Quarter-Circle Sampling');
legend('Location', 'northeast');
grid on;
hold off;