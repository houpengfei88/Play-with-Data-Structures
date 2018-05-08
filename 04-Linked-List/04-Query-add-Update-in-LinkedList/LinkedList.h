//
// Created by hpf on 18-5-8.
//

#include <iostream>

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
};
