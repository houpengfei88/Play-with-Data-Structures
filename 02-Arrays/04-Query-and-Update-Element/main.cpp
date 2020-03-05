#include <iostream>
#include "Array.h"

int main() {
    Array *array = new Array(20);
    for (int i = 0; i < 10; ++i) {
        array->addLast(i);
    }
    array->print();
    array->add(1, 100);
    array->addFirst(-1);
    array->print();
    array = nullptr;
    delete array;
    return 0;
}
