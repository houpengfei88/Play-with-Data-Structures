#include <iostream>
#include "ListNode.h"
#include "Solution1.h"
#include "Solution2.h"
#include "Solution3.h"

int main() {
    int nums[] = {1,2,6,4,5,6};
    ListNode<int> *head = new ListNode<int>(nums, 6);
    head->print();
    ListNode<int> *res = Solution1<int>().removeElements(head, 6);
    res->print();
    ListNode<int> *head2 = new ListNode<int>(nums, 6);
    head2->print();
    ListNode<int> *res2 = Solution2<int>().removeElements(head, 6);
    res2->print();
    ListNode<int> *head3 = new ListNode<int>(nums, 6);
    head3->print();
    ListNode<int> *res3 = Solution3<int>().removeElements(head, 6);
    res3->print();
    return 0;
}
