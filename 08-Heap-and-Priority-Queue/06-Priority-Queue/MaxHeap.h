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

	void shiftUp(int k) {
        while (k > 0 && data->get(parent(k)) < data->get(k)) {
            data->swap(k, parent(k));
            k = parent(k);
        }
    }
    
    void shiftDown(int k) {
        while (leftChild(k) < data->getSize()) {
            int j = leftChild(k);
            if (j + 1 < data->getSize() && data->get(j + 1) > data->get(j)) {
                j = rightChild(k);
            }
            if (data->get(k) > data->get(j)) {
                break;
            }
            data->swap(k, j);
            k = j;
        }
    }
    
public:
    class NoParent {
    };

	class Empty {
    };

    MaxHeap(int capacity) {
        data = new Array<T>(capacity);
    }

    MaxHeap() {
        data = new Array<T>();
    }

	MaxHeap(T arr[], int n){
        data = new Array<T>(arr, n);
        for (int i = parent(n - 1); i >= 0; --i) {
            shiftDown(i);
        }
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

    void add(T e) {
        data->addLast(e);
        shiftUp(data->getSize() - 1);
    }
    
    T findeMax() {
        if (data->isEmpty()) {
            throw Empty();
        }
        return data->get(0);
    }

    T extractMax() {
        T ret = findeMax();
        data->swap(0, data->getSize() - 1);
        data->removeLast();
        shiftDown(0);
        return ret;
    }
    
    T replace(T e){
        T ret = findeMax();
        data->set(0, e);
        shiftDown(0);
        return ret;
    }
    
    void print() {
    	data->toPrint();
    }
};

#endif //HEAP_MAXHEAP_H
