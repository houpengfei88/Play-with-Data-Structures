//
// Created by hpf on 18-5-18.
//

#ifndef SEGMENT_TREE_SEGMENTTREE_H
#define SEGMENT_TREE_SEGMENTTREE_H

#include <cassert>

template<class T>
class SegmentTree {
private:
    T *tree;
    T *data;
    int size;

    int leftChild(int index) {
        return index * 2;
    }

    int rightChild(int index) {
        return index * 2 + 1;
    }

public:
    SegmentTree(T arr[], int n) {
        data = new T[n];
        for (int i = 0; i < n; ++i) {
            data[i] = arr[i];
        }
        tree = new T[n * 4];
        size = n;
    }

    int getSize() {
        return size;
    }

    T get(int index) {
        assert(index >= 0 && index < size);
        return data[index];
    }


};

#endif //SEGMENT_TREE_SEGMENTTREE_H
