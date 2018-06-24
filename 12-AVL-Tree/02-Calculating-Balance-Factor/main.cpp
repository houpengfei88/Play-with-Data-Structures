#include <iostream>
#include "FileOperation.h"
#include "AVLTree.h"
#include "BST.h"

int main() {
    std::cout << "pride-and-prejudice.txt" << std::endl;
    string filename = ".././pride-and-prejudice.txt";
    BST<string, int> *bst = new BST<string, int>();
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        for (string word : words) {
            if (bst->contains(word)) {
                bst->set(word, *(bst->get(word)) + 1);
            } else {
                bst->add(word, 1);
            }
        }
        std::cout << "Total different words: " << bst->getSize() << std::endl;
        std::cout << "Frequency of PRIDE: " << *(bst->get("pride")) << std::endl;
        std::cout << "Frequency of PREJUDICE: " << *(bst->get("prejudice")) << std::endl;
    }

    std::cout << "pride-and-prejudice.txt" << std::endl;
    AVLTree<string, int> *avlTree = new AVLTree<string, int>();
    vector<string> words1;
    if (FileOps::readFile(filename, words1)) {
        std::cout << "Total words: " << words1.size() << std::endl;
        for (string word : words1) {
            if (avlTree->contains(word)) {
                avlTree->set(word, *(avlTree->get(word)) + 1);
            } else {
                avlTree->add(word, 1);
            }
        }
        std::cout << "Total different words: " << avlTree->getSize() << std::endl;
        std::cout << "Frequency of PRIDE: " << *(avlTree->get("pride")) << std::endl;
        std::cout << "Frequency of PREJUDICE: " << *(avlTree->get("prejudice")) << std::endl;
    }
    return 0;
}