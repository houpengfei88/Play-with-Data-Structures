//
// Created by hpf on 18-7-30.
//

#ifndef HASH_TABLE_HASHTABLE_H
#define HASH_TABLE_HASHTABLE_H

#include "RBTree.h"
#include <iostream>

template<typename Key, typename Value>
class HashTable {
private:
    int M;
    int size;
    RBTree<Key, Value> *hashTable[];

    int hash(Key key) {
        return (hashCode(key) & 0x7fffffff) % M;
    }

    int hashCode(Key key) {
        std::hash<Key> key_hash;
        return key_hash(key);
    }

public:

    HashTable(int M) {
        this->M = M;
        size = 0;
        *hashTable = new RBTree<Key, Value>[M]{};
        for (int i = 0; i < M; ++i) {
            hashTable[i] = new RBTree<Key, Value>();
        }
    }

    HashTable() {
        this->M = 97;
        size = 0;
        *hashTable = new RBTree<Key, Value>[M]{};
        for (int i = 0; i < M; ++i) {
            hashTable[i] = new RBTree<Key, Value>();
        }
    }

    int getSize() {
        return size;
    }

    void add(Key key, Value value) {
        RBTree<Key, Value> *rbTree = hashTable[hash(key)];
        if (rbTree->contains(key)) {
            rbTree->set(key, value);
        } else {
            rbTree->add(key, value);
            size++;
        }
    }

    Value *remove(Key key) {

    }

    bool contains(Key key) {
        return hashTable[hash(key)]->contains(key);
    }

    Value *get(Key key) {
        return hashTable[hash(key)]->get(key);
    }

    void set(Key key, Value value) {
        RBTree<Key, Value> *rbTree = hashTable[hash(key)];
        if (!rbTree->contains(key)) {
            throw key + "doesn't exist";
        }
        rbTree->set(key, value);
    }
};

#endif //HASH_TABLE_HASHTABLE_H
