//
// Created by hpf on 18-7-2.
//

#ifndef AVLTREE_AVLMAP_H
#define AVLTREE_AVLMAP_H

#include "AVLTree.h"
#include "Map.h"

template<typename Key, typename Value>
class AVLMap : Map<Key, Value> {
private:
    AVLTree<Key, Value> *avlTree;

public:
    AVLMap() {
        avlTree = new AVLTree<Key, Value>();
    }

    int getSize() {
        return avlTree->getSize();
    }

    bool isEmpty() {
        return avlTree->isEmpty();
    }

    void add(Key key, Value value) {
        avlTree->add(key, value);
    }

    bool contains(Key key) {
        return avlTree->contains(key);
    }

    void set(Key key, Value value) {
        avlTree->set(key,value);
    }

    Value *get(Key key) {
        return avlTree->get(key);
    }

    Value *remove(Key key) {
        return avlTree->remove(key);
    }
};

#endif //AVLTREE_AVLMAP_H
