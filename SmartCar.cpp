#include <iostream>
#include "SmartCar.h"

SmartCar::SmartCar() {
    // 默认值初始化
    chassisID = "dpXXXXXXXX"; // 默认底盘编号
    model = "SCOUT MINI";
    wheelbase = 451; // mm
    wheelTrack = 490; // mm
    minGroundClearance = 115; // mm
    minTurningRadius = 0; // m
    driveType = "四轮四驱";
    maxRange = 10; // KM
    tireModels[0] = "公路轮";
    tireModels[1] = "麦克纳姆轮";
    tireSize = 175; // mm
    
    agxModel = "AGX Xavier";
    aiPerformance = 32; // TOPS
    cudaCores = 512;
    tensorCores = 64;
    memory = 32; // GB
    storage = 32; // GB

    cameraModel = "RealSense D435i";
    cameraResolution = "1920x1080";
    cameraFrameRate = 30;
    fov = "87x58";
    depthFrameRate = 90;

    lidarModel = "RS-Helios-16p";
    lidarChannels = 16;
    testRange = 100; // m
    powerConsumption = 8; // W

    gyroModel = "CH110";
    gyroManufacturer = "NXP";

    lcdSize = 11.6; // inch
    batteryParameters = "24V/15Ah";
    externalPower = 24; // V
    chargingTime = 2; // hours
}

void SmartCar::inputCarInfo() {
    std::cout << "请输入小车编号 (格式: cqusnXXXXXXXXXXXX): ";
    std::cin >> carID;
}

void SmartCar::assignStudent(const Student& student) {
    assignedStudent = student;
}

void SmartCar::saveToFile(std::ofstream& file) const {
    file << "小车编号: " << carID << "\n"
         << "分配的学生学号: " << assignedStudent.getStudentID() << "\n"
         << "分配的学生姓名: " << assignedStudent.getName() ;
}

void SmartCar::loadFromFile(std::ifstream& file) {
    // 从文件中加载数据
    std::getline(file, carID);
    
    std::string studentID;
    std::string studentName;

    std::getline(file, studentID);
    std::getline(file, studentName);
    
    // 将读取的学生信息赋值给 assignedStudent
    assignedStudent = Student(); // 创建一个新的学生对象
    assignedStudent.setStudentID(studentID); // 假设你在 Student.h 中添加了 setStudentID 方法
    assignedStudent.setName(studentName); // 假设你在 Student.h 中添加了 setName 方法
}

std::string SmartCar::getCarID() const {
    return carID;
}

std::string SmartCar::getAssignedStudentID() const {
    return assignedStudent.getStudentID();
}

std::string SmartCar::getAssignedStudentName() const {
    return assignedStudent.getName();
}

Student SmartCar::getAssignedStudent() const {
    return assignedStudent; // 返回分配的学生对象
}
