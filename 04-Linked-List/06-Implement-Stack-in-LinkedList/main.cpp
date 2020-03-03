#include <iostream>
#include "LinkedListStack.h"
#include "Solution.h"

int main() {
    LinkedListStack<int> *stack = new LinkedListStack<int>();
    for (int i = 0; i < 5; ++i) {
		stack->push(i);
		stack->print();
    }
    std::cout << stack->pop() << std::endl;
    stack->print();
    std::cout << std::boolalpha << Solution().isValid("(){}[]") << std::endl;
    std::cout << std::boolalpha << Solution().isValid("([)]") << std::endl;
    return 0;
}
