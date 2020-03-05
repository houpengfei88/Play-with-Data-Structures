template<typename T>
class Solution1 {
public:
    ListNode<T>* removeElements(ListNode<T>* head, int val) {
        while(head != nullptr && head->val == val) {
            ListNode<T> *delNode = head;
            head = head->next;
            delNode->next = nullptr;
            delNode = nullptr;
            delete delNode;
        }
        
        if(head == nullptr) {
            return head;
        }
        
        ListNode<T> *prev = head;
        while(prev->next != nullptr) {
            if(prev->next->val == val) {
                ListNode<T> *delNode = prev->next;
                prev->next = delNode->next;
                delNode->next = nullptr;
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
