#include <iostream>
#include "BST.h"

int main() {
    BST<int> bst;
    int nums[] = {5, 3, 6, 8, 4, 2};
    for (int num : nums) {
        bst.add(num);
    }
    std::cout << "preorder:" << std::endl;
    bst.preOrder();
    std::cout << "inorder:" << std::endl;
    bst.inOrder();
    std::cout << "postorder:" << std::endl;
    bst.postOrder();
    bst.print();
    return 0;
}
