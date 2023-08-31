#include "craftdlg.h"
#include "ui_craftdlg.h"

craftDlg::craftDlg(my_parameters *mcs,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::craftDlg)
{
    ui->setupUi(this);
    m_mcs=mcs;

    ui->tableWidget->setColumnWidth(0, 20);    //设置第一列宽度
    ui->tableWidget->setColumnWidth(1, 100);    //设置第二列宽度
    ui->craftalstableWidget->setColumnWidth(0, 100);    //设置第一列宽度
    for(int i = 0; i < ui->tableWidget->rowCount(); i++)//设置第一二列不可编辑
    {
        QTableWidgetItem *item0 = ui->tableWidget->item(i, 0);
        QTableWidgetItem *item1 = ui->tableWidget->item(i, 1);
        if(item0)
        {
            item0->setFlags(item0->flags() & (~Qt::ItemIsEditable));
        }
        if(item1)
        {
            item1->setFlags(item1->flags() & (~Qt::ItemIsEditable));
        }
    }
    for(int i = 0; i < ui->craftalstableWidget->rowCount(); i++)//设置第一二列不可编辑
    {
        QTableWidgetItem *item0 = ui->craftalstableWidget->item(i, 0);
        if(item0)
        {
            item0->setFlags(item0->flags() & (~Qt::ItemIsEditable));
        }
    }

    //导入工艺号
    connect(ui->craftIdsetBtn,&QPushButton::clicked,[=](){
       if(link_craft_state==true)
       {
           m_mcs->resultdata.P_data_craftinfo.craft_Id=ui->lineEdit->text().toInt();
           uint16_t tab_reg[1];
           tab_reg[0]=(uint16_t)m_mcs->resultdata.P_data_craftinfo.craft_Id;
           int rc=modbus_write_registers(ctx_craft,ALS_REALTIME_CRAFTID_REG_ADD,1,tab_reg);
           if(rc!=1)
           {
               ui->record->append(QStringLiteral("更新工艺号失败"));
           }
           else
           {
               ui->record->append(QStringLiteral("更新工艺号成功"));
           }
       }
    });

    //导入工艺参数
    connect(ui->craftalssetBtn,&QPushButton::clicked,[=](){
       if(link_craft_state==true)
       {
           uint16_t tab_reg[10];
           ui->craftalssetBtn->setFocus();
           m_mcs->resultdata.P_data_craftinfo.craft_als1=(int16_t)ui->craftalstableWidget->item(0,1)->text().toInt();
           m_mcs->resultdata.P_data_craftinfo.craft_als2=(int16_t)ui->craftalstableWidget->item(1,1)->text().toInt();
           m_mcs->resultdata.P_data_craftinfo.craft_als3=(int16_t)ui->craftalstableWidget->item(2,1)->text().toInt();
           m_mcs->resultdata.P_data_craftinfo.craft_als4=(int16_t)ui->craftalstableWidget->item(3,1)->text().toInt();
           m_mcs->resultdata.P_data_craftinfo.craft_als5=(int16_t)ui->craftalstableWidget->item(4,1)->text().toInt();
           m_mcs->resultdata.P_data_craftinfo.craft_als6=(int16_t)ui->craftalstableWidget->item(5,1)->text().toInt();
           m_mcs->resultdata.P_data_craftinfo.craft_als7=(int16_t)ui->craftalstableWidget->item(6,1)->text().toInt();
           m_mcs->resultdata.P_data_craftinfo.craft_als8=(int16_t)ui->craftalstableWidget->item(7,1)->text().toInt();
           m_mcs->resultdata.P_data_craftinfo.craft_als9=(int16_t)ui->craftalstableWidget->item(8,1)->text().toInt();
           m_mcs->resultdata.P_data_craftinfo.craft_als10=(int16_t)ui->craftalstableWidget->item(9,1)->text().toInt();
           tab_reg[0]=(uint16_t)m_mcs->resultdata.P_data_craftinfo.craft_als1;
           tab_reg[1]=(uint16_t)m_mcs->resultdata.P_data_craftinfo.craft_als2;
           tab_reg[2]=(uint16_t)m_mcs->resultdata.P_data_craftinfo.craft_als3;
           tab_reg[3]=(uint16_t)m_mcs->resultdata.P_data_craftinfo.craft_als4;
           tab_reg[4]=(uint16_t)m_mcs->resultdata.P_data_craftinfo.craft_als5;
           tab_reg[5]=(uint16_t)m_mcs->resultdata.P_data_craftinfo.craft_als6;
           tab_reg[6]=(uint16_t)m_mcs->resultdata.P_data_craftinfo.craft_als7;
           tab_reg[7]=(uint16_t)m_mcs->resultdata.P_data_craftinfo.craft_als8;
           tab_reg[8]=(uint16_t)m_mcs->resultdata.P_data_craftinfo.craft_als9;
           tab_reg[9]=(uint16_t)m_mcs->resultdata.P_data_craftinfo.craft_als10;
           int rc=modbus_write_registers(ctx_craft,ALS_REALTIME_CRAFTALS1_REG_ADD,10,tab_reg);
           if(rc!=10)
           {
               ui->record->append(QStringLiteral("更新工艺参数失败"));
           }
           else
           {
               ui->record->append(QStringLiteral("更新工艺号成功"));
           }
       }
    });

    //读取工艺参数
    connect(ui->craftalsreadBtn,&QPushButton::clicked,[=](){
       if(link_craft_state==true)
       {
           uint16_t tab_reg[10];
           int rc=modbus_read_registers(ctx_craft,ALS_REALTIME_CRAFTALS1_REG_ADD,10,tab_reg);
           if(rc<0)
           {
               ui->record->append(QStringLiteral("读取工艺参数失败"));
           }
           else
           {
               ui->record->append(QStringLiteral("读取工艺参数成功"));
           }
           m_mcs->resultdata.P_data_craftinfo.craft_als1=(int16_t)tab_reg[0];
           m_mcs->resultdata.P_data_craftinfo.craft_als2=(int16_t)tab_reg[1];
           m_mcs->resultdata.P_data_craftinfo.craft_als3=(int16_t)tab_reg[2];
           m_mcs->resultdata.P_data_craftinfo.craft_als4=(int16_t)tab_reg[3];
           m_mcs->resultdata.P_data_craftinfo.craft_als5=(int16_t)tab_reg[4];
           m_mcs->resultdata.P_data_craftinfo.craft_als6=(int16_t)tab_reg[5];
           m_mcs->resultdata.P_data_craftinfo.craft_als7=(int16_t)tab_reg[6];
           m_mcs->resultdata.P_data_craftinfo.craft_als8=(int16_t)tab_reg[7];
           m_mcs->resultdata.P_data_craftinfo.craft_als9=(int16_t)tab_reg[8];
           m_mcs->resultdata.P_data_craftinfo.craft_als10=(int16_t)tab_reg[9];

           ui->craftalstableWidget->item(0,1)->setText(QString::number(m_mcs->resultdata.P_data_craftinfo.craft_als1));
           ui->craftalstableWidget->item(1,1)->setText(QString::number(m_mcs->resultdata.P_data_craftinfo.craft_als2));
           ui->craftalstableWidget->item(2,1)->setText(QString::number(m_mcs->resultdata.P_data_craftinfo.craft_als3));
           ui->craftalstableWidget->item(3,1)->setText(QString::number(m_mcs->resultdata.P_data_craftinfo.craft_als4));
           ui->craftalstableWidget->item(4,1)->setText(QString::number(m_mcs->resultdata.P_data_craftinfo.craft_als5));
           ui->craftalstableWidget->item(5,1)->setText(QString::number(m_mcs->resultdata.P_data_craftinfo.craft_als6));
           ui->craftalstableWidget->item(6,1)->setText(QString::number(m_mcs->resultdata.P_data_craftinfo.craft_als7));
           ui->craftalstableWidget->item(7,1)->setText(QString::number(m_mcs->resultdata.P_data_craftinfo.craft_als8));
           ui->craftalstableWidget->item(8,1)->setText(QString::number(m_mcs->resultdata.P_data_craftinfo.craft_als9));
           ui->craftalstableWidget->item(9,1)->setText(QString::number(m_mcs->resultdata.P_data_craftinfo.craft_als10));
       }
    });
}

