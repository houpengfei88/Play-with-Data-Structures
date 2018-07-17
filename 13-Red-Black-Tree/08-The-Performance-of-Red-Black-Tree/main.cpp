#include <iostream>
#include "FileOperation.h"
#include "BST.h"
#include "RBTree.h"
#include "AVLTree.h"

template<typename T>
double testMap(T *map, string filename) {
    clock_t startTime = clock();
    srand(66);
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        for (string word : words) {
            if (map->contains(word)) {
                map->set(word, *(map->get(word)) + 1);
            } else {
                map->add(word, 1);
            }
        }

        for (string word : words) {
            map->contains(word);
        }

        std::cout << "Total different words: " << map->getSize() << std::endl;
        std::cout << "Frequency of PRIDE: " << *(map->get("pride")) << std::endl;
        std::cout << "Frequency of PREJUDICE: " << *(map->get("prejudice")) << std::endl;
    }
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}

template<typename T>
double testData(T *map, vector<int> &dataes) {
    clock_t startTime = clock();
    for (int data : dataes) {
        if (map->contains(data)) {
            map->set(data, *(map->get(data)) + 1);
        } else {
            map->add(data, 1);
        }
    }

    for (int data : dataes) {
        map->contains(data);
    }

    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}


int main() {
    std::cout << "pride-and-prejudice.txt" << std::endl;
    string filename = ".././pride-and-prejudice.txt";
    int n = 20000000;
    vector<int> testDataes, testDataes1;
    for (int i = 0; i < n; ++i) {
        testDataes.push_back(rand() % INT64_MAX);
        testDataes1.push_back(i);
    }
    BSTMap<string, int> *bstMap = new BSTMap<string, int>();
    float time1 = testMap(bstMap, filename);
    std::cout << "BSTMap time : " << time1 << " s " << std::endl;
    RBTree<string, int> *rbTree = new RBTree<string, int>();
    float time2 = testMap(rbTree, filename);
    std::cout << "RBTree time : " << time2 << " s " << std::endl;
    AVLTree<string, int> *avlTree = new AVLTree<string, int>();
    float time3 = testMap(avlTree, filename);
    std::cout << "AVLTree time : " << time3 << " s " << std::endl;
    std::cout << "Test Dataes:" << std::endl;
    BSTMap<int, int> *bstMap1 = new BSTMap<int, int>();
    float time4 = testData(bstMap1, testDataes);
    std::cout << "BSTMap time : " << time4 << " s " << std::endl;
    RBTree<int, int> *rbTree1 = new RBTree<int, int>();
    float time5 = testData(rbTree1, testDataes);
    std::cout << "RBTree time : " << time5 << " s " << std::endl;
    AVLTree<int, int> *avlTree1 = new AVLTree<int, int>();
    float time6 = testData(avlTree1, testDataes);
    std::cout << "AVLTree time : " << time6 << " s " << std::endl;
    std::cout << "Test Dataes1" << std::endl;
    RBTree<int, int> *rbTree2 = new RBTree<int, int>();
    float time7 = testData(rbTree2, testDataes1);
    std::cout << "RBTree time : " << time7 << " s " << std::endl;
    AVLTree<int, int> *avlTree2 = new AVLTree<int, int>();
    float time8 = testData(avlTree2, testDataes1);
    std::cout << "AVLTree time : " << time8 << " s " << std::endl;
    return 0;
}
