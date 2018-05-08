//
// Created by hpf on 18-5-8.
//

#include <string>
#include "ArrayStack.h"

class Solution {
public:
    bool isValid(std::string s) {
        ArrayStack<char> *stack = new ArrayStack<char>();
        for (int i = 0; i < s.size(); ++i) {
            char c = s.at(i);
            if (c == '(' || c == '[' || c == '{') {
                stack->push(c);
            } else {
                if (stack->isEmpty()) {
                    return false;
                }
                char topChar = stack->pop();
                if (c == ')' && topChar != '(') {
                    return false;
                }
                if (c == ']' && topChar != '[') {
                    return false;
                }
                if (c == '}' && topChar != '{') {
                    return false;
                }
            }
        }
        return stack->isEmpty();
    }
};
