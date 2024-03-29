﻿#include "qtmysunnydlg.h"
#include "ui_qtmysunnydlg.h"

#if _MSC_VER||WINDOWS_TCP
extern QMutex mutex_IfAlgorhmitcloud;
#endif

qtmysunnyDlg::qtmysunnyDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qtmysunnyDlg)
{
#if _MSC_VER
    QString filePath =  "./DATA";
    QDir dir(filePath);
    if(!dir.exists())
        QDir().mkdir(filePath);
#else
    std::string dir = "./DATA";
    if (access(dir.c_str(), 0) == -1)
    {
      mkdir("./DATA",S_IRWXU);
    }
#endif
//  setAttribute(Qt::WA_Mapped);    //属性函数避免界面不刷新

    ui->setupUi(this);

#ifdef DEBUG_TIMEFPS
    ui->label_48->show();
    ui->label_49->show();
    ui->label_50->show();
    ui->label_51->show();
#else
    ui->label_48->hide();
    ui->label_49->hide();
    ui->label_50->hide();
    ui->label_51->hide();
#endif

    drow_height=CAMBUILD_IMAGE_HEIGHT;
    drow_width=CAMBUILD_IMAGE_WIDTH;
    tabWidget_task=0;
    zoom_left=0;
    zoom_right=0;
    zoom_top=0;
    zoom_deep=0;
    drowstep=0;
    drowstep_temp=0;

    b_robot_serves=false;
    ui->robot_ip->hide();

    ui->tabWidget->setTabText(0,QStringLiteral("任务0-99"));
    ui->tabWidget->setTabText(1,QStringLiteral("任务100"));
    ui->tabWidget->setTabText(2,QStringLiteral("任务101"));
    ui->tabWidget->setTabText(3,QStringLiteral("任务102"));
    ui->tabWidget->setTabText(4,QStringLiteral("任务103"));
    ui->tabWidget->setTabText(5,QStringLiteral("任务104"));
    ui->tabWidget->setTabText(6,QStringLiteral("任务105"));
    ui->tabWidget->setTabText(7,QStringLiteral("任务106"));
    ui->tabWidget->setTabText(8,QStringLiteral("任务107"));
    ui->tabWidget->setTabText(9,QStringLiteral("任务108"));
#if _MSC_VER||WINDOWS_TCP
#ifdef DEBUG_CLOUD_TCP
#else
    ui->record->document()->setMaximumBlockCount(500);
#endif
#else
    ui->record->document()->setMaximumBlockCount(500);   //调试窗最大设置行数
#endif

    ui->tab2tableWidget->setColumnWidth(0, 170);    //设置第一列宽度
    ui->tab3tableWidget->setColumnWidth(0, 170);    //设置第一列宽度
    ui->tab4tableWidget->setColumnWidth(0, 170);    //设置第一列宽度
    ui->tab5tableWidget->setColumnWidth(0, 170);    //设置第一列宽度
    ui->tab6tableWidget->setColumnWidth(0, 170);    //设置第一列宽度
    ui->tab7tableWidget->setColumnWidth(0, 170);    //设置第一列宽度
    ui->tab8tableWidget->setColumnWidth(0, 170);    //设置第一列宽度
    ui->tab9tableWidget->setColumnWidth(0, 170);    //设置第一列宽度
    ui->tab10tableWidget->setColumnWidth(0, 170);    //设置第一列宽度

    for(int i = 0; i < ui->tab2tableWidget->rowCount(); i++)//设置第一二列不可编辑
    {
        QTableWidgetItem *item0 = ui->tab2tableWidget->item(i, 0);
        QTableWidgetItem *item1 = ui->tab2tableWidget->item(i, 1);
        if(item0)
        {
            item0->setFlags(item0->flags() & (~Qt::ItemIsEditable));
        }
        if(item1)
        {
            item1->setFlags(item1->flags() & (~Qt::ItemIsEditable));
        }
    }
    for(int i = 0; i < ui->tab3tableWidget->rowCount(); i++)//设置第一二列不可编辑
    {
        QTableWidgetItem *item0 = ui->tab3tableWidget->item(i, 0);
        QTableWidgetItem *item1 = ui->tab3tableWidget->item(i, 1);
        if(item0)
        {
            item0->setFlags(item0->flags() & (~Qt::ItemIsEditable));
        }
        if(item1)
        {
            item1->setFlags(item1->flags() & (~Qt::ItemIsEditable));
        }
    }
    for(int i = 0; i < ui->tab4tableWidget->rowCount(); i++)//设置第一二列不可编辑
    {
        QTableWidgetItem *item0 = ui->tab4tableWidget->item(i, 0);
        QTableWidgetItem *item1 = ui->tab4tableWidget->item(i, 1);
        if(item0)
        {
            item0->setFlags(item0->flags() & (~Qt::ItemIsEditable));
        }
        if(item1)
        {
            item1->setFlags(item1->flags() & (~Qt::ItemIsEditable));
        }
    }
    for(int i = 0; i < ui->tab5tableWidget->rowCount(); i++)//设置第一二列不可编辑
    {
        QTableWidgetItem *item0 = ui->tab5tableWidget->item(i, 0);
        QTableWidgetItem *item1 = ui->tab5tableWidget->item(i, 1);
        if(item0)
        {
            item0->setFlags(item0->flags() & (~Qt::ItemIsEditable));
        }
        if(item1)
        {
            item1->setFlags(item1->flags() & (~Qt::ItemIsEditable));
        }
    }
    for(int i = 0; i < ui->tab6tableWidget->rowCount(); i++)//设置第一二列不可编辑
    {
        QTableWidgetItem *item0 = ui->tab6tableWidget->item(i, 0);
        QTableWidgetItem *item1 = ui->tab6tableWidget->item(i, 1);
        if(item0)
        {
            item0->setFlags(item0->flags() & (~Qt::ItemIsEditable));
        }
        if(item1)
        {
            item1->setFlags(item1->flags() & (~Qt::ItemIsEditable));
        }
    }
    for(int i = 0; i < ui->tab7tableWidget->rowCount(); i++)//设置第一二列不可编辑
    {
        QTableWidgetItem *item0 = ui->tab7tableWidget->item(i, 0);
        QTableWidgetItem *item1 = ui->tab7tableWidget->item(i, 1);
        if(item0)
        {
            item0->setFlags(item0->flags() & (~Qt::ItemIsEditable));
        }
        if(item1)
        {
            item1->setFlags(item1->flags() & (~Qt::ItemIsEditable));
        }
    }
    for(int i = 0; i < ui->tab8tableWidget->rowCount(); i++)//设置第一二列不可编辑
    {
        QTableWidgetItem *item0 = ui->tab8tableWidget->item(i, 0);
        QTableWidgetItem *item1 = ui->tab8tableWidget->item(i, 1);
        if(item0)
        {
            item0->setFlags(item0->flags() & (~Qt::ItemIsEditable));
        }
        if(item1)
        {
            item1->setFlags(item1->flags() & (~Qt::ItemIsEditable));
        }
    }
    for(int i = 0; i < ui->tab9tableWidget->rowCount(); i++)//设置第一二列不可编辑
    {
        QTableWidgetItem *item0 = ui->tab9tableWidget->item(i, 0);
        QTableWidgetItem *item1 = ui->tab9tableWidget->item(i, 1);
        if(item0)
        {
            item0->setFlags(item0->flags() & (~Qt::ItemIsEditable));
        }
        if(item1)
        {
            item1->setFlags(item1->flags() & (~Qt::ItemIsEditable));
        }
    }
    for(int i = 0; i < ui->tab10tableWidget->rowCount(); i++)//设置第一二列不可编辑
    {
        QTableWidgetItem *item0 = ui->tab10tableWidget->item(i, 0);
        QTableWidgetItem *item1 = ui->tab10tableWidget->item(i, 1);
        if(item0)
        {
            item0->setFlags(item0->flags() & (~Qt::ItemIsEditable));
        }
        if(item1)
        {
            item1->setFlags(item1->flags() & (~Qt::ItemIsEditable));
        }
    }

    b_init_show_cvimage_inlab_finish=true;
    b_init_show_pos_failed_finish=true;
    b_init_show_pos_list_finish=true;
    b_init_set_task=true; 
    b_init_show_cloud_inlab_finish=true;

    ctx_result_dosomeing=DO_NOTHING;

    b_thread1=false;
    thread1 = new getposThread(this);
    connect(thread1, SIGNAL(Send_show_pos_list()), this, SLOT(init_show_pos_list()));
    connect(thread1, SIGNAL(Send_show_pos_failed()), this, SLOT(init_show_pos_failed()));
    connect(thread1, SIGNAL(Send_show_cvimage_inlab(cv::Mat)), this, SLOT(init_show_cvimage_inlab(cv::Mat)));
    connect(thread1, SIGNAL(Send_set_task()), this, SLOT(init_set_task()));
#if _MSC_VER||WINDOWS_TCP
#ifdef DEBUG_CLOUD_TCP
    connect(thread1, SIGNAL(Send_show_cloud_list(IFAlgorhmitcloud)), this, SLOT(init_show_cloud_list(IFAlgorhmitcloud)));
#endif
#endif

    m_mcs=m_mcs->Get();

    ui->IPadd->setText(m_mcs->e2proomdata.sunnydlg_ipaddress);

    ui->tabWidget->setCurrentIndex(0);

    m_mcs->resultdata.client=new QTcpSocket(this);

    showtasknum=new showtasknumdlg;
    taskclear=new taskcleardlg(m_mcs);
    pshow=new pshowdlg(m_mcs);
#ifdef DEBUG_SSH
    sshpassword=new sshpasswordDlg(m_mcs);
#else
    ui->stepupBtn->hide();
#endif
    cambuild=new cambuilddlg(m_mcs);
    connect(ui->connectcameraBtn,&QPushButton::clicked,[=](){
        if(m_mcs->cam->sop_cam[0].b_connect==false)
        {
          m_mcs->e2proomdata.sunnydlg_ipaddress=ui->IPadd->text();
          m_mcs->e2proomdata.write_sunnydlg_para();
          img_windowshow(true,ui->widget);
          UpdataUi();
        }
        else
        {
          img_windowshow(false,ui->widget);
          UpdataUi();
        }
    });
/*
    connect(ui->comboBox,&QComboBox::currentIndexChanged,[=](){
        u_int16_t robotmod=ui->comboBox->currentIndex();
        UpdataRobot(robotmod);
    });
*/
    connect(ui->robotsetBtn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_robotset_state==true)
        {
            u_int16_t robotmod=ui->comboBox->currentIndex();
            u_int16_t robotport=ui->robotport->text().toInt();
            QString robot_ip=ui->robot_ip->text();
            std::vector<u_int8_t> address;
            uint16_t tab_reg[2];

            if(true==ipAddrIsOK(robot_ip,address))
            {
                uint16_t tab_reg[4];
                for(int i=0;i<address.size();i++)
                {
                    tab_reg[i]=address[i];
                }
                int rc=modbus_write_registers(m_mcs->resultdata.ctx_robotset,ALSROBOTCAM_ROBOTIPADDRESS_1_REG_ADD,4,tab_reg);
                if(rc!=4)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("更新机器人IP地址设置失败"));
                }
                else
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("更新机器人IP地址设置成功"));
                }
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("机器人IP地址非法,请检查"));
            }

            tab_reg[0]=robotmod;
            tab_reg[1]=robotport;
            int rc=modbus_write_registers(m_mcs->resultdata.ctx_robotset,ALSROBOTCAM_ROBOTMOD_REG_ADD,2,tab_reg);
            if(rc!=2)
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("更新机器人设置失败"));
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("更新机器人设置成功,请重启激光头"));
            }

        }
        else
        {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再设置机器人参数"));
        }
    });

    connect(ui->tasknumsetBtn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_result_state==true)
        {
           ctx_result_dosomeing=DO_WRITE_TASK;
        }
        else
        {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再设置任务号"));
        }
    });

    connect(ui->taskclearBtn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_ftp_state==true)
        {
            taskclear->get_task_list();
            taskclear->init_dlg_show();
            taskclear->setWindowTitle(QStringLiteral("查看任务号列表"));
            taskclear->exec();
            taskclear->close_dlg_show();
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再查看任务号列表"));
        }
     });

    connect(ui->psetBtn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_robotset_state==true)
        {
            uint16_t tab_reg[3];
            if(ui->checkBox_pEn->isChecked()==false)
            {
                tab_reg[0]=0;
            }
            else
            {
                tab_reg[0]=1;
            }
            tab_reg[1]=ui->comboBox_2->currentIndex();
            tab_reg[2]=ui->comboBox_3->currentIndex();
            int rc=modbus_write_registers(m_mcs->resultdata.ctx_robotset,ALSROBOTCAM_P_DATA_EN_REG_ADD,3,tab_reg);
            if(rc!=3)
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("更新P变量设置失败"));
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("更新P变量设置成功,请重启激光头"));
            }
        }
        else
        {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再设置P变量参数"));
        }
    });

    connect(ui->pshowBtn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_result_state==true)
        {
            pshow->init_dlg_show();
            pshow->setWindowTitle(QStringLiteral("查看P变量图示"));
            pshow->exec();
            pshow->close_dlg_show();
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再查看P变量图示"));
        }
    });

    //FTP端接收数据
    connect(m_mcs->resultdata.client,&QTcpSocket::readyRead,[=](){
        if(m_mcs->resultdata.link_ftp_state==true)
        {
            QByteArray array=m_mcs->resultdata.client->readAll();
            QString msg=array;
            QJsonObject json=QstringToJson(msg);
            QJsonObject::Iterator it;
            for(it=json.begin();it!=json.end();it++)//遍历Key
            {
                QString keyString=it.key();
                if(keyString=="ls")
                {
                    m_mcs->resultdata.taskfilename.clear();
                    QJsonArray versionArray=it.value().toArray();
                    for(int i=0;i<versionArray.size();i++)
                    {
                        taskinfo sing;
                        QJsonObject qtask=versionArray[i].toObject();
                        QJsonObject::Iterator oit;
                        for(oit=qtask.begin();oit!=qtask.end();oit++)//遍历Key
                        {
                            QString qkey=oit.key();
                            if(qkey=="taskname")
                            {
                                sing.taskname=oit.value().toInt();
                            }
                            else if(qkey=="alsnum")
                            {
                                sing.alsnum=oit.value().toInt();
                            }
                        }
                        m_mcs->resultdata.taskfilename.push_back(sing);
                    }
                    if(ui->checkBox->isChecked()==false)
                    {
                         QString msg=QStringLiteral("当前任务号列表:共")+QString::number(m_mcs->resultdata.taskfilename.size())+QStringLiteral("个");
                         ui->record->append(msg);
                         for(int i=0;i<m_mcs->resultdata.taskfilename.size();i++)
                         {
                             QString msg=QStringLiteral("任务号:")+QString::number(m_mcs->resultdata.taskfilename[i].taskname)+
                                     QStringLiteral(" 算法号:")+QString::number(m_mcs->resultdata.taskfilename[i].alsnum);
                             ui->record->append(msg);
                         }
                    }
                    taskclear->set_task_num();
                }
                else if(keyString=="touch")
                {
                    if(it.value().toString()=="ok")
                    {
                        if(ui->checkBox->isChecked()==false)
                        {
                            ui->record->append(QStringLiteral("自定义任务号生成成功"));
                        }
                    }
                }
                else if(keyString=="rm")
                {
                    if(it.value().toString()=="ok")
                    {
                        if(ui->checkBox->isChecked()==false)
                        {
                            ui->record->append(QStringLiteral("删除自定义任务号完成"));
                        }
                    }
                    taskclear->delete_task_num();
                    taskclear->get_task_list();
                }
                else if(keyString=="cat")
                {
                    QJsonObject qtask=it.value().toObject();
                    QJsonObject::Iterator oit;
                    for(oit=qtask.begin();oit!=qtask.end();oit++)//遍历Key
                    {
                        QString qkey=oit.key();
                        if(qkey=="homography_matrix")
                        {
                            m_mcs->resultdata.homography_matrix.resize(9);
                            QJsonArray versionArray=oit.value().toArray();
                            for(int i=0;i<versionArray.size();i++)
                            {
                                m_mcs->resultdata.homography_matrix[i]=versionArray[i].toDouble();
                            }
                        #if _MSC_VER||WINDOWS_TCP
                            m_mcs->cam->sop_cam[0].ros_Params.homography_matrix=m_mcs->resultdata.homography_matrix;
                        #endif
                            if(ui->checkBox->isChecked()==false)
                            {
                                QString msg=QStringLiteral("homography_matrix:[");
                                for(int i=0;i<m_mcs->resultdata.homography_matrix.size();i++)
                                {
                                    msg=msg+QString::number(m_mcs->resultdata.homography_matrix[i],'f',3);
                                    if(i<m_mcs->resultdata.homography_matrix.size()-1)
                                    {
                                        msg=msg+",";
                                    }
                                    else
                                    {
                                        msg=msg+"]";
                                    }
                                }
                                ui->record->append(msg);
                            }
                        }
                        else if(qkey=="pData_demdlg_R")
                        {
                            m_mcs->resultdata.pData_demdlg_R.resize(9);
                            QJsonArray versionArray=oit.value().toArray();
                            for(int i=0;i<versionArray.size();i++)
                            {
                                m_mcs->resultdata.pData_demdlg_R[i]=versionArray[i].toDouble();
                            }
                            if(ui->checkBox->isChecked()==false)
                            {
                                QString msg=QStringLiteral("pData_demdlg_R:[");
                                for(int i=0;i<m_mcs->resultdata.pData_demdlg_R.size();i++)
                                {
                                    msg=msg+QString::number(m_mcs->resultdata.pData_demdlg_R[i],'f',3);
                                    if(i<m_mcs->resultdata.pData_demdlg_R.size()-1)
                                    {
                                        msg=msg+",";
                                    }
                                    else
                                    {
                                        msg=msg+"]";
                                    }
                                }
                                ui->record->append(msg);
                            }
                        }
                        else if(qkey=="pData_demdlg_T")
                        {
                            m_mcs->resultdata.pData_demdlg_T.resize(3);
                            QJsonArray versionArray=oit.value().toArray();
                            for(int i=0;i<versionArray.size();i++)
                            {
                                m_mcs->resultdata.pData_demdlg_T[i]=versionArray[i].toDouble();
                            }
                            if(ui->checkBox->isChecked()==false)
                            {
                                QString msg=QStringLiteral("pData_demdlg_T:[");
                                for(int i=0;i<m_mcs->resultdata.pData_demdlg_T.size();i++)
                                {
                                    msg=msg+QString::number(m_mcs->resultdata.pData_demdlg_T[i],'f',3);
                                    if(i<m_mcs->resultdata.pData_demdlg_T.size()-1)
                                    {
                                        msg=msg+",";
                                    }
                                    else
                                    {
                                        msg=msg+"]";
                                    }
                                }
                                ui->record->append(msg);
                            }
                        }
                        else if(qkey=="pData_matrix_camera2plane")
                        {
                            m_mcs->resultdata.pData_matrix_camera2plane.resize(9);
                            QJsonArray versionArray=oit.value().toArray();
                            for(int i=0;i<versionArray.size();i++)
                            {
                                m_mcs->resultdata.pData_matrix_camera2plane[i]=versionArray[i].toDouble();
                            }
                            if(ui->checkBox->isChecked()==false)
                            {
                                QString msg=QStringLiteral("pData_matrix_camera2plane:[");
                                for(int i=0;i<m_mcs->resultdata.pData_matrix_camera2plane.size();i++)
                                {
                                    msg=msg+QString::number(m_mcs->resultdata.pData_matrix_camera2plane[i],'f',3);
                                    if(i<m_mcs->resultdata.pData_matrix_camera2plane.size()-1)
                                    {
                                        msg=msg+",";
                                    }
                                    else
                                    {
                                        msg=msg+"]";
                                    }
                                }
                                ui->record->append(msg);
                            }
                        }
                        else if(qkey=="pData_matrix_plane2robot")
                        {
                            m_mcs->resultdata.pData_matrix_plane2robot.resize(9);
                            QJsonArray versionArray=oit.value().toArray();
                            for(int i=0;i<versionArray.size();i++)
                            {
                                m_mcs->resultdata.pData_matrix_plane2robot[i]=versionArray[i].toDouble();
                            }
                            if(ui->checkBox->isChecked()==false)
                            {
                                QString msg=QStringLiteral("pData_matrix_plane2robot:[");
                                for(int i=0;i<m_mcs->resultdata.pData_matrix_plane2robot.size();i++)
                                {
                                    msg=msg+QString::number(m_mcs->resultdata.pData_matrix_plane2robot[i],'f',3);
                                    if(i<m_mcs->resultdata.pData_matrix_plane2robot.size()-1)
                                    {
                                        msg=msg+",";
                                    }
                                    else
                                    {
                                        msg=msg+"]";
                                    }
                                }
                                ui->record->append(msg);
                            }
                        }
                        else if(qkey=="pData_point")
                        {
                            m_mcs->resultdata.P_data.clear();
                            QJsonObject qtask2=oit.value().toObject();
                            QJsonObject::Iterator oit2;
                            for(oit2=qtask2.begin();oit2!=qtask2.end();oit2++)//遍历Key
                            {
                                QString qkey2=oit2.key();
                                int id=qkey2.toInt();
                                rob_group singl;
                                singl.pID=id;
                                QJsonArray versionArray=oit2.value().toArray();
                                for(int i=0;i<versionArray.size();i++)
                                {
                                    QJsonObject jpos=versionArray[i].toObject();
                                    rob_pinfo pos;
                                    pos.x=jpos["x"].toDouble();
                                    pos.y=jpos["y"].toDouble();
                                    pos.z=jpos["z"].toDouble();
                                    pos.rx=jpos["rx"].toDouble();
                                    pos.ry=jpos["ry"].toDouble();
                                    pos.rz=jpos["rz"].toDouble();
                                    pos.out1=jpos["out1"].toInt();
                                    pos.out2=jpos["out2"].toInt();
                                    pos.out3=jpos["out3"].toInt();
                                    pos.tool=jpos["tool"].toInt();
                                    pos.tcp=jpos["tcp"].toInt();
                                    pos.usertcp=jpos["usertcp"].toInt();
                                    pos.uy=jpos["uy"].toDouble();
                                    pos.vz=jpos["vz"].toDouble();
                                    singl.pos.push_back(pos);
                                }
                                m_mcs->resultdata.P_data.push_back(singl);
                            }
                        }
                    }
                }
            }
        }
    });

    connect(ui->setcamsizeBtn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_robotset_state==true)
        {
             u_int16_t width=ui->cam_width->text().toInt();
             u_int16_t height=ui->cam_height->text().toInt();
             u_int16_t fps=ui->cam_fps->text().toInt();
             u_int16_t view_width=ui->cam_view_width->text().toInt();
             u_int16_t view_height=ui->cam_view_height->text().toInt();

             uint16_t tab_reg[5];
             tab_reg[0]=width;
             tab_reg[1]=height;
             tab_reg[2]=fps;
             tab_reg[3]=view_width;
             tab_reg[4]=view_height;

             int rc=modbus_write_registers(m_mcs->resultdata.ctx_robotset,ALSROBOTCAM_CAMWIDTH_REG_ADD,5,tab_reg);
             if(rc!=5)
             {
                 if(ui->checkBox->isChecked()==false)
                     ui->record->append(QStringLiteral("更新相机设置失败"));
             }
             else
             {
                 if(ui->checkBox->isChecked()==false)
                     ui->record->append(QStringLiteral("更新相机设置成功,请重启激光头"));
             }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再设置相机参数"));
        }
    });

    connect(ui->setdposBtn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_robotset_state==true)
        {
             bool d_dX,d_dY,d_dZ;
             float dX=ui->dX->text().toFloat(&d_dX);
             float dY=ui->dY->text().toFloat(&d_dY);
             float dZ=ui->dZ->text().toFloat(&d_dZ);
             if(d_dX==true&&d_dY==true&&d_dZ==true)
             {
                 uint16_t tab_reg[3];
                 tab_reg[0]=(uint16_t)((int16_t)((int)(dX*100)));
                 tab_reg[1]=(uint16_t)((int16_t)((int)(dY*100)));
                 tab_reg[2]=(uint16_t)((int16_t)((int)(dZ*100)));
                 int rc=modbus_write_registers(m_mcs->resultdata.ctx_robotset,ALSROBOTCAM_COMPENSATION_X,3,tab_reg);
                 if(rc!=3)
                 {
                     if(ui->checkBox->isChecked()==false)
                         ui->record->append(QStringLiteral("更新补偿设置失败"));
                 }
                 else
                 {
                     if(ui->checkBox->isChecked()==false)
                         ui->record->append(QStringLiteral("更新补偿设置成功"));
                 }
             }
             else
             {
                 if(ui->checkBox->isChecked()==false)
                     ui->record->append(QStringLiteral("补偿数据格式输入错误"));
             }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再设置补偿参数"));
        }
    });

    connect(ui->checkBox_Y,&QCheckBox::clicked,[=](){
        if(m_mcs->resultdata.link_robotset_state==true)
        {
            u_int16_t dY;
            if(ui->checkBox_Y->isChecked()==false)
            {
                dY=0;
            }
            else
            {
                dY=1;
            }
            uint16_t tab_reg[1];
            tab_reg[0]=dY;
            int rc=modbus_write_registers(m_mcs->resultdata.ctx_robotset,ALSROBOTCAM_REVERSE_Y_REG_ADD,1,tab_reg);
            if(rc!=1)
            {
                if(ui->checkBox_Y->isChecked()==false)
                {
                    ui->checkBox_Y->setChecked(true);
                }
                else
                {
                    ui->checkBox_Y->setChecked(false);
                }
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("Y轴反向参数设置失败"));
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("Y轴反向参数设置成功"));
            }
        }
        else
        {
            if(ui->checkBox_Y->isChecked()==false)
            {
                ui->checkBox_Y->setChecked(true);
            }
            else
            {
                ui->checkBox_Y->setChecked(false);
            }
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再设置Y轴反向参数"));
        }
    });

    connect(ui->checkBox_Z,&QCheckBox::clicked,[=](){
        if(m_mcs->resultdata.link_robotset_state==true)
        {
            u_int16_t dZ;
            if(ui->checkBox_Z->isChecked()==false)
            {
                dZ=0;
            }
            else
            {
                dZ=1;
            }
            uint16_t tab_reg[1];
            tab_reg[0]=dZ;
            int rc=modbus_write_registers(m_mcs->resultdata.ctx_robotset,ALSROBOTCAM_REVERSE_Z_REG_ADD,1,tab_reg);
            if(rc!=1)
            {
                if(ui->checkBox_Z->isChecked()==false)
                {
                    ui->checkBox_Z->setChecked(true);
                }
                else
                {
                    ui->checkBox_Z->setChecked(false);
                }
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("Z轴反向参数设置失败"));
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("Z轴反向参数设置成功"));
            }
        }
        else
        {
            if(ui->checkBox_Z->isChecked()==false)
            {
                ui->checkBox_Z->setChecked(true);
            }
            else
            {
                ui->checkBox_Z->setChecked(false);
            }
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再设置Z轴反向参数"));
        }
    });

