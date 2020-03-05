// Leetcode 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/description/

class Solution3 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyHead = new ListNode(-1);
		dummyHead->next = head;
        ListNode *prev = dummyHead;
        while(prev->next != nullptr) {
            if(prev->next->val == val) {
                prev->next = prev->next->next;
            } else {
                prev = prev->next;
            }
        }
        prev = nullptr;
        delete prev;
        return dummyHead->next;
    }
};
