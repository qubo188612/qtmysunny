#ifndef PSHOWDLG_H
#define PSHOWDLG_H

#include <QDialog>
#include <QListWidgetItem>
#include <craftdlg.h>
#include "my_parameters.h"
#include <modbus/modbus.h>

namespace Ui {
class pshowdlg;
}

class pshowdlgThread;

class pshowdlg : public QDialog
{
    Q_OBJECT

public:
    explicit pshowdlg(my_parameters *mcs,QWidget *parent = nullptr);
    ~pshowdlg();

    my_parameters *m_mcs;

    craftDlg *craftdlg;

    void init_dlg_show();
    void close_dlg_show();

    pshowdlgThread *thread1;
    bool b_thread1;
    bool b_stop_thread1;
    bool b_init_show_pshow_text_finish;

    modbus_t *ctx_pshow;
    bool link_pshow_state;
    QTcpSocket *client;

    unsigned short pos_data[0x15];
    unsigned short p_pos_data[0x15];
    unsigned short result_data[0x03];
    void getrobinfo();//更新机器人坐标
    void updatatext();//刷新标定矩阵显示
    void initPdata();//初始化P变量显示
    void updataPdata();//刷新P变量显示

private:
    Ui::pshowdlg *ui;

    int findpDataId(std::vector<rob_group> P_data,int findId,int *pnum);//寻找P_data的findId号下对应的下标，如果找不到则返回非0

    void initpDatapoint(Eye_Hand_calibrationmode P_data_eye_hand_calibrationmode);

    int now_robPdata;       //当前指向P变量修改位置
    int now_robpos;         //当前指向TCP修改位置
    int now_leaserpos;      //当前指向激光头修改位置

    QString JsonToQstring(QJsonObject jsonObject);

    QJsonObject QstringToJson(QString jsonString);

    std::vector<rob_pinfo> P_data_rob;
    std::vector<rob_pinfo> P_data_leaser;

    rob_pinfo robposinfo;//机器人当前坐标信息
    rob_pinfo p_robposinfo;//P寄存器当前焊缝坐标
    bool b_robposfinduv;//机器人uv坐标是否有效

    void updataRoblistUi();
    void updataLeaserlistUi();
    void updataDemarcateResult();

    void pullpData();//上传pData
    void pulldemdl();//上传标定矩阵

    std::vector<double> errgroup;

private slots:
    void init_show_pshow_text();
    void on_pushButton_10_clicked();
    void on_radio1_clicked();
    void on_radio2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_7_clicked();
    void on_robposlist_itemClicked(QListWidgetItem *item);
    void on_leaserposlist_itemClicked(QListWidgetItem *item);
    void on_robPdata_itemClicked(QListWidgetItem *item);
    void on_pushButton_12_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_13_clicked();
};

class pshowdlgThread : public QThread
{
    Q_OBJECT

public:
    pshowdlgThread(pshowdlg *statci_p);
    void Stop();
protected:
    void run();
private:
    pshowdlg *_p;

signals:
    // 自定义信号
    void Send_show_pshow_text();
};

#endif // PSHOWDLG_H
