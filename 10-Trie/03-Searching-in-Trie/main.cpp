#include <iostream>
#include "BSTSet.h"
#include "FileOperation.h"
#include "Trie.h"
#include <ctime>

template<typename T>
double testTime(T *test, string filename) {
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
    	clock_t startTime = clock();
        for(string word : words) {
            test->add(word);
        }
        for(string word : words) {
            test->contains(word);
        }
        clock_t endTime = clock();
        std::cout << "Total different words: " << test->getSize() << std::endl;
        return double(endTime - startTime) / CLOCKS_PER_SEC;
    } else {
    	return 0;
    }
}

int main() {
    std::cout << "pride-and-prejudice.txt" << std::endl;
    string filename = ".././pride-and-prejudice.txt";
    BSTSet<string> *bstSet = new BSTSet<string>();
    double time1 = testTime(bstSet, filename);
    std::cout << "BST Set : " << time1 << " s " << std::endl;
    std::cout << "pride-and-prejudice.txt" << std::endl;
    Trie *trie = new Trie();
    double time2 = testTime(trie, filename);
    std::cout << "Trie : " << time2 << " s " << std::endl;
    return 0;
}
