//
// Created by hpf on 18-5-13.
//

#ifndef SET_LINKEDLISTSET_H
#define SET_LINKEDLISTSET_H

#include "Set.h"
#include "LinkedList.h"

template<class T>
class LinkedListSet : public Set<T>{
private:
    LinkedList<T> *list;
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

};

#endif //SET_LINKEDLISTSET_H
