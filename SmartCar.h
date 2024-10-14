#ifndef SMARTCAR_H
#define SMARTCAR_H

#include <string>
#include <fstream>
#include "Student.h"

class SmartCar {
private:
    std::string carID;
    std::string chassisID;
    std::string model;
    int wheelbase;
    int wheelTrack;
    int minGroundClearance;
    int minTurningRadius;
    std::string driveType;
    int maxRange;
    std::string tireModels[4];
    int tireSize;
    
    std::string agxModel;
    int aiPerformance;
    int cudaCores;
    int tensorCores;
    int memory;
    int storage;

    std::string cameraModel;
    std::string cameraResolution;
    int cameraFrameRate;
    std::string fov;
    int depthFrameRate;

    std::string lidarModel;
    int lidarChannels;
    int testRange;
    int powerConsumption;

    std::string gyroModel;
    std::string gyroManufacturer;

    double lcdSize;
    std::string batteryParameters;
    int externalPower;
    int chargingTime;

    Student assignedStudent;// 假设这个成员变量存储分配的学生信息

public:
    SmartCar();
    void inputCarInfo();
    void assignStudent(const Student& student);
    void display() const;
    void saveToFile(std::ofstream& file) const;
    void loadFromFile(std::ifstream& file);
    std::string getCarID() const;
    std::string getAssignedStudentID() const;
    std::string getAssignedStudentName() const;
    public:
    Student getAssignedStudent() const; // 添加这个声明
};

#endif // SMARTCAR_H