#if _MSC_VER||WINDOWS_TCP
#else
    connect(ui->writeTab1Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int alg0_99_threshold=ui->alg0_99_threshold->text().toInt();
           if(alg0_99_threshold<20||alg0_99_threshold>65535)
           {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("设置相机曝光值超出范围"));
           }
           else
           {
               m_mcs->cam->sop_cam[0].i32_exposure=alg0_99_threshold;
               m_mcs->cam->sop_cam[0].roscmd_set_exposure(m_mcs->cam->sop_cam[0].i32_exposure);
               m_mcs->resultdata.alg100_threshold=alg0_99_threshold;
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("设置相机曝光值成功"));
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再设置曝光值"));
       }
    });

    connect(ui->readTab1Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int exposure=0;
           if(0==m_mcs->cam->sop_cam[0].roscmd_get_exposure(&exposure))
           {
               if(exposure>65535)
               {
                   m_mcs->resultdata.alg100_threshold=65535;
               }
               else if(exposure<20)
               {
                   m_mcs->resultdata.alg100_threshold=20;
               }
               else
               {
                   m_mcs->resultdata.alg100_threshold=exposure;
               }
               ui->alg0_99_threshold->setText(QString::number(exposure));
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取相机曝光值成功"));
           }
           else
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取相机曝光值失败"));
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再读取曝光值"));
       }
    });
