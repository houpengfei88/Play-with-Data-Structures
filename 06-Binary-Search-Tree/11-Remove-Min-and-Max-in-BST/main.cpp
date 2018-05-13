#include <iostream>
#include "BST.h"
#include "Array.h"

int main() {
    BST<int> bst;
    int n = 1000;
    for (int i = 0; i < n; ++i) {
        bst.add(rand() % 10000);
    }
    Array<int> *nums = new Array<int>();
    int index = 0;
    while (!bst.isEmpty()) {
	nums->add(index,bst.removeMin());
	index++;
    }
    nums->print();
    for(int i = 1; i < nums->getSize(); ++i) {
	if(nums->get(i-1) > nums->get(i)){
	    std::cout << "error";
	    return -1;	
	}
    }
    std::cout << "removeMin test completed." << std::endl;
    delete[] nums;
    for (int i = 0; i < n; ++i) {
        bst.add(rand() % 10000);
    }
    nums = new Array<int>();
    index = 0;
    while (!bst.isEmpty()) {
	nums->add(index,bst.removeMax());
	index++;
    }
    nums->print();
    for(int i = 1; i < nums->getSize(); ++i) {
	if(nums->get(i-1) < nums->get(i)){
	    std::cout << "error" << std::endl;
	    return -1;	
	}
    }
    std::cout << "removeMax test completed." << std::endl;
    return 0;
}
