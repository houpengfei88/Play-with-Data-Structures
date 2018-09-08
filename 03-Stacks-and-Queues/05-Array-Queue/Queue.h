//
// Created by hpf on 18-5-3.
//

#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

template<typename T>
class Queue {
public:
    int getSize();

    bool isEmpty();

    void enqueue(T e);

    T dequeue();

    T getFront();
};

#endif //DATASTRUCTURE_QUEUE_H
