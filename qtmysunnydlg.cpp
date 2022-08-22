#include "qtmysunnydlg.h"
#include "ui_qtmysunnydlg.h"

qtmysunnyDlg::qtmysunnyDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qtmysunnyDlg)
{
    std::string dir = "./DATA";
    if (access(dir.c_str(), 0) == -1)
    {
      mkdir("./DATA",S_IRWXU);
    }

    ui->setupUi(this);
    ui->tabWidget->setTabText(0,"任务0-99");
    ui->tabWidget->setTabText(1,"任务100");
    ui->IPadd->setText("192.168.1.2");
    ui->record->document()->setMaximumBlockCount(500);   //最大设置行数

    ui->tab2tableWidget->setColumnWidth(0, 170);    //设置第一列宽度
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

    b_init_show_cvimage_inlab_finish=true;
    b_init_show_pos_failed_finish=true;
    b_init_show_pos_list_finish=true;
    b_init_set_task=true;

    ctx_result_dosomeing=DO_NOTHING;

    thread1 = new getposThread(this);
    connect(thread1, SIGNAL(Send_show_pos_list()), this, SLOT(init_show_pos_list()));
    connect(thread1, SIGNAL(Send_show_pos_failed()), this, SLOT(init_show_pos_failed()));
    connect(thread1, SIGNAL(Send_show_cvimage_inlab()), this, SLOT(init_show_cvimage_inlab()));
    connect(thread1, SIGNAL(Send_set_task()), this, SLOT(init_set_task()));

    showtasknum=new showtasknumdlg;


    m_mcs=m_mcs->Get();

    connect(ui->connectcameraBtn,&QPushButton::clicked,[=](){
       if(m_mcs->cam->sop_cam[0].b_connect==false)
       {
          img_windowshow(true,ui->imageshowlab);
          UpdataUi();
       }
       else
       {
         img_windowshow(false,ui->imageshowlab);
         UpdataUi();
       }
    });

    connect(ui->robotsetBtn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_robotset_state==true)
       {
            u_int16_t robotmod=ui->comboBox->currentIndex();
            u_int16_t robotport=ui->robotport->text().toInt();
            uint16_t tab_reg[2];
            tab_reg[0]=robotmod;
            tab_reg[1]=robotport;
            int rc=modbus_write_registers(m_mcs->resultdata.ctx_robotset,0x00,2,tab_reg);
            if(rc!=2)
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append("更新机器人设置失败");
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append("更新机器人设置成功,请重启激光头");
            }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append("请连接相机后再设置机器人参数");
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
                ui->record->append("请连接相机后再设置任务号");
       }
    });

    connect(ui->writeTab1Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int alg0_99_threshold=ui->alg0_99_threshold->text().toInt();
           if(alg0_99_threshold<20||alg0_99_threshold>65535)
           {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append("设置相机曝光值超出范围");
           }
           else
           {
               m_mcs->cam->sop_cam[0].i32_exposure=alg0_99_threshold;
               m_mcs->cam->sop_cam[0].roscmd_set_exposure(m_mcs->cam->sop_cam[0].i32_exposure);
               m_mcs->resultdata.alg100_threshold=alg0_99_threshold;
               if(ui->checkBox->isChecked()==false)
                   ui->record->append("设置相机曝光值成功");
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append("请连接相机后再设置曝光值");
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
                   ui->record->append("读取相机曝光值成功");
           }
           else
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append("读取相机曝光值失败");
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append("请连接相机后再读取曝光值");
       }
    });

    connect(ui->writeTab2Btn,&QPushButton::clicked,[=](){
       if(m_mcs->resultdata.link_param_state==true)
       {
           int alg100_threshold=ui->alg100_threshold->text().toInt();
           if(alg100_threshold<20||alg100_threshold>65535)
           {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append("设置相机曝光值超出范围");
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
                       ui->record->append("设置任务号100参数失败");
               }
               else
               {
                   m_mcs->resultdata.alg100_threshold=alg100_threshold;
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append("设置任务号100参数成功");
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append("请连接相机后再设置任务号100参数");
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
                   ui->record->append("重置任务号100参数失败");
           }
           else
           {
               if(ui->checkBox->isChecked()==false)
                   ui->record->append("重置任务号100参数成功");
               sleep(1);
               int real_readnum=0;
               u_int16_t rcvdata[ALS100_REG_TOTALNUM];
               real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS100_EXPOSURE_TIME_REG_ADD,ALS100_REG_TOTALNUM,rcvdata);
               if(real_readnum<0)
               {
                   if(ui->checkBox->isChecked()==false)
                       ui->record->append("重新读取任务号100参数失败");
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
                       ui->record->append("重新读取任务号100参数成功");
               }
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append("请连接相机后再重置任务号100参数");
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
                   ui->record->append("读取任务号100参数失败");
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
                   ui->record->append("读取任务号100参数成功");
           }
       }
       else
       {
           if(ui->checkBox->isChecked()==false)
                ui->record->append("请连接相机后再读取任务号100参数");
       }
    });

    connect(ui->tasknumshowBtn,&QPushButton::clicked,[=](){
        showtasknum->setWindowTitle("任务号图示");
        showtasknum->exec();
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
                        ui->record->append("写入视图步骤失败");
                }
                else
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append("写入视图步骤成功");
                }
            }
            else
            {
                if(ui->checkBox->isChecked()==false)
                     ui->record->append("请停止录制视频后再写入视图步骤");
            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append("请连接相机后再写入视图步骤");
        }
    });

    connect(ui->savebmpshowBtn,&QPushButton::clicked,[=](){
        if(m_mcs->cam->sop_cam[0].b_connect==true)
        {
            QString dir="./DATA/";
            QString time;
            TimeFunction to;
            to.get_time_ms(&time);
            QString format=".bmp";
            dir=dir+time+format;
            cv::imwrite(dir.toStdString(),(m_mcs->cam->sop_cam[0].cv_image));
            if(ui->checkBox->isChecked()==false)
                 ui->record->append("保存图片成功");
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append("请连接相机后再保存图片");
        }
    });

    connect(ui->saveavishowBtn,&QPushButton::clicked,[=](){
        if(m_mcs->cam->sop_cam[0].b_connect==true)
        {
            if(m_mcs->resultdata.b_luzhi==false)
            {
                QString dir="./DATA/";
                QString time;
                TimeFunction to;
                to.get_time_ms(&time);
                QString format=".avi";
                dir=dir+time+format;
                m_mcs->cam->sop_cam[0].StartRecord(dir);
                m_mcs->resultdata.b_luzhi=true;
                ui->saveavishowBtn->setText("停止录制");
                if(ui->checkBox->isChecked()==false)
                     ui->record->append("视频录制中");
            }
            else if(m_mcs->resultdata.b_luzhi==true)
            {
                m_mcs->resultdata.b_luzhi=false;
                m_mcs->cam->sop_cam[0].StopRecord();
                ui->saveavishowBtn->setText("录制视频");
                if(ui->checkBox->isChecked()==false)
                     ui->record->append("视频录制完成");
            }
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                 ui->record->append("请连接相机后再录制视频");
        }
    });
}

