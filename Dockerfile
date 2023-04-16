FROM ubuntu:latest
LABEL authors="lsc"

RUN apt-get update && \
    apt-get install -y g++ make cmake gcc && \
    rm -rf /var/lib/apt/lists/* \
COPY . /app
WORKDIR /app
RUN mkdir build && cd build
RUN cmake ..
RUN make .

CMD ["./FanSpeedControl"]