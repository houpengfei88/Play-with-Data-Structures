//
// Created by hpf on 18-5-7.
//

#ifndef DATASTRUCTURE_WITH_C_LINKLISTQUEUE_H
#define DATASTRUCTURE_WITH_C_LINKLISTQUEUE_H

#include "Queue.h"

template<class T>
class QNode {
public:
    T e;
    QNode *next;

    QNode(T e, QNode *next) : e(e), next(next) {

    }

    QNode(T e) : e(e), next(nullptr) {

    }

    QNode() : next(nullptr) {

    }
};

template<class T>
class LinkedListQueue : public Queue<T> {
public:
    class Empty {
    };

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
        if (isEmpty()) {
            throw Empty();
        }
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
        if (isEmpty()) {
            throw Empty();
        }
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

#endif //DATASTRUCTURE_WITH_C_LINKLISTQUEUE_H
