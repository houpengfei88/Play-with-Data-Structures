#include <iostream>
#include "BST.h"
#include "Array.h"

int main () {
    BST<int> bst;
    int n = 1000;
    for (int i = 0; i < n; ++i) {
        bst.add(rand() % 10000);
    }

    Array<int> *nums = new Array<int>();
    int index = 0;
    std::cout << "Before deleting the minimum BST size : " << bst.getSize() << std::endl;
    while (!bst.isEmpty()) {
        nums->add(index, bst.removeMin());
        index++;
    }
    std::cout << "After removing the minimum BST size : " << bst.getSize() << std::endl;
    nums->print();
    for(int i = 1; i < nums->getSize(); ++i) {
      if(nums->get(i-1) > nums->get(i)) {
          std::cout << "error";
          return -1;	
      }
    }
    std::cout << "Remove Min test completed." << std::endl;
    nums = nullptr;

    for (int i = 0; i < n; ++i) {
        bst.add(rand() % 10000);
    }
    nums = new Array<int>();
    std::cout << "Before deleting the maximum BST size : " << bst.getSize() << std::endl;
    index = 0;
    while (!bst.isEmpty()) {
		nums->add(index, bst.removeMax());
		index++;
    }
    std::cout << "After removing the maximum BST size : " << bst.getSize() << std::endl;
    nums->print();
    for(int i = 1; i < nums->getSize(); ++i) {
        if(nums->get(i-1) < nums->get(i)) {
            std::cout << "error" << std::endl;
            return -1;	
        }
    }
    nums = nullptr;
    delete nums;
    std::cout << "Remove Max test completed." << std::endl;
    return 0;
}