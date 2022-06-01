FROM debian:stable
RUN apt-get update && apt-get install build-essential bash -y


WORKDIR /app
COPY main.cpp .
RUN g++ -g -fno-omit-frame-pointer -o parca-demo main.cpp && chmod +x /app/parca-demo

CMD ["/bin/bash", "-c", "/app/parca-demo"]
