//
// Created by hpf on 18-5-14.
//

#include <iostream>
#include "Map.h"

#ifndef SET_LINKEDLISTMAP_H
#define SET_LINKEDLISTMAP_H

template<typename Key, typename Value>
class Node {
public:
	Key key;
	Value value;
	Node<Key, Value> *next;

	Node(Key key, Value value, Node<Key, Value> *next) : key(key), value(value), next(next) {
	}

	Node() : key(), value(), next(nullptr) {
	}
};

template<typename Key, typename Value>
class LinkedListMap : Map<Key, Value> {
private:
    Node<Key, Value> *dummyHead;
    int size;

    Node<Key, Value> *getNode(Key key) {
        Node<Key, Value> *cur = dummyHead->next;
        while (cur != nullptr) {
            if (cur->key == key) {
                return cur;
            }
            cur = cur->next;
        }
        return nullptr;
    };

public:
    LinkedListMap() {
        dummyHead = new Node<Key, Value>();
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

    Value *get(Key key) {
        Node<Key, Value> *node = getNode(key);
        return node == nullptr ? nullptr : &(node->value);
    }

    void add(Key key, Value value) {
        Node<Key, Value> *node = getNode(key);
        if (node == nullptr) {
            dummyHead->next = new Node<Key, Value>(key, value, dummyHead->next);
            size++;
        } else {
            node->value = value;
        }
    }

    void set(Key key, Value newValue) {
        Node<Key, Value> *node = getNode(key);
        if (node == nullptr) {

        }
        node->value = newValue;
    }

    Value *remove(Key key) {
        Node<Key, Value> *prev = dummyHead;
        while (prev->next != nullptr) {
            if (prev->next->key == key) {
                break;
            }
            prev = prev->next;
        }

        if (prev->next != nullptr) {
            Node<Key, Value> *delNode = prev->next;
            prev->next = delNode->next;
            delNode->next = nullptr;
            size--;
            return &(delNode->value);
        }
        return nullptr;
    }
};


#endif //SET_LINKEDLISTMAP_H
