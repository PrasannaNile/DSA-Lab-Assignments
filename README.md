# Advanced Data Structures Laboratory — Assignment 1

Empirical evaluation and simulation suite comparing algorithmic performance, sorting variants, and stochastic processes using **C++ (C++17/20)** for data generation and **MATLAB** for data analysis and visualization.

---

## 📌 Project Overview

This repository contains implementations, data generators, and visualization scripts for three core problems:

1. **Stochastic Simulation (Coin Tossing):** Demonstrates the empirical convergence of probabilities toward theoretical bounds ($0.5$ for a single coin, $0.25$ for two coins) to validate the Law of Large Numbers.
2. **Adaptive Bubble Sort Analysis:** Evaluates comparison overhead between classical Bubble Sort ($n-1$ passes) and optimized Bubble Sort (early-termination flag) across sorted, nearly sorted, and heavily inverted arrays.
3. **Hybrid Quick Sort Engine:** Identifies the empirical crossover point where Insertion Sort outperforms Quick Sort ($n \le 20$), and benchmarks an adaptive Hybrid Quick Sort routine that switches to Insertion Sort for subproblems of size $n \le 12$.

---

