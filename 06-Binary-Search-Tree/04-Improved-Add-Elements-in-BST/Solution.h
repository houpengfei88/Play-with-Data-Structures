//
// Created by hpf on 18-5-10.
//

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int uniqueMorseRepresentations(std::vector<std::string> &words) {
        std::vector<std::string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
                                          ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
                                          ".--", "-..-", "-.--", "--.."};
        BST<std::string> bst;
        for (const std::string &word : words) {
            std::cout << '"' << word << '"' << " -> ";
            std::string code = "";
            for (char c : word) {
                code += morse[c - 'a'];
            }
	    	std::cout << '"' << code << '"' << std::endl;
            bst.add(code);
        }
        return bst.getSize();
    }

private:
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
    
    private:
        Node<T> *root;
        int size;
    };
};
