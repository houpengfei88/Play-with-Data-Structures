//
// Created by hpf on 18-5-14.
//

#include <iostream>
#include "Map.h"
#include <cassert>

#ifndef LINKEDLISTMAP_H
#define LINKEDLISTMAP_H

template<typename Key, typename Value>
class MapNode {
public:
    Key key;
    Value value;
    MapNode<Key, Value> *next;

    MapNode(Key key, Value value, MapNode<Key, Value> *next) : key(key), value(value), next(next) {}

    MapNode() : key(), value(), next(nullptr) {}
};

template<typename Key, typename Value>
class LinkedListMap : Map<Key, Value> {
public:
    LinkedListMap() {
        dummyHead = new MapNode<Key, Value>();
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool contains(Key key) {
        return getNode(key) != nullptr;
    }

    Value get(Key key) {
        assert(contains(key));
        MapNode<Key, Value> *node = getNode(key);
        return node->value;
    }

    void add(Key key, Value value) {
        MapNode<Key, Value> *node = getNode(key);
        if (node == nullptr) {
            dummyHead->next = new MapNode<Key, Value>(key, value, dummyHead->next);
            size++;
        } else {
            node->value = value;
        }
    }

    void set(Key key, Value newValue) {
        MapNode<Key, Value> *node = getNode(key);
        if (node == nullptr) {
            add(key, newValue);
        }else {
            node->value = newValue;
        } 
    }

    Value remove(Key key) {
        assert(contains(key));
        MapNode<Key, Value> *prev = dummyHead;
        while (prev->next != nullptr) {
            if (prev->next->key == key) {
                break;
            }
            prev = prev->next;
        }
        if (prev->next != nullptr) {
            MapNode<Key, Value> *delNode = prev->next;
            prev->next = delNode->next;
            delNode->next = nullptr;
            size--;
            return delNode->value;
        } else {
            return prev->value;
        }
    }

private:
    MapNode<Key, Value> *dummyHead;
    int size;

    MapNode<Key, Value> *getNode(Key key) {
        MapNode<Key, Value> *cur = dummyHead->next;
        while (cur != nullptr) {
            if (cur->key == key) {
                return cur;
            }
            cur = cur->next;
        }
        return nullptr;
    };

};

#endif //LINKEDLISTMAP_H
