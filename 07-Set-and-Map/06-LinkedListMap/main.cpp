#include <iostream>
#include "FileOperation.h"
#include "LinkedListMap.h"

int main() {
    std::cout << "pride-and-prejudice.txt" << std::endl;
    string filename = ".././pride-and-prejudice.txt";
    LinkedListMap<string, int> *linkedListMap = new LinkedListMap<string, int>();
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        for (string word : words) {
            if (linkedListMap->contains(word)) {
                linkedListMap->set(word, linkedListMap->get(word) + 1);
            } else {
                linkedListMap->add(word, 1);
            }
        }
        std::cout << "Total different words: " << linkedListMap->getSize() << std::endl;
        std::cout << "Frequency of PRIDE: " << linkedListMap->get("pride") << std::endl;
        std::cout << "Frequency of PREJUDICE: " << linkedListMap->get("prejudice") << std::endl;
    }
    return 0;
}
