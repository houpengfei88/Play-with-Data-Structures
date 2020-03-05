//
// Created by hpf on 18-5-9.
//

#include <iostream>
#include <cassert>

template<typename T>
class ListNode {
public:
    T val;
    ListNode *next;

    ListNode(T x) {
        val = x;
    }

    ListNode(T arr[], int n) {
        assert(arr != nullptr && n != 0);
        val = arr[0];
        ListNode<T> *cur = this;
        for (int i = 1; i < n; i++) {
            cur->next = new ListNode<T>(arr[i]);
            cur = cur->next;
        }
    }

    void print() {
        ListNode<T> *cur = this;
        while(cur != nullptr) {
            std::cout << cur->val << "->";
            cur = cur->next;
        }
        std::cout << "NULL" <<std::endl;
    }
};
