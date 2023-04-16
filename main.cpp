#include <iostream>
#include <unistd.h>
#include "inc/cpuinfo.h"

int main() {
    CPUInfo cpu;
    cpu.getInfo();
    cpu.printInfo();
    while(1){
        cpu.getTemp();
        sleep(1);
    }
    return 0;
}
