#ifndef GLOBAL_H
#define GLOBAL_H

//#define WINDOWS_TCP 1   //linux仿windowstcp测试
#if _MSC_VER
#include "tistdtypes.h"

typedef uint8_t u_int8_t; /* u_int8_t is defined in <machine/types.h> */
typedef uint16_t u_int16_t; /* u_int16_t is defined in <machine/types.h> */
typedef uint32_t u_int32_t; /* u_int32_t is defined in <machine/types.h> */
typedef uint64_t u_int64_t; /* u_int64_t is defined in <machine/types.h> */
#endif

//#define DEBUG_TEST
#define DEBUG_TIMEFPS               //上位机和下位机时间戳测试
#define DEBUG_MYINTERFACES

#define CAMIMAGE_HEIGHT             960
#define CAMIMAGE_WIDTH              1280

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

/*****************************/
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


#define ALS100_REG_TOTALNUM                    0x0017

#define ALS100_INIT_REG_ADD                    0x001f



#define ALS101_EXPOSURE_TIME_REG_ADD           0x0020
#define ALS101_PINGJUN_REG_ADD                 0x0021
#define ALS101_B_YANMOFUZHU_REG_ADD            0x0022
#define ALS101_B_GUDINGQUYU_REG_ADD            0x0023
#define ALS101_WIDTHLIANTONGDIS_REG_ADD        0x0024
#define ALS101_HIGHLIANTONGDIS_REG_ADD         0x0025
#define ALS101_GUJIAERZHI_REG_ADD              0x0026
#define ALS101_JIGUANGHIGHT_REG_ADD            0x0027
#define ALS101_JIGUANGLONG_REG_ADD             0x0028
#define ALS101_JIGUANGKUANDU_REG_ADD           0x0029
#define ALS101_UPDIF_REG_ADD                   0x002a
#define ALS101_UPDIFMIN_REG_ADD                0x002b
#define ALS101_UPLONG_REG_ADD                  0x002c
#define ALS101_DOWNDIF_REG_ADD                 0x002d
#define ALS101_DOWNDIFMIN_REG_ADD              0x002e
#define ALS101_DOWNDLONG_REG_ADD               0x002f
#define ALS101_DUANXIANERZHI_REG_ADD           0x0030
#define ALS101_ERZHISIZE_REG_ADD               0x0031
#define ALS101_ERZHISIZE2_REG_ADD              0x0032
#define ALS101_SEARCHDECTANCEMAX_REG_ADD       0x0033
#define ALS101_SEARCHDECTANCEMIN_REG_ADD       0x0034
#define ALS101_DIS_CENTER_ST_REG_ADD           0x0035
#define ALS101_DIS_CENTER_ED_REG_ADD           0x0036


#define ALS101_REG_TOTALNUM                    0x0017

#define ALS101_INIT_REG_ADD                    0x003f


#define ALS102_EXPOSURE_TIME_REG_ADD           0x0040
#define ALS102_PINGJUN_REG_ADD                 0x0041
#define ALS102_B_YANMOFUZHU_REG_ADD            0x0042
#define ALS102_B_GUDINGQUYU_REG_ADD            0x0043
#define ALS102_WIDTHLIANTONGDIS_REG_ADD        0x0044
#define ALS102_HIGHLIANTONGDIS_REG_ADD         0x0045
#define ALS102_GUJIAERZHI_REG_ADD              0x0046
#define ALS102_JIGUANGHIGHT_REG_ADD            0x0047
#define ALS102_JIGUANGLONG_REG_ADD             0x0048
#define ALS102_JIGUANGKUANDU_REG_ADD           0x0049
#define ALS102_UPDIF_REG_ADD                   0x004a
#define ALS102_UPDIFMIN_REG_ADD                0x004b
#define ALS102_UPLONG_REG_ADD                  0x004c
#define ALS102_DOWNDIF_REG_ADD                 0x004d
#define ALS102_DOWNDIFMIN_REG_ADD              0x004e
#define ALS102_DOWNDLONG_REG_ADD               0x004f
#define ALS102_ST_DOWN_REG_ADD                 0x0050
#define ALS102_ED_DOWN_REG_ADD                 0x0051
#define ALS102_ST_UP_REG_ADD                   0x0052
#define ALS102_ED_UP_REG_ADD                   0x0053
#define ALS102_UPDIF2_REG_ADD                  0x0054
#define ALS102_UPDIFMIN2_REG_ADD               0x0055
#define ALS102_DIS_CENTER_ST_REG_ADD           0x0056
#define ALS102_DIS_CENTER_ED_REG_ADD           0x0057
#define ALS102_B_OPENGUDINGDIMIAN_REG_ADD      0x0058
#define ALS102_DIMIANPANGDINGJULI_REG_ADD      0x0059
#define ALS102_DIMIANPINGJUNSHUNUM_REG_ADD     0x005a
#define ALS102_DIS_CENTER_ST2_REG_ADD          0x005b
#define ALS102_DIS_CENTER_ED2_REG_ADD          0x005c
#define ALS102_DIS_CENTER_ST3_REG_ADD          0x005d
#define ALS102_DIS_CENTER_ED3_REG_ADD          0x005e
#define ALS102_XUEXIJULI_REG_ADD               0x005f
#define ALS102_B_PINGPOWENGDING_REG_ADD        0x0060
#define ALS102_PINGPOWENGDING_DIS_REG_ADD      0x0061
#define ALS102_B_XIELVOPEN_REG_ADD             0x0062
#define ALS102_XIELVFANWEI_REG_ADD             0x0063
#define ALS102_UPLONG2_REG_ADD                 0x0064
#define ALS102_CEBANKONGDONGDIS_REG_ADD        0x0065
#define ALS102_QIATOUQUWEI_REG_ADD             0x0066


