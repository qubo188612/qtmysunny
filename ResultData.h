#ifndef RESULTDATA_H
#define RESULTDATA_H
#include "global.h"
#include "opencv2/opencv.hpp"
#include <modbus/modbus.h>
#include <QThread>
#include <QTcpSocket>
#ifdef DEBUG_SSH
#include <CConnectionForSshClient.h>
#endif
#include "calibration.h"

#define MODBUS_ROBOT_REGISTERS_NUM      0x10
#define MODBUS_RESULT_MAXNUM            400
#define MODBUS_PARAM_MAXNUM             400

class taskinfo
{
public:
    uint16_t taskname;      //任务号
    uint16_t alsnum;        //算法号
};

class rob_pinfo
{
public:
  float x;
  float y;
  float z;
  float rx;
  float ry;
  float rz;
  int32_t out1;
  int32_t out2;
  int32_t out3;
  uint16_t tool;
  uint16_t tcp;
  uint16_t usertcp;

  float uy;
  float vz;
  rob_pinfo();
};

class rob_group
{
public:
  std::vector<rob_pinfo> pos;
  int pID;
};

class craftinfo
{
public:
    int16_t craft_Id;
    int16_t craft_als1;
    int16_t craft_als2;
    int16_t craft_als3;
    int16_t craft_als4;
    int16_t craft_als5;
    int16_t craft_als6;
    int16_t craft_als7;
    int16_t craft_als8;
    int16_t craft_als9;
    int16_t craft_als10;
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

    std::vector<double> homography_matrix;//激光器中的相机内参
    std::vector<double> pData_demdlg_R;//激光器中的眼在手外标定矩阵R
    std::vector<double> pData_demdlg_T;//激光器中的眼在手外标定矩阵T
    std::vector<double> pData_matrix_camera2plane;//激光器中的眼在手上标定矩阵
    std::vector<double> pData_matrix_plane2robot;//激光器中的眼在手上标定矩阵

    CAL_POSTURE P_data_cal_posture; //P变量姿态内外旋
    Eye_Hand_calibrationmode P_data_eye_hand_calibrationmode;//P寄存器激光器安装方式
    std::vector<rob_group> P_data; //P变量
    craftinfo P_data_craftinfo;//P变量工艺

    modbus_t *ctx_robotset;
    modbus_t *ctx_param;
    modbus_t *ctx_result;
    QTcpSocket *client;
#ifdef DEBUG_SSH
    bool m_bConnectState;
    bool m_bFileState;
    CConnectionForSshClient *ctx_ssh;
    QString setup_file;
    int updata_step;
    QString dockerid;
#endif

    std::vector<taskinfo> taskfilename;//当前激光器有几个任务号

    unsigned short red_robotset[MODBUS_ROBOT_REGISTERS_NUM];
    unsigned short red_robotresult[MODBUS_RESULT_MAXNUM];

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
