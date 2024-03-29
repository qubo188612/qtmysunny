﻿#ifndef GLOBAL_H
#define GLOBAL_H

//#define WINDOWS_TCP 1   //linux仿windowstcp传输相机图像测试开关
#if _MSC_VER
#include "tistdtypes.h"

typedef uint8_t u_int8_t; /* u_int8_t is defined in <machine/types.h> */
typedef uint16_t u_int16_t; /* u_int16_t is defined in <machine/types.h> */
typedef uint32_t u_int32_t; /* u_int32_t is defined in <machine/types.h> */
typedef uint64_t u_int64_t; /* u_int64_t is defined in <machine/types.h> */
#endif

#define DEBUG_TIMEFPS               //上位机和下位机时间戳测试开关
#define DEBUG_MYINTERFACES          //显示算法结果或者算法原图开关
#define DEBUG_SSH                   //ssh升级方式开关
//#define DEBUG_CLOUD_TCP             //tcp显示轮廓

#define CAMBUILD_IMAGE_WIDTH  1024
#define CAMBUILD_IMAGE_HEIGHT 1536

#define CAMTOTALNUM                 1

#define CLOULD_POINT_NOTDATE        FLT_MAX

/*************************/
//采集模式
#define AUTO_MOD                    0
#define CALLBACK_MOD                1
#define ACQUISITION_MOD             AUTO_MOD
/***************************/

#define ROWS_PROPORTION              1.0
#define COLS_PROPORTION              1.0

#define DEEPIMG_CALLBACKNUM_DNUM     5

#define ROB_WORK_DELAY_STEP     10000        //机器人每步循环等待时间(微秒)

/*****************************/
//相机任务号文件查询TCP传输端口
#define PORT_ALSTCP_FTP                       1476
//相机原图TCP传输端口
#define PORT_ALSTCP_CAMIMAGE                  1497
//相机处理结果图TCP传输端口
#define PORT_ALSTCP_CAMIMAGE_RESULT           1498
//点云轨迹处理结果TCP传输端口
#define PORT_ALSTCP_POINTCLOUDS_RESULT        1499

/*****************************/
//激光头算法参数寄存器
#define PORT_ALS_PARAMETER                    1500  //端口号1500: 激光头参数端口号

#define TASKNUM_START   100         //激光头框架2起始任务号


#define ALS100_EXPOSURE_TIME_REG_ADD           0x0000
#define ALS100_PINGJUN_REG_ADD                 0x0001
#define ALS100_B_YANMOFUZHU_REG_ADD            0x0002
#define ALS100_B_GUDINGQUYU_REG_ADD            0x0003
#define ALS100_WIDTHLIANTONGDIS_REG_ADD        0x0004
#define ALS100_HIGHLIANTONGDIS_REG_ADD         0x0005
#define ALS100_GUJIAERZHI_REG_ADD              0x0006
#define ALS100_JIGUANGHIGHT_REG_ADD            0x0007
#define ALS100_JIGUANGLONG_REG_ADD             0x0008
#define ALS100_JIGUANGKUANDU_REG_ADD           0x0009
#define ALS100_UPDIF_REG_ADD                   0x000a
#define ALS100_UPDIFMIN_REG_ADD                0x000b
#define ALS100_UPLONG_REG_ADD                  0x000c
#define ALS100_DOWNDIF_REG_ADD                 0x000d
#define ALS100_DOWNDIFMIN_REG_ADD              0x000e
#define ALS100_DOWNDLONG_REG_ADD               0x000f
#define ALS100_DUANXIANERZHI_REG_ADD           0x0010
#define ALS100_ERZHISIZE_REG_ADD               0x0011
#define ALS100_ERZHISIZE2_REG_ADD              0x0012
#define ALS100_SEARCHDECTANCEMAX_REG_ADD       0x0013
#define ALS100_SEARCHDECTANCEMIN_REG_ADD       0x0014
#define ALS100_DIS_CENTER_ST_REG_ADD           0x0015
#define ALS100_DIS_CENTER_ED_REG_ADD           0x0016
#define ALS100_ANSWERPOINT_REG_ADD             0x0017
#define ALS100_B_KALMANFILTER_REG_ADD          0x0018
#define ALS100_KALMANQF_REG_ADD                0x0019
#define ALS100_KALMANRF_REG_ADD                0x001a
#define ALS100_B_CUT_REG_ADD                   0x001b
#define ALS100_CUTLEFT_REG_ADD                 0x001c
#define ALS100_CUTRIGHT_REG_ADD                0x001d
#define ALS100_CUTTOP_REG_ADD                  0x001e
#define ALS100_CUTDEEP_REG_ADD                 0x001f


