#include <iostream>
#include "PriorityQueue.h"

int main() {
    PriorityQueue<int> *queue = new PriorityQueue<int>();
    for (int i = 0; i < 10; ++i) {
		queue->enqueue(i);
		queue->print();
    	if (i % 3 == 2) {
	    	queue->dequeue();
	    	queue->print();
		}
    }  
    return 0;
}
