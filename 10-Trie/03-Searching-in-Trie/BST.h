//
// Created by hpf on 18-5-10.
//

#include <stack>
#include <iostream>
#include <queue>

template<class T>
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

template<class T>
class BST {
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

    Node<T> *min(Node<T> *node) {
        if (node->left == nullptr)
            return node;
        return min(node->left);
    }

    Node<T> *max(Node<T> *node) {
        if (node->right == nullptr)
            return node;
        return max(node->right);
    }

    Node<T> *removeMin(Node<T> *node) {
        if (node->left == nullptr) {
            Node<T> *rightNode = node->right;
            delete node;
            size--;
            return rightNode;
        }

        node->left = removeMin(node->left);
        return node;
    }

    Node<T> *removeMax(Node<T> *node) {
        if (node->right == nullptr) {
            Node<T> *leftNode = node->left;
            delete node;
            size--;
            return leftNode;
        }

        node->right = removeMax(node->right);
        return node;
    }

    Node<T> *remove(Node<T> *node, T e) {
        if (node == nullptr) {
            return nullptr;
        }
        if (e < node->e) {
            node->left = remove(node->left, e);
            return node;
        } else if (e > node->e) {
            node->right = remove(node->right, e);
            return node;
        } else {
            if (node->left == nullptr) {
                Node<T> *rightNode = node->right;
                delete node;
                size--;
                return rightNode;
            }

            if (node->right == nullptr) {
                Node<T> *leftNode = node->left;
                delete node;
                size--;
                return leftNode;
            }

            Node<T> *successor = new Node<T>(min(node->right)->e);
            //Node *precursor = new Node(max(node->right)->e);
            size++;

            successor->right = removeMin(node->right);
            successor->left = node->left;
            //precursor->left = removeMax(node->left);
            //precursor->right = node->right;
            node->left = node->right = nullptr;
            delete node;
            size--;

            return successor;
            //return precursor;
        }
    }

public:
    class Empty {
    };

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

    void preOrderNR() {
        std::stack<Node<T> *> stack;
        stack.push(root);
        while (!stack.empty()) {
            Node<T> *cur = stack.top();
            std::cout << cur->e << " ";
            stack.pop();
            if (cur->right != nullptr) {
                stack.push(cur->right);
            }
            if (cur->left != nullptr) {
                stack.push(cur->left);
            }
        }
        std::cout << std::endl;
    }

    void inOrder() {
        inOrder(root);
        std::cout << std::endl;
    }

    void inOrderNR() {
        std::stack<Node<T> *> stack;
        Node<T> *cur = root;
        while (cur != nullptr || !stack.empty()) {
            while (cur != nullptr) {
                stack.push(cur);
                cur = cur->left;
            }
            if (!stack.empty()) {
                cur = stack.top();
                std::cout << cur->e << " ";
                stack.pop();
                cur = cur->right;
            }
        }
        std::cout << std::endl;
    }

    void postOrder() {
        postOrder(root);
        std::cout << std::endl;
    }
    
    void postOrderNR() {
        std::stack<Node<T> *> stack;
        Node<T> *cur = root;
        Node<T> *temp;
        while (cur != nullptr || !stack.empty()) {
            while (cur != nullptr) {
                stack.push(cur);
                cur = cur->left;
            }
            if (!stack.empty()) {
                cur = stack.top();
                if (cur->right == temp || cur->right == nullptr){
                    std::cout << cur->e << " ";
                    stack.pop();
                    temp = cur;
                    cur = nullptr;
                }else {
                    cur = cur->right;
                }

            }
        }
        std::cout << std::endl;
    }

    void levelOrder() {
        std::queue<Node<T> *> *q = new std::queue<Node<T> *>();
        q->push(root);
        while (!q->empty()) {
            Node<T> *node = q->front();
            q->pop();
            std::cout << node->e << " ";
            if (node->left != nullptr) {
                q->push(node->left);
            }
            if (node->right != nullptr) {
                q->push(node->right);
            }
        }
        std::cout << std::endl;
    }

    T minimun() {
        if (size == 0) {
            throw Empty();
        }
        return min(root)->e;
    }

    T maximun() {
        if (size == 0) {
            throw Empty();
        }
        return max(root)->e;
    }

    T removeMin() {
        T ret = minimun();
        root = removeMin(root);
        return ret;
    }

    T removeMax() {
        T ret = maximun();
        root = removeMax(root);
        return ret;
    }

    void remove(T e) {
        root = remove(root, e);
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
};
