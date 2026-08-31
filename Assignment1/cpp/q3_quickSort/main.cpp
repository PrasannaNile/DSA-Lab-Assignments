#include "generation/RandomInputGenerator.hpp"
#include "sorting/Sorting.hpp"

#include <vector>
#include <fstream>
#include <iostream>


class HybridSort{
private:
    static constexpr int CUTOFF = 12;
    static long long comparisons;

    static int lomutoPartition(
    std::vector<int>& data,
    int start,
    int end
    ) {

        int pivot = data[end];

        int left = start - 1;

        for (int right = start; right < end; right++) {


            comparisons++;

            if (data[right] < pivot) {

                left++;

                std::swap(data[left], data[right]);
            }
        }

        std::swap(data[left + 1], data[end]);

        return left + 1;
    }

    static void hybridSort(
        std:: vector<int>& data,
        int start,
        int end
    ){
        if (start >= end) 
            return;

        int size = end - start + 1;

        // small problem -> insertion sort
        if(size <= CUTOFF){
            comparisons += InsertionSort::sort(data,start,end);
            return;
        }

        int p = lomutoPartition(data,start,end);

        hybridSort(data, start, p-1);
        hybridSort(data, p+1,end);

    }

    public: 
        static void sort(std::vector<int>& data){
            if(data.empty())
                return;
            
            hybridSort(data,0,data.size()-1);
        }

        static void resetComparisons()
        {
            comparisons = 0;
        }


        static long long getComparisons()
        {
            return comparisons;
        }
            


};

long long HybridSort::comparisons {};




int main() {
    RandomInputGenerator generator {};

    InsertionSort isort;
    QuickSort qsort;

    std::fstream file("Assignment1/cpp/q3_quickSort/q3_InsertQuickUnsortedComparison.csv", std::ios::in | std::ios::out | std::ios::trunc);
    if(!file.is_open()) throw std::runtime_error("File cannot be open or cannot be recreate");

    file << "Datasize,InsertionComparison,QuickComparison\n";

    for(int datasize = 10; datasize <= 1000; datasize++) {
        std::vector<int> data1 = generator.generateInput(datasize, 1, 10000, InputType::HIGHLY_INVERSIONAL);
        std::vector<int> data2 = data1;
        int insertionComparison = isort.sort(data1);

        int quickComparison = qsort.sort(data2, PartitionScheme::HOARE);

        file << datasize << "," << insertionComparison << "," << quickComparison << "\n";
    }

    file.close();

    std::fstream file2("Assignment1/cpp/q3_quickSort/q3_InsertHybridQuickComparison.csv", std::ios::in | std::ios::out | std::ios::trunc);
    if(!file2.is_open()) throw std::runtime_error("File not opened!!");

    file2<< "InputSize, Comp(QSort), Comp(HQSort)" << "\n";
    for(int datasize = 100; datasize <= 400; datasize++){
        std::vector<int> qSortData = generator.generateInput(datasize, 1, 9999,InputType::HIGHLY_INVERSIONAL,SortOrder::ASCENDING, 0.75);
        std::vector<int> hybridData = qSortData;

        int qSortComparison = QuickSort::sort(qSortData, PartitionScheme::LOMUTO);

        HybridSort::sort(hybridData);
        int hSortComparison = HybridSort::getComparisons();
        HybridSort::resetComparisons();
        file2<< datasize << ", " << qSortComparison << ", " << hSortComparison << "\n";
    }

    file2.close();


    return 0;
}