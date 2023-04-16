# FanSpeedControl
This is a project which could control Fan Speed of Lenovo ThinkServer RD430X
## mechine info
```text
CPU0 : Xeon E5-2680 v4
CPU1 : Xeon E5-2680 v4
Fan x 3
```
In this version, we have not introduced GPU.Although it has two pciex16 and three pciex4
maybe in the future it is possible to control GPU fans independently.Also,this project just support x86 machine
## The principle of this project:
1. get cpu info from linux api.it could get every CPU core temp and cpu info.
2. with the parameter of temp,decide how to control fan speed via ipmitool instruction
3. it may be problem for this project that we could decide which model the server in ,such as boost,powerful or quiet

if your server is different from mine,there maybe some mistakes when you run this project
bacause there maybe some difference between different mechine about ipmitool instruction
if you have some good idea,welcome to contact me.
## how to install
1. git clone https://github.com/DailyNoBug/FanSpeedControl.git
2. apt update
3. apt install docker.io
4. cd FanSpeedControl
5. docker build -t fanspeedcontrol .
6. docker run --network host fanspeedcontrol