#include <iostream>
#include "Array.h"
#include "Student.h"

int main() {
    Array<Student> *array = new Array<Student>(20);
    array->addLast(Student("Alice",100));
    array->addLast(Student("Bob",66));
    array->addLast(Student("Charlie",88));
    array->print();
    array = nullptr;
    delete array;
    return 0;
}
