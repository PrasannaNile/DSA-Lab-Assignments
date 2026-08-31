#include "generation/RandomInputGenerator.hpp"
#include <sorting/Sorting.hpp>


#include <iostream>
#include <algorithm>
#include <fstream>


int bubbleSortWithoutEarlyExist(std::vector<int>& data) {
    int n = data.size();
    int comparison = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= n-i; j++) {

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


    // data is really distored from its original place (0.8)
    std::fstream file("Assignment1/cpp/q2_bubbleSort/q2_comparisonHighlyRandom.csv", std::ios::out | std::ios::in | std::ios::trunc);
    if(!file.is_open()) throw std::runtime_error("File cannot be opened");

    file << "InputSize,Comp(optimised),Comp(non optimised)\n";

    int comparison_of_with_early_exist = 0;
    int comparison_of_without_early_exist = 0;

    for(int datasize = 1; datasize <= 100; datasize++) {
        std::vector<int> data1 = generator.generateInput(datasize, 1, 1000, InputType::HIGHLY_INVERSIONAL);
        std::vector<int> data2 = data1;
        comparison_of_with_early_exist = bWithEarlyExist.sort(data1);
        
        comparison_of_without_early_exist = bubbleSortWithoutEarlyExist(data2);

        file << datasize << "," << comparison_of_with_early_exist << "," << comparison_of_without_early_exist <<"\n";
    }

    file.close();

    // data is sorted 
    file.open("Assignment1/cpp/q2_bubbleSort/q2_comparisonAlreadySorted.csv", std::ios::out | std::ios::in | std::ios::trunc);
    if(!file.is_open()) throw std::runtime_error("File cannot be open or recreate");

    file << "InputSize,Comp(optimised),Comp(non optimised)\n";

    comparison_of_with_early_exist = 0;
    comparison_of_without_early_exist = 0;

    for(int datasize = 1; datasize <= 100; datasize++) {
        std::vector<int> data = generator.generateInput(datasize, 1, 1000, InputType::SORTED);
        comparison_of_with_early_exist = bWithEarlyExist.sort(data);
        comparison_of_without_early_exist = bubbleSortWithoutEarlyExist(data);

        file << datasize << "," << comparison_of_with_early_exist << "," << comparison_of_without_early_exist <<"\n";

    }

    file.close();

    // data is nearly sorted 
    file.open("Assignment1/cpp/q2_bubbleSort/q2_comparisonNearlySorted.csv", std::ios::out | std::ios::in | std::ios::trunc);
    if(!file.is_open()) throw std::runtime_error("File cannot be open or recreate");

    file << "InputSize,Comp(optimised),Comp(non optimised)\n";

    comparison_of_with_early_exist = 0;
    comparison_of_without_early_exist = 0;

    for(int datasize = 1; datasize <= 100; datasize++) {
        std::vector<int> data1 = generator.generateInput(datasize, 1, 1000, InputType::NEARLY_SORTED);
        std::vector<int> data2 = data1;
        comparison_of_with_early_exist = bWithEarlyExist.sort(data1);
        comparison_of_without_early_exist = bubbleSortWithoutEarlyExist(data2);

        file << datasize << "," << comparison_of_with_early_exist << "," << comparison_of_without_early_exist <<"\n";

    }

    return 0;
}
