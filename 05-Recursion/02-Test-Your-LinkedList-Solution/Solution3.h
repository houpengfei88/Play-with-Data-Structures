template<typename T>
class Solution3 {
public:
    ListNode<T>* removeElements(ListNode<T>* head, int val) {
        ListNode<T> *dummyHead = new ListNode<T>(-1);
	 	dummyHead->next = head;
        ListNode<T> *prev = dummyHead;
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
