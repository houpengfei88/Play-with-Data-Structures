//
// Created by hpf on 18-5-8.
//

#include <ostream>
#include <string>

class Student {
public:
    Student(std::string studentName ="", int studentScore = 0) {
        name = studentName;
        score = studentScore;
    }

    friend std::ostream & operator<<(std::ostream &out, Student &student) {
        out << "name : " << student.name << ", " << " score : " << student.score;
	    return out;
    }

private:
    std::string name;
    int score;
};
