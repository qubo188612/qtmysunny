#ifndef CAM_SEN_H
#define CAM_SEN_H

#include "soptopcamera.h"
#if _MSC_VER
#include "soptocameratcpip.h"
#endif

class my_parameters;

class Cam_Sen
{
public:
    static Cam_Sen *Get();

/****************************/
//soptop相机
#if _MSC_VER
    Soptocameratcpip sop_cam[CAMTOTALNUM];
#else
    SoptopCamera sop_cam[CAMTOTALNUM];
#endif

/****************************/
//其他相机

/****************************/
protected:
    Cam_Sen();
    ~Cam_Sen();
};

#endif // CAM_SEN_H
