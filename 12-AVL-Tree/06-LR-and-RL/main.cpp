#include <iostream>
#include "FileOperation.h"
#include "AVLTree.h"
#include "BST.h"
#include <ctime>

int main() {
    std::cout << "pride-and-prejudice.txt" << std::endl;
    string filename = ".././pride-and-prejudice.txt";
    BST<string, int> *bst = new BST<string, int>();
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        std::sort(words.begin(),words.end());
        std::cout << "Total words: " << words.size() << std::endl;
        clock_t startTime = clock();
        for (string word : words) {
            if (bst->contains(word)) {
                bst->set(word, *(bst->get(word)) + 1);
            } else {
                bst->add(word, 1);
            }
        }
        for (string word : words) {
            bst->contains(word);
        }
        clock_t endTime = clock();
        std::cout << "BST : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s " << std::endl;
        std::cout << "Total different words: " << bst->getSize() << std::endl;
        std::cout << "Frequency of PRIDE: " << *(bst->get("pride")) << std::endl;
        std::cout << "Frequency of PREJUDICE: " << *(bst->get("prejudice")) << std::endl;
    }

    std::cout << "pride-and-prejudice.txt" << std::endl;
    AVLTree<string, int> *avlTree = new AVLTree<string, int>();
    vector<string> words1;
    if (FileOps::readFile(filename, words1)) {
        std::sort(words.begin(),words.end());
        std::cout << "Total words: " << words1.size() << std::endl;
        clock_t startTime = clock();
        for (string word : words1) {
            if (avlTree->contains(word)) {
                avlTree->set(word, *(avlTree->get(word)) + 1);
            } else {
                avlTree->add(word, 1);
            }
        }
        for (string word : words1) {
            avlTree->contains(word);
        }
        clock_t endTime = clock();
        std::cout << "AVLTree : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s " << std::endl;
        std::cout << "Total different words: " << avlTree->getSize() << std::endl;
        std::cout << "Frequency of PRIDE: " << *(avlTree->get("pride")) << std::endl;
        std::cout << "Frequency of PREJUDICE: " << *(avlTree->get("prejudice")) << std::endl;
        std::cout << "isBST : " << std::boolalpha << avlTree->isBST() << std::endl;
        std::cout << "isBalanced : " << std::boolalpha << avlTree->isBalanced() << std::endl;
    }
    return 0;
}