#define ALS100_REG_TOTALNUM                    0x0020

#define ALS100_INIT_REG_ADD                    0x002f



#define ALS101_EXPOSURE_TIME_REG_ADD           0x0030
#define ALS101_PINGJUN_REG_ADD                 0x0031
#define ALS101_B_YANMOFUZHU_REG_ADD            0x0032
#define ALS101_B_GUDINGQUYU_REG_ADD            0x0033
#define ALS101_WIDTHLIANTONGDIS_REG_ADD        0x0034
#define ALS101_HIGHLIANTONGDIS_REG_ADD         0x0035
#define ALS101_GUJIAERZHI_REG_ADD              0x0036
#define ALS101_JIGUANGHIGHT_REG_ADD            0x0037
#define ALS101_JIGUANGLONG_REG_ADD             0x0038
#define ALS101_JIGUANGKUANDU_REG_ADD           0x0039
#define ALS101_UPDIF_REG_ADD                   0x003a
#define ALS101_UPDIFMIN_REG_ADD                0x003b
#define ALS101_UPLONG_REG_ADD                  0x003c
#define ALS101_DOWNDIF_REG_ADD                 0x003d
#define ALS101_DOWNDIFMIN_REG_ADD              0x003e
#define ALS101_DOWNDLONG_REG_ADD               0x003f
#define ALS101_DUANXIANERZHI_REG_ADD           0x0040
#define ALS101_ERZHISIZE_REG_ADD               0x0041
#define ALS101_ERZHISIZE2_REG_ADD              0x0042
#define ALS101_SEARCHDECTANCEMAX_REG_ADD       0x0043
#define ALS101_SEARCHDECTANCEMIN_REG_ADD       0x0044
#define ALS101_DIS_CENTER_ST_REG_ADD           0x0045
#define ALS101_DIS_CENTER_ED_REG_ADD           0x0046
#define ALS101_ANSWERPOINT_REG_ADD             0x0047
#define ALS101_B_KALMANFILTER_REG_ADD          0x0048
#define ALS101_KALMANQF_REG_ADD                0x0049
#define ALS101_KALMANRF_REG_ADD                0x004a
#define ALS101_B_CUT_REG_ADD                   0x004b
#define ALS101_CUTLEFT_REG_ADD                 0x004c
#define ALS101_CUTRIGHT_REG_ADD                0x004d
#define ALS101_CUTTOP_REG_ADD                  0x004e
#define ALS101_CUTDEEP_REG_ADD                 0x004f

#define ALS101_REG_TOTALNUM                    0x0020

#define ALS101_INIT_REG_ADD                    0x005f


