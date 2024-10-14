#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string studentID;
    std::string name;

public:
    void input();
    std::string getStudentID() const;
    std::string getName() const;

    // 新增的setter方法
    void setStudentID(const std::string& id);
    void setName(const std::string& name);
};

#endif // STUDENT_H
