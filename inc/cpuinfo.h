//
// Created by lsc on 23-4-16.
//

#ifndef FANSPEEDCONTROL_CPUINFO_H
#define FANSPEEDCONTROL_CPUINFO_H
#include <iostream>
//#include <stdint.h>
#include <cstring>
#include <fstream>
#include <iomanip>
class CPUInfo {
public:
    int phyCpuNum;
    int coreNumber;
    std::string modelName[256];
    int temp;
    void getInfo();
    void printInfo();
    void getTemp();
};


#endif //FANSPEEDCONTROL_CPUINFO_H
