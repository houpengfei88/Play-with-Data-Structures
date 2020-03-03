#include <iostream>
#include <functional>
#include <string>
#include "Student.h"

using namespace __gnu_cxx;
int main() {
    std::hash<int> hash_int;
    std::hash<double> hash_double;
    std::hash<std::string> hash_string;
    int a = 42;
    std::cout << hash_int(a) << std::endl;

    int b = -42;
    std::cout << hash_int(b) << std::endl;

    double c = 3.1415926;
    std::cout << hash_double(c) << std::endl;

    std::string d = "imooc";
    std::cout << hash_string(d) << std::endl;

    std::cout << INT64_MAX + 1 << std::endl;

    Student student(3, 2, "Bobo", "Liu");
    std::cout << student.hashCode() << std::endl;

    Student student2(3, 2, "BObO", "LIU");
    std::cout << student2.hashCode() << std::endl;

    std::cout << std::boolalpha << student.isequals(student2) << std::endl;

    return 0;
}