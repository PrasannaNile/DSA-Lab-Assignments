clear;
clc;
close all;

%% =========================
% ONE COIN
% ==========================

oneCoin = readtable("one_coin_toss.csv");

figure('Name', 'One Coin Toss', 'NumberTitle', 'off');

plot(oneCoin.TossCount, oneCoin.ProbHead, ...
    'LineWidth', 1.5, ...
    'DisplayName', 'Heads');

hold on;

plot(oneCoin.TossCount, oneCoin.ProbTail, ...
    'LineWidth', 1.5, ...
    'DisplayName', 'Tails');

% Theoretical probability
yline(0.5, '--', ...
    'DisplayName', 'Theoretical = 0.5');

xlabel('Number of Tosses');
ylabel('Probability');
title('One Coin Toss');

legend('Location', 'best');
grid on;

hold off;


%% =========================
% TWO COINS
% ==========================

twoCoin = readtable("two_coin_toss.csv");

figure('Name', 'Two Coin Toss', 'NumberTitle', 'off');

% Columns 6-9 are P(HH), P(HT), P(TH), P(TT)

plot(twoCoin.TossCount, twoCoin.ProbHH, ...
    'LineWidth', 1.5, ...
    'DisplayName', 'P(HH)');

hold on;

plot(twoCoin.TossCount, twoCoin.ProbHT, ...
    'LineWidth', 1.5, ...
    'DisplayName', 'P(HT)');

plot(twoCoin.TossCount, twoCoin.ProbTH, ...
    'LineWidth', 1.5, ...
    'DisplayName', 'P(TH)');

plot(twoCoin.TossCount, twoCoin.ProbTT, ...
    'LineWidth', 1.5, ...
    'DisplayName', 'P(TT)');

% Theoretical probability
yline(0.25, '--', ...
    'DisplayName', 'Theoretical = 0.25');

xlabel('Number of Tosses');
ylabel('Probability');

title('Two Coin Toss');

legend('Location', 'best');

grid on;

hold off;