template<typename T>
class Solution5 {
public:
    ListNode<T>* removeElements(ListNode<T>* head, int val) {
        if (head == nullptr) {
	    	return head;
		}
        head->next = removeElements(head->next, val);
		return head->val == val ? head->next : head;
    }
};
