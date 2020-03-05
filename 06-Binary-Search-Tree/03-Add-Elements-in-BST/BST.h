//
// Created by hpf on 18-5-10.
//
#include <iostream>

template<typename T>
class Node {
public:
    T e;
    Node<T> *left, *right;

    Node(T e) {
        this->e = e;
        left = nullptr;
        right = nullptr;
    }
};

template<typename T>
class BST {
public:
    BST() {
        root = nullptr;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void add(T e) {
        if (root == nullptr) {
            root = new Node<T>(e);
            size++;
        } else {
            add(root, e);
        }
    }

    void add(Node<T> *node, T e) {
        if (node->e == e) {
            return;
        } else if (node->e > e && node->left == nullptr) {
            node->left = new Node<T>(e);
            size++;
            return;
        } else if (node->e < e && node->right == nullptr) {
            node->right = new Node<T>(e);
            size++;
            return;
        }

        if (node->e > e) {
            add(node->left, e);
        } else {
            add(node->right, e);
        }
    }

private:
    Node<T> *root;
    int size;
};
