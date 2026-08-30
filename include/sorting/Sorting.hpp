#pragma once

#include <vector>
#include <algorithm>

class BubbleSort {
private:

public:
    static int sort(std::vector<int>& data);
};

class InsertionSort {
private:
public:
    static int sort(std::vector<int>& data);
    static int sort(std::vector<int>& data, int start, int end);
};


enum class PartitionScheme {
    LOMUTO,
    HOARE,
    MEDIAN_OF_THREE,
    RANDOMIZED
};


class QuickSort {
private:
    static int comparison;
    static void sorting(std::vector<int>& data, int start, int end, PartitionScheme scheme);

public:
    static int lomutoPartition(std::vector<int>& data, int start, int end);

    static int hoarePartition(std::vector<int>& data, int start, int end);

    static int median_of_three(std::vector<int>& data, int start, int end);

    static int sort(std::vector<int>& data, PartitionScheme scheme);


    static void reset_comparison() {
        comparison = 0;
    }

    static int get_comparison() {
        return comparison;
    }

};