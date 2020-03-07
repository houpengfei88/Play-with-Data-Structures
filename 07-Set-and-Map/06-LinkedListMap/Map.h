//
// Created by hpf on 18-5-14.
//
#ifndef MAP_H
#define MAP_H

template<typename Key, typename Value>
class Map {
    virtual void add(Key key, Value value) = 0;

    virtual Value remove(Key key) = 0;

    virtual bool contains(Key key) = 0;

    virtual Value get(Key key) = 0;

    virtual void set(Key key, Value value) = 0;

    virtual int getSize() = 0;

    virtual bool isEmpty() = 0;
};

#endif //MAP_H