qtmysunnyDlg::~qtmysunnyDlg()
{
    thread1->Stop();
    thread1->quit();
    thread1->wait();
    m_mcs->cam->sop_cam[0].DisConnect();
    delete showtasknum;
    delete ui;
}

void qtmysunnyDlg::img_windowshow(bool b_show,QLabel *lab_show)
{
    if(b_show==true)
    {
        if(m_mcs->resultdata.link_result_state==false)
        {
            QString server_ip=ui->IPadd->text();
            QString server_port2="1502";
            m_mcs->resultdata.ctx_result = modbus_new_tcp(server_ip.toUtf8(), server_port2.toInt());
            if (modbus_connect(m_mcs->resultdata.ctx_result) == -1)
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append("1502端口连接失败");
                modbus_free(m_mcs->resultdata.ctx_result);
                return;
            }      
            m_mcs->resultdata.link_result_state=true;
            if(ui->checkBox->isChecked()==false)
                ui->record->append("1502端口连接成功");
            open_camer_modbus();
        }
        if(m_mcs->resultdata.link_param_state==false)
        {
            QString server_ip=ui->IPadd->text();
            QString server_port1="1500";
            m_mcs->resultdata.ctx_param = modbus_new_tcp(server_ip.toUtf8(), server_port1.toInt());
            if (modbus_connect(m_mcs->resultdata.ctx_param) == -1)
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append("1500端口连接失败");
                modbus_free(m_mcs->resultdata.ctx_param);
                return;
            }
            m_mcs->resultdata.link_param_state=true;
            if(ui->checkBox->isChecked()==false)
                ui->record->append("1500端口连接成功");
        }
        if(m_mcs->resultdata.link_robotset_state==false)
        {
            QString server_ip=ui->IPadd->text();
            QString server_port1="1501";
            m_mcs->resultdata.ctx_robotset = modbus_new_tcp(server_ip.toUtf8(), server_port1.toInt());
            if (modbus_connect(m_mcs->resultdata.ctx_robotset) == -1)
            {
                if(ui->checkBox->isChecked()==false)
                    ui->record->append("1501端口连接失败");
                modbus_free(m_mcs->resultdata.ctx_robotset);
                return;
            }
            m_mcs->resultdata.link_robotset_state=true;
            if(ui->checkBox->isChecked()==false)
                ui->record->append("1501端口连接成功");
        }
        //读取机器人信息
        int real_readnum;

        real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_robotset,0x00,2,m_mcs->resultdata.red_robotset);
        if(real_readnum<0)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append("获取当前机器人设置信息失败");
        }
        else
        {
            u_int16_t robotmod=m_mcs->resultdata.red_robotset[0];
            u_int16_t port=m_mcs->resultdata.red_robotset[1];
            ui->comboBox->setCurrentIndex(robotmod);
            ui->robotport->setText(QString::number(port));
            if(ui->checkBox->isChecked()==false)
            {
                switch(robotmod)
                {
                    case 0:
                        ui->record->append("获取当前内部机器人设置:无机器人");
                    break;
                    case 1:
                    {
                        ui->record->append("获取当前内部机器人设置:智昌机器人");
                        QString msg="获取当前内部机器人端口号:"+QString::number(port);
                        ui->record->append(msg);
                    }
                    break;
                    case 2:
                    {
                        ui->record->append("获取当前内部机器人设置:智昌-川崎机器人");
                        QString msg="获取当前内部机器人端口号:"+QString::number(port);
                        ui->record->append(msg);
                    }
                    break;
                    case 3:
                    {
                        ui->record->append("获取当前内部机器人设置:摩卡-纳伯特机器人");
                        QString msg="获取当前内部机器人端口号:"+QString::number(port);
                        ui->record->append(msg);
                    }
                    break;
                }

            }
        }

        //读取task信息
        u_int16_t task;
        real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_result,0x102,1,&task);
        if(real_readnum<0)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append("获取当前任务号信息失败");
        }
        else
        {
            ui->tasknum->setText(QString::number(task));
            if(ui->checkBox->isChecked()==false)
            {
                QString msg="获取当前内部任务号:"+QString::number(task);
                ui->record->append(msg);
            }
        }

        showupdata_tabWidget(ui->tabWidget->currentIndex());

        b_thread1=true;
        thread1->start();
    }
    else
    {
        thread1->Stop();
        thread1->quit();
        thread1->wait();

        if(m_mcs->resultdata.link_result_state==true)
        {
            close_camer_modbus();
            modbus_free(m_mcs->resultdata.ctx_result);
            m_mcs->resultdata.link_result_state=false;
            if(ui->checkBox->isChecked()==false)
                ui->record->append("1502端口关闭");
        }
        if(m_mcs->resultdata.link_param_state==true)
        {
            modbus_close(m_mcs->resultdata.ctx_param);
            m_mcs->resultdata.link_param_state=false;
            if(ui->checkBox->isChecked()==false)
                ui->record->append("1500端口关闭");
        }
        if(m_mcs->resultdata.link_robotset_state==true)
        {
            modbus_close(m_mcs->resultdata.ctx_robotset);
            m_mcs->resultdata.link_robotset_state=false;
            if(ui->checkBox->isChecked()==false)
                ui->record->append("1501端口关闭");
        }
    }
