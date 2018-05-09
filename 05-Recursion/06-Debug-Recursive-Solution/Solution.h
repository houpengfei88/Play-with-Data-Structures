template<class T>
class Solution {
public:
    ListNode<T> *removeElements(ListNode<T> *head, int val, int depth) {
        print(depth);
        std::cout << "Call: remove " << val << " in " ;
        head->print();

        if (head == nullptr) {
            print(depth);
            std::cout << "Return: ";
            head->print();
            return head;
        }
        ListNode<T> *res = removeElements(head->next, val, depth + 1);
        print(depth);
        std::cout << "After remove " << val << ":" ;
        res->print();
        ListNode<T> *ret;
        if (head->val == val) {
            ret = res;
        } else {
            head->next = res;
            ret = head;
        }
        print(depth);
        std::cout << "Return:";
        ret->print();
        return ret;
    }

    void print(int depth) {
        for (int i = 0; i < depth; ++i) {
            std::cout << "--";
        }
    }
};
