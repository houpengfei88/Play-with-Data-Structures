#include <iostream>
#include "Array.h"

int main() {
    Array<int> *array = new Array<int>();
    for (int i = 0; i < 10; ++i) {
        array->addLast(i);
        array->print();
    }
    array->add(1,100);
    array->print();
    array->addFirst(-1);
    array->print();
    array->remove(2);
    array->print();
    array->removeElement(4);
    array->print();
    for (int i = 0; i < 2; i++) {
        array->removeLast();
        array->print();
        array->removeFirst();
        array->print();
    }
    array = nullptr;
    delete array;
    return 0;
}