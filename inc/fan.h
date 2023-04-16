//
// Created by lsc on 23-4-16.
//

#ifndef FANSPEEDCONTROL_FAN_H
#define FANSPEEDCONTROL_FAN_H
#include <iostream>
#include <cstdio>
class Fan {
public:
    int speed;
    void decision(int temp);
    void err();
private:
    void excute(int speed);
};
#endif //FANSPEEDCONTROL_FAN_H
