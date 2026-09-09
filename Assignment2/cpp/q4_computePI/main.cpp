
#include <fstream>
#include <iostream>
#include <cmath>
#include <random>

// Compute P using randomized algorithm using Monte Carlo method

class ComputePI {
    private:
        std::size_t numPoints;
        std::size_t pointsInsideCircle;

    public:
        ComputePI(std::size_t numPoints) : numPoints(numPoints), pointsInsideCircle(0) {}

        void runSimulation() {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(0.0, 1.0);

            std::fstream file("Assignment2/cpp/q4_computePI/monte_carlo_output.csv", std::ios::out);
            if(!file.is_open()) {
                std::cerr << "Error opening output file." << std::endl;
                return;
            }

            file << "Point Index, X Coordinate, Y Coordinate, EstimatePI\n";

            for (std::size_t i = 0; i < numPoints; ++i) {
                double x = dis(gen);
                double y = dis(gen);
                if (x * x + y * y <= 1.0) {
                    ++pointsInsideCircle;
                    double currentEstimatePI = getEstimatedPI(i+1);
                    file << i + 1 << ", (" << x << ", " << y << ") , " << currentEstimatePI << "\n";
                }

                
            }
        }

        double getEstimatedPI(std::size_t pointsCount) const {
            return 4.0 * static_cast<double>(pointsInsideCircle) / static_cast<double>(pointsCount);
        }
};



int main() {

    const double EXACT_PI = 3.14159265358979323846;
    const std::size_t NUM_POINTS = 1e5; // Number of random points to generate

    ComputePI computePI(NUM_POINTS);

    computePI.runSimulation();
    double estimatedPI = computePI.getEstimatedPI(NUM_POINTS);

    std::cout << "Estimated PI: " << estimatedPI << std::endl;
    std::cout << "Exact PI: " << EXACT_PI << std::endl;
    std::cout << "Error: " << std::abs(estimatedPI - EXACT_PI) << std::endl;
}