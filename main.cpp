#include <iostream>
#include "inc/cpuinfo.h"

int main() {
    CPUInfo cpu;
    cpu.getInfo();
    cpu.printInfo();
    cpu.getTemp();
    return 0;
}
