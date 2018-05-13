//
// Created by hpf on 18-5-13.
//

#ifndef SET_BSTSET_H
#define SET_BSTSET_H

#include "Set.h"
#include "BST.h"

template<class T>
class BSTSet : public Set<T> {
private:
    BST<T> *bst;
public:
    BSTSet(){
        bst = new BST<T>();
    }

    int getSize(){
        return bst->getSize();
    }

    bool isEmpty(){
        return bst->isEmpty();
    }

    bool contains(T e){
        return bst->contains(e);
    }

    void remove(T e){
        bst->remove(e);
    }

    void add(T e){
        bst->add(e);
    }
};

#endif //SET_BSTSET_H
