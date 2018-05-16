#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> *linkedList = new LinkedList<int>();
    for (int i = 0; i < 5; ++i) {
		linkedList->addFirst(i);
		linkedList->print();
    }
    linkedList->add(2, 30);
    linkedList->print();    
    return 0;
}
