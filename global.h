#ifndef GLOBAL_H
#define GLOBAL_H

//#define DEBUG_TEST            //调试模式
#define DEBUG_MYINTERFACES      //使用自定义接口


#define CAMIMAGE_HEIGHT             960     //初始化相机图像长宽
#define CAMIMAGE_WIDTH              1280

#define CAMTOTALNUM                 1       //当前同型号下支持几路相机

#define CLOULD_POINT_NOTDATE        FLT_MAX   //深度值不存在时点云的值

/*************************/
//采集模式
#define AUTO_MOD                    0         //自适应采集模式
#define CALLBACK_MOD                1         //相机节拍采集模式
#define ACQUISITION_MOD             AUTO_MOD  //点云和深度图采集模式
/***************************/

#define ROWS_PROPORTION              1.0     //相机图像高度比例   实际距离(mm)/相机像素距离
#define COLS_PROPORTION              1.0     //相机图像宽度比例   实际距离(mm)/相机像素距离

#define DEEPIMG_CALLBACKNUM_DNUM     5     //采集深度图时多采集的帧数


/*****************************/
//框架2寄存器地址
//任务号100
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

//任务号100寄存器总数
#define ALS100_REG_TOTALNUM                    0x0015

//显示图像处理步骤
#define ALS_SHOW_STEP_REG_ADD                  0x018f
/*****************************/

#endif // GLOBAL_H
