FROM qubo188612/ubuntu20.04:opencv4.2 AS opencv
FROM qubo188612/ubuntu20.04:opencvrosqtmodbus AS run

COPY --from=opencv /opt/opencv4.2 /lib/x86_64-linux-gnu
COPY ./myRos2test/install /workspace/myRos2test/install
COPY ./build-qtmysunny-Replacement_for_Desktop_Qt_5_12_12_GCC_64bit-Release /workspace/qtmysunny

RUN sudo apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && sudo apt-get -y install --no-install-recommends  \
    libtbb2 \
    libopenexr-dev \
    libgdcm-tools \
    libgdal-dev \
    libdc1394-22-dev \
    libdc1394-22 \
    libdc1394-utils \
    libavcodec-dev \
    libavformat-dev \
    libswscale-dev \
    && sudo rm -rf /var/lib/apt/lists/*
    
RUN sudo chmod -R 777 /workspace/qtmysunny

WORKDIR /workspace/qtmysunny
RUN sed -i '$c source /workspace/myRos2test/install/local_setup.sh' /home/linuxbrew/.bashrc

CMD [ "/bin/bash","./qtmysunny" ]