#ifdef DEBUG_TEST
    if(b_show==true)
    {
        m_mcs->cam->sop_cam[0].b_connect=true;
        if(ui->checkBox->isChecked()==false)
            ui->record->append("相机连接成功");
    }
    else
    {
        if(m_mcs->resultdata.b_luzhi==true)
        {
            m_mcs->resultdata.b_luzhi=false;
            m_mcs->cam->sop_cam[0].StopRecord();
            ui->saveavishowBtn->setText("录制视频");
            if(ui->checkBox->isChecked()==false)
                 ui->record->append("视频录制完成");
        }
        m_mcs->cam->sop_cam[0].b_connect=false;
        if(ui->checkBox->isChecked()==false)
            ui->record->append("相机关闭");
    }
#else
    if(b_show==true)
    {
        m_mcs->cam->sop_cam[0].InitConnect(lab_show);
        if(m_mcs->cam->sop_cam[0].b_connect==true)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append("相机连接成功");
        }
        else if(m_mcs->cam->sop_cam[0].b_connect==false)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append("相机连接失败");
        }
    }
    else
    {
        //关闭过程图
        u_int16_t tab_reg[1];
        tab_reg[0]=0;
        modbus_write_registers(m_mcs->resultdata.ctx_param,ALS_SHOW_STEP_REG_ADD,1,tab_reg);

        if(m_mcs->resultdata.b_luzhi==true)
        {
            m_mcs->resultdata.b_luzhi=false;
            m_mcs->cam->sop_cam[0].StopRecord();
            ui->saveavishowBtn->setText("录制视频");
            if(ui->checkBox->isChecked()==false)
                 ui->record->append("视频录制完成");
        }     
        m_mcs->cam->sop_cam[0].DisConnect();
        if(ui->checkBox->isChecked()==false)
            ui->record->append("相机关闭");
    }
