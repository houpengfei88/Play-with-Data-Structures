#include <iostream>
#include "BST.h"

int main() {
    BST<int> bst;
    int nums[] = {5, 3, 6, 8, 4, 2};
    for (int num : nums) {
        bst.add(num);
    }
    bst.preOrder();
    bst.print();
    return 0;
}
