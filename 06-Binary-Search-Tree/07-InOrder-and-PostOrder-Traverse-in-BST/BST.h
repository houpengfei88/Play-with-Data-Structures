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

    Node<T> *add(Node<T> *node, T e) {
        if (node == nullptr) {
            size++;
	        return new Node<T>(e);
        } 
		if (node->e > e) {
            node->left = add(node->left, e);
        } else if (node->e < e) {
            node->right = add(node->right, e);
        }
		return node;
    }

    bool contains(T e) {
        return contains(root, e);
    }

    void preOrder() {
        preOrder(root);
        std::cout << std::endl;
    }

    void inOrder() {
        inOrder(root);
        std::cout << std::endl;
    }

    void postOrder() {
        postOrder(root);
        std::cout << std::endl;
    }

    void generateBSTString(Node<T> *node, int depth) {
        if (node == nullptr) {
            generateDepthString(depth);
            std::cout << "NULL" << std::endl;
            return;
        }
        generateDepthString(depth);
        std::cout << node->e << std::endl;
        generateBSTString(node->left, depth + 1);
        generateBSTString(node->right, depth + 1);
    }

    void print() {
        generateBSTString(root, 0);
    }

private:
    Node<T> *root;
    int size;

    bool contains(Node<T> *node, T e) {
        if (node == nullptr) {
            return false;
        }

        if (node->e == e) {
            return true;
        } else if (node->e > e) {
            return contains(node->left, e);
        } else {
            return contains(node->right, e);
        }
    }

    void preOrder(Node<T> *node) {
        if (node == nullptr) {
            return;
        }
	    std::cout << node->e << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void inOrder(Node<T> *node) {
        if (node == nullptr) {
            return;
        }
		inOrder(node->left);
        std::cout << node->e << " ";
        inOrder(node->right);
    }

    void postOrder(Node<T> *node) {
        if (node == nullptr) {
            return;
        }
		postOrder(node->left);
        postOrder(node->right);
        std::cout << node->e << " ";
    }

    void generateDepthString(int depth) {
        for (int i = 0; i < depth; ++i) {
            std::cout << "--";
        }
    }
};
