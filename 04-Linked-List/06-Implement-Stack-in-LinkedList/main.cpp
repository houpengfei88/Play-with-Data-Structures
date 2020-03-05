#include <iostream>
#include "LinkedListStack.h"
#include "Solution.h"

int main() {
    LinkedListStack<int> *linkedListStack = new LinkedListStack<int>();
    for (int i = 0; i < 5; ++i) {
        linkedListStack->push(i);
        linkedListStack->print();
    }
    std::cout << linkedListStack->pop() << std::endl;
    linkedListStack->print();
    std::cout << std::boolalpha << Solution().isValid("(){}[]") << std::endl;
    std::cout << std::boolalpha << Solution().isValid("([)]") << std::endl;
    linkedListStack = nullptr;
    delete linkedListStack;
    return 0;
}
