//
// Created by hpf on 18-5-7.
//

#ifndef LINKLISTQUEUE_H
#define LINKLISTQUEUE_H

#include "Queue.h"
#include <cassert>
#include <iostream>

template<typename T>
class QNode {
public:
    T e;
    QNode<T> *next;

    QNode(T e, QNode<T> *next) : e(e), next(next) {}

    QNode(T e) : e(e), next(nullptr) {}

    QNode() : next(nullptr) {}
};

template<typename T>
class LinkedListQueue : public Queue<T> {
public:
    LinkedListQueue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(T e) {
        if (tail == nullptr) {
            tail = new QNode<T>(e);
            head = tail;
        } else {
            tail->next = new QNode<T>(e);
            tail = tail->next;
        }
        size++;
    }

    T dequeue() {
        assert(!isEmpty());
        QNode<T> *retNode = head;
        head = head->next;
        retNode->next = nullptr;
        if (head == nullptr) {
            tail = nullptr;
        }
        size--;
        return retNode->e;
    }

    T getFront() {
        assert(!isEmpty());
        return head->e;
    }

    void print() {
        QNode<T> *prev = head;
        std::cout << "LinkListQueue: size = " << size << std::endl;
        std::cout << "front ";
        std::cout << "[";
        while (prev != nullptr) {
            std::cout << prev->e;
            if (prev->next != nullptr) {
                std::cout << ", ";
            }
            prev = prev->next;
        }
        std::cout << "] tail" << std::endl;
    }

private:
    QNode<T> *head;
    QNode<T> *tail;
    int size;
};

#endif //LINKLISTQUEUE_H
