#ifndef MY_PARAMETERS_H
#define MY_PARAMETERS_H


#include <opencv2/opencv.hpp>
#include "cam_sen.h"
#include "soptopcamera.h"
#include "ResultData.h"
#include "E2proomData.h"

class Cam_Sen;
class SoptopCamera;

class my_parameters
{
public:
    static my_parameters *Get();

    Cam_Sen *cam;    //相机

    ResultData resultdata;		//实时结果数据

    E2proomData e2proomdata;

protected:
    my_parameters();
    ~my_parameters();
};

#endif // MY_PARAMETERS_H
