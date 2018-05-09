template<class T>
class Solution {
public:
    ListNode<T>* removeElements(ListNode<T>* head, int val) {
        while(head != nullptr && head->val == val) {
            ListNode<T> *delNode = head;
            head = head->next;
            delNode->next = nullptr;
        }
        
        if(head == nullptr) {
            return head;
        }
        
        ListNode<T> *prev = head;
        while(prev->next != nullptr) {
            if(prev->next->val == val) {
                ListNode<T> *delNode = prev->next;
                prev->next = delNode->next;
                delNode->next == nullptr;
            } else {
                prev = prev->next;
            }
        }
        return head;
    }
};
