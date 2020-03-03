#include <iostream>
#include "MaxHeap.h"
#include <cassert>

int main() {
    int n = 1000000;
    MaxHeap<int> *maxHeap = new MaxHeap<int>();
    for (int i = 0; i < n; ++i) {
        maxHeap->add(rand() % INT32_MAX);
    }
    int *arr = new int[n];
    for (int j = 0; j < n; ++j) {
        arr[j] = maxHeap->extractMax();
    }

    for (int k = 1; k < n; ++k) {
        assert(arr[k-1] >= arr[k]);
    }
    std::cout << "Test MaxHeap completed." << std::endl;
    return 0;
}
