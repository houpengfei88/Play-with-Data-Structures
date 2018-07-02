#include <iostream>
#include "FileOperation.h"
#include "BSTMap.h"
#include "LinkedListMap.h"
#include "AVLMap.h"

template<typename T>
double testMap(T *map, string filename) {
    clock_t startTime = clock();
    srand(66);
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        for(string word : words) {
            if (map->contains(word)) {
                map->set(word, *(map->get(word)) + 1);
            } else {
                map->add(word, 1);
            }
        }
        std::cout << "Total different words: " << map->getSize() << std::endl;
        std::cout << "Frequency of PRIDE: " << *(map->get("pride")) << std::endl;
        std::cout << "Frequency of PREJUDICE: " << *(map->get("prejudice")) << std::endl;
    }
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}

int main() {
	std::cout << "test map ： " << std::endl;
    std::cout << "pride-and-prejudice.txt" << std::endl;
    string filename = ".././pride-and-prejudice.txt";
    BSTMap<string, int> *bstMap = new BSTMap<string, int>();
    float time1 = testMap(bstMap, filename);
    std::cout << "BSTMap time : " << time1 << " s " << std::endl;
    LinkedListMap<string, int> *linkedListMap = new LinkedListMap<string, int>();
    float time2 = testMap(linkedListMap, filename);
    std::cout << "LinkedListMap time : " << time2 << " s " << std::endl;
    AVLMap<string, int> *avlMap = new AVLMap<string, int>();
    float time3 = testMap(avlMap, filename);
    std::cout << "AVLMap time : " << time3 << " s " << std::endl;   
    return 0;
}