#endif
    connect(ui->writeTab2Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int alg100_threshold=ui->alg100_threshold->text().toInt();
           if(alg100_threshold<20||alg100_threshold>65535)
           {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("设置相机曝光值超出范围"));
           }
           else
           {
               uint16_t tab_reg[ALS100_REG_TOTALNUM];
               tab_reg[0]=alg100_threshold;
               for(int i=1;i<ALS100_REG_TOTALNUM;i++)
               {
                   tab_reg[i]=(uint16_t)(ui->tab2tableWidget->item(i-1,2)->text().toInt());
               }
               int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS100_EXPOSURE_TIME_REG_ADD,ALS100_REG_TOTALNUM,tab_reg);
               if(rc!=ALS100_REG_TOTALNUM)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号100参数失败"));
               }
               else
               {
                   m_mcs->resultdata.alg100_threshold=alg100_threshold;
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号100参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再设置任务号100参数"));
       }
    });

    connect(ui->initTab2Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           uint16_t tab_reg[1];
           tab_reg[0]=1;
           int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS100_INIT_REG_ADD,1,tab_reg);
           if(rc!=1)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号100参数失败"));
           }
           else
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号100参数成功"));
           #if _MSC_VER
               Sleep(1000);
           #else
               sleep(1);
           #endif
               int real_readnum=0;
               u_int16_t rcvdata[ALS100_REG_TOTALNUM];
               real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS100_EXPOSURE_TIME_REG_ADD,ALS100_REG_TOTALNUM,rcvdata);
               if(real_readnum<0)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号100参数失败"));
               }
               else
               {
                   if(rcvdata[0]>65535)
                   {
                       m_mcs->resultdata.alg100_threshold=65535;
                   }
                   else if(rcvdata[0]<20)
                   {
                       m_mcs->resultdata.alg100_threshold=20;
                   }
                   else
                   {
                       m_mcs->resultdata.alg100_threshold=rcvdata[0];
                   }
                   ui->alg100_threshold->setText(QString::number(m_mcs->resultdata.alg100_threshold));

                   for(int i=1;i<ALS100_REG_TOTALNUM;i++)
                   {
                       ui->tab2tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                   }

                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号100参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再重置任务号100参数"));
       }
    });

    connect(ui->readTab2Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int real_readnum=0;
           u_int16_t rcvdata[ALS100_REG_TOTALNUM];
           real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS100_EXPOSURE_TIME_REG_ADD,ALS100_REG_TOTALNUM,rcvdata);
           if(real_readnum<0)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号100参数失败"));
           }
           else
           {
               if(rcvdata[0]>65535)
               {
                   m_mcs->resultdata.alg100_threshold=65535;
               }
               else if(rcvdata[0]<20)
               {
                   m_mcs->resultdata.alg100_threshold=20;
               }
               else
               {
                   m_mcs->resultdata.alg100_threshold=rcvdata[0];
               }
               ui->alg100_threshold->setText(QString::number(m_mcs->resultdata.alg100_threshold));

               for(int i=1;i<ALS100_REG_TOTALNUM;i++)
               {
                   ui->tab2tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
               }

               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号100参数成功"));
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再读取任务号100参数"));
       }
    });

    connect(ui->othersaveTab2Btn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_ftp_state==true)
        {
            bool ok;
            int taskname=ui->alg100_othersave->text().toInt(&ok);
            if(ok==true)
            {
                if((taskname>=200&&taskname<=1000)||(taskname>0&&taskname<100))
                {
                    QJsonObject json;
                    QJsonObject sing;
                    sing.insert("taskname",taskname);
                    sing.insert("alsnum",100);
                    json.insert("touch",sing);
                    QString msg=JsonToQstring(json);
                    QByteArray arry=msg.toUtf8();
                    arry.push_back('\0');
                    m_mcs->resultdata.client->write(arry);
                    if(ui->checkBox->isChecked()==false)
                    {
                        QString msg=QStringLiteral("生成自定义任务号:")+QString::number(taskname)+QStringLiteral(" 算法号:100");
                        ui->record->append(msg);
                    }
                }
                else
                {
                    if(ui->checkBox->isChecked()==false)
                         ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
                }
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                     ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再另存自定义任务号"));
        }
     });

    connect(ui->tab2ZoomBtn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_param_state==true)
        {
            if(drowstep==2)
            {
                uint16_t tab_reg[ALS100_REG_TOTALNUM];
                drowstep=0;
                drowstep_temp=0;
                tab_reg[0]=u16_zoom_left;
                tab_reg[1]=u16_zoom_right;
                tab_reg[2]=u16_zoom_top;
                tab_reg[3]=u16_zoom_deep;

                int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS100_CUTLEFT_REG_ADD,4,tab_reg);
                if(rc!=4)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("设置更新区域失败"));
                }
                else
                {
                    ui->tab2tableWidget->item(ALS100_CUTLEFT_REG_ADD-ALS100_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_left));
                    ui->tab2tableWidget->item(ALS100_CUTRIGHT_REG_ADD-ALS100_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_right));
                    ui->tab2tableWidget->item(ALS100_CUTTOP_REG_ADD-ALS100_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_top));
                    ui->tab2tableWidget->item(ALS100_CUTDEEP_REG_ADD-ALS100_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_deep));
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("设置更新区域成功"));
                }

            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再更新区域"));
        }
    });

    connect(ui->writeTab3Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int alg101_threshold=ui->alg101_threshold->text().toInt();
           if(alg101_threshold<20||alg101_threshold>65535)
           {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("设置相机曝光值超出范围"));
           }
           else
           {
               uint16_t tab_reg[ALS101_REG_TOTALNUM];
               tab_reg[0]=alg101_threshold;
               for(int i=1;i<ALS101_REG_TOTALNUM;i++)
               {
                   tab_reg[i]=(uint16_t)(ui->tab3tableWidget->item(i-1,2)->text().toInt());
               }
               int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS101_EXPOSURE_TIME_REG_ADD,ALS101_REG_TOTALNUM,tab_reg);
               if(rc!=ALS101_REG_TOTALNUM)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号101参数失败"));
               }
               else
               {
                   m_mcs->resultdata.alg101_threshold=alg101_threshold;
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号101参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再设置任务号101参数"));
       }
    });

    connect(ui->initTab3Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           uint16_t tab_reg[1];
           tab_reg[0]=1;
           int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS101_INIT_REG_ADD,1,tab_reg);
           if(rc!=1)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号101参数失败"));
           }
           else
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号101参数成功"));
                #if _MSC_VER
                    Sleep(1000);
                #else
                    sleep(1);
                #endif
               int real_readnum=0;
               u_int16_t rcvdata[ALS101_REG_TOTALNUM];
               real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS101_EXPOSURE_TIME_REG_ADD,ALS101_REG_TOTALNUM,rcvdata);
               if(real_readnum<0)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号101参数失败"));
               }
               else
               {
                   if(rcvdata[0]>65535)
                   {
                       m_mcs->resultdata.alg101_threshold=65535;
                   }
                   else if(rcvdata[0]<20)
                   {
                       m_mcs->resultdata.alg101_threshold=20;
                   }
                   else
                   {
                       m_mcs->resultdata.alg101_threshold=rcvdata[0];
                   }
                   ui->alg101_threshold->setText(QString::number(m_mcs->resultdata.alg101_threshold));

                   for(int i=1;i<ALS101_REG_TOTALNUM;i++)
                   {
                       ui->tab3tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                   }

                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号101参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再重置任务号101参数"));
       }
    });

    connect(ui->readTab3Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int real_readnum=0;
           u_int16_t rcvdata[ALS101_REG_TOTALNUM];
           real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS101_EXPOSURE_TIME_REG_ADD,ALS101_REG_TOTALNUM,rcvdata);
           if(real_readnum<0)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号101参数失败"));
           }
           else
           {
               if(rcvdata[0]>65535)
               {
                   m_mcs->resultdata.alg101_threshold=65535;
               }
               else if(rcvdata[0]<20)
               {
                   m_mcs->resultdata.alg101_threshold=20;
               }
               else
               {
                   m_mcs->resultdata.alg101_threshold=rcvdata[0];
               }
               ui->alg101_threshold->setText(QString::number(m_mcs->resultdata.alg101_threshold));

               for(int i=1;i<ALS101_REG_TOTALNUM;i++)
               {
                   ui->tab3tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
               }

               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号101参数成功"));
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再读取任务号101参数"));
       }
    });

    connect(ui->othersaveTab3Btn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_ftp_state==true)
        {
            bool ok;
            int taskname=ui->alg101_othersave->text().toInt(&ok);
            if(ok==true)
            {
                if((taskname>=200&&taskname<=1000)||(taskname>0&&taskname<100))
                {
                    QJsonObject json;
                    QJsonObject sing;
                    sing.insert("taskname",taskname);
                    sing.insert("alsnum",101);
                    json.insert("touch",sing);
                    QString msg=JsonToQstring(json);
                    QByteArray arry=msg.toUtf8();
                    arry.push_back('\0');
                    m_mcs->resultdata.client->write(arry);
                    if(ui->checkBox->isChecked()==false)
                    {
                        QString msg=QStringLiteral("生成自定义任务号:")+QString::number(taskname)+QStringLiteral(" 算法号:101");
                        ui->record->append(msg);
                    }
                }
                else
                {
                    if(ui->checkBox->isChecked()==false)
                         ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
                }
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                     ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再另存自定义任务号"));
        }
     });

    connect(ui->tab3ZoomBtn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_param_state==true)
        {
            if(drowstep==2)
            {
                uint16_t tab_reg[ALS101_REG_TOTALNUM];
                drowstep=0;
                drowstep_temp=0;
                tab_reg[0]=u16_zoom_left;
                tab_reg[1]=u16_zoom_right;
                tab_reg[2]=u16_zoom_top;
                tab_reg[3]=u16_zoom_deep;

                int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS101_CUTLEFT_REG_ADD,4,tab_reg);
                if(rc!=4)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("设置更新区域失败"));
                }
                else
                {
                    ui->tab3tableWidget->item(ALS101_CUTLEFT_REG_ADD-ALS101_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_left));
                    ui->tab3tableWidget->item(ALS101_CUTRIGHT_REG_ADD-ALS101_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_right));
                    ui->tab3tableWidget->item(ALS101_CUTTOP_REG_ADD-ALS101_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_top));
                    ui->tab3tableWidget->item(ALS101_CUTDEEP_REG_ADD-ALS101_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_deep));
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("设置更新区域成功"));
                }

            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再更新区域"));
        }
    });

    connect(ui->writeTab4Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int alg102_threshold=ui->alg102_threshold->text().toInt();
           if(alg102_threshold<20||alg102_threshold>65535)
           {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("设置相机曝光值超出范围"));
           }
           else
           {
               uint16_t tab_reg[ALS102_REG_TOTALNUM];
               tab_reg[0]=alg102_threshold;
               for(int i=1;i<ALS102_REG_TOTALNUM;i++)
               {
                   tab_reg[i]=(uint16_t)(ui->tab4tableWidget->item(i-1,2)->text().toInt());
               }
               int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS102_EXPOSURE_TIME_REG_ADD,ALS102_REG_TOTALNUM,tab_reg);
               if(rc!=ALS102_REG_TOTALNUM)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号102参数失败"));
               }
               else
               {
                   m_mcs->resultdata.alg102_threshold=alg102_threshold;
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号102参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再设置任务号102参数"));
       }
    });

    connect(ui->initTab4Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           uint16_t tab_reg[1];
           tab_reg[0]=1;
           int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS102_INIT_REG_ADD,1,tab_reg);
           if(rc!=1)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号102参数失败"));
           }
           else
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号102参数成功"));
                #if _MSC_VER
                    Sleep(1000);
                #else
                    sleep(1);
                #endif
               int real_readnum=0;
               u_int16_t rcvdata[ALS102_REG_TOTALNUM];
               real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS102_EXPOSURE_TIME_REG_ADD,ALS102_REG_TOTALNUM,rcvdata);
               if(real_readnum<0)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号102参数失败"));
               }
               else
               {
                   if(rcvdata[0]>65535)
                   {
                       m_mcs->resultdata.alg102_threshold=65535;
                   }
                   else if(rcvdata[0]<20)
                   {
                       m_mcs->resultdata.alg102_threshold=20;
                   }
                   else
                   {
                       m_mcs->resultdata.alg102_threshold=rcvdata[0];
                   }
                   ui->alg102_threshold->setText(QString::number(m_mcs->resultdata.alg102_threshold));

                   for(int i=1;i<ALS102_REG_TOTALNUM;i++)
                   {
                       ui->tab4tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                   }

                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号102参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再重置任务号102参数"));
       }
    });

    connect(ui->readTab4Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int real_readnum=0;
           u_int16_t rcvdata[ALS102_REG_TOTALNUM];
           real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS102_EXPOSURE_TIME_REG_ADD,ALS102_REG_TOTALNUM,rcvdata);
           if(real_readnum<0)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号102参数失败"));
           }
           else
           {
               if(rcvdata[0]>65535)
               {
                   m_mcs->resultdata.alg102_threshold=65535;
               }
               else if(rcvdata[0]<20)
               {
                   m_mcs->resultdata.alg102_threshold=20;
               }
               else
               {
                   m_mcs->resultdata.alg102_threshold=rcvdata[0];
               }
               ui->alg102_threshold->setText(QString::number(m_mcs->resultdata.alg102_threshold));

               for(int i=1;i<ALS102_REG_TOTALNUM;i++)
               {
                   ui->tab4tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
               }

               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号102参数成功"));
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再读取任务号102参数"));
       }
    });

    connect(ui->othersaveTab4Btn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_ftp_state==true)
        {
            bool ok;
            int taskname=ui->alg102_othersave->text().toInt(&ok);
            if(ok==true)
            {
                if((taskname>=200&&taskname<=1000)||(taskname>0&&taskname<100))
                {
                    QJsonObject json;
                    QJsonObject sing;
                    sing.insert("taskname",taskname);
                    sing.insert("alsnum",102);
                    json.insert("touch",sing);
                    QString msg=JsonToQstring(json);
                    QByteArray arry=msg.toUtf8();
                    arry.push_back('\0');
                    m_mcs->resultdata.client->write(arry);
                    if(ui->checkBox->isChecked()==false)
                    {
                        QString msg=QStringLiteral("生成自定义任务号:")+QString::number(taskname)+QStringLiteral(" 算法号:102");
                        ui->record->append(msg);
                    }
                }
                else
                {
                    if(ui->checkBox->isChecked()==false)
                         ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
                }
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                     ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再另存自定义任务号"));
        }
     });

    connect(ui->writeTab5Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int alg103_threshold=ui->alg103_threshold->text().toInt();
           if(alg103_threshold<20||alg103_threshold>65535)
           {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("设置相机曝光值超出范围"));
           }
           else
           {
               uint16_t tab_reg[ALS103_REG_TOTALNUM];
               tab_reg[0]=alg103_threshold;
               for(int i=1;i<ALS103_REG_TOTALNUM;i++)
               {
                   tab_reg[i]=(uint16_t)(ui->tab5tableWidget->item(i-1,2)->text().toInt());
               }
               int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS103_EXPOSURE_TIME_REG_ADD,ALS103_REG_TOTALNUM,tab_reg);
               if(rc!=ALS103_REG_TOTALNUM)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号103参数失败"));
               }
               else
               {
                   m_mcs->resultdata.alg103_threshold=alg103_threshold;
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号103参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再设置任务号103参数"));
       }
    });

    connect(ui->initTab5Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           uint16_t tab_reg[1];
           tab_reg[0]=1;
           int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS103_INIT_REG_ADD,1,tab_reg);
           if(rc!=1)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号103参数失败"));
           }
           else
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号103参数成功"));
                #if _MSC_VER
                    Sleep(1000);
                #else
                    sleep(1);
                #endif
               int real_readnum=0;
               u_int16_t rcvdata[ALS103_REG_TOTALNUM];
               real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS103_EXPOSURE_TIME_REG_ADD,ALS103_REG_TOTALNUM,rcvdata);
               if(real_readnum<0)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号103参数失败"));
               }
               else
               {
                   if(rcvdata[0]>65535)
                   {
                       m_mcs->resultdata.alg103_threshold=65535;
                   }
                   else if(rcvdata[0]<20)
                   {
                       m_mcs->resultdata.alg103_threshold=20;
                   }
                   else
                   {
                       m_mcs->resultdata.alg103_threshold=rcvdata[0];
                   }
                   ui->alg103_threshold->setText(QString::number(m_mcs->resultdata.alg103_threshold));

                   for(int i=1;i<ALS103_REG_TOTALNUM;i++)
                   {
                       ui->tab5tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                   }

                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号103参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再重置任务号103参数"));
       }
    });

    connect(ui->readTab5Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int real_readnum=0;
           u_int16_t rcvdata[ALS103_REG_TOTALNUM];
           real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS103_EXPOSURE_TIME_REG_ADD,ALS103_REG_TOTALNUM,rcvdata);
           if(real_readnum<0)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号103参数失败"));
           }
           else
           {
               if(rcvdata[0]>65535)
               {
                   m_mcs->resultdata.alg103_threshold=65535;
               }
               else if(rcvdata[0]<20)
               {
                   m_mcs->resultdata.alg103_threshold=20;
               }
               else
               {
                   m_mcs->resultdata.alg103_threshold=rcvdata[0];
               }
               ui->alg103_threshold->setText(QString::number(m_mcs->resultdata.alg103_threshold));

               for(int i=1;i<ALS103_REG_TOTALNUM;i++)
               {
                   ui->tab5tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
               }

               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号103参数成功"));
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再读取任务号103参数"));
       }
    });

    connect(ui->othersaveTab5Btn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_ftp_state==true)
        {
            bool ok;
            int taskname=ui->alg103_othersave->text().toInt(&ok);
            if(ok==true)
            {
                if((taskname>=200&&taskname<=1000)||(taskname>0&&taskname<100))
                {
                    QJsonObject json;
                    QJsonObject sing;
                    sing.insert("taskname",taskname);
                    sing.insert("alsnum",103);
                    json.insert("touch",sing);
                    QString msg=JsonToQstring(json);
                    QByteArray arry=msg.toUtf8();
                    arry.push_back('\0');
                    m_mcs->resultdata.client->write(arry);
                    if(ui->checkBox->isChecked()==false)
                    {
                        QString msg=QStringLiteral("生成自定义任务号:")+QString::number(taskname)+QStringLiteral(" 算法号:103");
                        ui->record->append(msg);
                    }
                }
                else
                {
                    if(ui->checkBox->isChecked()==false)
                         ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
                }
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                     ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再另存自定义任务号"));
        }
     });


    connect(ui->writeTab6Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int alg104_threshold=ui->alg104_threshold->text().toInt();
           if(alg104_threshold<20||alg104_threshold>65535)
           {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("设置相机曝光值超出范围"));
           }
           else
           {
               uint16_t tab_reg[ALS104_REG_TOTALNUM];
               tab_reg[0]=alg104_threshold;
               for(int i=1;i<ALS104_REG_TOTALNUM;i++)
               {
                   tab_reg[i]=(uint16_t)(ui->tab6tableWidget->item(i-1,2)->text().toInt());
               }
               int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS104_EXPOSURE_TIME_REG_ADD,ALS104_REG_TOTALNUM,tab_reg);
               if(rc!=ALS104_REG_TOTALNUM)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号104参数失败"));
               }
               else
               {
                   m_mcs->resultdata.alg104_threshold=alg104_threshold;
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号104参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再设置任务号104参数"));
       }
    });

    connect(ui->initTab6Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           uint16_t tab_reg[1];
           tab_reg[0]=1;
           int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS104_INIT_REG_ADD,1,tab_reg);
           if(rc!=1)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号104参数失败"));
           }
           else
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号104参数成功"));
                #if _MSC_VER
                    Sleep(1000);
                #else
                    sleep(1);
                #endif
               int real_readnum=0;
               u_int16_t rcvdata[ALS104_REG_TOTALNUM];
               real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS104_EXPOSURE_TIME_REG_ADD,ALS104_REG_TOTALNUM,rcvdata);
               if(real_readnum<0)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号104参数失败"));
               }
               else
               {
                   if(rcvdata[0]>65535)
                   {
                       m_mcs->resultdata.alg104_threshold=65535;
                   }
                   else if(rcvdata[0]<20)
                   {
                       m_mcs->resultdata.alg104_threshold=20;
                   }
                   else
                   {
                       m_mcs->resultdata.alg104_threshold=rcvdata[0];
                   }
                   ui->alg104_threshold->setText(QString::number(m_mcs->resultdata.alg104_threshold));

                   for(int i=1;i<ALS104_REG_TOTALNUM;i++)
                   {
                       ui->tab6tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                   }

                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号104参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再重置任务号104参数"));
       }
    });

    connect(ui->readTab6Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int real_readnum=0;
           u_int16_t rcvdata[ALS104_REG_TOTALNUM];
           real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS104_EXPOSURE_TIME_REG_ADD,ALS104_REG_TOTALNUM,rcvdata);
           if(real_readnum<0)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号104参数失败"));
           }
           else
           {
               if(rcvdata[0]>65535)
               {
                   m_mcs->resultdata.alg104_threshold=65535;
               }
               else if(rcvdata[0]<20)
               {
                   m_mcs->resultdata.alg104_threshold=20;
               }
               else
               {
                   m_mcs->resultdata.alg104_threshold=rcvdata[0];
               }
               ui->alg104_threshold->setText(QString::number(m_mcs->resultdata.alg104_threshold));

               for(int i=1;i<ALS104_REG_TOTALNUM;i++)
               {
                   ui->tab6tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
               }

               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号104参数成功"));
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再读取任务号104参数"));
       }
    });

    connect(ui->othersaveTab6Btn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_ftp_state==true)
        {
            bool ok;
            int taskname=ui->alg104_othersave->text().toInt(&ok);
            if(ok==true)
            {
                if((taskname>=200&&taskname<=1000)||(taskname>0&&taskname<100))
                {
                    QJsonObject json;
                    QJsonObject sing;
                    sing.insert("taskname",taskname);
                    sing.insert("alsnum",104);
                    json.insert("touch",sing);
                    QString msg=JsonToQstring(json);
                    QByteArray arry=msg.toUtf8();
                    arry.push_back('\0');
                    m_mcs->resultdata.client->write(arry);
                    if(ui->checkBox->isChecked()==false)
                    {
                        QString msg=QStringLiteral("生成自定义任务号:")+QString::number(taskname)+QStringLiteral(" 算法号:104");
                        ui->record->append(msg);
                    }
                }
                else
                {
                    if(ui->checkBox->isChecked()==false)
                         ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
                }
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                     ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再另存自定义任务号"));
        }
     });

    connect(ui->writeTab7Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int alg105_threshold=ui->alg105_threshold->text().toInt();
           if(alg105_threshold<20||alg105_threshold>65535)
           {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("设置相机曝光值超出范围"));
           }
           else
           {
               uint16_t tab_reg[ALS105_REG_TOTALNUM];
               tab_reg[0]=alg105_threshold;
               for(int i=1;i<ALS105_REG_TOTALNUM;i++)
               {
                   tab_reg[i]=(uint16_t)(ui->tab7tableWidget->item(i-1,2)->text().toInt());
               }
               int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS105_EXPOSURE_TIME_REG_ADD,ALS105_REG_TOTALNUM,tab_reg);
               if(rc!=ALS105_REG_TOTALNUM)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号105参数失败"));
               }
               else
               {
                   m_mcs->resultdata.alg105_threshold=alg105_threshold;
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号105参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再设置任务号105参数"));
       }
    });

    connect(ui->initTab7Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           uint16_t tab_reg[1];
           tab_reg[0]=1;
           int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS105_INIT_REG_ADD,1,tab_reg);
           if(rc!=1)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号105参数失败"));
           }
           else
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号105参数成功"));
                #if _MSC_VER
                    Sleep(1000);
                #else
                    sleep(1);
                #endif
               int real_readnum=0;
               u_int16_t rcvdata[ALS105_REG_TOTALNUM];
               real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS105_EXPOSURE_TIME_REG_ADD,ALS105_REG_TOTALNUM,rcvdata);
               if(real_readnum<0)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号105参数失败"));
               }
               else
               {
                   if(rcvdata[0]>65535)
                   {
                       m_mcs->resultdata.alg105_threshold=65535;
                   }
                   else if(rcvdata[0]<20)
                   {
                       m_mcs->resultdata.alg105_threshold=20;
                   }
                   else
                   {
                       m_mcs->resultdata.alg105_threshold=rcvdata[0];
                   }
                   ui->alg105_threshold->setText(QString::number(m_mcs->resultdata.alg105_threshold));

                   for(int i=1;i<ALS105_REG_TOTALNUM;i++)
                   {
                       ui->tab7tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                   }

                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号105参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再重置任务号105参数"));
       }
    });

    connect(ui->readTab7Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int real_readnum=0;
           u_int16_t rcvdata[ALS105_REG_TOTALNUM];
           real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS105_EXPOSURE_TIME_REG_ADD,ALS105_REG_TOTALNUM,rcvdata);
           if(real_readnum<0)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号105参数失败"));
           }
           else
           {
               if(rcvdata[0]>65535)
               {
                   m_mcs->resultdata.alg105_threshold=65535;
               }
               else if(rcvdata[0]<20)
               {
                   m_mcs->resultdata.alg105_threshold=20;
               }
               else
               {
                   m_mcs->resultdata.alg105_threshold=rcvdata[0];
               }
               ui->alg105_threshold->setText(QString::number(m_mcs->resultdata.alg105_threshold));

               for(int i=1;i<ALS105_REG_TOTALNUM;i++)
               {
                   ui->tab7tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
               }

               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号105参数成功"));
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再读取任务号105参数"));
       }
    });

    connect(ui->othersaveTab7Btn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_ftp_state==true)
        {
            bool ok;
            int taskname=ui->alg105_othersave->text().toInt(&ok);
            if(ok==true)
            {
                if((taskname>=200&&taskname<=1000)||(taskname>0&&taskname<100))
                {
                    QJsonObject json;
                    QJsonObject sing;
                    sing.insert("taskname",taskname);
                    sing.insert("alsnum",105);
                    json.insert("touch",sing);
                    QString msg=JsonToQstring(json);
                    QByteArray arry=msg.toUtf8();
                    arry.push_back('\0');
                    m_mcs->resultdata.client->write(arry);
                    if(ui->checkBox->isChecked()==false)
                    {
                        QString msg=QStringLiteral("生成自定义任务号:")+QString::number(taskname)+QStringLiteral(" 算法号:105");
                        ui->record->append(msg);
                    }
                }
                else
                {
                    if(ui->checkBox->isChecked()==false)
                         ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
                }
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                     ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再另存自定义任务号"));
        }
     });

    connect(ui->tab7ZoomBtn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_param_state==true)
        {
            if(drowstep==2)
            {
                uint16_t tab_reg[ALS105_REG_TOTALNUM];
                drowstep=0;
                drowstep_temp=0;
                tab_reg[0]=u16_zoom_left;
                tab_reg[1]=u16_zoom_right;
                tab_reg[2]=u16_zoom_top;
                tab_reg[3]=u16_zoom_deep;

                int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS105_CUTLEFT_REG_ADD,4,tab_reg);
                if(rc!=4)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("设置更新区域失败"));
                }
                else
                {
                    ui->tab7tableWidget->item(ALS105_CUTLEFT_REG_ADD-ALS105_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_left));
                    ui->tab7tableWidget->item(ALS105_CUTRIGHT_REG_ADD-ALS105_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_right));
                    ui->tab7tableWidget->item(ALS105_CUTTOP_REG_ADD-ALS105_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_top));
                    ui->tab7tableWidget->item(ALS105_CUTDEEP_REG_ADD-ALS105_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_deep));
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("设置更新区域成功"));
                }

            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再更新区域"));
        }
    });

    connect(ui->writeTab8Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int alg106_threshold=ui->alg106_threshold->text().toInt();
           if(alg106_threshold<20||alg106_threshold>65535)
           {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("设置相机曝光值超出范围"));
           }
           else
           {
               uint16_t tab_reg[ALS106_REG_TOTALNUM];
               tab_reg[0]=alg106_threshold;
               for(int i=1;i<ALS106_REG_TOTALNUM;i++)
               {
                   tab_reg[i]=(uint16_t)(ui->tab8tableWidget->item(i-1,2)->text().toInt());
               }
               int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS106_EXPOSURE_TIME_REG_ADD,ALS106_REG_TOTALNUM,tab_reg);
               if(rc!=ALS106_REG_TOTALNUM)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号106参数失败"));
               }
               else
               {
                   m_mcs->resultdata.alg106_threshold=alg106_threshold;
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号106参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再设置任务号106参数"));
       }
    });

    connect(ui->initTab8Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           uint16_t tab_reg[1];
           tab_reg[0]=1;
           int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS106_INIT_REG_ADD,1,tab_reg);
           if(rc!=1)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号106参数失败"));
           }
           else
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号106参数成功"));
                #if _MSC_VER
                    Sleep(1000);
                #else
                    sleep(1);
                #endif
               int real_readnum=0;
               u_int16_t rcvdata[ALS106_REG_TOTALNUM];
               real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS106_EXPOSURE_TIME_REG_ADD,ALS106_REG_TOTALNUM,rcvdata);
               if(real_readnum<0)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号106参数失败"));
               }
               else
               {
                   if(rcvdata[0]>65535)
                   {
                       m_mcs->resultdata.alg106_threshold=65535;
                   }
                   else if(rcvdata[0]<20)
                   {
                       m_mcs->resultdata.alg106_threshold=20;
                   }
                   else
                   {
                       m_mcs->resultdata.alg106_threshold=rcvdata[0];
                   }
                   ui->alg106_threshold->setText(QString::number(m_mcs->resultdata.alg106_threshold));

                   for(int i=1;i<ALS106_REG_TOTALNUM;i++)
                   {
                       ui->tab8tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                   }

                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号106参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再重置任务号106参数"));
       }
    });

    connect(ui->readTab8Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int real_readnum=0;
           u_int16_t rcvdata[ALS106_REG_TOTALNUM];
           real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS106_EXPOSURE_TIME_REG_ADD,ALS106_REG_TOTALNUM,rcvdata);
           if(real_readnum<0)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号106参数失败"));
           }
           else
           {
               if(rcvdata[0]>65535)
               {
                   m_mcs->resultdata.alg106_threshold=65535;
               }
               else if(rcvdata[0]<20)
               {
                   m_mcs->resultdata.alg106_threshold=20;
               }
               else
               {
                   m_mcs->resultdata.alg106_threshold=rcvdata[0];
               }
               ui->alg106_threshold->setText(QString::number(m_mcs->resultdata.alg106_threshold));

               for(int i=1;i<ALS106_REG_TOTALNUM;i++)
               {
                   ui->tab8tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
               }

               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号106参数成功"));
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再读取任务号106参数"));
       }
    });

    connect(ui->othersaveTab8Btn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_ftp_state==true)
        {
            bool ok;
            int taskname=ui->alg106_othersave->text().toInt(&ok);
            if(ok==true)
            {
                if((taskname>=200&&taskname<=1000)||(taskname>0&&taskname<100))
                {
                    QJsonObject json;
                    QJsonObject sing;
                    sing.insert("taskname",taskname);
                    sing.insert("alsnum",106);
                    json.insert("touch",sing);
                    QString msg=JsonToQstring(json);
                    QByteArray arry=msg.toUtf8();
                    arry.push_back('\0');
                    m_mcs->resultdata.client->write(arry);
                    if(ui->checkBox->isChecked()==false)
                    {
                        QString msg=QStringLiteral("生成自定义任务号:")+QString::number(taskname)+QStringLiteral(" 算法号:106");
                        ui->record->append(msg);
                    }
                }
                else
                {
                    if(ui->checkBox->isChecked()==false)
                         ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
                }
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                     ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再另存自定义任务号"));
        }
     });

    connect(ui->tab8ZoomBtn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_param_state==true)
        {
            if(drowstep==2)
            {
                uint16_t tab_reg[ALS106_REG_TOTALNUM];
                drowstep=0;
                drowstep_temp=0;
                tab_reg[0]=u16_zoom_left;
                tab_reg[1]=u16_zoom_right;
                tab_reg[2]=u16_zoom_top;
                tab_reg[3]=u16_zoom_deep;

                int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS106_CUTLEFT_REG_ADD,4,tab_reg);
                if(rc!=4)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("设置更新区域失败"));
                }
                else
                {
                    ui->tab8tableWidget->item(ALS106_CUTLEFT_REG_ADD-ALS106_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_left));
                    ui->tab8tableWidget->item(ALS106_CUTRIGHT_REG_ADD-ALS106_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_right));
                    ui->tab8tableWidget->item(ALS106_CUTTOP_REG_ADD-ALS106_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_top));
                    ui->tab8tableWidget->item(ALS106_CUTDEEP_REG_ADD-ALS106_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_deep));
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("设置更新区域成功"));
                }

            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再更新区域"));
        }
    });

    connect(ui->writeTab9Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int alg107_threshold=ui->alg107_threshold->text().toInt();
           if(alg107_threshold<20||alg107_threshold>65535)
           {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("设置相机曝光值超出范围"));
           }
           else
           {
               uint16_t tab_reg[ALS107_REG_TOTALNUM];
               tab_reg[0]=alg107_threshold;
               for(int i=1;i<ALS107_REG_TOTALNUM;i++)
               {
                   tab_reg[i]=(uint16_t)(ui->tab9tableWidget->item(i-1,2)->text().toInt());
               }
               int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS107_EXPOSURE_TIME_REG_ADD,ALS107_REG_TOTALNUM,tab_reg);
               if(rc!=ALS107_REG_TOTALNUM)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号107参数失败"));
               }
               else
               {
                   m_mcs->resultdata.alg107_threshold=alg107_threshold;
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号107参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再设置任务号107参数"));
       }
    });

    connect(ui->initTab9Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           uint16_t tab_reg[1];
           tab_reg[0]=1;
           int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS107_INIT_REG_ADD,1,tab_reg);
           if(rc!=1)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号107参数失败"));
           }
           else
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号107参数成功"));
                #if _MSC_VER
                    Sleep(1000);
                #else
                    sleep(1);
                #endif
               int real_readnum=0;
               u_int16_t rcvdata[ALS107_REG_TOTALNUM];
               real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS107_EXPOSURE_TIME_REG_ADD,ALS107_REG_TOTALNUM,rcvdata);
               if(real_readnum<0)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号107参数失败"));
               }
               else
               {
                   if(rcvdata[0]>65535)
                   {
                       m_mcs->resultdata.alg107_threshold=65535;
                   }
                   else if(rcvdata[0]<20)
                   {
                       m_mcs->resultdata.alg107_threshold=20;
                   }
                   else
                   {
                       m_mcs->resultdata.alg107_threshold=rcvdata[0];
                   }
                   ui->alg107_threshold->setText(QString::number(m_mcs->resultdata.alg107_threshold));

                   for(int i=1;i<ALS107_REG_TOTALNUM;i++)
                   {
                       ui->tab9tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                   }

                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号107参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再重置任务号107参数"));
       }
    });

    connect(ui->readTab9Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int real_readnum=0;
           u_int16_t rcvdata[ALS107_REG_TOTALNUM];
           real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS107_EXPOSURE_TIME_REG_ADD,ALS107_REG_TOTALNUM,rcvdata);
           if(real_readnum<0)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号107参数失败"));
           }
           else
           {
               if(rcvdata[0]>65535)
               {
                   m_mcs->resultdata.alg107_threshold=65535;
               }
               else if(rcvdata[0]<20)
               {
                   m_mcs->resultdata.alg107_threshold=20;
               }
               else
               {
                   m_mcs->resultdata.alg107_threshold=rcvdata[0];
               }
               ui->alg107_threshold->setText(QString::number(m_mcs->resultdata.alg107_threshold));

               for(int i=1;i<ALS107_REG_TOTALNUM;i++)
               {
                   ui->tab9tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
               }

               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号107参数成功"));
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再读取任务号107参数"));
       }
    });

    connect(ui->othersaveTab9Btn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_ftp_state==true)
        {
            bool ok;
            int taskname=ui->alg107_othersave->text().toInt(&ok);
            if(ok==true)
            {
                if((taskname>=200&&taskname<=1000)||(taskname>0&&taskname<100))
                {
                    QJsonObject json;
                    QJsonObject sing;
                    sing.insert("taskname",taskname);
                    sing.insert("alsnum",107);
                    json.insert("touch",sing);
                    QString msg=JsonToQstring(json);
                    QByteArray arry=msg.toUtf8();
                    arry.push_back('\0');
                    m_mcs->resultdata.client->write(arry);
                    if(ui->checkBox->isChecked()==false)
                    {
                        QString msg=QStringLiteral("生成自定义任务号:")+QString::number(taskname)+QStringLiteral(" 算法号:107");
                        ui->record->append(msg);
                    }
                }
                else
                {
                    if(ui->checkBox->isChecked()==false)
                         ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
                }
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                     ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再另存自定义任务号"));
        }
     });

    connect(ui->writeTab10Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int alg108_threshold=ui->alg108_threshold->text().toInt();
           if(alg108_threshold<20||alg108_threshold>65535)
           {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("设置相机曝光值超出范围"));
           }
           else
           {
               uint16_t tab_reg[ALS108_REG_TOTALNUM];
               tab_reg[0]=alg108_threshold;
               for(int i=1;i<ALS108_REG_TOTALNUM;i++)
               {
                   tab_reg[i]=(uint16_t)(ui->tab10tableWidget->item(i-1,2)->text().toInt());
               }
               int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS108_EXPOSURE_TIME_REG_ADD,ALS108_REG_TOTALNUM,tab_reg);
               if(rc!=ALS108_REG_TOTALNUM)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号108参数失败"));
               }
               else
               {
                   m_mcs->resultdata.alg108_threshold=alg108_threshold;
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("设置任务号108参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再设置任务号108参数"));
       }
    });

    connect(ui->initTab10Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           uint16_t tab_reg[1];
           tab_reg[0]=1;
           int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS108_INIT_REG_ADD,1,tab_reg);
           if(rc!=1)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号108参数失败"));
           }
           else
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("重置任务号108参数成功"));
                #if _MSC_VER
                    Sleep(1000);
                #else
                    sleep(1);
                #endif
               int real_readnum=0;
               u_int16_t rcvdata[ALS108_REG_TOTALNUM];
               real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS108_EXPOSURE_TIME_REG_ADD,ALS108_REG_TOTALNUM,rcvdata);
               if(real_readnum<0)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号108参数失败"));
               }
               else
               {
                   if(rcvdata[0]>65535)
                   {
                       m_mcs->resultdata.alg108_threshold=65535;
                   }
                   else if(rcvdata[0]<20)
                   {
                       m_mcs->resultdata.alg108_threshold=20;
                   }
                   else
                   {
                       m_mcs->resultdata.alg108_threshold=rcvdata[0];
                   }
                   ui->alg108_threshold->setText(QString::number(m_mcs->resultdata.alg108_threshold));

                   for(int i=1;i<ALS108_REG_TOTALNUM;i++)
                   {
                       ui->tab10tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                   }

                   if(ui->checkBox->isChecked()==false)
                       ui->record->append(QStringLiteral("重新读取任务号108参数成功"));
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再重置任务号108参数"));
       }
    });

    connect(ui->readTab10Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int real_readnum=0;
           u_int16_t rcvdata[ALS108_REG_TOTALNUM];
           real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS108_EXPOSURE_TIME_REG_ADD,ALS108_REG_TOTALNUM,rcvdata);
           if(real_readnum<0)
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号108参数失败"));
           }
           else
           {
               if(rcvdata[0]>65535)
               {
                   m_mcs->resultdata.alg108_threshold=65535;
               }
               else if(rcvdata[0]<20)
               {
                   m_mcs->resultdata.alg108_threshold=20;
               }
               else
               {
                   m_mcs->resultdata.alg108_threshold=rcvdata[0];
               }
               ui->alg108_threshold->setText(QString::number(m_mcs->resultdata.alg108_threshold));

               for(int i=1;i<ALS108_REG_TOTALNUM;i++)
               {
                   ui->tab10tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
               }

               if(ui->checkBox->isChecked()==false)
                   ui->record->append(QStringLiteral("读取任务号108参数成功"));
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("请连接相机后再读取任务号108参数"));
       }
    });

    connect(ui->othersaveTab10Btn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_ftp_state==true)
        {
            bool ok;
            int taskname=ui->alg108_othersave->text().toInt(&ok);
            if(ok==true)
            {
                if((taskname>=200&&taskname<=1000)||(taskname>0&&taskname<100))
                {
                    QJsonObject json;
                    QJsonObject sing;
                    sing.insert("taskname",taskname);
                    sing.insert("alsnum",108);
                    json.insert("touch",sing);
                    QString msg=JsonToQstring(json);
                    QByteArray arry=msg.toUtf8();
                    arry.push_back('\0');
                    m_mcs->resultdata.client->write(arry);
                    if(ui->checkBox->isChecked()==false)
                    {
                        QString msg=QStringLiteral("生成自定义任务号:")+QString::number(taskname)+QStringLiteral(" 算法号:108");
                        ui->record->append(msg);
                    }
                }
                else
                {
                    if(ui->checkBox->isChecked()==false)
                         ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
                }
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                     ui->record->append(QStringLiteral("另存自定义任务号的值需为200-1000之间或1-99之间"));
            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再另存自定义任务号"));
        }
     });

    connect(ui->tab10ZoomBtn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_param_state==true)
        {
            if(drowstep==2)
            {
                uint16_t tab_reg[ALS108_REG_TOTALNUM];
                drowstep=0;
                drowstep_temp=0;
                tab_reg[0]=u16_zoom_center_x;
                tab_reg[1]=u16_zoom_center_y;

                int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS108_CENTER_X_REG_ADD,2,tab_reg);
                if(rc!=2)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("设置更新区域失败"));
                }
                else
                {
                    ui->tab10tableWidget->item(ALS108_CENTER_X_REG_ADD-ALS108_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_center_x));
                    ui->tab10tableWidget->item(ALS108_CENTER_Y_REG_ADD-ALS108_EXPOSURE_TIME_REG_ADD-1,2)->setText(QString::number(u16_zoom_center_y));
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("设置更新区域成功"));
                }
            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再更新区域"));
        }
    });

    connect(ui->tasknumshowBtn,&QPushButton::clicked,[=](){
        showtasknum->setWindowTitle(QStringLiteral("任务号图示"));
        showtasknum->exec();
    });

    connect(ui->cambuildBtn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_param_state==true)
        {
            u_int16_t tab_reg[1];
            tab_reg[0]=2;
            int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS_SHOW_STEP_REG_ADD,1,tab_reg);
            if(rc!=1)
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(QStringLiteral("写入视图步骤失败"));
            }
            else
            {
                cambuild->init_dlg_show();
                cambuild->setWindowTitle(QStringLiteral("激光头标定"));
                cambuild->exec();
                cambuild->close_dlg_show();
                tab_reg[0]=1;
                int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS_SHOW_STEP_REG_ADD,1,tab_reg);
                if(rc!=1)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("恢复视图步骤失败"));
                }
            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再进行激光头标定"));
        }
    });

    connect(ui->savebmpstepBtn,&QPushButton::clicked,[=](){
        if(m_mcs->cam->sop_cam[0].b_connect==true)
        {
            if(m_mcs->resultdata.b_luzhi==false)
            {
                int step=ui->bmpstepEdit->text().toInt();
                u_int16_t tab_reg[1];
                tab_reg[0]=step;
                int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS_SHOW_STEP_REG_ADD,1,tab_reg);
                if(rc!=1)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("写入视图步骤失败"));
                }
                else
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("写入视图步骤成功"));
                }
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                     ui->record->append(QStringLiteral("请停止录制视频后再写入视图步骤"));
            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再写入视图步骤"));
        }
    });

    connect(ui->savebmpshowBtn,&QPushButton::clicked,[=](){
        if(m_mcs->cam->sop_cam[0].b_connect==true)
        {
            QString dir="./DATA/";
            QString time;
            std::string s_time;
            TimeFunction to;
            to.get_time_ms(&s_time);
            time=QString::fromStdString(s_time);
            QString format=".bmp";
            dir=dir+time+format;
            cv::imwrite(dir.toStdString(),(m_mcs->cam->sop_cam[0].cv_image));
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("保存图片成功"));
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再保存图片"));
        }
    });

    connect(ui->saveavishowBtn,&QPushButton::clicked,[=](){
        if(m_mcs->cam->sop_cam[0].b_connect==true)
        {
            if(m_mcs->resultdata.b_luzhi==false)
            {
                QString dir="./DATA/";
                QString time;
                std::string s_time;
                TimeFunction to;
                to.get_time_ms(&s_time);
                time=QString::fromStdString(s_time);
                QString format=".avi";
                dir=dir+time+format;
                m_mcs->cam->sop_cam[0].StartRecord(dir);
                m_mcs->resultdata.b_luzhi=true;
                ui->saveavishowBtn->setText(QStringLiteral("停止录制"));
                if(ui->checkBox->isChecked()==false)
                     ui->record->append(QStringLiteral("视频录制中"));
            }
            else if(m_mcs->resultdata.b_luzhi==true)
            {
                m_mcs->resultdata.b_luzhi=false;
                m_mcs->cam->sop_cam[0].StopRecord();
                ui->saveavishowBtn->setText(QStringLiteral("录制视频"));
                if(ui->checkBox->isChecked()==false)
                     ui->record->append(QStringLiteral("视频录制完成"));
            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再录制视频"));
        }
    });

#ifdef DEBUG_SSH

    connect(ui->stepupBtn,&QPushButton::clicked,[=](){
        if(m_mcs->cam->sop_cam[0].b_connect==true)
        {
            sshpassword->init_dlg_show();
            sshpassword->setWindowTitle(QStringLiteral("激光器升级"));
            sshpassword->exec();
            sshpassword->close_dlg_show();
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("请连接相机后再进行激光器升级"));
        }
    });
