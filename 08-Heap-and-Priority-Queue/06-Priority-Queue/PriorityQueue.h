//
// Created by hpf on 18-5-16.
//

#ifndef HEAP_PRIORITYQUEUE_H
#define HEAP_PRIORITYQUEUE_H

#include "Queue.h"
#include "MaxHeap.h"

template<class T>
class PriorityQueue : public Queue<T> {
private:
    MaxHeap<T> *maxHeap;
public:
    PriorityQueue() {
        maxHeap = new MaxHeap<T>();
    }

    int getSize() {
        return maxHeap->size();
    }

    bool isEmpty() {
        return maxHeap->isEmpty();
    }

    T getFront() {
        return maxHeap->findeMax();
    }

    void enqueue(T e) {
        maxHeap->add(e);
    }

    T dequeue() {
        return maxHeap->extractMax();
    }

	void print() {
		std::cout << "Queue: size = " << maxHeap->size() << std::endl;
        std::cout << "front ";
        maxHeap->print();
        std::cout << " tail" << std::endl;
	}
};

#endif //HEAP_PRIORITYQUEUE_H
