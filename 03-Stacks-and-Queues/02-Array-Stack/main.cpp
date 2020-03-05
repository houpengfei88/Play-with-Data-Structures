#include <iostream>
#include "ArrayStack.h"

int main() {
    ArrayStack<int> *arrayStack = new ArrayStack<int>();
    for(int i = 0; i < 5; ++i) {
	    arrayStack->push(i);
	    arrayStack->print();
    }
    std::cout << arrayStack->pop() << std::endl;
    arrayStack->print();
    arrayStack = nullptr;
    delete arrayStack;
    return 0;
}
