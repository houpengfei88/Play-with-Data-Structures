#include <iostream>
#include "FileOperation.h"
#include "BSTMap.h"

int main() {
    std::cout << "pride-and-prejudice.txt" << std::endl;
    string filename = ".././pride-and-prejudice.txt";
    BSTMap<string, int> *bstMap = new BSTMap<string, int>();
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        for (string word : words) {
            if (bstMap->contains(word)) {
                bstMap->set(word, *(bstMap->get(word)) + 1);
            } else {
                bstMap->add(word, 1);
            }
        }
        std::cout << "Total different words: " << bstMap->getSize() << std::endl;
        std::cout << "Frequency of PRIDE: " << *(bstMap->get("pride")) << std::endl;
        std::cout << "Frequency of PREJUDICE: " << *(bstMap->get("prejudice")) << std::endl;
    }
    return 0;
}