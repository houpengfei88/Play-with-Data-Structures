#include <iostream>
#include "BSTSet.h"
#include "FileOperation.h"

int main() {
    std::cout << "a-tale-of-two-cities.txt" << std::endl;
    vector<string> words;
    if (FileOps::readFile(".././a-tale-of-two-cities.txt", words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        BSTSet<string> *bstSet = new BSTSet<string>();
        for(string word : words) {
            bstSet->add(word);
        }
        std::cout << "Total different words: " << bstSet->getSize() << std::endl;
        bstSet = nullptr;
        delete bstSet;
    }

    std::cout << "a-tale-of-two-cities.txt" << std::endl;
    vector<string> words1;
    if (FileOps::readFile(".././pride-and-prejudice.txt", words1)) {
        std::cout << "Total words: " << words1.size() << std::endl;
        BSTSet<string> *bstSet = new BSTSet<string>();
        for(string word : words1) {
            bstSet->add(word);
        }
        std::cout << "Total different words: " << bstSet->getSize() << std::endl;
        bstSet = nullptr;
        delete bstSet;
    }
    return 0;
}