#endif
}

qtmysunnyDlg::~qtmysunnyDlg()
{
    img_windowshow(false,ui->widget);
    /*
    thread1->Stop();
    thread1->quit();
    thread1->wait();
    m_mcs->cam->sop_cam[0].DisConnect();
    */
    delete thread1;
    delete showtasknum;
    delete taskclear;
    delete pshow;
#ifdef DEBUG_SSH
    delete sshpassword;
#endif
    delete m_mcs->resultdata.client;
#if _MSC_VER||WINDOWS_TCP
#else
    delete cambuild;
#endif
    delete ui;
}
/*
void qtmysunnyDlg::showEvent(QShowEvent *e)

{
    this->setAttribute(Qt::WA_Mapped);
    QWidget::showEvent(e);
}
*/
void qtmysunnyDlg::img_windowshow(bool b_show,PictureBox *lab_show)
{
    if(b_show==true)
    {
        if(m_mcs->resultdata.link_result_state==false)
        {
            QString server_ip=ui->IPadd->text();
            QString server_port2=QString::number(PORT_ALS_RESULT);
            m_mcs->resultdata.ctx_result = modbus_new_tcp(server_ip.toUtf8(), server_port2.toInt());
            if (modbus_connect(m_mcs->resultdata.ctx_result) == -1)
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append((server_port2+QStringLiteral("端口连接失败")));
                modbus_free(m_mcs->resultdata.ctx_result);
                return;
            }      
            m_mcs->resultdata.link_result_state=true;
            if(ui->checkBox->isChecked()==false)
                ui->record->append(server_port2+QStringLiteral("端口连接成功"));
            open_camer_modbus();
        }
        if(m_mcs->resultdata.link_param_state==false)
        {
            QString server_ip=ui->IPadd->text();
            QString server_port1=QString::number(PORT_ALS_PARAMETER);
            m_mcs->resultdata.ctx_param = modbus_new_tcp(server_ip.toUtf8(), server_port1.toInt());
            if (modbus_connect(m_mcs->resultdata.ctx_param) == -1)
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(server_port1+QStringLiteral("端口连接失败"));
                modbus_free(m_mcs->resultdata.ctx_param);
                return;
            }
            m_mcs->resultdata.link_param_state=true;
            if(ui->checkBox->isChecked()==false)
                ui->record->append(server_port1+QStringLiteral("端口连接成功"));
        }
        if(m_mcs->resultdata.link_robotset_state==false)
        {
            QString server_ip=ui->IPadd->text();
            QString server_port1=QString::number(PORT_ALSROBOTCAM_SET);
            m_mcs->resultdata.ctx_robotset = modbus_new_tcp(server_ip.toUtf8(), server_port1.toInt());
            if (modbus_connect(m_mcs->resultdata.ctx_robotset) == -1)
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(server_port1+QStringLiteral("端口连接失败"));
                modbus_free(m_mcs->resultdata.ctx_robotset);
                return;
            }
            m_mcs->resultdata.link_robotset_state=true;
            if(ui->checkBox->isChecked()==false)
                ui->record->append(server_port1+QStringLiteral("端口连接成功"));
        }
        if(m_mcs->resultdata.link_ftp_state==false)
        {
            QString server_ip=ui->IPadd->text();
            QString server_port1=QString::number(PORT_ALSTCP_FTP);
            m_mcs->resultdata.client->connectToHost(server_ip.toUtf8(), server_port1.toInt());
            if(!m_mcs->resultdata.client->waitForConnected(1000))
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append(server_port1+QStringLiteral("端口连接失败"));
                return;
            }
            /******************/
            QJsonObject json;
            QJsonArray jarry;
            jarry.append("homography_matrix");
            jarry.append("pData_demdlg_R");
            jarry.append("pData_demdlg_T");
            jarry.append("pData_matrix_camera2plane");
            jarry.append("pData_matrix_plane2robot");
            jarry.append("pData_point");
            json.insert("cat",jarry);
            QString msg=JsonToQstring(json);
            QByteArray arry=msg.toUtf8();
            arry.push_back('\0');
            m_mcs->resultdata.client->write(arry);
            /*******************/
            m_mcs->resultdata.link_ftp_state=true;
            if(ui->checkBox->isChecked()==false)
                ui->record->append(server_port1+QStringLiteral("端口连接成功"));
        }

        int real_readnum;

        real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_robotset,ALSROBOTCAM_ROBOTMOD_REG_ADD,2,m_mcs->resultdata.red_robotset);
        if(real_readnum<0)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("获取当前机器人设置信息失败"));
        }
        else
        {
            u_int16_t robotmod=m_mcs->resultdata.red_robotset[0];
            u_int16_t port=m_mcs->resultdata.red_robotset[1];
            ui->comboBox->setCurrentIndex(robotmod);
            ui->robotport->setText(QString::number(port));
            UpdataRobot(robotmod);
            if(ui->checkBox->isChecked()==false)
            {
                switch(robotmod)
                {
                    case 0:
                    {
                        ui->record->append(QStringLiteral("获取当前内部机器人设置:无机器人"));
                    }
                    break;
                    case 1:
                    {
                        ui->record->append(QStringLiteral("获取当前内部机器人设置:智昌机器人"));
                        QString msg=QStringLiteral("获取当前内部机器人端口号:")+QString::number(port);
                        ui->record->append(msg);
                    }
                    break;
                    case 2:
                    {
                        ui->record->append(QStringLiteral("获取当前内部机器人设置:智昌-川崎机器人"));
                        QString msg=QStringLiteral("获取当前内部机器人端口号:")+QString::number(port);
                        ui->record->append(msg);
                    }
                    break;
                    case 3:
                    {
                        ui->record->append(QStringLiteral("获取当前内部机器人设置:摩卡-纳伯特机器人"));
                        QString msg=QStringLiteral("获取当前内部机器人端口号:")+QString::number(port);
                        ui->record->append(msg);
                    }
                    break;
                    case 4:
                    {
                        ui->record->append(QStringLiteral("获取当前内部机器人设置:岗上机器人"));
                        QString msg=QStringLiteral("获取当前内部机器人端口号:")+QString::number(port);
                        ui->record->append(msg);
                    }
                    break;
                    case 5:
                    {
                        ui->record->append(QStringLiteral("获取当前内部机器人设置:埃夫特机器人"));
                        QString msg=QStringLiteral("获取当前内部机器人端口号:")+QString::number(port);
                        ui->record->append(msg);
                    }
                    break;
                    case 6:
                    {
                        ui->record->append(QStringLiteral("获取当前内部机器人设置:藦卡机器人"));
                        QString msg=QStringLiteral("获取当前内部机器人端口号:")+QString::number(port);
                        ui->record->append(msg);
                    }
                    break;
                    case 7:
                    {
                        ui->record->append(QStringLiteral("获取当前内部机器人设置:智歌机器人协议2"));
                        QString msg=QStringLiteral("获取当前内部机器人端口号:")+QString::number(port);
                        ui->record->append(msg);
                    }
                    break;
                    case 8:
                    {
                        ui->record->append(QStringLiteral("获取当前内部机器人设置:华成工控-创想"));
                        QString msg=QStringLiteral("获取当前内部机器人端口号:")+QString::number(port);
                        ui->record->append(msg);
                    }
                    break;
                    case 9:
                    {
                        ui->record->append(QStringLiteral("获取当前内部机器人设置:新时达机器人"));
                        QString msg=QStringLiteral("获取当前内部机器人端口号:")+QString::number(port);
                        ui->record->append(msg);
                    }
                    break;
                    case 10:
                    {
                        ui->record->append(QStringLiteral("获取当前内部机器人设置:智昌-川崎机器人AS"));
                        QString msg=QStringLiteral("获取当前内部机器人端口号:")+QString::number(port);
                        ui->record->append(msg);
                    }
                    break;
                    case 11:
                    {
                        ui->record->append(QStringLiteral("获取当前内部机器人设置:钱江机器人"));
                        QString msg=QStringLiteral("获取当前内部机器人端口号:")+QString::number(port);
                        ui->record->append(msg);
                    }
                    break;
                }
            }
        }

        real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_robotset,ALSROBOTCAM_ROBOTIPADDRESS_1_REG_ADD,4,m_mcs->resultdata.red_robotset);
        if(real_readnum<0)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("获取当前机器人IP地址失败"));
        }
        else
        {
            u_int16_t ip1=m_mcs->resultdata.red_robotset[0];
            u_int16_t ip2=m_mcs->resultdata.red_robotset[1];
            u_int16_t ip3=m_mcs->resultdata.red_robotset[2];
            u_int16_t ip4=m_mcs->resultdata.red_robotset[3];
            QString robot_ip=QString::number(ip1)+"."+QString::number(ip2)+"."+QString::number(ip3)+"."+QString::number(ip4);
            ui->robot_ip->setText(robot_ip);
            if(ui->checkBox->isChecked()==false)
            {
                QString msg=QStringLiteral("当前机器人IP地址:")+robot_ip;
                ui->record->append(msg);
            }
        }

        real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_robotset,ALSROBOTCAM_COMPENSATION_X,3,m_mcs->resultdata.red_robotset);
        if(real_readnum<0)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("获取当前标定补偿信息失败"));
        }
        else
        {
            int16_t dX=(int16_t)m_mcs->resultdata.red_robotset[0];
            int16_t dY=(int16_t)m_mcs->resultdata.red_robotset[1];
            int16_t dZ=(int16_t)m_mcs->resultdata.red_robotset[2];
            float f_dX=(float)dX/100.0;
            float f_dY=(float)dY/100.0;
            float f_dZ=(float)dZ/100.0;
            ui->dX->setText(QString::number(f_dX,'f',2));
            ui->dY->setText(QString::number(f_dY,'f',2));
            ui->dZ->setText(QString::number(f_dZ,'f',2));
            if(ui->checkBox->isChecked()==false)
            {
                QString msg=QStringLiteral("获取当前标定补偿: X=")+QString::number(f_dX,'f',2)+" Y="+QString::number(f_dY,'f',2)+" Z="+QString::number(f_dZ,'f',2);
                ui->record->append(msg);
            }
        }

        real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_robotset,ALSROBOTCAM_REVERSE_Y_REG_ADD,2,m_mcs->resultdata.red_robotset);
        if(real_readnum<0)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("获取当前数据反向信息失败"));
        }
        else
        {
            QString msgY,msgZ;
            u_int16_t dY=m_mcs->resultdata.red_robotset[0];
            u_int16_t dZ=m_mcs->resultdata.red_robotset[1];
            if(dY==0)
            {
                ui->checkBox_Y->setChecked(false);
                msgY=QStringLiteral("与标定同向");
            }
            else
            {
                ui->checkBox_Y->setChecked(true);
                msgY=QStringLiteral("与标定反向");
            }
            if(dZ==0)
            {
                ui->checkBox_Z->setChecked(false);
                msgZ=QStringLiteral("与标定同向");
            }
            else
            {
                ui->checkBox_Z->setChecked(true);
                msgZ=QStringLiteral("与标定反向");
            }
            if(ui->checkBox->isChecked()==false)
            {
                QString msg=QStringLiteral("获取当前数据反向信息: Y")+msgY+" Z"+msgZ;
                ui->record->append(msg);
            }
        }

        real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_robotset,ALSROBOTCAM_CAMWIDTH_REG_ADD,5,m_mcs->resultdata.red_robotset);
        if(real_readnum<0)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("获取当前相机分辨率信息失败"));
        }
        else
        {
            u_int16_t width=m_mcs->resultdata.red_robotset[0];
            u_int16_t height=m_mcs->resultdata.red_robotset[1];
            u_int16_t fps=m_mcs->resultdata.red_robotset[2];
            u_int16_t view_widht=m_mcs->resultdata.red_robotset[3];
            u_int16_t view_height=m_mcs->resultdata.red_robotset[4];
            ui->cam_width->setText(QString::number(width));
            ui->cam_height->setText(QString::number(height));
            ui->cam_fps->setText(QString::number(fps));
            ui->cam_view_width->setText(QString::number(view_widht));
            ui->cam_view_height->setText(QString::number(view_height));

            drow_height=width;
            drow_width=height;

            if(ui->checkBox->isChecked()==false)
            {
                ui->record->append(QStringLiteral("获取当前相机设置:"));
                QString msg=QString::number(width)+"x"+QString::number(height)+" fps:"+QString::number(fps);
                ui->record->append(msg);
            }
        }

        real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_robotset,ALSROBOTCAM_P_DATA_EN_REG_ADD,3,m_mcs->resultdata.red_robotset);
        if(real_readnum<0)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("获取当前相机P变量信息失败"));
        }
        else
        {
            bool pEn=m_mcs->resultdata.red_robotset[0];
            u_int16_t u16_CAL_POSTURE=m_mcs->resultdata.red_robotset[1];
            u_int16_t u16_Eye_Hand_calibrationmode=m_mcs->resultdata.red_robotset[2];
            m_mcs->resultdata.P_data_cal_posture=(CAL_POSTURE)u16_CAL_POSTURE;
            m_mcs->resultdata.P_data_eye_hand_calibrationmode=(Eye_Hand_calibrationmode)u16_Eye_Hand_calibrationmode;
            ui->checkBox_pEn->setChecked(pEn);
            ui->comboBox_2->setCurrentIndex(u16_CAL_POSTURE);
            ui->comboBox_3->setCurrentIndex(u16_Eye_Hand_calibrationmode);
            if(ui->checkBox->isChecked()==false)
            {
                QString msg;
                ui->record->append(QStringLiteral("获取当前P变量设置:"));
                if(pEn==0)
                {
                    msg=QStringLiteral("P变量功能:关");
                    ui->record->append(msg);
                }
                else
                {
                    msg=QStringLiteral("P变量功能:开");
                    ui->record->append(msg);
                }
                msg=QStringLiteral("P变量姿态:")+ui->comboBox_2->currentText();
                ui->record->append(msg);
                msg=QStringLiteral("P变量标定:")+ui->comboBox_3->currentText();
                ui->record->append(msg);
            }
        }

        real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_result,ALS_REALTIME_CRAFTID_REG_ADD,11,m_mcs->resultdata.red_robotresult);
        if(real_readnum<0)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("获取当前工艺参数信息失败"));
        }
        else
        {
            m_mcs->resultdata.P_data_craftinfo.craft_Id=(int16_t)m_mcs->resultdata.red_robotresult[0];
            m_mcs->resultdata.P_data_craftinfo.craft_als1=(int16_t)m_mcs->resultdata.red_robotresult[1];
            m_mcs->resultdata.P_data_craftinfo.craft_als2=(int16_t)m_mcs->resultdata.red_robotresult[2];
            m_mcs->resultdata.P_data_craftinfo.craft_als3=(int16_t)m_mcs->resultdata.red_robotresult[3];
            m_mcs->resultdata.P_data_craftinfo.craft_als4=(int16_t)m_mcs->resultdata.red_robotresult[4];
            m_mcs->resultdata.P_data_craftinfo.craft_als5=(int16_t)m_mcs->resultdata.red_robotresult[5];
            m_mcs->resultdata.P_data_craftinfo.craft_als6=(int16_t)m_mcs->resultdata.red_robotresult[6];
            m_mcs->resultdata.P_data_craftinfo.craft_als7=(int16_t)m_mcs->resultdata.red_robotresult[7];
            m_mcs->resultdata.P_data_craftinfo.craft_als8=(int16_t)m_mcs->resultdata.red_robotresult[8];
            m_mcs->resultdata.P_data_craftinfo.craft_als9=(int16_t)m_mcs->resultdata.red_robotresult[9];
            m_mcs->resultdata.P_data_craftinfo.craft_als10=(int16_t)m_mcs->resultdata.red_robotresult[10];
            if(ui->checkBox->isChecked()==false)
            {
                QString msg=QStringLiteral("获取当前工艺号:")+QString::number(m_mcs->resultdata.P_data_craftinfo.craft_Id);
                ui->record->append(msg);
            }
        }

        u_int16_t task;
        real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_result,ALS_TASKNUM_REG_ADD,1,&task);
        if(real_readnum<0)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("获取当前任务号信息失败"));
        }
        else
        {
            ui->tasknum->setText(QString::number(task));
            if(ui->checkBox->isChecked()==false)
            {
                QString msg=QStringLiteral("获取当前内部任务号:")+QString::number(task);
                ui->record->append(msg);
            }
        }

        if(task>=TASKNUM_START)
        {
            u_int16_t num=task-TASKNUM_START+1;
            if(num<ui->tabWidget->count())
            {
                ui->tabWidget->setCurrentIndex(num);
                showupdata_tabWidget(num);
            }
        }
        else if(task<TASKNUM_START)
        {
            ui->tabWidget->setCurrentIndex(0);
        }
        showupdata_tabWidget(ui->tabWidget->currentIndex());

        u_int16_t tab_reg[1];
        tab_reg[0]=1;
        modbus_write_registers(m_mcs->resultdata.ctx_param,ALS_SHOW_STEP_REG_ADD,1,tab_reg);

        b_thread1=true;
        thread1->start();

     #if _MSC_VER||WINDOWS_TCP
     #ifdef DEBUG_CLOUD_TCP
        m_mcs->cam->sop_cam[0].InitConnect_cloud(ui->IPadd->text(),PORT_ALSTCP_POINTCLOUDS_RESULT);
     #else
        m_mcs->cam->sop_cam[0].InitConnect(lab_show,ui->IPadd->text(),PORT_ALSTCP_CAMIMAGE_RESULT);
     #endif
     #else
        m_mcs->cam->sop_cam[0].InitConnect(lab_show);
     #endif
        if(m_mcs->cam->sop_cam[0].b_connect==true)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("相机连接成功"));
        }
        else if(m_mcs->cam->sop_cam[0].b_connect==false)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("相机连接失败"));
        }
    }
    else
    {
        drowstep=0;
        drowstep_temp=0;

        thread1->Stop();
        thread1->quit();
        thread1->wait();

        if(m_mcs->resultdata.link_param_state==true)
        {
            u_int16_t tab_reg[1];
            tab_reg[0]=0;
            modbus_write_registers(m_mcs->resultdata.ctx_param,ALS_SHOW_STEP_REG_ADD,1,tab_reg);
        }
        if(m_mcs->resultdata.b_luzhi==true)
        {
            m_mcs->resultdata.b_luzhi=false;
            m_mcs->cam->sop_cam[0].StopRecord();
            ui->saveavishowBtn->setText(QStringLiteral("录制视频"));
            if(ui->checkBox->isChecked()==false)
                 ui->record->append(QStringLiteral("视频录制完成"));
        }
        m_mcs->cam->sop_cam[0].DisConnect();
        if(ui->checkBox->isChecked()==false)
            ui->record->append(QStringLiteral("相机关闭"));


        if(m_mcs->resultdata.link_ftp_state==true)
        {
            m_mcs->resultdata.client->disconnectFromHost();
            m_mcs->resultdata.link_ftp_state=false;
            QString msg=QString::number(PORT_ALSTCP_FTP);
            if(ui->checkBox->isChecked()==false)
                ui->record->append(msg+QStringLiteral("端口关闭"));
        }
        if(m_mcs->resultdata.link_result_state==true)
        {
            close_camer_modbus();
            modbus_close(m_mcs->resultdata.ctx_result);
            modbus_free(m_mcs->resultdata.ctx_result);
            m_mcs->resultdata.link_result_state=false;
            QString msg=QString::number(PORT_ALS_RESULT);
            if(ui->checkBox->isChecked()==false)
                ui->record->append(msg+QStringLiteral("端口关闭"));
        }
        if(m_mcs->resultdata.link_param_state==true)
        {
            modbus_close(m_mcs->resultdata.ctx_param);
            modbus_free(m_mcs->resultdata.ctx_param);
            m_mcs->resultdata.link_param_state=false;
            QString msg=QString::number(PORT_ALS_PARAMETER);
            if(ui->checkBox->isChecked()==false)
                ui->record->append(msg+QStringLiteral("端口关闭"));
        }
        if(m_mcs->resultdata.link_robotset_state==true)
        {
            modbus_close(m_mcs->resultdata.ctx_robotset);
            modbus_free(m_mcs->resultdata.ctx_robotset);
            m_mcs->resultdata.link_robotset_state=false;
            QString msg=QString::number(PORT_ALSROBOTCAM_SET);
            if(ui->checkBox->isChecked()==false)
                ui->record->append(msg+QStringLiteral("端口关闭"));
        }
    }
    UpdataUi();
}

