//
// Created by hpf on 18-5-14.
//

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        LinkedListSet<int> *set1 = new LinkedListSet<int>();
        for (int num : nums1) {
            set1->add(num);
        }
        std::cout << std::endl;
        vector<int> list;
        for (int num : nums2) {
            if (set1->contains(num)) {
                list.push_back(num);
                set1->remove(num);
            }
        }
        return list;
    }

private:
    template<class T>
    class Set {
        void add(T e);

        void remove(T e);

        bool contains(T e);

        int getSize();

        bool isEmpty();
    };
    
    template<class T>
    class Node {
    public:
        T e;
        Node *next;

        Node(T e, Node *next) : e(e), next(next) {
        }

        Node(T e) : e(e), next(nullptr) {
        }

        Node() : next(nullptr) {
        }
    };

    template<class T>
    class LinkedList {
    private:
        Node<T> *head;
        int size;
    public:
        class Range {
        };

        class Empty {
        };

        LinkedList() {
            head = new Node<T>();
            size = 0;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }

        void add(int index, T e) {
            if (index < 0 || index > size) {
                throw Range();
            }
            Node<T> *prev = head;
            for (int i = 0; i < index; ++i) {
                prev = prev->next;
            }
            prev->next = new Node<T>(e, prev->next);
            size++;
        }

        void addFirst(T e) {
            add(0, e);
        }

        void addLast(T e) {
            add(size, e);
        }

        T get(int index) {
            if (size == 0) {
                throw Empty();
            }
            if (index < 0 || index >= size) {
                throw Range();
            }
            Node<T> *cur = head->next;
            for (int i = 0; i < index; ++i) {
                cur = cur->next;
            }
            return cur->e;
        }

        T getFirst() {
            return get(0);
        }

        T getLast() {
            return get(size - 1);
        }

        void set(int index, T e) {
            if (size == 0) {
                throw Empty();
            }
            if (index < 0 || index >= size) {
                throw Range();
            }
            Node<T> *cur = head->next;
            for (int i = 0; i < index; ++i) {
                cur = cur->next;
            }
            cur->e = e;
        }

        void setFirst(T e) {
            set(0, e);
        }

        void setLast(T e) {
            set(size - 1, e);
        }

        T remove(int index) {
            if (index < 0 || index >= size) {
                throw Range();
            }
            if (size == 0) {
                throw Empty();
            }
            Node<T> *prev = head;
            for (int i = 0; i < index; ++i) {
                prev = prev->next;
            }
            Node<T> *retNode = prev->next;
            prev->next = retNode->next;
            retNode->next = nullptr;
            size--;
            return retNode->e;
        }

        T removeFirst() {
            return remove(0);
        }

        T removeLast() {
            return remove(size - 1);
        }

        void removeElement(T e) {
            Node<T> *prev = head;
            while (prev->next != nullptr) {
                if (prev->next->e == e) {
                    break;
                }
                prev = prev->next;
            }

            if (prev->next != nullptr) {
                Node<T> *delNode = prev->next;
                prev->next = delNode->next;
                delNode->next = nullptr;
                size--;
            }
        }

        bool contains(T e) {
            Node<T> *cur = head;
            for (int i = 0; i < size; ++i) {
                cur = cur->next;
                if (cur->e == e) {
                    return true;
                }
            }
            return false;
        }

        void print() {
            Node<T> *prev = head;
            std::cout << "LinkedList: size = " << size << std::endl;
            std::cout << "[";
            for (int i = 0; i < size; ++i) {
                prev = prev->next;
                std::cout << prev->e;
                if (i < size - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
        }

        void toPrint() {
            Node<T> *prev = head;
            std::cout << "[";
            for (int i = 0; i < size; ++i) {
                prev = prev->next;
                std::cout << prev->e;
                if (i < size - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]";
        }
    };

    template<class T>
    class LinkedListSet : public Set<T> {
    private:
        LinkedList <T> *list;
    public:
        LinkedListSet() {
            list = new LinkedList<T>();
        }

        int getSize() {
            return list->getSize();
        }

        bool isEmpty() {
            return list->isEmpty();
        }

        bool contains(T e) {
            return list->contains(e);
        }

        void add(T e) {
            if (!list->contains(e)) {
                list->addFirst(e);
            }
        }

        void remove(T e) {
            list->removeElement(e);
        }

    };

    
};
