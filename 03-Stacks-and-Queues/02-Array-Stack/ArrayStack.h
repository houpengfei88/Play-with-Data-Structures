//
// Created by hpf on 18-5-3.
//

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "Array.h"
#include "Stack.h"

template<typename T>
class ArrayStack : public Stack<T> {
public:
    ArrayStack(int capacity) {
        array = new Array<T>(capacity);
    }

    ArrayStack() {
    	array = new Array<T>();
    }

    ~ArrayStack() {
        delete[] array;
        array = nullptr;
    }

    int getSize() {
        return array->getSize();
    }

    T pop() {
        return array->removeLast();
    }

    T peek() {
        return array->getLast();
    }

    void push(T e) {
        array->addLast(e);
    }

    bool isEmpty() {
        return array->isEmpty();
    }

    /**
     * 打印数组的所有元素
     */
    void print() {
        std::cout << "ArrayStack: size = " << array->getSize() << ", capacity = " << array->getCapacity() << std::endl;
        std::cout << "bottom ";
        array->print();
        std::cout << " top" << std::endl;
    }

private:
    Array<T> *array;
};

#endif //ARRAYSTACK_H
