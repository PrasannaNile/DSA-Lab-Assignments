#include <iostream>
#include <random>
#include <fstream>
#include <cmath>

// Write a program that test a number to be prime or not. 
// Perform an analysis to compute the correctness?


class PrimalityTesting {
private:
    static int num;

    static long long power(int base, int exp, int mod) {
        long long res = 1;

        while(exp > 0) {
            if(exp % 2 == 1) res = (__int128_t) res * base % mod;
            base = (__int128_t) base * base % mod;
            exp /= 2;
        }
        return res;
    }

public:

    static bool is_prime(int trails = 30) {
        if(num <= 1) return false;
        if(num <= 3) return true;
        if(num % 2 == 0) return false;

        std::random_device rd {};
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(2, num-1);

        for(int t = 1; t <= trails; t++) {
            int a = distrib(gen);

            if(power(a, num-1, num) != 1) return false; 
            
        }

        return true;
    }

    static void set_num(int n) {
        num = n;
    }

    static void empirical_error_prob() {
        std::fstream file("Assignment2/cpp/q6_primalityTesting/primality_error.csv", std::ios::out | std::ios::trunc);
        if(!file.is_open()) throw std::runtime_error("File cannot be open or does not exist");

        file << "Trials,EmpiricalErrorRate,TheoreticalBound\n";

        // n = 91 is composite (7 * 13) with Fermat liars like 9, 16, 22, 29...
        const long long COMPOSITE_TEST = 91;
        const int RUNS_PER_TRIAL = 1e4;
        const int MAX_TRIALS = 15;

        for(int t = 1; t <= MAX_TRIALS; t++) {
            int false_count = 0;

            for(int run = 1; run <= RUNS_PER_TRIAL; run++) {
                if(is_prime(t)) false_count ++; 
            }

            double empirical_error = static_cast<double> (false_count) / RUNS_PER_TRIAL;
            double theoretical_bound = std::pow(0.5, t);

            file << t << "," << empirical_error << "," << theoretical_bound << "\n";
        }

    }
};

int PrimalityTesting::num { 2 };





int main() {

    int num { 2 };
    std::cout << "Enter an positive integer: ";
    std::cin >> num;



    PrimalityTesting::set_num(num);
    PrimalityTesting::empirical_error_prob();

    int epoch = 1e3;

    if(PrimalityTesting::is_prime(epoch)) std::cout << num << " is a prime number\n";
    else std::cout << num << " is not a prime number....\n";
    return 0;
}