#include <iostream>
#include "FileOperation.h"
#include "BSTSet.h"
#include "LinkedListSet.h"
#include "AVLSet.h"

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
    std::cout << "test set ： " << std::endl;
    std::cout << "pride-and-prejudice.txt" << std::endl;
    string filename = ".././pride-and-prejudice.txt";
    BSTSet<string> *bstSet = new BSTSet<string>();
    double time1 = testSet(bstSet, filename);
    std::cout << "BSTSet time: " << time1 << " s " << std::endl;
    LinkedListSet<string> *linkedListSet = new LinkedListSet<string>();
    double time2 = testSet(linkedListSet, filename);
    std::cout << "LinkedListSet time : " << time2 << " s " << std::endl;
    AVLSet<string> *avlSet = new AVLSet<string>();
    double time3 = testSet(avlSet, filename);
    std::cout << "AVLSet time : " << time3 << " s " << std::endl;
   
    return 0;
}
