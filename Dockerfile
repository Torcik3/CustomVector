FROM ubuntu

WORKDIR ./app
RUN apt-get update && apt-get install -y build-essential cmake

COPY . .

RUN  mkdir build && cd build && cmake ..  && make

CMD ["./build/Cmemory"]