#define ALS102_EXPOSURE_TIME_REG_ADD           0x0060
#define ALS102_PINGJUN_REG_ADD                 0x0061
#define ALS102_B_YANMOFUZHU_REG_ADD            0x0062
#define ALS102_B_GUDINGQUYU_REG_ADD            0x0063
#define ALS102_WIDTHLIANTONGDIS_REG_ADD        0x0064
#define ALS102_HIGHLIANTONGDIS_REG_ADD         0x0065
#define ALS102_GUJIAERZHI_REG_ADD              0x0066
#define ALS102_JIGUANGHIGHT_REG_ADD            0x0067
#define ALS102_JIGUANGLONG_REG_ADD             0x0068
#define ALS102_JIGUANGKUANDU_REG_ADD           0x0069
#define ALS102_UPDIF_REG_ADD                   0x006a
#define ALS102_UPDIFMIN_REG_ADD                0x006b
#define ALS102_UPLONG_REG_ADD                  0x006c
#define ALS102_DOWNDIF_REG_ADD                 0x006d
#define ALS102_DOWNDIFMIN_REG_ADD              0x006e
#define ALS102_DOWNDLONG_REG_ADD               0x006f
#define ALS102_ST_DOWN_REG_ADD                 0x0070
#define ALS102_ED_DOWN_REG_ADD                 0x0071
#define ALS102_ST_UP_REG_ADD                   0x0072
#define ALS102_ED_UP_REG_ADD                   0x0073
#define ALS102_UPDIF2_REG_ADD                  0x0074
#define ALS102_UPDIFMIN2_REG_ADD               0x0075
#define ALS102_DIS_CENTER_ST_REG_ADD           0x0076
#define ALS102_DIS_CENTER_ED_REG_ADD           0x0077
#define ALS102_B_OPENGUDINGDIMIAN_REG_ADD      0x0078
#define ALS102_DIMIANPANGDINGJULI_REG_ADD      0x0079
#define ALS102_DIMIANPINGJUNSHUNUM_REG_ADD     0x007a
#define ALS102_DIS_CENTER_ST2_REG_ADD          0x007b
#define ALS102_DIS_CENTER_ED2_REG_ADD          0x007c
#define ALS102_DIS_CENTER_ST3_REG_ADD          0x007d
#define ALS102_DIS_CENTER_ED3_REG_ADD          0x007e
#define ALS102_XUEXIJULI_REG_ADD               0x007f
#define ALS102_B_PINGPOWENGDING_REG_ADD        0x0080
#define ALS102_PINGPOWENGDING_DIS_REG_ADD      0x0081
#define ALS102_B_XIELVOPEN_REG_ADD             0x0082
#define ALS102_XIELVFANWEI_REG_ADD             0x0083
#define ALS102_UPLONG2_REG_ADD                 0x0084
#define ALS102_CEBANKONGDONGDIS_REG_ADD        0x0085
#define ALS102_QIATOUQUWEI_REG_ADD             0x0086
#define ALS102_ANSWERPOINT_REG_ADD             0x0087
#define ALS102_B_KALMANFILTER_REG_ADD          0x0088
#define ALS102_KALMANQF_REG_ADD                0x0089
#define ALS102_KALMANRF_REG_ADD                0x008a


#define ALS102_REG_TOTALNUM                    0x002b

#define ALS102_INIT_REG_ADD                    0x008f


#define ALS103_EXPOSURE_TIME_REG_ADD           0x0090
#define ALS103_PINGJUN_REG_ADD                 0x0091
#define ALS103_GUJIAERZHI_REG_ADD              0x0092
#define ALS103_WIDTHLIANTONGDIS_REG_ADD        0x0093
#define ALS103_HIGHLIANTONGDIS_REG_ADD         0x0094
#define ALS103_JIGUANGLONG_REG_ADD             0x0095
#define ALS103_JIGUANGKUANDU_REG_ADD           0x0096
#define ALS103_JIGUANGDUIBIDU_REG_ADD          0x0097
#define ALS103_LVBOMOD_REG_ADD                 0x0098

#define ALS103_REG_TOTALNUM                    0x0009

#define ALS103_INIT_REG_ADD                    0x009f


