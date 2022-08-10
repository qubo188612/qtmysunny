#ifndef QTMYSUNNYDLG_H
#define QTMYSUNNYDLG_H

#include <QDialog>
#include <my_parameters.h>

namespace Ui {
class qtmysunnyDlg;
}

class getposThread;

class qtmysunnyDlg : public QDialog
{
    Q_OBJECT

public:
    explicit qtmysunnyDlg(QWidget *parent = nullptr);
    ~qtmysunnyDlg();

    my_parameters *m_mcs;

    void UpdataUi();

    void img_windowshow(bool b_show,QLabel *lab_show);

    void open_camer_modbus();       //打开相机采集
    void close_camer_modbus();      //关闭相机采集

    getposThread *thread1;
    bool b_thread1;
    bool b_stop_thread1;

    unsigned short pos_data[3];

private:
    Ui::qtmysunnyDlg *ui;

private slots:
    void init_show_pos_list();
    void init_show_pos_failed();
};

class getposThread : public QThread
{
    Q_OBJECT

public:
    getposThread(qtmysunnyDlg *statci_p);
    void Stop();
protected:
    void run();
private:
    qtmysunnyDlg *_p;

signals:
    // 自定义信号
    void Send_show_pos_list();
    void Send_show_pos_failed();

};

#endif // QTMYSUNNYDLG_H
