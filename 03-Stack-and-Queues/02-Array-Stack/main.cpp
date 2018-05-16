#include <iostream>
#include "ArrayStack.h"

int main() {
    ArrayStack<int> *stack = new ArrayStack<int>();
    for(int i = 0; i < 5; ++i) {
		stack->push(i);
		stack->print();
    }
    std::cout << stack->pop() << std::endl;
    stack->print();
    return 0;
}