#define ALS104_EXPOSURE_TIME_REG_ADD           0x00a0
#define ALS104_PINGJUN_REG_ADD                 0x00a1
#define ALS104_B_YANMOFUZHU_REG_ADD            0x00a2
#define ALS104_B_GUDINGQUYU_REG_ADD            0x00a3
#define ALS104_WIDTHLIANTONGDIS_REG_ADD        0x00a4
#define ALS104_HIGHLIANTONGDIS_REG_ADD         0x00a5
#define ALS104_GUJIAERZHI_REG_ADD              0x00a6
#define ALS104_JIGUANGHIGHT_REG_ADD            0x00a7
#define ALS104_JIGUANGLONG_REG_ADD             0x00a8
#define ALS104_JIGUANGKUANDU_REG_ADD           0x00a9
#define ALS104_UPDIF_REG_ADD                   0x00aa
#define ALS104_UPDIFMIN_REG_ADD                0x00ab
#define ALS104_UPLONG_REG_ADD                  0x00ac
#define ALS104_DOWNDIF_REG_ADD                 0x00ad
#define ALS104_DOWNDIFMIN_REG_ADD              0x00ae
#define ALS104_DOWNDLONG_REG_ADD               0x00af
#define ALS104_DIS_CENTER_ST_REG_ADD           0x00b0
#define ALS104_DIS_CENTER_ED_REG_ADD           0x00b1
#define ALS104_B_KALMANFILTER_REG_ADD          0x00b2
#define ALS104_KALMANQF_REG_ADD                0x00b3
#define ALS104_KALMANRF_REG_ADD                0x00b4


#define ALS104_REG_TOTALNUM                    0x0015

#define ALS104_INIT_REG_ADD                    0x00bf


#define ALS105_EXPOSURE_TIME_REG_ADD           0x00c0
#define ALS105_PINGJUN_REG_ADD                 0x00c1
#define ALS105_B_YANMOFUZHU_REG_ADD            0x00c2
#define ALS105_WIDTHLIANTONGDIS_REG_ADD        0x00c3
#define ALS105_HIGHLIANTONGDIS_REG_ADD         0x00c4
#define ALS105_GUJIAERZHI_REG_ADD              0x00c5
#define ALS105_JIGUANGHIGHT_REG_ADD            0x00c6
#define ALS105_JIGUANGLONG_REG_ADD             0x00c7
#define ALS105_JIGUANGKUANDU_REG_ADD           0x00c8
#define ALS105_UPDIF_REG_ADD                   0x00c9
#define ALS105_UPDIFMIN_REG_ADD                0x00ca
#define ALS105_UPLONG_REG_ADD                  0x00cb
#define ALS105_DOWNDIF_REG_ADD                 0x00cc
#define ALS105_DOWNDIFMIN_REG_ADD              0x00cd
#define ALS105_DOWNDLONG_REG_ADD               0x00ce
#define ALS105_DIS_CENTER_ST_REG_ADD           0x00cf
#define ALS105_DIS_CENTER_ED_REG_ADD           0x00d0
#define ALS105_B_CUT_REG_ADD                   0x00d1
#define ALS105_CUTLEFT_REG_ADD                 0x00d2
#define ALS105_CUTRIGHT_REG_ADD                0x00d3
#define ALS105_CUTTOP_REG_ADD                  0x00d4
#define ALS105_CUTDEEP_REG_ADD                 0x00d5
#define ALS105_GUAIDIANYUZHI_REG_ADD           0x00d6
#define ALS105_DUANDIANJULI_REG_ADD            0x00d7
#define ALS105_B_DIBUFAXIANGLIANG_REG_ADD      0x00d8
#define ALS105_ANSWERPOINT_REG_ADD             0x00d9
#define ALS105_B_USEDOWNLIANTONG_REG_ADD       0x00da
#define ALS105_B_KALMANFILTER_REG_ADD          0x00db
#define ALS105_KALMANQF_REG_ADD                0x00dc
#define ALS105_KALMANRF_REG_ADD                0x00dd
#define ALS105_CUTSIDE_UP_REG_ADD              0x00de
#define ALS105_CUTSIDE_DOWN_REG_ADD            0x00df
#define ALS105_B_ERJIEDAO_REG_ADD              0x00e0
#define ALS105_B_QUXIAN_REG_ADD                0x00e1


#define ALS105_REG_TOTALNUM                    0x0022

#define ALS105_INIT_REG_ADD                    0x00ef

