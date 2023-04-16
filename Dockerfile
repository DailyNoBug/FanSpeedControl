FROM gcc:latest
LABEL authors="lsc"

RUN apt-get update
RUN apt-get install -y cmake ipmitool lm-sensors
COPY . /app
VOLUME /app
WORKDIR /app
RUN cmake .
RUN make .

CMD ["bash ./setup.sh"]
