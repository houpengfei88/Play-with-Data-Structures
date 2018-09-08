#include <iostream>
#include "Solution.h"

int main() {
    std::cout << std::boolalpha << Solution().isValid("(){}[]") << std::endl;
    std::cout << std::boolalpha << Solution().isValid("([)]") << std::endl;
    return 0;
}