void qtmysunnyDlg::UpdataUi()
{
    if(m_mcs->cam->sop_cam[0].b_connect==false)
    {
        ui->connectcameraBtn->setText(QStringLiteral("连接相机"));
    }
    else
    {
        ui->connectcameraBtn->setText(QStringLiteral("断开相机"));
    }
}

void qtmysunnyDlg::UpdataRobot(u_int16_t robotmod)
{
    switch(robotmod)
    {
        case 0:     //机器人做客户端
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        {
            b_robot_serves=false;
            ui->label_4->setText(QStringLiteral("机器人端口:"));
            ui->label_43->show();
            ui->robot_ip->hide();
            ui->robotport->show();
        }
        break;
        case 10:    //机器人做服务器
        {
            b_robot_serves=true;
            ui->label_4->setText(QStringLiteral("机器人IP:"));
            ui->label_43->hide();
            ui->robot_ip->show();
            ui->robotport->hide();
        }
        break;
        case 11:
        break;
    }
}

bool qtmysunnyDlg::ipAddrIsOK(const QString & ip,std::vector<u_int8_t> &address)
{
    if (ip.isEmpty())
    {
        return false;
    }

    QStringList list = ip.split('.');
    if (list.size() != 4)
    {
        return false;
    }
    address.clear();
    for (const auto& num : list)
    {
        bool ok = false;
        int temp = num.toInt(&ok);
        if (!ok || temp < 0 || temp > 255)
        {
            return false;
        }
        address.push_back(temp);
    }

    return true;
}