craftDlg::~craftDlg()
{
    delete ui;
}

void craftDlg::init_dlg_show()
{
    ui->record->clear();

    ui->lineEdit->setText(QString::number((int16_t)m_mcs->resultdata.P_data_craftinfo.craft_Id));
    ui->craftalstableWidget->item(0,1)->setText(QString::number((int16_t)m_mcs->resultdata.P_data_craftinfo.craft_als1));
    ui->craftalstableWidget->item(1,1)->setText(QString::number((int16_t)m_mcs->resultdata.P_data_craftinfo.craft_als2));
    ui->craftalstableWidget->item(2,1)->setText(QString::number((int16_t)m_mcs->resultdata.P_data_craftinfo.craft_als3));
    ui->craftalstableWidget->item(3,1)->setText(QString::number((int16_t)m_mcs->resultdata.P_data_craftinfo.craft_als4));
    ui->craftalstableWidget->item(4,1)->setText(QString::number((int16_t)m_mcs->resultdata.P_data_craftinfo.craft_als5));
    ui->craftalstableWidget->item(5,1)->setText(QString::number((int16_t)m_mcs->resultdata.P_data_craftinfo.craft_als6));
    ui->craftalstableWidget->item(6,1)->setText(QString::number((int16_t)m_mcs->resultdata.P_data_craftinfo.craft_als7));
    ui->craftalstableWidget->item(7,1)->setText(QString::number((int16_t)m_mcs->resultdata.P_data_craftinfo.craft_als8));
    ui->craftalstableWidget->item(8,1)->setText(QString::number((int16_t)m_mcs->resultdata.P_data_craftinfo.craft_als9));
    ui->craftalstableWidget->item(9,1)->setText(QString::number((int16_t)m_mcs->resultdata.P_data_craftinfo.craft_als10));

    link_craft_state=false;
    QString server_ip=m_mcs->e2proomdata.sunnydlg_ipaddress;
    QString server_port2=QString::number(PORT_ALS_RESULT);
    ctx_craft = modbus_new_tcp(server_ip.toUtf8(), server_port2.toInt());
    if (modbus_connect(ctx_craft) == 0)
    {
        link_craft_state=true;
    }
}

void craftDlg::close_dlg_show()
{
    if(link_craft_state==true)
    {
        modbus_close(ctx_craft);
    }
    link_craft_state=false;
    modbus_free(ctx_craft);
}