#define ALS102_REG_TOTALNUM                    0x0027

#define ALS102_INIT_REG_ADD                    0x006f


#define ALS103_EXPOSURE_TIME_REG_ADD           0x0070
#define ALS103_PINGJUN_REG_ADD                 0x0071
#define ALS103_GUJIAERZHI_REG_ADD              0x0072
#define ALS103_WIDTHLIANTONGDIS_REG_ADD        0x0073
#define ALS103_HIGHLIANTONGDIS_REG_ADD         0x0074
#define ALS103_JIGUANGLONG_REG_ADD             0x0075
#define ALS103_JIGUANGKUANDU_REG_ADD           0x0076
#define ALS103_JIGUANGDUIBIDU_REG_ADD          0x0077

#define ALS103_REG_TOTALNUM                    0x0008

#define ALS103_INIT_REG_ADD                    0x007f

#define ALS104_EXPOSURE_TIME_REG_ADD           0x0080
#define ALS104_PINGJUN_REG_ADD                 0x0081
#define ALS104_B_YANMOFUZHU_REG_ADD            0x0082
#define ALS104_B_GUDINGQUYU_REG_ADD            0x0083
#define ALS104_WIDTHLIANTONGDIS_REG_ADD        0x0084
#define ALS104_HIGHLIANTONGDIS_REG_ADD         0x0085
#define ALS104_GUJIAERZHI_REG_ADD              0x0086
#define ALS104_JIGUANGHIGHT_REG_ADD            0x0087
#define ALS104_JIGUANGLONG_REG_ADD             0x0088
#define ALS104_JIGUANGKUANDU_REG_ADD           0x0089
#define ALS104_UPDIF_REG_ADD                   0x008a
#define ALS104_UPDIFMIN_REG_ADD                0x008b
#define ALS104_UPLONG_REG_ADD                  0x008c
#define ALS104_DOWNDIF_REG_ADD                 0x008d
#define ALS104_DOWNDIFMIN_REG_ADD              0x008e
#define ALS104_DOWNDLONG_REG_ADD               0x008f
#define ALS104_ST_DOWN_REG_ADD                 0x0090
#define ALS104_ED_DOWN_REG_ADD                 0x0091
#define ALS104_ST_UP_REG_ADD                   0x0092
#define ALS104_ED_UP_REG_ADD                   0x0093
#define ALS104_UPDIF2_REG_ADD                  0x0094
#define ALS104_UPDIFMIN2_REG_ADD               0x0095
#define ALS104_DIS_CENTER_ST_REG_ADD           0x0096
#define ALS104_DIS_CENTER_ED_REG_ADD           0x0097
#define ALS104_B_OPENGUDINGDIMIAN_REG_ADD      0x0098
#define ALS104_DIMIANPANGDINGJULI_REG_ADD      0x0099
#define ALS104_DIMIANPINGJUNSHUNUM_REG_ADD     0x009a
#define ALS104_DIS_CENTER_ST2_REG_ADD          0x009b
#define ALS104_DIS_CENTER_ED2_REG_ADD          0x009c
#define ALS104_DIS_CENTER_ST3_REG_ADD          0x009d
#define ALS104_DIS_CENTER_ED3_REG_ADD          0x009e
#define ALS104_XUEXIJULI_REG_ADD               0x009f
#define ALS104_B_PINGPOWENGDING_REG_ADD        0x00a0
#define ALS104_PINGPOWENGDING_DIS_REG_ADD      0x00a1
#define ALS104_B_XIELVOPEN_REG_ADD             0x00a2
#define ALS104_XIELVFANWEI_REG_ADD             0x00a3
#define ALS104_UPLONG2_REG_ADD                 0x00a4
#define ALS104_CEBANKONGDONGDIS_REG_ADD        0x00a5
#define ALS104_QIATOUQUWEI_REG_ADD             0x00a6


