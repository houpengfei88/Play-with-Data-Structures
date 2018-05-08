//
// Created by hpf on 18-5-8.
//

template<class T>
class Node {
public:
    T e;
    Node *next;

    Node(T e, Node *next) : e(e), next(next) {
    }

    Node(T e) : e(e), next(nullptr) {
    }

    Node() : e(), next(nullptr){
    }
};

template<class T>
class LinkedList {
private:
    Node *head;
    int size;
public:
    class Range {
    };

    class Empty {
    };

    LinkedList() {
        head = nullptr;
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
        if (index == 0) {
            addFirst(e);
        } else {
            Node<T> *prev = head;
            for (int i = 0; i < index; ++i) {
                prev = prev->next;
            }
            prev->next = new Node<T>(e, prev->next);
            size++;
        }
    }

    void addFirst(T e) {
        head = new Node(e, head);
        size++;
    }

    void addLast(T e) {
        add(size, e);
    }

};
