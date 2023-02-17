#ifndef RESULTDATA_H
#define RESULTDATA_H
#include "global.h"
#include "opencv2/opencv.hpp"
#include <modbus/modbus.h>
#include <QThread>
#include <QTcpSocket>
#ifdef DEBUS_SSH
#include <CConnectionForSshClient.h>
#endif

#define MODBUS_ROBOT_REGISTERS_NUM      0x10
#define MODBUS_RESULT_MAXNUM            400
#define MODBUS_PARAM_MAXNUM             400

class taskinfo
{
public:
    uint16_t taskname;      //任务号
    uint16_t alsnum;        //算法号
};

class modbustcpThread;

class ResultData
{
public:
    ResultData();
    ~ResultData();

    uint8_t link_result_state;
    uint8_t link_param_state;
    uint8_t link_robotset_state;
    uint8_t link_ftp_state;
    uint8_t b_luzhi;

    modbus_t *ctx_robotset;
    modbus_t *ctx_param;
    modbus_t *ctx_result;
    QTcpSocket *client;
#ifdef DEBUS_SSH
    bool m_bConnectState;
    bool m_bFileState;
    CConnectionForSshClient *ctx_ssh;
    QString setup_file;
    int updata_step;
    QString dockerid;
#endif

    std::vector<taskinfo> taskfilename;//当前激光器有几个任务号

    unsigned short red_robotset[MODBUS_ROBOT_REGISTERS_NUM];

    /******************/
    uint16_t alg0_99_threshold;
    uint16_t alg100_threshold;
    uint16_t alg101_threshold;
    uint16_t alg102_threshold;
    uint16_t alg103_threshold;
    uint16_t alg104_threshold;
    uint16_t alg105_threshold;
    uint16_t alg106_threshold;
    uint16_t alg107_threshold;
    uint16_t alg108_threshold;

protected:

};

#endif // RESULTDATA_H
