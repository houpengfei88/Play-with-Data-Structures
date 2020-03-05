// Leetcode 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/description/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != nullptr && head->val == val) {
            ListNode *delNode = head;
            head = head->next;
            delNode->next = nullptr;
            delNode = nullptr;
            delete delNode;
        }
        
        if(head == nullptr) {
            return head;
        }
        
        ListNode *prev = head;
        while(prev->next != nullptr) {
            if(prev->next->val == val) {
                ListNode *delNode = prev->next;
                prev->next = delNode->next;
                delNode->next == nullptr;
                delNode = nullptr;
                delete delNode;
            } else {
                prev = prev->next;
            }
        }
        prev = nullptr;
        delete prev;
        return head;
    }
};
