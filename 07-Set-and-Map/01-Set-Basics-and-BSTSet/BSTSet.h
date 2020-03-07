//
// Created by hpf on 18-5-13.
//

#ifndef BSTSET_H
#define BSTSET_H

#include "Set.h"
#include "BST.h"

template<typename T>
class BSTSet : public Set<T> {
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
    
private:
    BST<T> *bst;
};

#endif //BSTSET_H
