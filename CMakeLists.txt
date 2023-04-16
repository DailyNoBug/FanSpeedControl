cmake_minimum_required(VERSION 3.15)
project(FanSpeedControl)

set(CMAKE_CXX_STANDARD 17)
include_directories(inc)
set(SOURCES src/cpuinfo.cpp main.cpp src/fan.cpp)
add_executable(FanSpeedControl ${SOURCES})