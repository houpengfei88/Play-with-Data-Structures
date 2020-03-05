//
// Created by hpf on 18-5-8.
//

#include <iostream>
#include <cassert>

template<typename T>
class Node {
public:
    T e;
    Node<T> *next;

    Node(T e, Node<T> *next) : e(e), next(next) {}

    Node(T e) : e(e), next(nullptr) {}

    Node() : e(), next(nullptr) {}
};

template<typename T>
class LinkedList {
public:
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
        assert(index >= 0 && index <= size);
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
        head = new Node<T>(e, head);
        size++;
    }

    void addLast(T e) {
        add(size, e);
    }

private:
    Node<T> *head;
    int size;
};