#define ALS106_EXPOSURE_TIME_REG_ADD           0x00f0
#define ALS106_PINGJUN_REG_ADD                 0x00f1
#define ALS106_B_YANMOFUZHU_REG_ADD            0x00f2
#define ALS106_B_GUDINGQUYU_REG_ADD            0x00f3
#define ALS106_WIDTHLIANTONGDIS_REG_ADD        0x00f4
#define ALS106_HIGHLIANTONGDIS_REG_ADD         0x00f5
#define ALS106_GUJIAERZHI_REG_ADD              0x00f6
#define ALS106_JIGUANGHIGHT_REG_ADD            0x00f7
#define ALS106_JIGUANGLONG_REG_ADD             0x00f8
#define ALS106_JIGUANGKUANDU_REG_ADD           0x00f9
#define ALS106_B_CUT_REG_ADD                   0x00fa
#define ALS106_CUTLEFT_REG_ADD                 0x00fb
#define ALS106_CUTRIGHT_REG_ADD                0x00fc
#define ALS106_CUTTOP_REG_ADD                  0x00fd
#define ALS106_CUTDEEP_REG_ADD                 0x00fe
#define ALS106_DIFMIN_REG_ADD                  0x00ff
#define ALS106_SIDELONG_REG_ADD                0x0100
#define ALS106_UPBACK_ST_REG_ADD               0x0101
#define ALS106_UPBACK_ED_REG_ADD               0x0102
#define ALS106_DOWNBACK_ST_REG_ADD             0x0103
#define ALS106_DOWNBACK_ED_REG_ADD             0x0104
#define ALS106_UPMINDIS_REG_ADD                0x0105
#define ALS106_DOWNMINDIS_REG_ADD              0x0106
#define ALS106_UPLONG_REG_ADD                  0x0107
#define ALS106_DOWNDLONG_REG_ADD               0x0108
#define ALS106_DISCENTER_ED_REG_ADD            0x0109
#define ALS106_DUANDIANJULI_REG_ADD            0x010a
#define ALS106_POKOUMOD_REG_ADD                0x010b
#define ALS106_POKOUUPDIF_REG_ADD              0x010c
#define ALS106_POKOUUPDIFMIN_REG_ADD           0x010d
#define ALS106_POKOUUPBACK_ST_REG_ADD          0x010e
#define ALS106_POKOUUPBACK_ED_REG_ADD          0x010f
#define ALS106_POKOUDOWNDIF_REG_ADD            0x0110
#define ALS106_POKOUDOWNDIFMIN_REG_ADD         0x0111
#define ALS106_POKOUDOWNBACK_ST_REG_ADD        0x0112
#define ALS106_POKOUDOWNBACK_ED_REG_ADD        0x0113
#define ALS106_POKOUUPLONG_REG_ADD             0x0114
#define ALS106_POKOUDOWNLONG_REG_ADD           0x0115
#define ALS106_B_POKOUYAOBIAN_REG_ADD          0x0116
#define ALS106_POKOUYAOBIANHSIZE_REG_ADD       0x0117
#define ALS106_POKOUDUANXIANERZHI_REG_ADD      0x0118
#define ALS106_POKOUSEARCHDECTANCEMAX_REG_ADD  0x0119
#define ALS106_POKOUSEARCHDECTANCEMIN_REG_ADD  0x011a
#define ALS106_ANSWERPOINT_REG_ADD             0x011b
#define ALS106_B_KALMANFILTER_REG_ADD          0x011c
#define ALS106_KALMANQF_REG_ADD                0x011d
#define ALS106_KALMANRF_REG_ADD                0x011e

#define ALS106_REG_TOTALNUM                    0x002f

#define ALS106_INIT_REG_ADD                    0x011f

