FROM qubo188612/ubuntu20.04:latest AS latest

COPY ./qtmysunnyexe /workspace/qtmysunny
    
RUN sudo chmod -R 777 /workspace/qtmysunny

WORKDIR /workspace/qtmysunny

CMD ["/workspace/qtmysunny/qtmysunny.sh"]
