#include <iostream>

template<typename T>
class ListNode {
public:
    T val;
    ListNode<T> *next;
    ListNode(T x) {
        val = x;
    }
};
