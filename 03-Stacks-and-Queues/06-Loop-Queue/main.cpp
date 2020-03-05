#include <iostream>
#include "ArrayQueue.h"
#include "LoopQueue.h"

int main() {
    LoopQueue<int> *loopQueue = new LoopQueue<int>(5);
    for (int j = 0; j < 5; ++j) {
        loopQueue->enqueue(j);
        loopQueue->print();
    }
    loopQueue->enqueue(20);
    loopQueue->enqueue(33);
    loopQueue->print();
    loopQueue->dequeue();
    loopQueue->print();
    std::cout << loopQueue->getFront() << std::endl;
    loopQueue = nullptr;
    delete loopQueue;
    return 0;
}