void qtmysunnyDlg::open_camer_modbus()
{
    if(m_mcs->resultdata.link_result_state==true)
    {
        uint16_t tab_reg[1];
        tab_reg[0]=0xff;
        int rc=modbus_write_registers(m_mcs->resultdata.ctx_result,ALS_OPEN_REG_ADD,1,tab_reg);
        if(rc!=1)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("激光器相机启动设置失败"));
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("激光器相机启动设置成功"));
        }
    }
}

void qtmysunnyDlg::close_camer_modbus()
{
    if(m_mcs->resultdata.link_result_state==true)
    {
        uint16_t tab_reg[1];
        tab_reg[0]=0;
        int rc=modbus_write_registers(m_mcs->resultdata.ctx_result,ALS_OPEN_REG_ADD,1,tab_reg);
        if(rc!=1)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("激光器相机关闭设置失败"));
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append(QStringLiteral("激光器相机关闭设置成功"));
        }
    }
}

void qtmysunnyDlg::init_show_pos_list()
{
    float Y=(int16_t)pos_data[1]/100.0;
    float Z=(int16_t)pos_data[2]/100.0;
    float RY=(int16_t)pos_data[3]/1000.0;
    float RZ=(int16_t)pos_data[4]/1000.0;


    u_int16_t hour=(int16_t)pos_data[5];
    u_int16_t min=(int16_t)pos_data[6];
    u_int16_t sec=(int16_t)pos_data[7];
    u_int16_t msec=(int16_t)pos_data[8];

    u_int16_t hour2=(int16_t)pos_data[11];
    u_int16_t min2=(int16_t)pos_data[12];
    u_int16_t sec2=(int16_t)pos_data[13];
    u_int16_t msec2=(int16_t)pos_data[14];
    float fps=(float)pos_data[9]/100.0;
    float camfps=(float)pos_data[10]/100.0;

    float Y2=(int16_t)pos_data2[0]/100.0;
    float Z2=(int16_t)pos_data2[1]/100.0;
    float Y3=(int16_t)pos_data2[2]/100.0;
    float Z3=(int16_t)pos_data2[3]/100.0;

    ui->label_9->setText("0x"+QString::number(pos_data[0],16));
    ui->label_10->setText(QString::number(Y,'f',2));
    ui->label_11->setText(QString::number(Z,'f',2));
    ui->label_17->setText(QString::number(Y2,'f',2));
    ui->label_19->setText(QString::number(Z2,'f',2));
    ui->label_21->setText(QString::number(Y3,'f',2));
    ui->label_23->setText(QString::number(Z3,'f',2));

    QString msg=QString::number(hour)+":"+QString::number(min)+":"+QString::number(sec)+":"+QString::number(msec);
    ui->label_34->setText(msg);
    QString msg2=QString::number(hour2)+":"+QString::number(min2)+":"+QString::number(sec2)+":"+QString::number(msec2);
    ui->label_42->setText(msg2);

    ui->label_36->setText(QString::number(fps,'f',2));
    ui->label_38->setText(QString::number(camfps,'f',2));

    if(pos_data3[0]==0xff)
        ui->label_25->setText(QStringLiteral("是"));
    else if(pos_data3[0]==0)
        ui->label_25->setText(QStringLiteral("否"));


    ui->label_55->setText(QString::number(RY,'f',3));
    ui->label_56->setText(QString::number(RZ,'f',3));

#ifdef DEBUG_TIMEFPS
    QString time;
    u_int16_t Year,mounth,days,H,M,S,ms;
    TimeFunction to;
    to.get_time_ms(Year,mounth,days,H,M,S,ms);
    time=QString::number(H)+":"+QString::number(M)+":"+QString::number(S)+":"+QString::number(ms);
    ui->label_49->setText(time);

    long int l_ms1=ms+S*1000+M*60*1000+H*3600*1000;
    long int l_ms2=(long int)msec2+(long int)sec2*1000+(long int)min2*60*1000+(long int)hour2*3600*1000;
    long int disms=l_ms1-l_ms2;
    long int l_ms=disms;
    QString dtime;
    long int abs_ms=abs(l_ms);
    uint16_t dH=abs_ms/(3600*1000);
    uint16_t dM=(abs_ms-dH*(3600*1000))/(60*1000);
    uint16_t dS=(abs_ms-dH*(3600*1000)-dM*60*1000)/1000;
    uint16_t dmS=abs_ms-dH*(3600*1000)-dM*60*1000-dS*1000;
    QString stime=QString::number(dH)+":"+QString::number(dM)+":"+QString::number(dS)+":"+QString::number(dmS).asprintf("%03d",dmS);
    if(l_ms<0)
    {
        stime="-"+stime;
    }
    ui->label_51->setText(stime);
#endif

    b_init_show_pos_list_finish=true;
}

void qtmysunnyDlg::init_show_pos_failed()
{
    if(ui->checkBox->isChecked()==false)
        ui->record->append(QStringLiteral("获取当前检测信息失败"));
    b_init_show_pos_failed_finish=true;
}

