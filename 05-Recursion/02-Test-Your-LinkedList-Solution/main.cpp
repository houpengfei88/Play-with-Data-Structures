#include <iostream>
#include "ListNode.h"
#include "Solution1.h"
#include "Solution2.h"
#include "Solution3.h"

int main() {
    int nums[] = {1,2,6,4,5,6};
    ListNode<int> *head1 = new ListNode<int>(nums, 6);
    head1->print();
    ListNode<int> *res1 = Solution1<int>().removeElements(head1, 6);
    res1->print();
    ListNode<int> *head2 = new ListNode<int>(nums, 6);
    head2->print();
    ListNode<int> *res2 = Solution2<int>().removeElements(head2, 6);
    res2->print();
    ListNode<int> *head3 = new ListNode<int>(nums, 6);
    head3->print();
    ListNode<int> *res3 = Solution3<int>().removeElements(head3, 6);
    res3->print();
    head1 = head2 = head3 = nullptr;
    res1 = res2 = res3 = nullptr;
    delete head1;
    delete head2;
    delete head3;
    delete res1;
    delete res2;
    delete res3;
    return 0;
}
