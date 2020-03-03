//
// Created by hpf on 18-6-13.
//

#ifndef UNION_FIND_UNIONFIND4_H
#define UNION_FIND_UNIONFIND4_H

#include "UF.h"
#include <cassert>

class UnionFind4 : public UF {
private:
    int *parent;
    int *rank;
    int size;
public:
    UnionFind4(int capacity) {
        parent = new int[capacity];
        rank = new int[capacity];
        size = capacity;
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
            rank[i] = 1;
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

        if (rank[pRoot] < rank[qRoot]) {
            parent[pRoot] = qRoot;
        } else if (rank[pRoot] > rank[qRoot]) {
            parent[qRoot] = pRoot;
        } else {
            parent[qRoot] = pRoot;
            rank[pRoot] += 1;
        }

    }
};

#endif //UNION_FIND_UNIONFIND4_H