void qtmysunnyDlg::drow_image(int32_t oldheight,int32_t oldwidth,QImage *img)
{
    static int32_t i32_zoom_left,i32_zoom_right,i32_zoom_top,i32_zoom_deep,i32_zoom_center_x,i32_zoom_center_y;
    int32_t nHeight=img->height();
    int32_t nWidth=img->width();
    if(drowstep==0)
    {
        switch(tabWidget_task)
        {
            case TABWIDGET_TASK100:
            {
                uint16_t tab_reg[ALS100_REG_TOTALNUM];
                tab_reg[0]=ui->alg100_threshold->text().toInt();
                for(int i=1;i<ALS100_REG_TOTALNUM;i++)
                {
                    tab_reg[i]=(uint16_t)(ui->tab2tableWidget->item(i-1,2)->text().toInt());
                }
                if(tab_reg[ALS100_B_CUT_REG_ADD-ALS100_EXPOSURE_TIME_REG_ADD]==1)
                {
                    zoom_left=tab_reg[ALS100_CUTLEFT_REG_ADD-ALS100_EXPOSURE_TIME_REG_ADD]*nWidth/oldwidth;
                    zoom_right=tab_reg[ALS100_CUTRIGHT_REG_ADD-ALS100_EXPOSURE_TIME_REG_ADD]*nWidth/oldwidth;
                    zoom_top=tab_reg[ALS100_CUTTOP_REG_ADD-ALS100_EXPOSURE_TIME_REG_ADD]*nHeight/oldheight;
                    zoom_deep=tab_reg[ALS100_CUTDEEP_REG_ADD-ALS100_EXPOSURE_TIME_REG_ADD]*nHeight/oldheight;
                    QPainter painter(img);
                    QPen pen; //画笔。绘制图形边线，由颜色、宽度、线风格等参数组成
                    pen.setColor(QColor(255,0,0,255));
                    painter.setPen(pen);
                    painter.drawRect(zoom_left, zoom_top, zoom_right-zoom_left+1, zoom_deep-zoom_top+1);
                }
            }
            break;
            case TABWIDGET_TASK101:
            {
                uint16_t tab_reg[ALS101_REG_TOTALNUM];
                tab_reg[0]=ui->alg101_threshold->text().toInt();
                for(int i=1;i<ALS101_REG_TOTALNUM;i++)
                {
                    tab_reg[i]=(uint16_t)(ui->tab3tableWidget->item(i-1,2)->text().toInt());
                }
                if(tab_reg[ALS101_B_CUT_REG_ADD-ALS101_EXPOSURE_TIME_REG_ADD]==1)
                {
                    zoom_left=tab_reg[ALS101_CUTLEFT_REG_ADD-ALS101_EXPOSURE_TIME_REG_ADD]*nWidth/oldwidth;
                    zoom_right=tab_reg[ALS101_CUTRIGHT_REG_ADD-ALS101_EXPOSURE_TIME_REG_ADD]*nWidth/oldwidth;
                    zoom_top=tab_reg[ALS101_CUTTOP_REG_ADD-ALS101_EXPOSURE_TIME_REG_ADD]*nHeight/oldheight;
                    zoom_deep=tab_reg[ALS101_CUTDEEP_REG_ADD-ALS101_EXPOSURE_TIME_REG_ADD]*nHeight/oldheight;
                    QPainter painter(img);
                    QPen pen; //画笔。绘制图形边线，由颜色、宽度、线风格等参数组成
                    pen.setColor(QColor(255,0,0,255));
                    painter.setPen(pen);
                    painter.drawRect(zoom_left, zoom_top, zoom_right-zoom_left+1, zoom_deep-zoom_top+1);
                }
            }
            break;
            case TABWIDGET_TASK105:
            {
                uint16_t tab_reg[ALS105_REG_TOTALNUM];
                tab_reg[0]=ui->alg105_threshold->text().toInt();
                for(int i=1;i<ALS105_REG_TOTALNUM;i++)
                {
                    tab_reg[i]=(uint16_t)(ui->tab7tableWidget->item(i-1,2)->text().toInt());
                }
                if(tab_reg[ALS105_B_CUT_REG_ADD-ALS105_EXPOSURE_TIME_REG_ADD]==1)
                {
                    zoom_left=tab_reg[ALS105_CUTLEFT_REG_ADD-ALS105_EXPOSURE_TIME_REG_ADD]*nWidth/oldwidth;
                    zoom_right=tab_reg[ALS105_CUTRIGHT_REG_ADD-ALS105_EXPOSURE_TIME_REG_ADD]*nWidth/oldwidth;
                    zoom_top=tab_reg[ALS105_CUTTOP_REG_ADD-ALS105_EXPOSURE_TIME_REG_ADD]*nHeight/oldheight;
                    zoom_deep=tab_reg[ALS105_CUTDEEP_REG_ADD-ALS105_EXPOSURE_TIME_REG_ADD]*nHeight/oldheight;
                    QPainter painter(img);
                    QPen pen; //画笔。绘制图形边线，由颜色、宽度、线风格等参数组成
                    pen.setColor(QColor(255,0,0,255));
                    painter.setPen(pen);
                    painter.drawRect(zoom_left, zoom_top, zoom_right-zoom_left+1, zoom_deep-zoom_top+1);
                }
            }
            break;
            case TABWIDGET_TASK106:
            {
                uint16_t tab_reg[ALS106_REG_TOTALNUM];
                tab_reg[0]=ui->alg106_threshold->text().toInt();
                for(int i=1;i<ALS106_REG_TOTALNUM;i++)
                {
                    tab_reg[i]=(uint16_t)(ui->tab8tableWidget->item(i-1,2)->text().toInt());
                }
                if(tab_reg[ALS106_B_CUT_REG_ADD-ALS106_EXPOSURE_TIME_REG_ADD]==1)
                {
                    zoom_left=tab_reg[ALS106_CUTLEFT_REG_ADD-ALS106_EXPOSURE_TIME_REG_ADD]*nWidth/oldwidth;
                    zoom_right=tab_reg[ALS106_CUTRIGHT_REG_ADD-ALS106_EXPOSURE_TIME_REG_ADD]*nWidth/oldwidth;
                    zoom_top=tab_reg[ALS106_CUTTOP_REG_ADD-ALS106_EXPOSURE_TIME_REG_ADD]*nHeight/oldheight;
                    zoom_deep=tab_reg[ALS106_CUTDEEP_REG_ADD-ALS106_EXPOSURE_TIME_REG_ADD]*nHeight/oldheight;
                    QPainter painter(img);
                    QPen pen; //画笔。绘制图形边线，由颜色、宽度、线风格等参数组成
                    pen.setColor(QColor(255,0,0,255));
                    painter.setPen(pen);
                    painter.drawRect(zoom_left, zoom_top, zoom_right-zoom_left+1, zoom_deep-zoom_top+1);
                }
            }
            break;
            case TABWIDGET_TASK108:
            {
                uint16_t tab_reg[ALS108_REG_TOTALNUM];
                tab_reg[0]=ui->alg108_threshold->text().toInt();
                for(int i=1;i<ALS108_REG_TOTALNUM;i++)
                {
                    tab_reg[i]=(uint16_t)(ui->tab10tableWidget->item(i-1,2)->text().toInt());
                }
                zoom_center_x=tab_reg[ALS108_CENTER_X_REG_ADD-ALS108_EXPOSURE_TIME_REG_ADD]*nWidth/oldwidth;
                zoom_center_y=tab_reg[ALS108_CENTER_Y_REG_ADD-ALS108_EXPOSURE_TIME_REG_ADD]*nHeight/oldheight;
                zoom_left=zoom_center_x-tab_reg[ALS108_SEARCT_W_REG_ADD-ALS108_EXPOSURE_TIME_REG_ADD]*nWidth/oldwidth;
                zoom_right=zoom_center_x+tab_reg[ALS108_SEARCT_W_REG_ADD-ALS108_EXPOSURE_TIME_REG_ADD]*nWidth/oldwidth;
                zoom_top=zoom_center_y-tab_reg[ALS108_SEARCT_H_REG_ADD-ALS108_EXPOSURE_TIME_REG_ADD]*nHeight/oldheight;
                zoom_deep=zoom_center_y+tab_reg[ALS108_SEARCT_H_REG_ADD-ALS108_EXPOSURE_TIME_REG_ADD]*nHeight/oldheight;
                QPainter painter(img);
                QPen pen; //画笔。绘制图形边线，由颜色、宽度、线风格等参数组成
                pen.setColor(QColor(255,0,0,255));
                painter.setPen(pen);
                painter.drawRect(zoom_left, zoom_top, zoom_right-zoom_left+1, zoom_deep-zoom_top+1);
                pen.setColor(QColor(0,255,0,255));
                painter.setPen(pen);
                painter.drawEllipse(zoom_center_x-16*nWidth/oldwidth,zoom_center_y-16*nHeight/oldheight,32*nWidth/oldwidth,32*nHeight/oldheight);
            }
            break;
            default:
            break;
        }
    }
    //鼠标按下
    if(ui->widget->b_mouse_push==true)
    {
        drowstep=1;
        if(drowstep_temp==0)
        {
            drowstep_temp=1;
            switch(tabWidget_task)
            {
                case TABWIDGET_TASK100:
                case TABWIDGET_TASK101:
                case TABWIDGET_TASK105:
                case TABWIDGET_TASK106:
                {
                    i32_zoom_left=ui->widget->mousePos.rx();
                    i32_zoom_right=ui->widget->mousePos.rx();
                    i32_zoom_top=ui->widget->mousePos.ry();
                    i32_zoom_deep=ui->widget->mousePos.ry();
                }
                break;
                case TABWIDGET_TASK108:
                {
                    i32_zoom_center_x=ui->widget->mousePos.rx();
                    i32_zoom_center_y=ui->widget->mousePos.ry();
                }
                break;
            }
        }
        else if(drowstep_temp==1)
        {
            switch(tabWidget_task)
            {
                case TABWIDGET_TASK100:
                case TABWIDGET_TASK101:
                case TABWIDGET_TASK105:
                case TABWIDGET_TASK106:
                {
                    i32_zoom_right=ui->widget->mousePos.rx();
                    i32_zoom_deep=ui->widget->mousePos.ry();
                }
                break;
                case TABWIDGET_TASK108:
                {
                    i32_zoom_center_x=ui->widget->mousePos.rx();
                    i32_zoom_center_y=ui->widget->mousePos.ry();
                }
                break;
            }
        }
        switch(tabWidget_task)
        {
            case TABWIDGET_TASK100:
            case TABWIDGET_TASK101:
            case TABWIDGET_TASK105:
            case TABWIDGET_TASK106:
            {
                QPainter painter(img);
                QPen pen; //画笔。绘制图形边线，由颜色、宽度、线风格等参数组成
                pen.setColor(QColor(255,0,0,255));
                painter.setPen(pen);
                painter.drawRect(i32_zoom_left, i32_zoom_top, i32_zoom_right-i32_zoom_left+1, i32_zoom_deep-i32_zoom_top+1);
            }
            break;
            case TABWIDGET_TASK108:
            {
                uint16_t tab_reg[ALS108_REG_TOTALNUM];
                tab_reg[0]=ui->alg108_threshold->text().toInt();
                for(int i=1;i<ALS108_REG_TOTALNUM;i++)
                {
                    tab_reg[i]=(uint16_t)(ui->tab10tableWidget->item(i-1,2)->text().toInt());
                }
                i32_zoom_left=i32_zoom_center_x-tab_reg[ALS108_SEARCT_W_REG_ADD-ALS108_EXPOSURE_TIME_REG_ADD]*nWidth/oldwidth;
                i32_zoom_right=i32_zoom_center_x+tab_reg[ALS108_SEARCT_W_REG_ADD-ALS108_EXPOSURE_TIME_REG_ADD]*nWidth/oldwidth;
                i32_zoom_top=i32_zoom_center_y-tab_reg[ALS108_SEARCT_H_REG_ADD-ALS108_EXPOSURE_TIME_REG_ADD]*nHeight/oldheight;
                i32_zoom_deep=i32_zoom_center_y+tab_reg[ALS108_SEARCT_H_REG_ADD-ALS108_EXPOSURE_TIME_REG_ADD]*nHeight/oldheight;
                QPainter painter(img);
                QPen pen; //画笔。绘制图形边线，由颜色、宽度、线风格等参数组成
                pen.setColor(QColor(255,0,0,255));
                painter.setPen(pen);
                painter.drawRect(i32_zoom_left, i32_zoom_top, i32_zoom_right-i32_zoom_left+1, i32_zoom_deep-i32_zoom_top+1);
                pen.setColor(QColor(0,255,0,255));
                painter.setPen(pen);
                painter.drawEllipse(i32_zoom_center_x-16*nWidth/oldwidth,i32_zoom_center_y-16*nHeight/oldheight,32*nWidth/oldwidth,32*nHeight/oldheight);
            }
            break;
        }
    }
    else
    {
        drowstep_temp=0;
        if(drowstep==1)
        {
            drowstep=2;
            switch(tabWidget_task)
            {
                case TABWIDGET_TASK100:
                case TABWIDGET_TASK101:
                case TABWIDGET_TASK105:
                case TABWIDGET_TASK106:
                {
                    zoom_left=MIN(i32_zoom_left,i32_zoom_right);
                    zoom_right=MAX(i32_zoom_left,i32_zoom_right);
                    zoom_top=MIN(i32_zoom_top,i32_zoom_deep);
                    zoom_deep=MAX(i32_zoom_top,i32_zoom_deep);
                    u16_zoom_left=(uint16_t)(zoom_left*oldwidth/nWidth);
                    u16_zoom_right=(uint16_t)(zoom_right*oldwidth/nWidth);
                    u16_zoom_top=(uint16_t)(zoom_top*oldheight/nHeight);
                    u16_zoom_deep=(uint16_t)(zoom_deep*oldheight/nHeight);
                }
                break;
                case TABWIDGET_TASK108:
                {
                    zoom_center_x=i32_zoom_center_x;
                    zoom_center_y=i32_zoom_center_y;
                    u16_zoom_center_x=(uint16_t)(zoom_center_x*oldwidth/nWidth);
                    u16_zoom_center_y=(uint16_t)(zoom_center_y*oldheight/nHeight);
                }
                break;
            }
        }
        if(drowstep==2)
        {
            switch(tabWidget_task)
            {
                case TABWIDGET_TASK100:
                case TABWIDGET_TASK101:
                case TABWIDGET_TASK105:
                case TABWIDGET_TASK106:
                {
                    QPainter painter(img);
                    QPen pen; //画笔。绘制图形边线，由颜色、宽度、线风格等参数组成
                    pen.setColor(QColor(255,0,0,255));
                    painter.setPen(pen);
                    painter.drawRect(zoom_left, zoom_top, zoom_right-zoom_left+1, zoom_deep-zoom_top+1);
                }
                break;
                case TABWIDGET_TASK108:
                {
                    uint16_t tab_reg[ALS108_REG_TOTALNUM];
                    tab_reg[0]=ui->alg108_threshold->text().toInt();
                    for(int i=1;i<ALS108_REG_TOTALNUM;i++)
                    {
                        tab_reg[i]=(uint16_t)(ui->tab10tableWidget->item(i-1,2)->text().toInt());
                    }
                    zoom_left=zoom_center_x-tab_reg[ALS108_SEARCT_W_REG_ADD-ALS108_EXPOSURE_TIME_REG_ADD]*nWidth/oldwidth;
                    zoom_right=zoom_center_x+tab_reg[ALS108_SEARCT_W_REG_ADD-ALS108_EXPOSURE_TIME_REG_ADD]*nWidth/oldwidth;
                    zoom_top=zoom_center_y-tab_reg[ALS108_SEARCT_H_REG_ADD-ALS108_EXPOSURE_TIME_REG_ADD]*nHeight/oldheight;
                    zoom_deep=zoom_center_y+tab_reg[ALS108_SEARCT_H_REG_ADD-ALS108_EXPOSURE_TIME_REG_ADD]*nHeight/oldheight;
                    QPainter painter(img);
                    QPen pen; //画笔。绘制图形边线，由颜色、宽度、线风格等参数组成
                    pen.setColor(QColor(255,0,0,255));
                    painter.setPen(pen);
                    painter.drawRect(zoom_left, zoom_top, zoom_right-zoom_left+1, zoom_deep-zoom_top+1);
                    pen.setColor(QColor(0,255,0,255));
                    painter.setPen(pen);
                    painter.drawEllipse(zoom_center_x-16*nWidth/oldwidth,zoom_center_y-16*nHeight/oldheight,32*nWidth/oldwidth,32*nHeight/oldheight);
                }
                break;
            }
        }
    }
}

