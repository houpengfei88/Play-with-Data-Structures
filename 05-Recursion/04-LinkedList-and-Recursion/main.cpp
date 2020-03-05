#include <iostream>
#include "ListNode.h"
#include "Solution1.h"
#include "Solution2.h"
#include "Solution3.h"
#include "Solution4.h"
#include "Solution5.h"
#include "Sum.h"

int main() {
    int nums[] = {1,2,6,4,5,6};
    ListNode<int> *head1 = new ListNode<int>(nums,6);
    head1->print();
    ListNode<int> *res1 = Solution1<int>().removeElements(head1,6);
    res1->print();
    ListNode<int> *head2 = new ListNode<int>(nums,6);
    head2->print();
    ListNode<int> *res2 = Solution2<int>().removeElements(head2,6);
    res2->print();
    ListNode<int> *head3 = new ListNode<int>(nums,6);
    head3->print();
    ListNode<int> *res3 = Solution3<int>().removeElements(head3,6);
    res3->print();
    ListNode<int> *head4 = new ListNode<int>(nums,6);
    head4->print();
    ListNode<int> *res4 = Solution4<int>().removeElements(head4,6);
    res4->print();
    ListNode<int> *head5 = new ListNode<int>(nums,6);
    head5->print();
    ListNode<int> *res5 = Solution5<int>().removeElements(head5,6);
    res5->print();
    int num[9] = {1,2,3,4,5,6,7,8,9};
    std::cout << "sum: " << Sum<int>().sum(num,9) << std::endl;
    float num1[9] = {1.2,2.3,3.4,4.5,5.6,6.7,7.8,8.9,9.1};
    std::cout << "sum: " << Sum<float>().sum(num1,9) << std::endl;
    head1 = head2 = head3 = head4 = head5 = nullptr;
    res1 = res2 = res3 = res4 = res5 = nullptr;
    delete head1;
    delete head2;
    delete head3;
    delete head4;
    delete head5;
    delete res1;
    delete res2;
    delete res3;
    delete res4;
    delete res5;
    return 0;
}
