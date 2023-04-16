//
// Created by lsc on 23-4-16.
//
#include "fan.h"
void Fan::decision(int temp) {
    if(temp<=10)err();
    char cmd[128];
    this->speed=0;
    double bi=0.0;
    if(temp<=35){
        this->speed = 10;
    }else if(temp>35 &&temp<=60){
        bi = (temp-35.0)*1.0/25.0;
        this->speed = bi*15+10;
    }else if(temp>60 && temp<=85){
        this->speed = temp - 35;
    }else{
        this->speed = (temp - 85)*2 + 50;
    }
    Fan::excute(this->speed);
}
void Fan::err() {
    exit(0);
}
void Fan::excute(int speed) {
    char cmd[128];
    sprintf(cmd,"ipmitool -I lanplus -H 192.168.3.234 -U root -P root raw 0x2e 0x30 00 00 %d\n",speed);
    std::system(cmd);
}