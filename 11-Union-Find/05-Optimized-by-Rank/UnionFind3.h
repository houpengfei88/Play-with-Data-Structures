//
// Created by hpf on 18-6-11.
//

#ifndef UNION_FIND_UNIONFIND3_H
#define UNION_FIND_UNIONFIND3_H

#include "UF.h"
#include <cassert>

class UnionFind3 : public UF {
private:
    int *parent;
    int *sz;
    int size;
public:
    UnionFind3(int capacity) {
        parent = new int[capacity];
        sz = new int[capacity];
        size = capacity;
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
            sz[i] = 1;
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

        if (sz[pRoot] < sz[qRoot]) {
            parent[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];
        } else {
            parent[qRoot] = pRoot;
            sz[pRoot] += sz[qRoot];
        }

    }
};

#endif //UNION_FIND_UNIONFIND3_H