#endif
    UpdataUi();
}

void qtmysunnyDlg::UpdataUi()
{
    if(m_mcs->cam->sop_cam[0].b_connect==false)
    {
        ui->connectcameraBtn->setText("连接相机");
    }
    else
    {
        ui->connectcameraBtn->setText("断开相机");
    }
}

void qtmysunnyDlg::open_camer_modbus()
{
    if(m_mcs->resultdata.link_result_state==true)
    {
        uint16_t tab_reg[1];
        tab_reg[0]=0xff;
        int rc=modbus_write_registers(m_mcs->resultdata.ctx_result,0x101,1,tab_reg);
        if(rc!=1)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append("激光器相机启动设置失败");
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append("激光器相机启动设置成功");
        }
    }
}

void qtmysunnyDlg::close_camer_modbus()
{
    if(m_mcs->resultdata.link_result_state==true)
    {
        uint16_t tab_reg[1];
        tab_reg[0]=0;
        int rc=modbus_write_registers(m_mcs->resultdata.ctx_result,0x101,1,tab_reg);
        if(rc!=1)
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append("激光器相机关闭设置失败");
        }
        else
        {
            if(ui->checkBox->isChecked()==false)
                ui->record->append("激光器相机关闭设置成功");
        }
    }
}

void qtmysunnyDlg::init_show_pos_list()
{
    ui->label_9->setText("0x"+QString::number(pos_data[0],16));
    float Y=(int16_t)pos_data[1]/100.0;
    float Z=(int16_t)pos_data[2]/100.0;
    ui->label_10->setText(QString::number(Y,'f',2));
    ui->label_11->setText(QString::number(Z,'f',2));

    float Y2=(int16_t)pos_data2[0]/100.0;
    float Z2=(int16_t)pos_data2[1]/100.0;
    float Y3=(int16_t)pos_data2[2]/100.0;
    float Z3=(int16_t)pos_data2[3]/100.0;
    ui->label_17->setText(QString::number(Y2,'f',2));
    ui->label_19->setText(QString::number(Z2,'f',2));
    ui->label_21->setText(QString::number(Y3,'f',2));
    ui->label_23->setText(QString::number(Z3,'f',2));

    if(pos_data3[0]==0xff)
        ui->label_25->setText("是");
    else if(pos_data3[0]==0)
        ui->label_25->setText("否");

    b_init_show_pos_list_finish=true;
}

