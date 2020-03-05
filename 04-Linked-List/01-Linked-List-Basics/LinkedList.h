//
// Created by hpf on 18-5-8.
//
#include <iostream>

template<typename T>
class Node {
public:
    T e;
    Node<T> *next;

    Node(T e, Node *next) : e(e), next(next) {}

    Node(T e) : e(e), next(nullptr) {}

    Node() : e(), next(nullptr){}
};
