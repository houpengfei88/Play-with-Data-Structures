#include <iostream>
#include "ArrayQueue.h"
#include "LoopQueue.h"

template<typename T>
double testQueue(T *queue, int opCount) {
    clock_t startTime = clock();
    srand(66);
    for (int i = 0; i < opCount; ++i) {
        queue->enqueue(rand());
    }
    for (int j = 0; j < opCount; ++j) {
        queue->dequeue();
    }
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}

int main() {
    int opCount = 100000;
    ArrayQueue<int> *arrayQueue = new ArrayQueue<int>();
    std::cout << "ArrayQueue time: " << testQueue(arrayQueue, opCount) << " s" << std::endl;
    LoopQueue<int> *loopQueue = new LoopQueue<int>();
    std::cout << "LoopQueue time: " << testQueue(loopQueue, opCount) << " s" << std::endl;
    arrayQueue = nullptr;
    loopQueue = nullptr;
    delete arrayQueue;
    delete loopQueue;
    return 0;
}
