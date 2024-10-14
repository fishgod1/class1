#include <iostream>
#include "Student.h"

void Student::input() {
    std::cout << "请输入学生学号: ";
    std::cin >> studentID;
    std::cout << "请输入学生姓名: ";
    std::cin >> name;
}

std::string Student::getStudentID() const {
    return studentID;
}

std::string Student::getName() const {
    return name;
}
void Student::setStudentID(const std::string& id) {
    studentID = id;
}

void Student::setName(const std::string& name) {
    this->name = name;
}