#define ALS104_REG_TOTALNUM                    0x0027

#define ALS104_INIT_REG_ADD                    0x00af

#define ALS105_EXPOSURE_TIME_REG_ADD           0x00b0
#define ALS105_PINGJUN_REG_ADD                 0x00b1
#define ALS105_B_YANMOFUZHU_REG_ADD            0x00b2
#define ALS105_WIDTHLIANTONGDIS_REG_ADD        0x00b3
#define ALS105_HIGHLIANTONGDIS_REG_ADD         0x00b4
#define ALS105_GUJIAERZHI_REG_ADD              0x00b5
#define ALS105_JIGUANGHIGHT_REG_ADD            0x00b6
#define ALS105_JIGUANGLONG_REG_ADD             0x00b7
#define ALS105_JIGUANGKUANDU_REG_ADD           0x00b8
#define ALS105_UPDIF_REG_ADD                   0x00b9
#define ALS105_UPDIFMIN_REG_ADD                0x00ba
#define ALS105_UPLONG_REG_ADD                  0x00bb
#define ALS105_DOWNDIF_REG_ADD                 0x00bc
#define ALS105_DOWNDIFMIN_REG_ADD              0x00bd
#define ALS105_DOWNDLONG_REG_ADD               0x00be
#define ALS105_DIS_CENTER_ST_REG_ADD           0x00bf
#define ALS105_DIS_CENTER_ED_REG_ADD           0x00c0
#define ALS105_B_CUT_REG_ADD                   0x00c1
#define ALS105_CUTLEFT_REG_ADD                 0x00c2
#define ALS105_CUTRIGHT_REG_ADD                0x00c3
#define ALS105_CUTTOP_REG_ADD                  0x00c4
#define ALS105_CUTDEEP_REG_ADD                 0x00c5
#define ALS105_GUAIDIANYUZHI_REG_ADD           0x00c6
#define ALS105_DUANDIANJULI_REG_ADD            0x00c7
#define ALS105_B_DIBUFAXIANGLIANG_REG_ADD      0x00c8

#define ALS105_REG_TOTALNUM                    0x0019

#define ALS105_INIT_REG_ADD                    0x00cf


#define ALS_SHOW_STEP_REG_ADD                  0x018f

/*****************************/
//激光头机器人型号和相机尺寸寄存器
#define PORT_ALSROBOTCAM_SET               1501  //端口号1501: 激光头机器人型号和相机尺寸端口号

#define ALSROBOTCAM_ROBOTMOD_REG_ADD            0x0000  //机器人型号
#define ALSROBOTCAM_ROBOTPORT_REG_ADD           0x0001  //机器人端口号
#define ALSROBOTCAM_COMPENSATION_X              0x0002  //标定补偿X
#define ALSROBOTCAM_COMPENSATION_Y              0x0003  //标定补偿Y
#define ALSROBOTCAM_COMPENSATION_Z              0x0004  //标定补偿Z
#define ALSROBOTCAM_CAMWIDTH_REG_ADD            0x0005  //相机算法宽度
#define ALSROBOTCAM_CAMHEIGHT_REG_ADD           0x0006  //相机算法高度
#define ALSROBOTCAM_CAMFPS_REG_ADD              0x0007  //相机帧率
#define ALSROBOTCAM_VIEW_CAM_WIDTH_REG_ADD      0x0008  //相机视野宽度
#define ALSROBOTCAM_VIEW_CAM_HEIGHT_REG_ADD     0x0009  //相机视野高度

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


/*****************************/



#endif // GLOBAL_H
