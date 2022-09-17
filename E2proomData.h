#ifndef E2PROOMDATA_H
#define E2PROOMDATA_H
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include "tistdtypes.h"
#include "FileOut.h"

#define E2POOM_CAMDLG_SAVEBUFF              32
#define E2POOM_CAMDLG_SYSPATH_MOTO			"./SAVE/E2P_CAMDLG.bsd"

#define E2POOM_CAMDLG_MODPOSX1_MIN          0
#define E2POOM_CAMDLG_MODPOSX1_MAX          100000
#define E2POOM_CAMDLG_MODPOSX1_USE          0
#define E2POOM_CAMDLG_MODPOSY1_MIN          0
#define E2POOM_CAMDLG_MODPOSY1_MAX          100000
#define E2POOM_CAMDLG_MODPOSY1_USE          8000
#define E2POOM_CAMDLG_MODPOSX2_MIN          0
#define E2POOM_CAMDLG_MODPOSX2_MAX          100000
#define E2POOM_CAMDLG_MODPOSX2_USE          2750
#define E2POOM_CAMDLG_MODPOSY2_MIN          0
#define E2POOM_CAMDLG_MODPOSY2_MAX          100000
#define E2POOM_CAMDLG_MODPOSY2_USE          0
#define E2POOM_CAMDLG_MODPOSX3_MIN          0
#define E2POOM_CAMDLG_MODPOSX3_MAX          100000
#define E2POOM_CAMDLG_MODPOSX3_USE          5750
#define E2POOM_CAMDLG_MODPOSY3_MIN          0
#define E2POOM_CAMDLG_MODPOSY3_MAX          100000
#define E2POOM_CAMDLG_MODPOSY3_USE          0
#define E2POOM_CAMDLG_MODPOSX4_MIN          0
#define E2POOM_CAMDLG_MODPOSX4_MAX          100000
#define E2POOM_CAMDLG_MODPOSX4_USE          8500
#define E2POOM_CAMDLG_MODPOSY4_MIN          0
#define E2POOM_CAMDLG_MODPOSY4_MAX          100000
#define E2POOM_CAMDLG_MODPOSY4_USE          8000

class E2proomData
{
public:
    E2proomData();
    ~E2proomData();
/****************************/
//cambuilddld界面参数
    Int32 camdlg_modposX1;
    Int32 camdlg_modposY1;
    Int32 camdlg_modposX2;
    Int32 camdlg_modposY2;
    Int32 camdlg_modposX3;
    Int32 camdlg_modposY3;
    Int32 camdlg_modposX4;
    Int32 camdlg_modposY4;

    void write_camdlg_para();	//保存cambuilddld界面参数
    void init_camdlg_para();	//初始化cambuilddld界面参数

    Int32 camdlg_modposX1_min;
    Int32 camdlg_modposX1_max;
    Int32 camdlg_modposX1_use;
    Int32 camdlg_modposY1_min;
    Int32 camdlg_modposY1_max;
    Int32 camdlg_modposY1_use;
    Int32 camdlg_modposX2_min;
    Int32 camdlg_modposX2_max;
    Int32 camdlg_modposX2_use;
    Int32 camdlg_modposY2_min;
    Int32 camdlg_modposY2_max;
    Int32 camdlg_modposY2_use;
    Int32 camdlg_modposX3_min;
    Int32 camdlg_modposX3_max;
    Int32 camdlg_modposX3_use;
    Int32 camdlg_modposY3_min;
    Int32 camdlg_modposY3_max;
    Int32 camdlg_modposY3_use;
    Int32 camdlg_modposX4_min;
    Int32 camdlg_modposX4_max;
    Int32 camdlg_modposX4_use;
    Int32 camdlg_modposY4_min;
    Int32 camdlg_modposY4_max;
    Int32 camdlg_modposY4_use;
 /***************************/


    void write();
private:
    void read_para();				//读取
    void check_para();			//检查参数
};

#endif // E2PROOMDATA_H
