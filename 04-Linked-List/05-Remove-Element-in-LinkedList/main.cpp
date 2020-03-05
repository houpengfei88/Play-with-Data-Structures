#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> *linkedList = new LinkedList<int>();
    for (int i = 0; i < 5; ++i) {
	    linkedList->addFirst(i);
    }
    linkedList->add(2, 30);
    linkedList->print(); 
    linkedList->remove(2);
    linkedList->print();
    linkedList->removeFirst();
    linkedList->print();
    linkedList->removeLast();
    linkedList->print();   
    linkedList = nullptr;
    delete linkedList;
    return 0;
}
