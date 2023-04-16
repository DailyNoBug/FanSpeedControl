#include <iostream>
#include <unistd.h>
#include "inc/cpuinfo.h"
#include "fan.h"
int main() {
    CPUInfo cpu;
    Fan sfan;
    cpu.getInfo();
    cpu.printInfo();
    while(1){
        cpu.getTemp();
        sfan.decision(cpu.temp);
        sleep(2);
        printf("[INFO]  Temp: %d    Speed: %d\n",cpu.temp,sfan.speed);
    }
    return 0;
}
