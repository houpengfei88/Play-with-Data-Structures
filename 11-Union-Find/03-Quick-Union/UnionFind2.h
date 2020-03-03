//
// Created by hpf on 18-6-11.
//

#ifndef UNION_FIND_UNIONFIND2_H
#define UNION_FIND_UNIONFIND2_H

#include "UF.h"
#include <cassert>

class UnionFind2 : public UF {
private:
    int *parent;
    int size;
public:
    UnionFind2(int capacity) {
        parent = new int[capacity];
        size = capacity;
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int getSize() {
        return size;
    }

    int find(int p) {
        assert(p >= 0 && p < size);
        while (p != parent[p]) {
            p = parent[p];
        }
        return p;
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot) {
            return;
        }

        parent[pRoot] = qRoot;
    }
};

#endif //UNION_FIND_UNIONFIND2_H
