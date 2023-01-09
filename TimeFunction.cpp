#include "TimeFunction.h"

TimeFunction::TimeFunction()
{

}

TimeFunction::~TimeFunction()
{

}

void TimeFunction::get_time_ms(std::string *timeOut)
{
#if _MSC_VER
    typedef struct
    {
        __int64 tv_sec;
        __int64 tv_usec;
    }timeval;
    timeval tv;
#else
    struct timeval tv;
#endif
    struct tm* ptm;
    char time_string[40];
    char time_string2[40];
    long milliseconds;
#if _MSC_VER
    auto time_now = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
    auto duration_in_s = std::chrono::duration_cast<std::chrono::seconds>(time_now.time_since_epoch()).count();
    auto duration_in_us = std::chrono::duration_cast<std::chrono::microseconds>(time_now.time_since_epoch()).count();
    tv.tv_sec = duration_in_s;
    tv.tv_usec = duration_in_us;
    ptm = localtime (&(tv.tv_sec));
    milliseconds = (tv.tv_usec-tv.tv_sec*1000000) / 1000;
#else
    gettimeofday(&tv, NULL);
    ptm = localtime (&(tv.tv_sec));
    milliseconds = tv.tv_usec / 1000;
#endif 
    strftime (time_string, sizeof(time_string), "%Y_%m_%d_%H_%M_%S", ptm);
    snprintf (time_string2, sizeof(time_string2), "%s_%03ld", time_string, milliseconds);
    (*timeOut)=time_string2;
}

void TimeFunction::get_time_ms(u_int16_t &Y,u_int16_t &m,u_int16_t &d,u_int16_t &H,u_int16_t &M,u_int16_t &S,u_int16_t &ms)
{
#if _MSC_VER
    typedef struct
    {
        __int64 tv_sec;
        __int64 tv_usec;
    }timeval;
    timeval tv;
#else
    struct timeval tv;
#endif
    struct tm* ptm;
    long milliseconds;
#if _MSC_VER
    auto time_now = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
    auto duration_in_s = std::chrono::duration_cast<std::chrono::seconds>(time_now.time_since_epoch()).count();
    auto duration_in_us = std::chrono::duration_cast<std::chrono::microseconds>(time_now.time_since_epoch()).count();
    tv.tv_sec = duration_in_s;
    tv.tv_usec = duration_in_us;
    ptm = localtime (&(tv.tv_sec));
    milliseconds = (tv.tv_usec-tv.tv_sec*1000000) / 1000;
#else
    gettimeofday(&tv, NULL);
    ptm = localtime (&(tv.tv_sec));
    milliseconds = tv.tv_usec / 1000;
#endif

    Y=ptm->tm_year+1900;
    m=ptm->tm_mon+1;
    d=ptm->tm_mday;
    H=ptm->tm_hour;
    M=ptm->tm_min;
    S=ptm->tm_sec;
    ms=milliseconds;
}
