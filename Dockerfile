FROM ubuntu:latest
LABEL authors="lsc"

RUN apt-get update
RUN apt-get install apt-utils
RUN apt-get update
RUN apt-get install -y g++ make cmake gcc ipmitool lm-sensors
COPY . /app
WORKDIR /app
RUN mkdir build
RUN cd build
RUN cmake ..
RUN make .

CMD ["./FanSpeedControl"]