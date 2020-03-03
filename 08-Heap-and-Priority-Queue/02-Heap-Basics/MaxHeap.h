//
// Created by hpf on 18-5-15.
//

#ifndef HEAP_MAXHEAP_H
#define HEAP_MAXHEAP_H

#include "Array.h"

template<class T>
class MaxHeap {
private:
    Array<T> *data;

    // 返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
    int leftChild(int index) {
        return index * 2 + 1;
    }

    // 返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引
    int rightChild(int index) {
        return index * 2 + 2;
    }

public:
    class NoParent {
    };

    MaxHeap(int capacity) {
        data = new Array<T>(capacity);
    }

    MaxHeap() {
        data = new Array<T>();
    }

    int size() {
        return data->getSize();
    }

    bool isEmpty() {
        return data->isEmpty();
    }

    // 返回完全二叉树的数组表示中，一个索引所表示的元素的父亲节点的索引
    int parent(int index) {
        if (index == 0) {
            throw NoParent();
        }
        return (index - 1) / 2;
    }
};

#endif //HEAP_MAXHEAP_H
