//
// Created by hpf on 18-5-9.
//

#include <iostream>

template<class T>
class ListNode {
public:
    class Empty {
    };

    T val;
    ListNode *next;

    ListNode(T x) {
        val = x;
    }

    ListNode(T arr[], int n) {
        if (arr == nullptr || n == 0) {
            throw Empty();
        }
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
