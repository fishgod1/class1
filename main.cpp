#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include "SmartCar.h"
#include "Student.h"

int main() {
    std::vector<SmartCar> smartCars(10);
    std::vector<Student> students(10);
    
    // 输入小车信息
    for (int i = 0; i < 10; ++i) {
        std::cout << "=== 输入第 " << (i + 1) << " 台小车信息 ===\n";
        smartCars[i].inputCarInfo();
    }

    // 输入学生信息
    for (int i = 0; i < 10; ++i) {
        std::cout << "=== 输入第 " << (i + 1) << " 名学生信息 ===\n";
        students[i].input();
    }

    // 分配小车给学生
    for (int i = 0; i < 10; ++i) {
        smartCars[i].assignStudent(students[i]);
    }

    // 将信息保存到文件
    std::ofstream outFile("cars_data.txt");
    if (!outFile) {
        std::cerr << "无法打开文件保存数据!\n";
        return 1;
    }

    for (const auto& car : smartCars) {
        car.saveToFile(outFile);
        outFile << "\n"; // 每个小车信息间隔一行
    }
    outFile.close();

    // 从文件中读取信息并显示
    std::ifstream inFile("cars_data.txt");
    if (!inFile) {
        std::cerr << "无法打开文件读取数据!\n";
        return 1;
    }

    std::string line;
    int currentIndex = 0;
    std::vector<SmartCar> loadedCars;

    // 读取文件数据并加载小车信息
    while (!inFile.eof()) {
        SmartCar car;
        car.loadFromFile(inFile);  // 从文件加载小车信息
        loadedCars.push_back(car);
    }
    inFile.close();

    char ch;
    while (true) {
        system("cls");
        if (currentIndex < 0) {
            currentIndex = 0;
        }
        if (currentIndex >= loadedCars.size()) {
            currentIndex = loadedCars.size() - 1;
        }

        // 显示当前小车的信息
        std::cout << "=== 小车信息 ===\n";
        std::cout  << loadedCars[currentIndex].getCarID() << "\n"; // 显示小车编号
        std::cout  << loadedCars[currentIndex].getAssignedStudentID() << "\n"; // 学生学号
        std::cout  << loadedCars[currentIndex].getAssignedStudentName() << "\n"; // 学生姓名
        std::cout << "按 n 键查看下一辆小车，按 p 键查看上一辆，按 q 键退出";

        ch = _getch();
        if (ch == 'n' || ch == 'N') {
            currentIndex++; // 每个小车信息占用1行
        } else if (ch == 'p' || ch == 'P') {
            currentIndex--;
        } else if (ch == 'q' || ch == 'Q') {
            break;
        }
    }

    return 0;
}
