#include "cambuilddlg.h"
#include "ui_cambuilddlg.h"

cambuilddlg::cambuilddlg(my_parameters *mcs,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cambuilddlg)
{
    ui->setupUi(this);
    m_mcs=mcs;
    init_dlg_show();
}

cambuilddlg::~cambuilddlg()
{
    delete ui;
}

void cambuilddlg::init_dlg_show()
{
    ui->x1_Edit->setText(QString::number(m_mcs->e2proomdata.camdlg_modposX1/100.0,'f',2));
    ui->y1_Edit->setText(QString::number(m_mcs->e2proomdata.camdlg_modposY1/100.0,'f',2));
    ui->x2_Edit->setText(QString::number(m_mcs->e2proomdata.camdlg_modposX2/100.0,'f',2));
    ui->y2_Edit->setText(QString::number(m_mcs->e2proomdata.camdlg_modposY2/100.0,'f',2));
    ui->x3_Edit->setText(QString::number(m_mcs->e2proomdata.camdlg_modposX3/100.0,'f',2));
    ui->y3_Edit->setText(QString::number(m_mcs->e2proomdata.camdlg_modposY3/100.0,'f',2));
    ui->x4_Edit->setText(QString::number(m_mcs->e2proomdata.camdlg_modposX4/100.0,'f',2));
    ui->y4_Edit->setText(QString::number(m_mcs->e2proomdata.camdlg_modposY4/100.0,'f',2));
}