void qtmysunnyDlg::init_show_cvimage_inlab(cv::Mat cv_image)
{
    if(!cv_image.empty())
    {
        QImage::Format format = QImage::Format_RGB888;
        cv::Mat cvimg=cv_image;
        switch (cvimg.type())
        {
        case CV_8UC1:
          format = QImage::Format_RGB888;
          cv::cvtColor(cvimg,cvimg,cv::COLOR_GRAY2BGR);
          break;
        case CV_8UC3:
          format = QImage::Format_RGB888;
          break;
        case CV_8UC4:
          format = QImage::Format_ARGB32;
          break;
        }
        QImage img = QImage((const uchar*)cvimg.data,
                                          cvimg.cols,
                                          cvimg.rows,
                                          cvimg.cols * cvimg.channels(), format);
        img = img.scaled(ui->widget->width(),ui->widget->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        drow_image(drow_height,drow_width,&img);
        ui->widget->setImage(img);
    }
    b_init_show_cvimage_inlab_finish=true;
    m_mcs->cam->sop_cam[0].b_int_show_image_inlab=false;
    m_mcs->cam->sop_cam[0].b_updataimage_finish=false;
}

#if _MSC_VER||WINDOWS_TCP
#ifdef DEBUG_CLOUD_TCP
//点云解码历程
void qtmysunnyDlg::init_show_cloud_list(IFAlgorhmitcloud IfAlgorhmitcloud)
{
//  mutex_IfAlgorhmitcloud.lock();
    QString msg;
    msg="header.stamp.sec:"+QString::number(IfAlgorhmitcloud.header.stamp.sec)+"\n";
    printf(msg.toStdString().c_str());
    msg="header.stamp.nanosec:"+QString::number(IfAlgorhmitcloud.header.stamp.nanosec)+"\n";
    printf(msg.toStdString().c_str());
    msg="header.frame_id:"+IfAlgorhmitcloud.header.frame_id+"\n";
    printf(msg.toStdString().c_str());
    for(int i=0;i<IfAlgorhmitcloud.targetpointoutcloud.size();i++)
    {
        msg="targetpointoutcloud name:"+IfAlgorhmitcloud.targetpointoutcloud[i].name+"\n";
        printf(msg.toStdString().c_str());
        msg="targetpointoutcloud x:"+QString::number(IfAlgorhmitcloud.targetpointoutcloud[i].x,'f',3)+"\n";
        printf(msg.toStdString().c_str());
        msg="targetpointoutcloud y:"+QString::number(IfAlgorhmitcloud.targetpointoutcloud[i].y,'f',3)+"\n";
        printf(msg.toStdString().c_str());
        msg="targetpointoutcloud u:"+QString::number(IfAlgorhmitcloud.targetpointoutcloud[i].u)+"\n";
        printf(msg.toStdString().c_str());
        msg="targetpointoutcloud v:"+QString::number(IfAlgorhmitcloud.targetpointoutcloud[i].v)+"\n";
        printf(msg.toStdString().c_str());
    }
    for(int i=0;i<IfAlgorhmitcloud.lasertrackoutcloud.size();i++)
    {
        msg="lasertrackoutcloud x:"+QString::number(IfAlgorhmitcloud.lasertrackoutcloud[i].x,'f',3)+"\n";
        printf(msg.toStdString().c_str());
        msg="lasertrackoutcloud y:"+QString::number(IfAlgorhmitcloud.lasertrackoutcloud[i].y,'f',3)+"\n";
        printf(msg.toStdString().c_str());
        msg="lasertrackoutcloud u:"+QString::number(IfAlgorhmitcloud.lasertrackoutcloud[i].u)+"\n";
        printf(msg.toStdString().c_str());
        msg="lasertrackoutcloud v:"+QString::number(IfAlgorhmitcloud.lasertrackoutcloud[i].v)+"\n";
        printf(msg.toStdString().c_str());
    }
    b_init_show_cloud_inlab_finish=true;
    m_mcs->cam->sop_cam[0].b_updatacloud_finish=false;
//  mutex_IfAlgorhmitcloud.unlock();
}
#endif
#endif

void qtmysunnyDlg::init_set_task()
{
    u_int16_t tasknum=ui->tasknum->text().toInt();
    uint16_t tab_reg[1];
    tab_reg[0]=tasknum;
    int rc=modbus_write_registers(m_mcs->resultdata.ctx_result,ALS_TASKNUM_REG_ADD,1,tab_reg);
    if(rc!=1)
    {
        if(ui->checkBox->isChecked()==false)
            ui->record->append(QStringLiteral("更新任务号失败"));
    }
    else
    {
        if(ui->checkBox->isChecked()==false)
            ui->record->append(QStringLiteral("更新任务号成功"));
        if(tasknum>=TASKNUM_START)
        {
            u_int16_t num=tasknum-TASKNUM_START+1;
            if(num<ui->tabWidget->count())
            {
                ui->tabWidget->setCurrentIndex(num);
                showupdata_tabWidget(num);
            }
        }
        else if(tasknum<TASKNUM_START)
        {
            ui->tabWidget->setCurrentIndex(0);
        }
    }
    ctx_result_dosomeing=DO_NOTHING;
    b_init_set_task=true;
}

void qtmysunnyDlg::on_tabWidget_currentChanged(int index)
{
    drowstep=0;
    drowstep_temp=0;
    tabWidget_task=index;
    showupdata_tabWidget(index);
}

void qtmysunnyDlg::showupdata_tabWidget(int index)
{
    if(m_mcs->resultdata.link_param_state==true)
    {
        switch(index)
        {
            case TABWIDGET_TASK100:
            {
                int real_readnum=0;
                u_int16_t rcvdata[ALS100_REG_TOTALNUM];
                real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS100_EXPOSURE_TIME_REG_ADD,ALS100_REG_TOTALNUM,rcvdata);
                if(real_readnum<0)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号100参数失败"));
                }
                else
                {
                    if(rcvdata[0]>65535)
                    {
                        m_mcs->resultdata.alg100_threshold=65535;
                    }
                    else if(rcvdata[0]<20)
                    {
                        m_mcs->resultdata.alg100_threshold=20;
                    }
                    else
                    {
                        m_mcs->resultdata.alg100_threshold=rcvdata[0];
                    }
                    ui->alg100_threshold->setText(QString::number(m_mcs->resultdata.alg100_threshold));

                    for(int i=1;i<ALS100_REG_TOTALNUM;i++)
                    {
                        ui->tab2tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                    }

                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号100参数成功"));
                }
            }
            case TABWIDGET_TASK101:
            {
                int real_readnum=0;
                u_int16_t rcvdata[ALS101_REG_TOTALNUM];
                real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS101_EXPOSURE_TIME_REG_ADD,ALS101_REG_TOTALNUM,rcvdata);
                if(real_readnum<0)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号101参数失败"));
                }
                else
                {
                    if(rcvdata[0]>65535)
                    {
                        m_mcs->resultdata.alg101_threshold=65535;
                    }
                    else if(rcvdata[0]<20)
                    {
                        m_mcs->resultdata.alg101_threshold=20;
                    }
                    else
                    {
                        m_mcs->resultdata.alg101_threshold=rcvdata[0];
                    }
                    ui->alg101_threshold->setText(QString::number(m_mcs->resultdata.alg101_threshold));

                    for(int i=1;i<ALS101_REG_TOTALNUM;i++)
                    {
                        ui->tab3tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                    }

                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号101参数成功"));
                }
            }
            case TABWIDGET_TASK102:
            {
                int real_readnum=0;
                u_int16_t rcvdata[ALS102_REG_TOTALNUM];
                real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS102_EXPOSURE_TIME_REG_ADD,ALS102_REG_TOTALNUM,rcvdata);
                if(real_readnum<0)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号102参数失败"));
                }
                else
                {
                    if(rcvdata[0]>65535)
                    {
                        m_mcs->resultdata.alg102_threshold=65535;
                    }
                    else if(rcvdata[0]<20)
                    {
                        m_mcs->resultdata.alg102_threshold=20;
                    }
                    else
                    {
                        m_mcs->resultdata.alg102_threshold=rcvdata[0];
                    }
                    ui->alg102_threshold->setText(QString::number(m_mcs->resultdata.alg102_threshold));

                    for(int i=1;i<ALS102_REG_TOTALNUM;i++)
                    {
                        ui->tab4tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                    }

                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号102参数成功"));
                }
            }
            break;
            case TABWIDGET_TASK103:
            {
                int real_readnum=0;
                u_int16_t rcvdata[ALS103_REG_TOTALNUM];
                real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS103_EXPOSURE_TIME_REG_ADD,ALS103_REG_TOTALNUM,rcvdata);
                if(real_readnum<0)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号103参数失败"));
                }
                else
                {
                    if(rcvdata[0]>65535)
                    {
                        m_mcs->resultdata.alg103_threshold=65535;
                    }
                    else if(rcvdata[0]<20)
                    {
                        m_mcs->resultdata.alg103_threshold=20;
                    }
                    else
                    {
                        m_mcs->resultdata.alg103_threshold=rcvdata[0];
                    }
                    ui->alg103_threshold->setText(QString::number(m_mcs->resultdata.alg103_threshold));

                    for(int i=1;i<ALS103_REG_TOTALNUM;i++)
                    {
                        ui->tab5tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                    }

                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号103参数成功"));
                }
            }
            break;
            case TABWIDGET_TASK104:
            {
                int real_readnum=0;
                u_int16_t rcvdata[ALS104_REG_TOTALNUM];
                real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS104_EXPOSURE_TIME_REG_ADD,ALS104_REG_TOTALNUM,rcvdata);
                if(real_readnum<0)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号104参数失败"));
                }
                else
                {
                    if(rcvdata[0]>65535)
                    {
                        m_mcs->resultdata.alg104_threshold=65535;
                    }
                    else if(rcvdata[0]<20)
                    {
                        m_mcs->resultdata.alg104_threshold=20;
                    }
                    else
                    {
                        m_mcs->resultdata.alg104_threshold=rcvdata[0];
                    }
                    ui->alg104_threshold->setText(QString::number(m_mcs->resultdata.alg104_threshold));

                    for(int i=1;i<ALS104_REG_TOTALNUM;i++)
                    {
                        ui->tab6tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                    }

                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号104参数成功"));
                }
            }
            break;
            case TABWIDGET_TASK105:
            {
                int real_readnum=0;
                u_int16_t rcvdata[ALS105_REG_TOTALNUM];
                real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS105_EXPOSURE_TIME_REG_ADD,ALS105_REG_TOTALNUM,rcvdata);
                if(real_readnum<0)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号105参数失败"));
                }
                else
                {
                    if(rcvdata[0]>65535)
                    {
                        m_mcs->resultdata.alg105_threshold=65535;
                    }
                    else if(rcvdata[0]<20)
                    {
                        m_mcs->resultdata.alg105_threshold=20;
                    }
                    else
                    {
                        m_mcs->resultdata.alg105_threshold=rcvdata[0];
                    }
                    ui->alg105_threshold->setText(QString::number(m_mcs->resultdata.alg105_threshold));

                    for(int i=1;i<ALS105_REG_TOTALNUM;i++)
                    {
                        ui->tab7tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                    }

                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号105参数成功"));
                }
            }
            break;
            case TABWIDGET_TASK106:
            {
                int real_readnum=0;
                u_int16_t rcvdata[ALS106_REG_TOTALNUM];
                real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS106_EXPOSURE_TIME_REG_ADD,ALS106_REG_TOTALNUM,rcvdata);
                if(real_readnum<0)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号106参数失败"));
                }
                else
                {
                    if(rcvdata[0]>65535)
                    {
                        m_mcs->resultdata.alg106_threshold=65535;
                    }
                    else if(rcvdata[0]<20)
                    {
                        m_mcs->resultdata.alg106_threshold=20;
                    }
                    else
                    {
                        m_mcs->resultdata.alg106_threshold=rcvdata[0];
                    }
                    ui->alg106_threshold->setText(QString::number(m_mcs->resultdata.alg106_threshold));

                    for(int i=1;i<ALS106_REG_TOTALNUM;i++)
                    {
                        ui->tab8tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                    }

                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号106参数成功"));
                }
            }
            break;
            case TABWIDGET_TASK107:
            {
                int real_readnum=0;
                u_int16_t rcvdata[ALS107_REG_TOTALNUM];
                real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS107_EXPOSURE_TIME_REG_ADD,ALS107_REG_TOTALNUM,rcvdata);
                if(real_readnum<0)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号107参数失败"));
                }
                else
                {
                    if(rcvdata[0]>65535)
                    {
                        m_mcs->resultdata.alg107_threshold=65535;
                    }
                    else if(rcvdata[0]<20)
                    {
                        m_mcs->resultdata.alg107_threshold=20;
                    }
                    else
                    {
                        m_mcs->resultdata.alg107_threshold=rcvdata[0];
                    }
                    ui->alg107_threshold->setText(QString::number(m_mcs->resultdata.alg107_threshold));

                    for(int i=1;i<ALS107_REG_TOTALNUM;i++)
                    {
                        ui->tab9tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                    }

                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号107参数成功"));
                }
            }
            break;
            case TABWIDGET_TASK108:
            {
                int real_readnum=0;
                u_int16_t rcvdata[ALS108_REG_TOTALNUM];
                real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS108_EXPOSURE_TIME_REG_ADD,ALS108_REG_TOTALNUM,rcvdata);
                if(real_readnum<0)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号108参数失败"));
                }
                else
                {
                    if(rcvdata[0]>65535)
                    {
                        m_mcs->resultdata.alg108_threshold=65535;
                    }
                    else if(rcvdata[0]<20)
                    {
                        m_mcs->resultdata.alg108_threshold=20;
                    }
                    else
                    {
                        m_mcs->resultdata.alg108_threshold=rcvdata[0];
                    }
                    ui->alg108_threshold->setText(QString::number(m_mcs->resultdata.alg108_threshold));

                    for(int i=1;i<ALS108_REG_TOTALNUM;i++)
                    {
                        ui->tab10tableWidget->item(i-1,2)->setText(QString::number((int16_t)rcvdata[i]));
                    }

                    if(ui->checkBox->isChecked()==false)
                        ui->record->append(QStringLiteral("读取任务号108参数成功"));
                }
            }
            break;
            default:
            break;
        }
    }
}

QJsonObject qtmysunnyDlg::QstringToJson(QString jsonString)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toLocal8Bit().data());
    if(jsonDocument.isNull())
    {
        qDebug()<< "String NULL"<< jsonString.toLocal8Bit().data();
    }
    QJsonObject jsonObject = jsonDocument.object();
    return jsonObject;
}

QString qtmysunnyDlg::JsonToQstring(QJsonObject jsonObject)
{
    return QString(QJsonDocument(jsonObject).toJson());
}


getposThread::getposThread(qtmysunnyDlg *statci_p)
{
    _p=statci_p;
}

void getposThread::run()
{
    while (1)
    {
        if(_p->b_thread1==true)
        {       
            if(_p->m_mcs->cam->sop_cam[0].b_connect==true)
            {
                //读取坐标信息
                if(_p->ctx_result_dosomeing==DO_WRITE_TASK)
                {
                    if(_p->b_init_set_task==true)
                    {
                        _p->b_init_set_task=false;
                        emit Send_set_task();
                    }
                }
                else if(_p->ctx_result_dosomeing==DO_NOTHING)
                {
                    int real_readnum_1=modbus_read_registers(_p->m_mcs->resultdata.ctx_result,ALS_STATE_REG_ADD,15,_p->pos_data);
                    int real_readnum_2=modbus_read_registers(_p->m_mcs->resultdata.ctx_result,ALS_Y_POINT2_REG_ADD,4,_p->pos_data2);
                    int real_readnum_3=modbus_read_registers(_p->m_mcs->resultdata.ctx_result,ALS_SOLDER_REG_ADD,1,_p->pos_data3);

                    if(real_readnum_1<0||real_readnum_2<0||real_readnum_3<0)
                    {
                        if(_p->b_init_show_pos_failed_finish==true)
                        {
                            _p->b_init_show_pos_failed_finish=false;
                        //  emit Send_show_pos_failed();      
                        }
                    }
                    else
                    {
                        if(_p->b_init_show_pos_list_finish==true)
                        {
                            _p->b_init_show_pos_list_finish=false;
                            emit Send_show_pos_list();
                        }
                    }
                }
            }
            if(_p->m_mcs->cam->sop_cam[0].b_updataimage_finish==true)
            {
                if(_p->b_init_show_cvimage_inlab_finish==true)
                {
                    _p->b_init_show_cvimage_inlab_finish=false;
                    qRegisterMetaType< cv::Mat >("cv::Mat"); //传递自定义类型信号时要添加注册
                    emit Send_show_cvimage_inlab(_p->m_mcs->cam->sop_cam[0].cv_image);
                }
            }

            #if _MSC_VER||WINDOWS_TCP
            #ifdef DEBUG_CLOUD_TCP
            if(_p->m_mcs->cam->sop_cam[0].b_updatacloud_finish==true)
            {
                if(_p->b_init_show_cloud_inlab_finish==true)
                {
                    mutex_IfAlgorhmitcloud.lock();
                    _p->b_init_show_cloud_inlab_finish=false;
                    qRegisterMetaType<IFAlgorhmitcloud>("IFAlgorhmitcloud");
                    emit Send_show_cloud_list(_p->m_mcs->cam->sop_cam[0].IfAlgorhmitcloud);
                    mutex_IfAlgorhmitcloud.unlock();
                }
            }
            #endif
            #endif

            usleep(30000);
        }
        else
        {
            _p->b_stop_thread1=true;
            break;
        }
    }
}

void getposThread::Stop()
{
  if(_p->b_thread1==true)
  {
    _p->b_stop_thread1=false;
    _p->b_thread1=false;
    while (_p->b_stop_thread1==false)
    {
      sleep(0);
    }
  }
}





