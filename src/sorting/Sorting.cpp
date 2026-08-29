#include "sorting/Sorting.hpp"


int BubbleSort::sort(std::vector<int>& data) {
    size_t n = data.size();
    int comparison = 0;
    for(int i = 1; i < n; i++) {

        bool swapped = false;

        for(int j = 1; j <= n-i; j++) {
            comparison ++;
            if(data[j] < data[j-1]) {
                swapped = true;
                std::swap(data[j], data[j-1]);
            }
        }

        if(swapped == false) {
            break;
        }
    }

    return comparison;
}


int InsertionSort::sort(std::vector<int>& data) {
    size_t n = data.size();
    int comparison = 0;
    for(int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;

        while(j >= 0 && data[j] > key) {
            comparison++;
            data[j + 1] = data[j];
            j--;
        }
        comparison++;
        data[j + 1] = key;
    }

    return comparison;
}

int InsertionSort::sort(std::vector<int>& data, int start, int end) {
    int comparison = 0;

    for(int i = start+1; i <= end; i++) {
        int val = data[i];
        int j = i-1;

        while(j >= start && data[j] > val) {
            data[j+1] = data[j];
            j--;
            comparison++;
        }

        data[j+1] = val;
    }

    return comparison;
}


int QuickSort::comparison = 0;

int QuickSort::lomutoPartition(std::vector<int>& data, int start, int end) {
    int pivot = data[end];

    int left = start-1;
    
    for(int right = start; right < end; right++) {
        comparison++;
        if(data[right] < pivot) {
            left++;
            std::swap(data[left], data[right]);
        }
    }

    std::swap(data[left+1], data[end]);

    return left+1;
}

int QuickSort::hoarePartition(std::vector<int>& data, int start, int end) {
    int pivot = data[start + ((end - start) >> 1)];

    int left = start - 1;
    int right = end + 1;

    while(true) {
        do {
            comparison++;
            left++;
        } while(data[left] < pivot);

        do {
            comparison++;
            right--;
        } while(data[right] > pivot);

        if(left >= right) return right;

        std::swap(data[left], data[right]);
    }

    return right;
}

int QuickSort::median_of_three(std::vector<int>& data, int start, int end) {
    int a = data[start];
    int b = data[end];
    int c = data[start + ((end - start) >> 1)];

    int pivot = c;

    if((a <= b && b <= c) || (c <= b && b <= a)) pivot = b;
    else if((b <= a && a <= c) || (c <= a) && a <= b) pivot = a;

    int left = start - 1;
    int right = end + 1;

    while(true) {
        do {
            comparison++;
            left++;
        } while(data[left] < pivot);

        do {
            comparison++;
            right--;
        } while(data[right] > pivot);

        if(left >= right) return right;

        std::swap(data[left], data[right]);
    }

    return right;
}


void QuickSort::sorting(std::vector<int>& data, int start, int end, PartitionScheme scheme) {
    if(start >= end) return;

    int p = 0;

    switch(scheme) {
        case PartitionScheme::LOMUTO:
            p = lomutoPartition(data, start, end);
            sorting(data, start, p-1, scheme);
            sorting(data, p+1, end, scheme);
            break;

        case PartitionScheme::HOARE:
            p = hoarePartition(data, start, end);
            sorting(data, start, p, scheme);
            sorting(data, p+1, end, scheme);
            break;

    }

}


int QuickSort::sort(std::vector<int>& data, PartitionScheme scheme) {
    reset_comparison();
    sorting(data, 0, data.size()-1, scheme);
    return comparison;
}