#define ALS107_EXPOSURE_TIME_REG_ADD           0x0120
#define ALS107_PINGJUN_REG_ADD                 0x0121
#define ALS107_B_YANMOFUZHU_REG_ADD            0x0122
#define ALS107_B_GUDINGQUYU_REG_ADD            0x0123
#define ALS107_WIDTHLIANTONGDIS_REG_ADD        0x0124
#define ALS107_HIGHLIANTONGDIS_REG_ADD         0x0125
#define ALS107_GUJIAERZHI_REG_ADD              0x0126
#define ALS107_JIGUANGHIGHT_REG_ADD            0x0127
#define ALS107_JIGUANGLONG_REG_ADD             0x0128
#define ALS107_JIGUANGKUANDU_REG_ADD           0x0129
#define ALS107_UPDIF_REG_ADD                   0x012a
#define ALS107_UPDIFMIN_REG_ADD                0x012b
#define ALS107_UPLONG_REG_ADD                  0x012c
#define ALS107_DOWNDIF_REG_ADD                 0x012d
#define ALS107_DOWNDIFMIN_REG_ADD              0x012e
#define ALS107_DOWNDLONG_REG_ADD               0x012f
#define ALS107_ST_DOWN_REG_ADD                 0x0130
#define ALS107_ED_DOWN_REG_ADD                 0x0131
#define ALS107_ST_UP_REG_ADD                   0x0132
#define ALS107_ED_UP_REG_ADD                   0x0133
#define ALS107_DIS_CENTER_ST_REG_ADD           0x0134
#define ALS107_DIS_CENTER_ST2_REG_ADD          0x0135
#define ALS107_DIS_CENTER_ED2_REG_ADD          0x0136
#define ALS107_B_KALMANFILTER_REG_ADD          0x0137
#define ALS107_KALMANQF_REG_ADD                0x0138
#define ALS107_KALMANRF_REG_ADD                0x0139

#define ALS107_REG_TOTALNUM                    0x001a

#define ALS107_INIT_REG_ADD                    0x013f

#define ALS108_EXPOSURE_TIME_REG_ADD           0x0140
#define ALS108_CENTER_X_REG_ADD                0x0141
#define ALS108_CENTER_Y_REG_ADD                0x0142
#define ALS108_SEARCT_W_REG_ADD                0x0143
#define ALS108_SEARCT_H_REG_ADD                0x0144
#define ALS108_STC_ALPHA_REG_ADD               0x0145
#define ALS108_STC_BETA_REG_ADD                0x0146
#define ALS108_STC_RHO_REG_ADD                 0x0147
#define ALS108_STC_SIGMA_REG_ADD               0x0148

#define ALS108_REG_TOTALNUM                    0x0009

#define ALS108_INIT_REG_ADD                    0x014f


#define ALS_SHOW_STEP_REG_ADD                  0x018f

/*****************************/
//激光头机器人型号和相机尺寸寄存器
#define PORT_ALSROBOTCAM_SET               1501  //端口号1501: 激光头机器人型号和相机尺寸端口号

#define ALSROBOTCAM_ROBOTMOD_REG_ADD                        0x0000  //机器人型号
#define ALSROBOTCAM_ROBOTPORT_REG_ADD                       0x0001  //机器人端口号
#define ALSROBOTCAM_COMPENSATION_X                          0x0002  //标定补偿X
#define ALSROBOTCAM_COMPENSATION_Y                          0x0003  //标定补偿Y
#define ALSROBOTCAM_COMPENSATION_Z                          0x0004  //标定补偿Z
#define ALSROBOTCAM_CAMWIDTH_REG_ADD                        0x0005  //相机算法宽度
#define ALSROBOTCAM_CAMHEIGHT_REG_ADD                       0x0006  //相机算法高度
#define ALSROBOTCAM_CAMFPS_REG_ADD                          0x0007  //相机帧率
#define ALSROBOTCAM_VIEW_CAM_WIDTH_REG_ADD                  0x0008  //相机视野宽度
#define ALSROBOTCAM_VIEW_CAM_HEIGHT_REG_ADD                 0x0009  //相机视野高度
#define ALSROBOTCAM_REVERSE_Y_REG_ADD                       0x000a  //相机Y数据反向
#define ALSROBOTCAM_REVERSE_Z_REG_ADD                       0x000b  //相机Z数据反向
#define ALSROBOTCAM_P_DATA_EN_REG_ADD                       0x000c  //P寄存器功能开关
#define ALSROBOTCAM_P_DATA_CAL_POSTURE_REG_ADD              0x000d  //P变量姿态内外旋
#define ALSROBOTCAM_P_DATA_EYE_HAND_CALIBRATIONMODE_REG_ADD 0x000e  //P寄存器激光器安装方式
#define ALSROBOTCAM_ROBOTIPADDRESS_1_REG_ADD                0x000f  //机器人IP1,机器人为服务器时使用
#define ALSROBOTCAM_ROBOTIPADDRESS_2_REG_ADD                0x0010  //机器人IP2,机器人为服务器时使用
#define ALSROBOTCAM_ROBOTIPADDRESS_3_REG_ADD                0x0011  //机器人IP3,机器人为服务器时使用
#define ALSROBOTCAM_ROBOTIPADDRESS_4_REG_ADD                0x0012  //机器人IP4,机器人为服务器时使用