void qtmysunnyDlg::init_show_pos_failed()
{
    if(ui->checkBox->isChecked()==false)
        ui->record->append("获取当前检测信息失败");
    b_init_show_pos_failed_finish=true;
}

void qtmysunnyDlg::init_show_cvimage_inlab()
{
    if(!m_mcs->cam->sop_cam[0].cv_image.empty())
    {
        QImage::Format format = QImage::Format_RGB888;
        cv::Mat cvimg=m_mcs->cam->sop_cam[0].cv_image;
        switch (cvimg.type())
        {
        case CV_8UC1:
          format = QImage::Format_Indexed8;
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
        img = img.scaled(ui->imageshowlab->width(),ui->imageshowlab->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//图片自适应lab大小
        ui->imageshowlab->setPixmap(QPixmap::fromImage(img));
    }
    b_init_show_cvimage_inlab_finish=true;
}

void qtmysunnyDlg::init_set_task()
{
    u_int16_t tasknum=ui->tasknum->text().toInt();
    uint16_t tab_reg[1];
    tab_reg[0]=tasknum;
    int rc=modbus_write_registers(m_mcs->resultdata.ctx_result,0x102,1,tab_reg);
    if(rc!=1)
    {
        if(ui->checkBox->isChecked()==false)
            ui->record->append("更新任务号失败");
    }
    else
    {
        if(ui->checkBox->isChecked()==false)
            ui->record->append("更新任务号成功");
    }
    ctx_result_dosomeing=DO_NOTHING;
    b_init_set_task=true;
}

void qtmysunnyDlg::on_tabWidget_tabBarClicked(int index)
{
    showupdata_tabWidget(index);
}

void qtmysunnyDlg::showupdata_tabWidget(int index)
{
    if(m_mcs->resultdata.link_param_state==true)
    {
        switch(index)
        {
            case 1:
            {
                int real_readnum=0;
                u_int16_t rcvdata[ALS100_REG_TOTALNUM];
                real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS100_EXPOSURE_TIME_REG_ADD,ALS100_REG_TOTALNUM,rcvdata);
                if(real_readnum<0)
                {
                    if(ui->checkBox->isChecked()==false)
                        ui->record->append("读取任务号100参数失败");
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
                        ui->record->append("读取任务号100参数成功");
                }
            }
            break;
            default:
            break;
        }
    }
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
                    int real_readnum_1=modbus_read_registers(_p->m_mcs->resultdata.ctx_result,0x02,3,_p->pos_data);
                    int real_readnum_2=modbus_read_registers(_p->m_mcs->resultdata.ctx_result,0x50,4,_p->pos_data2);
                    int real_readnum_3=modbus_read_registers(_p->m_mcs->resultdata.ctx_result,0x60,1,_p->pos_data3);
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
                    emit Send_show_cvimage_inlab();
                }
            }
            sleep(0);
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


