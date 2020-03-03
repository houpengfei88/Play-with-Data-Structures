#include <iostream>
#include "BST.h"
#include <ctime>

template<typename T>
void shuffle(T arr[], int n) {
    srand(time(0));
    for (int i = n - 1; i >= 0; i--) {
        int pos = (int) (rand() % n);
        T t = arr[pos];
        arr[pos] = arr[i];
        arr[i] = t;
    }
}

int main() {
    BST<int> bst;
    int n = 100;
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        bst.add(rand() % 100);
    }
    int *order = new int[n];
    for (int j = 0; j < n; ++j) {
        order[j] = j;
    }
    shuffle(order, n);
    std::cout << "size = " << bst.getSize() << std::endl;
    for (int k = 0; k < n; ++k) {
        if (bst.contains(order[k])){
            bst.remove(order[k]);
            std::cout << "After remove " << order[k] << ", size = " << bst.getSize() << std::endl;
        }
    }
    return 0;
}