/*****************************/
//激光头计算结果寄存器
#define PORT_ALS_RESULT                    1502  //端口号1502: 激光头计算结果寄存器

#define ALS_VERSION_REG_ADD                     0x0000  //版本号
#define ALS_DELAY_REG_ADD                       0x0001  //延迟
#define ALS_STATE_REG_ADD                       0x0002  //搜索状态
#define ALS_Y_POINT1_REG_ADD                    0x0003  //Y坐标POINT1
#define ALS_Z_POINT1_REG_ADD                    0x0004  //Z坐标POINT1
#define ALS_WELD_WIDTH_REG_ADD                  0x0005  //焊缝Y法向量
#define ALS_WELD_HIGHT_REG_ADD                  0x0006  //焊缝Z法向量
#define ALS_TIMESTAMP_HOURS_REG_ADD             0x0007  //时间戳时
#define ALS_TIMESTAMP_MINUTES_REG_ADD           0x0008  //时间戳分
#define ALS_TIMESTAMP_SECONDS_REG_ADD           0x0009  //时间戳秒
#define ALS_TIMESTAMP_MILLISECONDS_REG_ADD      0x000a  //时间戳毫秒
#define ALS_RESULT_FPS_REG_ADD                  0x000b  //数据帧率
#define ALS_CAM_FPS_REG_ADD                     0x000c  //相机帧率
#define ALS_TIME_HOURS_REG_ADD                  0x000d  //当前时间时
#define ALS_TIME_MINUTES_REG_ADD                0x000e  //当前时间分
#define ALS_TIME_SECONDS_REG_ADD                0x000f  //当前时间秒
#define ALS_TIME_MILLISECONDS_REG_ADD           0x0010  //当前时间毫秒
#define ALS_STATE2_REG_ADD                      0x0011  //传感器状态,0表示正在处理,1表示成功,-1表示失败
#define ALS_P_REALTIME_POSX_REG_ADD             0x0012  //P变量实时检测结果X，(0x012-0x013)单位微米
#define ALS_P_REALTIME_POSY_REG_ADD             0x0014  //P变量实时检测结果Y，(0x014-0x015)单位微米
#define ALS_P_REALTIME_POSZ_REG_ADD             0x0016  //P变量实时检测结果Z，(0x016-0x017)单位微米
#define ALS_P_REALTIME_POSRX_REG_ADD            0x0018  //P变量实时检测结果RX，(0x018-0x019)单位0.0001deg
#define ALS_P_REALTIME_POSRY_REG_ADD            0x001a  //P变量实时检测结果RY，(0x01a-0x01b)单位0.0001deg
#define ALS_P_REALTIME_POSRZ_REG_ADD            0x001c  //P变量实时检测结果RZ，(0x01c-0x01d)单位0.0001deg
#define ALS_P_REALTIME_POSOUT1_REG_ADD          0x001e  //P变量实时检测结果，机器人外部轴1，(0x01e-0x01f)
#define ALS_P_REALTIME_POSOUT2_REG_ADD          0x0020  //P变量实时检测结果，机器人外部轴2，(0x020-0x021)
#define ALS_P_REALTIME_POSOUT3_REG_ADD          0x0022  //P变量实时检测结果，机器人外部轴3，(0x022-0x023)
#define ALS_P_REALTIME_TOOL_REG_ADD             0x0024  //P变量实时检测结果，机器人工具号
#define ALS_P_REALTIME_TCP_REG_ADD              0x0025  //P变量实时检测结果，机器人坐标系号
#define ALS_P_REALTIME_USERTCP_REG_ADD          0x0026  //P变量实时检测结果，机器人用户坐标系号

