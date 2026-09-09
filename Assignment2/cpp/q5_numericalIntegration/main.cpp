#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include <iomanip>

int main() {
    const double EXACT_VAL = M_PI; // Analytical answer is pi
    const std::size_t TOTAL_SAMPLES = 1e6;

    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 2.0); // Range [a, b] = [0, 2]

    std::ofstream file("Assignment2/cpp/q5_numericalIntegration/q5_numerical_integration.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open output CSV file.\n";
        return 1;
    }
    file << "Samples,EstimatedIntegral,ExactValue,AbsoluteError\n";

    double sum_fx = 0.0;

    for (std::size_t i = 1; i <= TOTAL_SAMPLES; ++i) {
        double x = dist(gen);
        double fx = std::sqrt(4.0 - x * x);
        sum_fx += fx;

        // Log checkpoints to observe convergence
        if (i <= 1000 || i % 1000 == 0) {
            double current_estimate = (2.0 - 0.0) * (sum_fx / i);
            double error = std::abs(current_estimate - EXACT_VAL);
            file << i << "," << current_estimate << "," << EXACT_VAL << "," << error << "\n";
        }
    }

    file.close();

    double final_estimate = (2.0 / TOTAL_SAMPLES) * sum_fx;
    std::cout << std::fixed << std::setprecision(8);
    std::cout << "Final Estimated Value : " << final_estimate << "\n";
    std::cout << "Exact Value (pi)       : " << EXACT_VAL << "\n";
    std::cout << "Absolute Error        : " << std::abs(final_estimate - EXACT_VAL) << "\n";

    return 0;
}