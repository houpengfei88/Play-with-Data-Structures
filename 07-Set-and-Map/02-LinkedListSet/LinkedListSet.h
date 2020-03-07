//
// Created by hpf on 18-5-13.
//

#ifndef LINKEDLISTSET_H
#define LINKEDLISTSET_H

#include "Set.h"
#include "LinkedList.h"

template<typename T>
class LinkedListSet : public Set<T>{
public:
    LinkedListSet(){
        list = new LinkedList<T>();
    }

    int getSize(){
        return list->getSize();
    }

    bool isEmpty(){
        return list->isEmpty();
    }

    bool contains(T e){
        return list->contains(e);
    }

    void add(T e){
        if(!list->contains(e)){
            list->addFirst(e);
        }
    }

    void remove(T e){
        list->removeElement(e);
    }

private:
    LinkedList<T> *list;
};

#endif //LINKEDLISTSET_H
