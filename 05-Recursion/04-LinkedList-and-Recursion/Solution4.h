template<typename T>
class Solution4 {
public:
    ListNode<T>* removeElements(ListNode<T>* head, int val) {
        if (head == nullptr) {
	    	return head;
		}

    	ListNode<T> *res = removeElements(head->next, val);
    	if (head->val == val) {
	    	return res;
		} else {
	    	head->next = res;
	    	return head;
		}
    }
};
