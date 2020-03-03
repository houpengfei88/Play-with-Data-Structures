#include <iostream>
#include "ListNode.h"
#include "Solution.h"

int main() {
    int nums[] = {1,2,6,4,5,6};
    ListNode<int> *head = new ListNode<int>(nums, 6);
    head->print();
    ListNode<int> *res = Solution<int>().removeElements(head, 6, 0);
    res->print();
    return 0;
}
