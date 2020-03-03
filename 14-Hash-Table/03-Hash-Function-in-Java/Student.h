//
// Created by hpf on 18-7-18.
//

#ifndef HASH_STUDENT_H
#define HASH_STUDENT_H

#include <string>
#include <algorithm>
#include <functional>

using namespace std;

class Student {
private:
    int grade;
    int cls;
    std::string firstName;
    std::string lastName;

public:
    Student(int grade, int cls, std::string firstName, std::string lastName) {
        this->grade = grade;
        this->cls = cls;
        this->firstName = firstName;
        this->lastName = lastName;
    }

    int hashCode() {
        std::hash<int> hash_int;
        std::hash<std::string> hash_string;
        transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);
        transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);
        int B = 31;
        int hash = 0;
        hash = hash * B + hash_int(grade);
        hash = hash * B + hash_int(cls);
        hash = hash * B + hash_string(firstName);
        hash = hash * B + hash_string(lastName);
        return hash;
    }

    bool isequals(const Student &another) {
        transform(firstName.begin(), firstName.end(), firstName.begin(), ::tolower);
        transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);
        std::string anotherFirstName = another.firstName;
        std::string anotherLastName = another.lastName;
        transform(anotherFirstName.begin(), anotherFirstName.end(), anotherFirstName.begin(), ::tolower);
        transform(anotherLastName.begin(), anotherLastName.end(), anotherLastName.begin(), ::tolower);
        return this->grade == another.grade &&
               this->cls == another.cls &&
               this->firstName == anotherFirstName &&
               this->lastName == anotherLastName;
    }
};

#endif //HASH_STUDENT_H
