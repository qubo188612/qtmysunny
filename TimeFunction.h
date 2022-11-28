#ifndef TIMEFUNCTION_H
#define TIMEFUNCTION_H

#include <global.h>
#include <stdio.h>
#include <stdlib.h>
#if _MSC_VER
#include<chrono>
#else
#include <sys/time.h>
#endif
#include <time.h>
#include <string>

//#include <QString>

class TimeFunction
{
public:
    TimeFunction();
    ~TimeFunction();

    void get_time_ms(std::string *timeOut);

    void get_time_ms(u_int16_t &Y,u_int16_t &m,u_int16_t &d,u_int16_t &H,u_int16_t &M,u_int16_t &S,u_int16_t &ms);
};
#endif
