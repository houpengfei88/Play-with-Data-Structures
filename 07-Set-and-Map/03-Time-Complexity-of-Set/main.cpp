#include <iostream>
#include "LinkedListSet.h"
#include "FileOperation.h"
#include "BSTSet.h"

template<typename T>
double testSet(T *set, string filename) {
    clock_t startTime = clock();
    srand(66);
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        for(string word : words) {
            set->add(word);
        }
        std::cout << "Total different words: " << set->getSize() << std::endl;
    }
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}

int main() {
    std::cout << "pride-and-prejudice.txt" << std::endl;
    string filename = ".././pride-and-prejudice.txt";
    BSTSet<string> *bstSet = new BSTSet<string>();
    LinkedListSet<string> *linkedListSet = new LinkedListSet<string>();
    double time1 = testSet(bstSet, filename);
    std::cout << "BST Set : " << time1 << " s " << std::endl;
    std::cout << "pride-and-prejudice.txt" << std::endl;
    double time2 = testSet(linkedListSet, filename);
    std::cout << "LinkedList Set : " << time2 << " s " << std::endl;
    return 0;
}
