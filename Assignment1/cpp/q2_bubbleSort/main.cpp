#include "generation/RandomInputGenerator.hpp"
#include <sorting/Sorting.hpp>


#include <iostream>
#include <algorithm>
#include <fstream>


int bubbleSortWithoutEarlyExist(std::vector<int>& data) {
    int n = data.size();
    int comparison = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n-i; j++) {

            comparison++;
            if(data[j] < data[j-1]) {
                std::swap(data[j], data[j-1]);
            }
        }
    }

    return comparison;
}


int main() {
    RandomInputGenerator generator;
    BubbleSort bWithEarlyExist {}; 

    std::fstream file("comparisonHighlyRandom.csv", std::ios::out | std::ios::in | std::ios::trunc);
    if(!file.is_open()) throw std::runtime_error("File cannot be opened");

    file << "InputSize,Comp(optimised),Comp(non optimised)\n";

    int comparison_of_with_early_exist = 0;
    int comparison_of_without_early_exist = 0;

    for(int datasize = 1; datasize <= 100; datasize++) {
        std::vector<int> data = generator.generateInput(datasize, 1, 1000, InputType::HIGHLY_INVERSIONAL);
        comparison_of_with_early_exist = bWithEarlyExist.sort(data);
        comparison_of_without_early_exist = bubbleSortWithoutEarlyExist(data);

        file << datasize << "," << comparison_of_with_early_exist << "," << comparison_of_without_early_exist <<"\n";
    }


    return 0;
}