#define ALS_Y_POINT2_REG_ADD                    0x0050  //Y坐标POINT2
#define ALS_Z_POINT2_REG_ADD                    0x0051  //Z坐标POINT2
#define ALS_Y_POINT3_REG_ADD                    0x0052  //Y坐标POINT3
#define ALS_Z_POINT3_REG_ADD                    0x0053  //Z坐标POINT3
#define ALS_Y_POINT4_REG_ADD                    0x0054  //Y坐标POINT4
#define ALS_Z_POINT4_REG_ADD                    0x0055  //Z坐标POINT4

#define ALS_SOLDER_REG_ADD                      0x0060  //焊点

#define ALS_X_POINT1_REG_ADD                    0x0070  //X坐标POINT
#define ALS_WELD_LONG_REG_ADD                   0x0071  //焊缝X法向量

#define ALS_OPEN_REG_ADD                        0x0101  //跟踪开关
#define ALS_TASKNUM_REG_ADD                     0x0102  //任务号

#define ALS_REALTIME_POSX_REG_ADD               0x0111  //写入实时坐标，机器人X，(0x111-0x112)单位微米
#define ALS_REALTIME_POSY_REG_ADD               0x0113  //写入实时坐标，机器人Y，(0x113-0x114)单位微米
#define ALS_REALTIME_POSZ_REG_ADD               0x0115  //写入实时坐标，机器人Z，(0x115-0x116)单位微米
#define ALS_REALTIME_POSRX_REG_ADD              0x0117  //写入实时坐标，机器人RX，(0x117-0x118)单位0.0001deg
#define ALS_REALTIME_POSRY_REG_ADD              0x0119  //写入实时坐标，机器人RY，(0x119-0x11a)单位0.0001deg
#define ALS_REALTIME_POSRZ_REG_ADD              0x011b  //写入实时坐标，机器人RZ，(0x11b-0x11c)单位0.0001deg
#define ALS_REALTIME_POSOUT1_REG_ADD            0x011d  //写入实时坐标，机器人外部轴1，(0x11d-0x11e)
#define ALS_REALTIME_POSOUT2_REG_ADD            0x011f  //写入实时坐标，机器人外部轴2，(0x11f-0x120)
#define ALS_REALTIME_POSOUT3_REG_ADD            0x0121  //写入实时坐标，机器人外部轴3，(0x121-0x122)
#define ALS_REALTIME_TOOL_REG_ADD               0x0123  //写入实时坐标，机器人工具号
#define ALS_REALTIME_TCP_REG_ADD                0x0124  //写入实时坐标，机器人坐标系号
#define ALS_REALTIME_USERTCP_REG_ADD            0x0125  //写入实时坐标，机器人用户坐标系号

#define ALS_REALTIME_CRAFTID_REG_ADD            0x0144  //工艺包ID
#define ALS_REALTIME_CRAFTALS1_REG_ADD          0x0145  //工艺参数1
#define ALS_REALTIME_CRAFTALS2_REG_ADD          0x0146  //工艺参数2
#define ALS_REALTIME_CRAFTALS3_REG_ADD          0x0147  //工艺参数3
#define ALS_REALTIME_CRAFTALS4_REG_ADD          0x0148  //工艺参数4
#define ALS_REALTIME_CRAFTALS5_REG_ADD          0x0149  //工艺参数5
#define ALS_REALTIME_CRAFTALS6_REG_ADD          0x014a  //工艺参数6
#define ALS_REALTIME_CRAFTALS7_REG_ADD          0x014b  //工艺参数7
#define ALS_REALTIME_CRAFTALS8_REG_ADD          0x014c  //工艺参数8
#define ALS_REALTIME_CRAFTALS9_REG_ADD          0x014d  //工艺参数9
#define ALS_REALTIME_CRAFTALS10_REG_ADD         0x014e  //工艺参数10



/*****************************/



#endif // GLOBAL_H
