#include <iostream>
#include "MaxHeap.h"
#include <cassert>

template<typename T>
double testHeap(T testData[], int n, bool isHeapify) {
    clock_t startTime = clock();
    MaxHeap<T> *maxHeap;
    if (isHeapify) {
        maxHeap = new MaxHeap<T>(testData, n);
    } else {
        maxHeap = new MaxHeap<T>();
        for (int i = 0; i < n; ++i) {
            maxHeap->add(testData[i]);
        }
    }

    T *arr = new T[n];
    for (int j = 0; j < n; ++j) {
        arr[j] = maxHeap->extractMax();
    }

    for (int k = 1; k < n; ++k) {
        assert(arr[k - 1] >= arr[k]);
    }
    std::cout << "Test MaxHeap completed." << std::endl;
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}

int main() {
    int n = 10000000;
    int *testData = new int[n];
    for (int i = 0; i < n; ++i) {
        testData[i] = rand() % INT32_MAX;
    }
    double time1 = testHeap(testData, n, false);
    std::cout << "Without heapify :" << time1 << " s " << std::endl;
    double time2 = testHeap(testData, n, true);
    std::cout << "With heapify :" << time2 << " s " << std::endl;
    return 0;
}
