//
// Created by hpf on 18-7-2.
//

#ifndef AVLTREE_AVLSET_H
#define AVLTREE_AVLSET_H

#include "Set.h"
#include "AVLTree.h"

template<class T>
class AVLSet : public Set<T> {
private:
    AVLTree<T, T> *avlTree;

public:
    AVLSet() {
        avlTree = new AVLTree<T, T>();
    }

    int getSize() {
        return avlTree->getSize();
    }

    bool isEmpty() {
        return avlTree->isEmpty();
    }

    void add(T e) {
        avlTree->add(e,e);
    }

    bool contains(T e) {
        return avlTree->contains(e);
    }

    void remove(T e) {
        avlTree->remove(e);
    }
};

#endif //AVLTREE_AVLSET_H
