#ifndef RESULTDATA_H
#define RESULTDATA_H
#include "opencv2/opencv.hpp"
#include <modbus/modbus.h>
#include <QThread>


#define MODBUS_ROBOT_REGISTERS_NUM      10
#define MODBUS_RESULT_MAXNUM            400
#define MODBUS_PARAM_MAXNUM             400

class modbustcpThread;

class ResultData
{
public:
    ResultData();
    ~ResultData();

    cv::Mat cv_image;                                                //激光原图

    uint8_t link_result_state;
    uint8_t link_param_state;
    uint8_t link_robotset_state;
    uint8_t b_luzhi;

    modbus_t *ctx_robotset;     //机器人参数表
    modbus_t *ctx_param;        //激光头参数表
    modbus_t *ctx_result;       //激光头结果表

    unsigned short red_robotset[MODBUS_ROBOT_REGISTERS_NUM];

    /******************/
    uint16_t alg0_99_threshold;      //任务0-99曝光值
    uint16_t alg100_threshold;       //任务100曝光值
    uint16_t alg101_threshold;       //任务101曝光值
    uint16_t alg102_threshold;       //任务102曝光值


protected:

};

#endif // RESULTDATA_H
