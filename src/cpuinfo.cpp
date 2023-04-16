//
// Created by lsc on 23-4-16.
//

#include "../inc/cpuinfo.h"

void CPUInfo::getInfo() {
    std::ifstream infile("/proc/cpuinfo");
    std::string line;
    this->phyCpuNum=0;
    while(std::getline(infile,line)){
        if(line.substr(0,10) == "model name"){
            this->modelName[this->coreNumber] = line.substr(line.find(":")+2);
        }else if(line.substr(0,11) == "physical id" ){
//            std::cout<<"[INFO] "<<line.substr(line.find(":")+1)<<std::endl;
            this->phyCpuNum = std::max(this->phyCpuNum, std::stoi(line.substr(line.find(":")+1))+1);
        }else if(line.find("processor") != std::string::npos){
            this->coreNumber++;
        }
    }
}
void CPUInfo::printInfo() {
    std::cout<<"CPU number      : "<<this->phyCpuNum<<std::endl;
    std::cout<<"CPU core number : "<<this->coreNumber<<std::endl;
    for(int core = 1;core<=this->coreNumber;core++)
        std::cout<<"CPU core number "<<std::setw(3)<<core<<" : "<<this->modelName[core]<<std::endl;
}
void CPUInfo::getCoreTemp(int coreNum) {
    char filename[64];
    std::sprintf(filename,"/sys/class/thermal/thermal_zone%d/temp",coreNum);
    std::ifstream  file(filename);
    if (file.is_open()) {
        std::string line;
        std::getline(file, line);
        int temper = std::stoi(line) / 1000;
        this->temp[coreNum] = temper;
        std::cout << "CPU"<<std::setw(3)<<coreNum<<" temperature: " << temper << " C" << std::endl;
        file.close();
    } else {
        std::cerr << "Failed to open file " << filename << std::endl;
        exit(1);
    }
}
void CPUInfo::getTemp() {
    for(int core = 0;core<this->coreNumber;core++){
        CPUInfo::getCoreTemp(core);
    }
}