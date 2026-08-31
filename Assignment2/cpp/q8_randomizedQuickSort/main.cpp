#include "generation/RandomInputGenerator.hpp"
#include "sorting/Sorting.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>


class RandomisedQuickSort {
private:
    static int comparison;

    static int hoare(std::vector<int>& data, int start, int end) {
        std::random_device rd {};
        std::mt19937 gen (rd());
        std::uniform_int_distribution<int> distrib(start, end-1); // to make sure that it is not loop infinitely

        int pivot = data[distrib(gen)];

        int left = start-1;
        int right = end+1;

        while(true) {
            do {
                left++;
                comparison++;
            } while(data[left] < pivot);

            do {
                right--;
                comparison++;
            } while(data[right] > pivot);

            if(left >= right) return right;

            std::swap(data[left], data[right]);
        }

        return right;

    }


    static void sorting(std::vector<int>& data, int start, int end) {
        if(start >= end) return;

        int p = hoare(data, start, end);
        sorting(data, start, p);
        sorting(data, p+1, end);
    }

public:

    static int sort(std::vector<int>& data) {
        reset_comparison();
        sorting(data, 0, data.size()-1);
        return comparison;
    }

    static void reset_comparison() {
        comparison = 0;
    }

    static int get_comparison() {
        return comparison;
    }

};

int RandomisedQuickSort::comparison {};


int main() {
    RandomInputGenerator generator {};

    // highly inversional data set
    std::fstream file("Assignment2/cpp/q8_randomizedQuickSort/q8_RandQuickVSQuickUnsorted.csv", std::ios::in | std::ios::out | std::ios::trunc);
    if(!file.is_open()) throw std::runtime_error("File does not exist or cannot be open");

    file << "Datasize,RandQuickComp,QuickComp\n";

    int MAX_SIZE = 1e3;
    int TRAILS = 30;

    for(int datasize = 1; datasize <= MAX_SIZE; datasize++) {
        int total_comp_randquick = 0;
        int total_comp_quick = 0;

        for(int t = 1; t <= TRAILS; t++) {
            std::vector<int> data1 = generator.generateInput(datasize, 1, 1e3, InputType::HIGHLY_INVERSIONAL);
            std::vector<int> data2 = data1;

            total_comp_randquick += RandomisedQuickSort::sort(data1);
            total_comp_quick += QuickSort::sort(data2, PartitionScheme::LOMUTO);
        }

        file << datasize << "," << total_comp_randquick / TRAILS << "," << total_comp_quick / TRAILS << "\n";
    }

    // sorted data set

    std::fstream file2("Assignment2/cpp/q8_randomizedQuickSort/q8_RandQuickVSQuickSorted.csv", std::ios::in | std::ios::out | std::ios::trunc);
    if(!file2.is_open()) throw std::runtime_error("File does not exist or cannot be open");

    file2 << "Datasize,RandQuickComp,QuickComp\n";

    for(int datasize = 1; datasize <= MAX_SIZE; datasize++) {
        int total_comp_randquick = 0;
        int total_comp_quick = 0;

        for(int t = 1; t <= TRAILS; t++) {
            std::vector<int> data1 = generator.generateInput(datasize, 1, 1e3, InputType::SORTED);
            std::vector<int> data2 = data1;

            total_comp_randquick += RandomisedQuickSort::sort(data1);
            total_comp_quick += QuickSort::sort(data2, PartitionScheme::LOMUTO);
        }

        file2 << datasize << "," << total_comp_randquick / TRAILS << "," << total_comp_quick / TRAILS << "\n";
    }

    return 0;
}