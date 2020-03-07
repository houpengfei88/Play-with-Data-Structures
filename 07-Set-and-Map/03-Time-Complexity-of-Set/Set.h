//
// Created by hpf on 18-5-13.
//

#ifndef SET_H
#define SET_H

template<typename T>
class Set {
    virtual void add(T e) = 0;

    virtual void remove(T e) = 0;

    virtual bool contains(T e) = 0;

    virtual int getSize() = 0;
    
    virtual bool isEmpty() = 0;
};

#endif //SET_H
