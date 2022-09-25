FROM qubo188612/ubuntu20.04:latest AS latest

COPY ./qtmysunnyexe /workspace/qtmysunny

RUN sudo apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && sudo apt-get -y install --no-install-recommends  \
    fonts-noto-cjk \
    && sudo rm -rf /var/lib/apt/lists/*
    
RUN sudo chmod -R 777 /workspace/qtmysunny

WORKDIR /workspace/qtmysunny

CMD ["/workspace/qtmysunny/qtmysunny.sh"]
