//
// Created by lsc on 23-4-16.
//

#include "../inc/cpuinfo.h"
#include <cstdlib>
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
void CPUInfo::getTemp() {
    this->temp = 0;
    std::string cmd = "sensors | grep Core";
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) {
        std::cerr << "popen() failed!" << std::endl;
    }
    char buffer[128];
    std::string line;

    while(fgets(buffer, sizeof(buffer), pipe) != NULL) {
        line.assign(buffer);
        line = line.substr(line.find(":")+10);
        line = line.erase(line.find('.'));
        this->temp = std::max(this->temp, std::stoi(line));
//        double temperature = std::stod(buffer);
//        std::cout << "Temperature: " << temperature << std::endl;
    }
    pclose(pipe);
//    std::cout<<this->temp<<std::endl;
}