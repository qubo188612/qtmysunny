#include "pshowdlg.h"
#include "ui_pshowdlg.h"

template<typename _Tp>
std::vector<_Tp> convertMat2Vector(cv::Mat &mat)
{
    return (std::vector<_Tp>)(mat.reshape(1, 1));//通道数不变，按行转为一行
}

pshowdlg::pshowdlg(my_parameters *mcs,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pshowdlg)
{
    ui->setupUi(this);
    m_mcs=mcs;

    client=new QTcpSocket(this);
    craftdlg=new craftDlg(m_mcs);
}

pshowdlg::~pshowdlg()
{
    delete client;
    delete craftdlg;
    delete ui;
}

void pshowdlg::init_dlg_show()
{
    initPdata();
    updatatext();
    switch(m_mcs->resultdata.P_data_eye_hand_calibrationmode)
    {
        case HAND_IN_EYE:
        {
            ui->radio1->setChecked(1);
        }
        break;
        case HAND_OUT_EYE:
        {
            ui->radio2->setChecked(1);
        }
        break;
    }
    initpDatapoint(m_mcs->resultdata.P_data_eye_hand_calibrationmode);

    link_pshow_state=false;
    b_init_show_pshow_text_finish=true;

    QString server_ip=m_mcs->e2proomdata.sunnydlg_ipaddress;
    QString server_port2=QString::number(PORT_ALS_RESULT);
    ctx_pshow = modbus_new_tcp(server_ip.toUtf8(), server_port2.toInt());
    if (modbus_connect(ctx_pshow) == 0)
    {
        link_pshow_state=true;
    }   

    QString server_port1=QString::number(PORT_ALSTCP_FTP);
    client->connectToHost(server_ip.toUtf8(), server_port1.toInt());
    if(!client->waitForConnected(1000))
    {
        ui->record->append(server_port1+QStringLiteral("端口连接失败"));
        return;
    }

    thread1 = new pshowdlgThread(this);
    connect(thread1, SIGNAL(Send_show_pshow_text()), this, SLOT(init_show_pshow_text()));

    b_thread1=true;
    thread1->start();
}

void pshowdlg::close_dlg_show()
{
    thread1->Stop();
    thread1->quit();
    thread1->wait();
    delete thread1;

    if(link_pshow_state==true)
    {
        modbus_close(ctx_pshow);
    }
    link_pshow_state=false;
    modbus_free(ctx_pshow);   

    client->disconnectFromHost();
}

void pshowdlg::updataPdata()
{
    ui->robPdata->clear();
    ui->robPdatapoint->clear();
    for(int i=0;i<m_mcs->resultdata.P_data.size();i++)
    {
        QString msg;
        msg="No."+QString::number(i+1)+": P["+QString::number(m_mcs->resultdata.P_data[i].pID)+"]";
        ui->robPdata->addItem(msg);
    }
    if(now_robPdata>=0&&now_robPdata<m_mcs->resultdata.P_data.size())
    {
        ui->robPdata->setCurrentRow(now_robPdata);
        ui->robPdatapoint->clear();
        for(int i=0;i<m_mcs->resultdata.P_data[now_robPdata].pos.size();i++)
        {
            QString msg;
            msg="pos["+QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].x,'f',3)+","+
                       QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].y,'f',3)+","+
                       QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].z,'f',3)+","+
                       QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].rx,'f',3)+","+
                       QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].ry,'f',3)+","+
                       QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].rz,'f',3)+
                "] out1["+QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].out1)+","+
                          QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].out2)+","+
                          QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].out3)+
                "] tool:"+QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].tool)+
                " tcp:"+QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].tcp)+
                " usertcp:"+QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].usertcp);
            ui->robPdatapoint->addItem(msg);
        }
    }
}

void pshowdlg::initPdata()
{
    now_robPdata=-1;
    ui->robPdata->clear();
    ui->robPdatapoint->clear();
    for(int i=0;i<m_mcs->resultdata.P_data.size();i++)
    {
        QString msg;
        msg="No."+QString::number(i+1)+": P["+QString::number(m_mcs->resultdata.P_data[i].pID)+"]";
        ui->robPdata->addItem(msg);
    }
    now_robPdata=m_mcs->resultdata.P_data.size()-1;
    if(now_robPdata>=0)
    {
        ui->robPdata->setCurrentRow(now_robPdata);
        for(int i=0;i<m_mcs->resultdata.P_data[now_robPdata].pos.size();i++)
        {
            QString msg;
            msg="pos["+QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].x,'f',3)+","+
                       QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].y,'f',3)+","+
                       QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].z,'f',3)+","+
                       QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].rx,'f',3)+","+
                       QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].ry,'f',3)+","+
                       QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].rz,'f',3)+
                "] out1["+QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].out1)+","+
                          QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].out2)+","+
                          QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].out3)+
                "] tool:"+QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].tool)+
                " tcp:"+QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].tcp)+
                " usertcp:"+QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].usertcp);
            ui->robPdatapoint->addItem(msg);
        }
    }
}

void pshowdlg::updatatext()
{
    ui->a00_label->setText(QString::number(m_mcs->resultdata.pData_demdlg_R[0],'f',3));
    ui->a01_label->setText(QString::number(m_mcs->resultdata.pData_demdlg_R[1],'f',3));
    ui->a02_label->setText(QString::number(m_mcs->resultdata.pData_demdlg_R[2],'f',3));
    ui->a10_label->setText(QString::number(m_mcs->resultdata.pData_demdlg_R[3],'f',3));
    ui->a11_label->setText(QString::number(m_mcs->resultdata.pData_demdlg_R[4],'f',3));
    ui->a12_label->setText(QString::number(m_mcs->resultdata.pData_demdlg_R[5],'f',3));
    ui->a20_label->setText(QString::number(m_mcs->resultdata.pData_demdlg_R[6],'f',3));
    ui->a21_label->setText(QString::number(m_mcs->resultdata.pData_demdlg_R[7],'f',3));
    ui->a22_label->setText(QString::number(m_mcs->resultdata.pData_demdlg_R[8],'f',3));
    ui->t0_label->setText(QString::number(m_mcs->resultdata.pData_demdlg_T[0],'f',3));
    ui->t1_label->setText(QString::number(m_mcs->resultdata.pData_demdlg_T[1],'f',3));
    ui->t2_label->setText(QString::number(m_mcs->resultdata.pData_demdlg_T[2],'f',3));
    ui->c00_label->setText(QString::number(m_mcs->resultdata.pData_matrix_camera2plane[0],'f',3));
    ui->c01_label->setText(QString::number(m_mcs->resultdata.pData_matrix_camera2plane[1],'f',3));
    ui->c02_label->setText(QString::number(m_mcs->resultdata.pData_matrix_camera2plane[2],'f',3));
    ui->c10_label->setText(QString::number(m_mcs->resultdata.pData_matrix_camera2plane[3],'f',3));
    ui->c11_label->setText(QString::number(m_mcs->resultdata.pData_matrix_camera2plane[4],'f',3));
    ui->c12_label->setText(QString::number(m_mcs->resultdata.pData_matrix_camera2plane[5],'f',3));
    ui->c20_label->setText(QString::number(m_mcs->resultdata.pData_matrix_camera2plane[6],'f',3));
    ui->c21_label->setText(QString::number(m_mcs->resultdata.pData_matrix_camera2plane[7],'f',3));
    ui->c22_label->setText(QString::number(m_mcs->resultdata.pData_matrix_camera2plane[8],'f',3));
    ui->p00_label->setText(QString::number(m_mcs->resultdata.pData_matrix_plane2robot[0],'f',3));
    ui->p01_label->setText(QString::number(m_mcs->resultdata.pData_matrix_plane2robot[1],'f',3));
    ui->p02_label->setText(QString::number(m_mcs->resultdata.pData_matrix_plane2robot[2],'f',3));
    ui->p10_label->setText(QString::number(m_mcs->resultdata.pData_matrix_plane2robot[3],'f',3));
    ui->p11_label->setText(QString::number(m_mcs->resultdata.pData_matrix_plane2robot[4],'f',3));
    ui->p12_label->setText(QString::number(m_mcs->resultdata.pData_matrix_plane2robot[5],'f',3));
    ui->p20_label->setText(QString::number(m_mcs->resultdata.pData_matrix_plane2robot[6],'f',3));
    ui->p21_label->setText(QString::number(m_mcs->resultdata.pData_matrix_plane2robot[7],'f',3));
    ui->p22_label->setText(QString::number(m_mcs->resultdata.pData_matrix_plane2robot[8],'f',3));

    ui->craft_Id->setText(QString::number(m_mcs->resultdata.P_data_craftinfo.craft_Id));
}

void pshowdlg::getrobinfo()
{
    u_int16_t u16_data[2];
    int32_t *i32_data=(int32_t*)u16_data;
    u16_data[0]=pos_data[0];
    u16_data[1]=pos_data[1];
    robposinfo.x=*i32_data/1000.0;
    u16_data[0]=pos_data[2];
    u16_data[1]=pos_data[3];
    robposinfo.y=*i32_data/1000.0;
    u16_data[0]=pos_data[4];
    u16_data[1]=pos_data[5];
    robposinfo.z=*i32_data/1000.0;
    u16_data[0]=pos_data[6];
    u16_data[1]=pos_data[7];
    robposinfo.rx=*i32_data/10000.0;
    u16_data[0]=pos_data[8];
    u16_data[1]=pos_data[9];
    robposinfo.ry=*i32_data/10000.0;
    u16_data[0]=pos_data[10];
    u16_data[1]=pos_data[11];
    robposinfo.rz=*i32_data/10000.0;
    u16_data[0]=pos_data[12];
    u16_data[1]=pos_data[13];
    robposinfo.out1=*i32_data;
    u16_data[0]=pos_data[14];
    u16_data[1]=pos_data[15];
    robposinfo.out2=*i32_data;
    u16_data[0]=pos_data[16];
    u16_data[1]=pos_data[17];
    robposinfo.out3=*i32_data;
    robposinfo.tool=pos_data[18];
    robposinfo.tcp=pos_data[19];
    robposinfo.usertcp=pos_data[20];
    if(result_data[0]==0xff)
    {
        b_robposfinduv=true;
    }
    else
    {
        b_robposfinduv=false;
    }
    robposinfo.uy=((int16_t)result_data[1])/100.0;
    robposinfo.vz=((int16_t)result_data[2])/100.0;


    u16_data[0]=p_pos_data[0];
    u16_data[1]=p_pos_data[1];
    p_robposinfo.x=*i32_data/1000.0;
    u16_data[0]=p_pos_data[2];
    u16_data[1]=p_pos_data[3];
    p_robposinfo.y=*i32_data/1000.0;
    u16_data[0]=p_pos_data[4];
    u16_data[1]=p_pos_data[5];
    p_robposinfo.z=*i32_data/1000.0;
    u16_data[0]=p_pos_data[6];
    u16_data[1]=p_pos_data[7];
    p_robposinfo.rx=*i32_data/10000.0;
    u16_data[0]=p_pos_data[8];
    u16_data[1]=p_pos_data[9];
    p_robposinfo.ry=*i32_data/10000.0;
    u16_data[0]=p_pos_data[10];
    u16_data[1]=p_pos_data[11];
    p_robposinfo.rz=*i32_data/10000.0;
    u16_data[0]=p_pos_data[12];
    u16_data[1]=p_pos_data[13];
    p_robposinfo.out1=*i32_data;
    u16_data[0]=p_pos_data[14];
    u16_data[1]=p_pos_data[15];
    p_robposinfo.out2=*i32_data;
    u16_data[0]=p_pos_data[16];
    u16_data[1]=p_pos_data[17];
    p_robposinfo.out3=*i32_data;
    p_robposinfo.tool=p_pos_data[18];
    p_robposinfo.tcp=p_pos_data[19];
    p_robposinfo.usertcp=p_pos_data[20];

    p_robposinfo.uy=((int16_t)result_data[1])/100.0;
    p_robposinfo.vz=((int16_t)result_data[2])/100.0;
}

void pshowdlg::init_show_pshow_text()
{
    ui->realposX->setText(QString::number(robposinfo.x,'f',3));
    ui->realposY->setText(QString::number(robposinfo.y,'f',3));
    ui->realposZ->setText(QString::number(robposinfo.z,'f',3));
    ui->realposRX->setText(QString::number(robposinfo.rx,'f',4));
    ui->realposRY->setText(QString::number(robposinfo.ry,'f',4));
    ui->realposRZ->setText(QString::number(robposinfo.rz,'f',4));
    ui->realout1->setText(QString::number(robposinfo.out1));
    ui->realout2->setText(QString::number(robposinfo.out2));
    ui->realout3->setText(QString::number(robposinfo.out3));
    ui->realtool->setText(QString::number(robposinfo.tool));
    ui->realtcp->setText(QString::number(robposinfo.tcp));
    ui->realusertcp->setText(QString::number(robposinfo.usertcp));
    ui->realuy->setText(QString::number(robposinfo.uy));
    ui->realvz->setText(QString::number(robposinfo.vz));

    ui->p_realposX->setText(QString::number(p_robposinfo.x,'f',3));
    ui->p_realposY->setText(QString::number(p_robposinfo.y,'f',3));
    ui->p_realposZ->setText(QString::number(p_robposinfo.z,'f',3));
    ui->p_realposRX->setText(QString::number(p_robposinfo.rx,'f',4));
    ui->p_realposRY->setText(QString::number(p_robposinfo.ry,'f',4));
    ui->p_realposRZ->setText(QString::number(p_robposinfo.rz,'f',4));
    ui->p_realout1->setText(QString::number(p_robposinfo.out1));
    ui->p_realout2->setText(QString::number(p_robposinfo.out2));
    ui->p_realout3->setText(QString::number(p_robposinfo.out3));
    ui->p_realtool->setText(QString::number(p_robposinfo.tool));
    ui->p_realtcp->setText(QString::number(p_robposinfo.tcp));
    ui->p_realusertcp->setText(QString::number(p_robposinfo.usertcp));
    ui->p_realuy->setText(QString::number(p_robposinfo.uy));
    ui->p_realvz->setText(QString::number(p_robposinfo.vz));
    b_init_show_pshow_text_finish=true;
}

int pshowdlg::findpDataId(std::vector<rob_group> P_data,int findId,int *pnum)
{
    int b_find=1;
    for(int i=0;i<P_data.size();i++)
    {
        if(P_data[i].pID==findId)
        {
            b_find=0;
            *pnum=i;
            break;
        }
    }
    return b_find;
}

//排列P点
void pshowdlg::initpDatapoint(Eye_Hand_calibrationmode P_data_eye_hand_calibrationmode)
{
    int pnum;
    ui->robposlist->clear();
    ui->leaserposlist->clear();
    now_robpos=-1;
    now_leaserpos=-1;
    P_data_rob.clear();
    P_data_leaser.clear();
    if(0!=findpDataId(m_mcs->resultdata.P_data,0,&pnum))
    {
        return;
    }
    switch(P_data_eye_hand_calibrationmode)
    {
        case HAND_IN_EYE:
        {
            QString msg;
            int pDatanum=m_mcs->resultdata.P_data[pnum].pos.size();
            rob_pinfo pos;
            int n=0;
            int leasernum=0;
            if(pDatanum<1)
            {
                return;
            }
            pos=m_mcs->resultdata.P_data[pnum].pos[n];
            msg="TCP"+QString::number(n+1)+": pos["+
                QString::number(pos.x,'f',3)+","+
                QString::number(pos.y,'f',3)+","+
                QString::number(pos.z,'f',3)+","+
                QString::number(pos.rx,'f',3)+","+
                QString::number(pos.ry,'f',3)+","+
                QString::number(pos.rz,'f',3)+
                "] out["+QString::number(pos.out1)+","+
                         QString::number(pos.out2)+","+
                         QString::number(pos.out3)+
                "] tool:"+QString::number(pos.tool)+
                " tcp:"+QString::number(pos.tcp)+
                " usertcp:"+QString::number(pos.usertcp);
            P_data_rob.push_back(pos);
            ui->robposlist->addItem(msg);
            now_robpos=0;
            ui->robposlist->setCurrentRow(now_robpos);
            for(int n=1;n<pDatanum;n++)
            {
                leasernum++;
                pos=m_mcs->resultdata.P_data[pnum].pos[n];
                msg="TCP"+QString::number(n)+":uv["+
                    QString::number(pos.uy,'f',3)+","+
                    QString::number(pos.vz,'f',3)+"] pos["+
                    QString::number(pos.x,'f',3)+","+
                    QString::number(pos.y,'f',3)+","+
                    QString::number(pos.z,'f',3)+","+
                    QString::number(pos.rx,'f',3)+","+
                    QString::number(pos.ry,'f',3)+","+
                    QString::number(pos.rz,'f',3)+
                    "] out["+QString::number(pos.out1)+","+
                             QString::number(pos.out2)+","+
                             QString::number(pos.out3)+
                    "] tool:"+QString::number(pos.tool)+
                    " tcp:"+QString::number(pos.tcp)+
                    " usertcp:"+QString::number(pos.usertcp);
                P_data_leaser.push_back(pos);
                ui->leaserposlist->addItem(msg);
            }
            now_leaserpos=leasernum-1;
            if(leasernum>0)
            {
                ui->leaserposlist->setCurrentRow(now_leaserpos);
            }
        }
        break;
        case HAND_OUT_EYE:
        {
            QString msg;
            int pDatanum=m_mcs->resultdata.P_data[pnum].pos.size();
            rob_pinfo pos;
            int halfpDatanum;
            int leasernum=0;
            int robnum=0;
            if(pDatanum<1)
            {
                return;
            }
            halfpDatanum=pDatanum-pDatanum/2;
            for(int n=0;n<halfpDatanum;n++)
            {
                robnum++;
                pos=m_mcs->resultdata.P_data[pnum].pos[n];
                msg="TCP"+QString::number(n+1)+": pos["+
                    QString::number(pos.x,'f',3)+","+
                    QString::number(pos.y,'f',3)+","+
                    QString::number(pos.z,'f',3)+","+
                    QString::number(pos.rx,'f',3)+","+
                    QString::number(pos.ry,'f',3)+","+
                    QString::number(pos.rz,'f',3)+
                    "] out["+QString::number(pos.out1)+","+
                             QString::number(pos.out2)+","+
                             QString::number(pos.out3)+
                    "] tool:"+QString::number(pos.tool)+
                    " tcp:"+QString::number(pos.tcp)+
                    " usertcp:"+QString::number(pos.usertcp);
                P_data_rob.push_back(pos);
                ui->robposlist->addItem(msg);
            }
            now_robpos=robnum-1;
            if(robnum>0)
            {
                ui->robposlist->setCurrentRow(now_robpos);
            }
            for(int n=halfpDatanum;n<pDatanum;n++)
            {
                leasernum++;
                pos=m_mcs->resultdata.P_data[pnum].pos[n];
                msg="TCP"+QString::number(n-halfpDatanum+1)+": uv["+
                    QString::number(pos.uy,'f',3)+","+
                    QString::number(pos.vz,'f',3)+"] pos["+
                    QString::number(pos.x,'f',3)+","+
                    QString::number(pos.y,'f',3)+","+
                    QString::number(pos.z,'f',3)+","+
                    QString::number(pos.rx,'f',3)+","+
                    QString::number(pos.ry,'f',3)+","+
                    QString::number(pos.rz,'f',3)+
                    "] out["+QString::number(pos.out1)+","+
                             QString::number(pos.out2)+","+
                             QString::number(pos.out3)+
                    "] tool:"+QString::number(pos.tool)+
                    " tcp:"+QString::number(pos.tcp)+
                    " usertcp:"+QString::number(pos.usertcp);
                P_data_leaser.push_back(pos);
                ui->leaserposlist->addItem(msg);
            }
            now_leaserpos=leasernum-1;
            if(leasernum>0)
            {
                ui->leaserposlist->setCurrentRow(now_leaserpos);
            }
        }
        break;
    }
}

void pshowdlg::updataRoblistUi()
{
    ui->robposlist->clear();
    for(int n=0;n<P_data_rob.size();n++)
    {
        QString msg;
        rob_pinfo pos=P_data_rob[n];
        msg="TCP"+QString::number(n+1)+": pos["+
            QString::number(pos.x,'f',3)+","+
            QString::number(pos.y,'f',3)+","+
            QString::number(pos.z,'f',3)+","+
            QString::number(pos.rx,'f',3)+","+
            QString::number(pos.ry,'f',3)+","+
            QString::number(pos.rz,'f',3)+
            "] out["+QString::number(pos.out1)+","+
                     QString::number(pos.out2)+","+
                     QString::number(pos.out3)+
            "] tool:"+QString::number(pos.tool)+
            " tcp:"+QString::number(pos.tcp)+
            " usertcp:"+QString::number(pos.usertcp);
        ui->robposlist->addItem(msg);
    }
    if(P_data_rob.size()>0)
    {
        ui->robposlist->setCurrentRow(now_robpos);
    }
}

void pshowdlg::updataLeaserlistUi()
{
    ui->leaserposlist->clear();
    for(int n=0;n<P_data_leaser.size();n++)
    {
        QString msg;
        rob_pinfo pos=P_data_leaser[n];
        msg="TCP"+QString::number(n+1)+": uv["+
            QString::number(pos.uy,'f',3)+","+
            QString::number(pos.vz,'f',3)+"] pos["+
            QString::number(pos.x,'f',3)+","+
            QString::number(pos.y,'f',3)+","+
            QString::number(pos.z,'f',3)+","+
            QString::number(pos.rx,'f',3)+","+
            QString::number(pos.ry,'f',3)+","+
            QString::number(pos.rz,'f',3)+
            "] out["+QString::number(pos.out1)+","+
                     QString::number(pos.out2)+","+
                     QString::number(pos.out3)+
            "] tool:"+QString::number(pos.tool)+
            " tcp:"+QString::number(pos.tcp)+
            " usertcp:"+QString::number(pos.usertcp);

        ui->leaserposlist->addItem(msg);
    }
    if(P_data_leaser.size()>0)
    {
        ui->leaserposlist->setCurrentRow(now_leaserpos);
    }
}

void pshowdlg::updataDemarcateResult()
{
    ui->leaserposlist->clear();
    for(int n=0;n<P_data_leaser.size();n++)
    {
        QString msg;
        rob_pinfo pos=P_data_leaser[n];
        msg="TCP"+QString::number(n+1)+": Precision:"+
            QString::number(errgroup[n],'f',2)+" uv["+
            QString::number(pos.uy,'f',3)+","+
            QString::number(pos.vz,'f',3)+"] pos["+
            QString::number(pos.x,'f',3)+","+
            QString::number(pos.y,'f',3)+","+
            QString::number(pos.z,'f',3)+","+
            QString::number(pos.rx,'f',3)+","+
            QString::number(pos.ry,'f',3)+","+
            QString::number(pos.rz,'f',3)+
            "] out["+QString::number(pos.out1)+","+
                     QString::number(pos.out2)+","+
                     QString::number(pos.out3)+
            "] tool:"+QString::number(pos.tool)+
            " tcp:"+QString::number(pos.tcp)+
            " usertcp:"+QString::number(pos.usertcp);

        ui->leaserposlist->addItem(msg);
    }
    if(P_data_leaser.size()>0)
    {
        ui->leaserposlist->setCurrentRow(now_leaserpos);
    }
}

//计算标定结果
void pshowdlg::on_pushButton_7_clicked()
{
    double err;
    switch(m_mcs->resultdata.P_data_eye_hand_calibrationmode)
    {
        case HAND_IN_EYE://眼在手上
        {
            if(P_data_rob.size()!=1)
            {
                ui->record->append(QStringLiteral("TCP坐标点应该只能有一个"));
            }
            else if(P_data_leaser.size()<4)
            {
                ui->record->append(QStringLiteral("激光头坐标点个数要至少大于4个"));
            }
            else
            {
                RobPos rob;
                rob.nEn=1;
                rob.X=P_data_rob[0].x;
                rob.Y=P_data_rob[0].y;
                rob.Z=P_data_rob[0].z;
                rob.RX=P_data_rob[0].rx;
                rob.RY=P_data_rob[0].ry;
                rob.RZ=P_data_rob[0].rz;
                std::vector<TCP_Leaserpos> leaser(P_data_leaser.size());
                for(int i=0;i<P_data_leaser.size();i++)
                {
                    leaser[i].leaserpos.Y=P_data_leaser[i].uy;
                    leaser[i].leaserpos.Z=P_data_leaser[i].vz;
                    leaser[i].leaserpos.nEn=1;
                    leaser[i].robotpos.X=P_data_leaser[i].x;
                    leaser[i].robotpos.Y=P_data_leaser[i].y;
                    leaser[i].robotpos.Z=P_data_leaser[i].z;
                    leaser[i].robotpos.RX=P_data_leaser[i].rx;
                    leaser[i].robotpos.RY=P_data_leaser[i].ry;
                    leaser[i].robotpos.RZ=P_data_leaser[i].rz;
                }
                cv::Mat matrix_camera2plane;
                cv::Mat matrix_plane2robot;
                if(true==Calibration::hand_on_yes_point2RT(m_mcs->resultdata.P_data_cal_posture,
                                                  rob,
                                                  leaser,
                                                  matrix_camera2plane,
                                                  matrix_plane2robot,
                                                  err,errgroup))
                {
                    m_mcs->resultdata.pData_matrix_camera2plane=convertMat2Vector<double>(matrix_camera2plane);
                    m_mcs->resultdata.pData_matrix_plane2robot=convertMat2Vector<double>(matrix_plane2robot);
                    updataDemarcateResult();
                    updatatext();
                    ui->record->append(QStringLiteral("标定完成"));
                }
                else
                {
                    ui->record->append(QStringLiteral("标定计算出现问题,请检查数据"));
                }
                ui->err->setText(QString::number(err,'f',2));
            }
        }
        break;
        case HAND_OUT_EYE://眼在手外
        {
            if(P_data_rob.size()!=P_data_leaser.size())
            {
                ui->record->append(QStringLiteral("TCP坐标点要与激光头坐标点个数相同"));
            }
            else if(P_data_rob.size()<4)
            {
                ui->record->append(QStringLiteral("TCP坐标点个数要至少大于4个"));
            }
            else
            {
                std::vector<Eigen::Vector3d> cloudpoint;
                std::vector<Eigen::Vector3d> robotpoint;
                Eigen::Matrix3d R;      //输入旋转矩阵
                Eigen::Vector3d T;      //输入平移举证
                for(int n=0;n<P_data_leaser.size();n++)
                {
                    Eigen::Vector3d cloudsing;
                    Eigen::Vector3d robotsing;
                    cloudsing[0]=0;
                    cloudsing[1]=P_data_leaser[n].uy;
                    cloudsing[2]=P_data_leaser[n].vz;
                    cloudpoint.push_back(cloudsing);
                    robotsing[0]=P_data_rob[n].x;
                    robotsing[1]=P_data_rob[n].y;
                    robotsing[2]=P_data_rob[n].z;
                    robotpoint.push_back(robotsing);
                }
                Calibration::hand_out_yes_point2RT(cloudpoint,robotpoint,R,T,err,errgroup);
                m_mcs->resultdata.pData_demdlg_R.resize(9);
                int n=0;
                for(int j=0;j<3;j++)
                {
                  for(int i=0;i<3;i++)
                  {
                      m_mcs->resultdata.pData_demdlg_R[n++]=R(j,i);
                  }
                }
                m_mcs->resultdata.pData_demdlg_T.resize(3);
                n=0;
                for(int i=0;i<3;i++)
                {
                    m_mcs->resultdata.pData_demdlg_T[n++]=T(i);
                }
                ui->err->setText(QString::number(err,'f',2));
                updataDemarcateResult();
                updatatext();
                ui->record->append(QStringLiteral("标定完成"));
            }
        }
        break;
    }

}


//导入标定结果
void pshowdlg::on_pushButton_10_clicked()
{
    int pnum;
    if(0!=findpDataId(m_mcs->resultdata.P_data,0,&pnum))
    {
        ui->record->append(QStringLiteral("导入时出现异常,请尝试重启激光器和本软件"));
        return;
    }
    m_mcs->resultdata.P_data[pnum].pos.resize(P_data_rob.size()+P_data_leaser.size());
    for(int i=0;i<P_data_rob.size();i++)
    {
        m_mcs->resultdata.P_data[pnum].pos[i]=P_data_rob[i];
    }
    for(int i=P_data_rob.size();i<P_data_rob.size()+P_data_leaser.size();i++)
    {
        m_mcs->resultdata.P_data[pnum].pos[i]=P_data_leaser[i-P_data_rob.size()];
    }
    pulldemdl();
//  pullpData();
    ui->record->append(QStringLiteral("导入完成"));
}

//眼在手上
void pshowdlg::on_radio1_clicked()
{
    m_mcs->resultdata.P_data_eye_hand_calibrationmode=HAND_IN_EYE;
    ui->record->append(QStringLiteral("选择眼在手上模式"));
}

//眼在手外
void pshowdlg::on_radio2_clicked()
{
    m_mcs->resultdata.P_data_eye_hand_calibrationmode=HAND_OUT_EYE;
    ui->record->append(QStringLiteral("选择眼在手外模式"));
}

//添加机器人TCP点
void pshowdlg::on_pushButton_clicked()
{
    if(now_robpos==P_data_rob.size()-1)
    {
        P_data_rob.push_back(robposinfo);
    }
    else
    {
        P_data_rob.insert(P_data_rob.begin()+now_robpos+1,robposinfo);
    }
    ui->record->append(QStringLiteral("添加TCP点成功"));
    now_robpos++;
    updataRoblistUi();
}

//替换机器人TCP点
void pshowdlg::on_pushButton_2_clicked()
{
    if(now_robpos>=0&&P_data_rob.size()>now_robpos)
    {
        P_data_rob[now_robpos]=robposinfo;
        ui->record->append(QStringLiteral("替换TCP点成功"));
        updataRoblistUi();
    }
    else
    {
        ui->record->append(QStringLiteral("请先选中要替换的TCP点"));
    }
}

//删除机器人TCP点
void pshowdlg::on_pushButton_3_clicked()
{
    if(now_robpos>=0&&P_data_rob.size()>now_robpos)
    {
        P_data_rob.erase(P_data_rob.begin()+now_robpos);
        ui->record->append(QStringLiteral("删除TCP点"));
        if(now_robpos>=P_data_rob.size())
            now_robpos=now_robpos-1;
        updataRoblistUi();
    }
    else
    {
        ui->record->append(QStringLiteral("请先选中要删除的TCP点"));
    }
}

//清空TCP点
void pshowdlg::on_pushButton_8_clicked()
{
    P_data_rob.clear();
    ui->record->append(QStringLiteral("清空TCP点"));
    now_robpos=P_data_rob.size()-1;
    updataRoblistUi();
}

//添加激光点
void pshowdlg::on_pushButton_4_clicked()
{
    int num=0;
    b_robposfinduv=false;
    while (b_robposfinduv==false)
    {
        if(num>10)
        {
            break;
        }
    #if _MSC_VER
        _sleep(ROB_WORK_DELAY_STEP/1000);
    #else
        usleep(ROB_WORK_DELAY_STEP);
    #endif
        num++;
    }
    if(b_robposfinduv==false)
    {
        ui->record->append(QStringLiteral("获取激光头坐标失败"));
    }
    else
    {
        if(now_leaserpos==P_data_leaser.size()-1)
        {
            P_data_leaser.push_back(robposinfo);
        }
        else
        {
            P_data_leaser.insert(P_data_leaser.begin()+now_leaserpos+1,robposinfo);
        }
        ui->record->append(QStringLiteral("添加TCP点成功"));
        now_leaserpos++;
        updataLeaserlistUi();
    }
}

//替换激光点
void pshowdlg::on_pushButton_5_clicked()
{
    if(now_leaserpos>=0&&P_data_leaser.size()>now_leaserpos)
    {
        int num=0;
        b_robposfinduv=false;
        while (b_robposfinduv==false)
        {
            if(num>10)
            {
                break;
            }
        #if _MSC_VER
            _sleep(ROB_WORK_DELAY_STEP/1000);
        #else
            usleep(ROB_WORK_DELAY_STEP);
        #endif
            num++;
        }
        if(b_robposfinduv==false)
        {
            ui->record->append(QStringLiteral("获取激光头坐标失败"));
        }
        else
        {
            P_data_leaser[now_leaserpos]=robposinfo;
            ui->record->append(QStringLiteral("替换激光头点成功"));
            updataLeaserlistUi();
        }
    }
    else
    {
        ui->record->append(QStringLiteral("请先选中要替换的激光头点"));
    }
}

//删除激光点
void pshowdlg::on_pushButton_6_clicked()
{
    if(now_leaserpos>=0&&P_data_leaser.size()>now_leaserpos)
    {
        P_data_leaser.erase(P_data_leaser.begin()+now_leaserpos);
        ui->record->append(QStringLiteral("删除激光头点"));
        if(now_leaserpos>=P_data_leaser.size())
            now_leaserpos=now_leaserpos-1;
        updataLeaserlistUi();
    }
    else
    {
        ui->record->append(QStringLiteral("请先选中要删除的激光头点"));
    }
}

//清空激光点
void pshowdlg::on_pushButton_9_clicked()
{
    P_data_leaser.clear();
    ui->record->append(QStringLiteral("清空激光头点"));
    now_leaserpos=P_data_leaser.size()-1;
    updataLeaserlistUi();
}

//添加P变量
void pshowdlg::on_pushButton_12_clicked()
{
    bool ok;
    int pId;
    int pnum;
    if(ui->pidaddEdit->text().isEmpty())
    {
        ui->record->append(QStringLiteral("请填写要添加的P变量号"));
        return;
    }
    pId=ui->pidaddEdit->text().toInt(&ok);
    if(ok==false)
    {
        ui->record->append(QStringLiteral("要添加的P变量号格式不正确"));
        return;
    }
    if(pId==0||pId==1||pId==2||pId==3||pId==11||pId==1000||pId==1001||pId==1002)
    {
        QString msg=QStringLiteral("不能添加的P变量号")+"P["+QString::number(pId)+"]"+QStringLiteral(",其为系统保留");
        ui->record->append(msg);
        return;
    }
    else if(pId<0||pId>65535)
    {
        ui->record->append(QStringLiteral("P变量号超出设置范围"));
        return;
    }
    if(0!=findpDataId(m_mcs->resultdata.P_data,pId,&pnum))
    {
        //找不到
        QString msg;
        rob_group singl;
        singl.pID=pId;
        singl.pos.resize(1);
        singl.pos[0]=robposinfo;
        m_mcs->resultdata.P_data.push_back(singl);
        now_robPdata=m_mcs->resultdata.P_data.size()-1;
        msg=QStringLiteral("新建了P变量号")+"P["+QString::number(pId)+"]";
        ui->record->append(msg);
    }
    else
    {
        //找到了替换
        QString msg;
        rob_group singl;
        singl.pID=pId;
        singl.pos.resize(1);
        singl.pos[0]=robposinfo;
        m_mcs->resultdata.P_data[pnum]=singl;
        now_robPdata=pnum;
        msg=QStringLiteral("替换了P变量号")+"P["+QString::number(pId)+"]";
        ui->record->append(msg);
    }
    updataPdata();
    pullpData();
}

//删除P变量
void pshowdlg::on_pushButton_11_clicked()
{
    bool ok;
    int pId;
    int pnum;
    if(ui->piddelEdit->text().isEmpty())
    {
        ui->record->append(QStringLiteral("请填写要删除的P变量号"));
        return;
    }
    pId=ui->piddelEdit->text().toInt(&ok);
    if(ok==false)
    {
        ui->record->append(QStringLiteral("要删除的P变量号格式不正确"));
        return;
    }
    if(pId==0||pId==1||pId==2||pId==3||pId==11||pId==1000||pId==1001||pId==1002)
    {
        QString msg=QStringLiteral("不能删除的P变量号")+"P["+QString::number(pId)+"]"+QStringLiteral(",其为系统保留");
        ui->record->append(msg);
        return;
    }
    else if(pId<0||pId>65535)
    {
        ui->record->append(QStringLiteral("P变量号超出设置范围"));
        return;
    }
    if(0!=findpDataId(m_mcs->resultdata.P_data,pId,&pnum))
    {
        //找不到
        QString msg;
        msg=QStringLiteral("当前系统无P变量号")+"P["+QString::number(pId)+"]";
        ui->record->append(msg);
    }
    else
    {
        //找到了删除
        QString msg;
        m_mcs->resultdata.P_data.erase(m_mcs->resultdata.P_data.begin()+pnum);
        msg=QStringLiteral("删除了P变量号")+"P["+QString::number(pId)+"]";
        //如果当前选择的点在下方，则往上位移，如果移到0，则不再位移
        if(now_robPdata>=pnum)
        {
            now_robPdata=now_robPdata-1;
        }
        if(m_mcs->resultdata.P_data.size()>0&&now_robPdata<0)
        {
            now_robPdata=0;
        }
        ui->record->append(msg);
    }
    updataPdata();
    pullpData();
}

//点云工艺设置
void pshowdlg::on_pushButton_13_clicked()
{
    craftdlg->init_dlg_show();
    craftdlg->setWindowTitle(QStringLiteral("查看工艺参数"));
    craftdlg->exec();
    craftdlg->close_dlg_show();
    ui->craft_Id->setText(QString::number(m_mcs->resultdata.P_data_craftinfo.craft_Id));
}


void pshowdlg::on_robposlist_itemClicked(QListWidgetItem *item)
{
    now_robpos=ui->robposlist->currentRow();
}


void pshowdlg::on_leaserposlist_itemClicked(QListWidgetItem *item)
{
    now_leaserpos=ui->leaserposlist->currentRow();
}

void pshowdlg::on_robPdata_itemClicked(QListWidgetItem *item)
{
    now_robPdata=ui->robPdata->currentRow();
    ui->robPdatapoint->clear();
    for(int i=0;i<m_mcs->resultdata.P_data[now_robPdata].pos.size();i++)
    {
        QString msg;
        msg="pos["+QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].x,'f',3)+","+
                   QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].y,'f',3)+","+
                   QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].z,'f',3)+","+
                   QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].rx,'f',3)+","+
                   QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].ry,'f',3)+","+
                   QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].rz,'f',3)+
            "] out1["+QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].out1)+","+
                      QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].out2)+","+
                      QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].out3)+
            "] tool:"+QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].tool)+
            " tcp:"+QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].tcp)+
            " usertcp:"+QString::number(m_mcs->resultdata.P_data[now_robPdata].pos[i].usertcp);
        ui->robPdatapoint->addItem(msg);
    }
}

void pshowdlg::pulldemdl()
{
    QJsonObject jsent;
    QJsonObject json;
    QJsonArray jarry1,jarry2,jarry3,jarry4;
    for(int i=0;i<m_mcs->resultdata.pData_demdlg_R.size();i++)
    {
        jarry1.append(m_mcs->resultdata.pData_demdlg_R[i]);
    }
    json["pData_demdlg_R"]=jarry1;
    for(int i=0;i<m_mcs->resultdata.pData_demdlg_T.size();i++)
    {
        jarry2.append(m_mcs->resultdata.pData_demdlg_T[i]);
    }
    json["pData_demdlg_T"]=jarry2;
    for(int i=0;i<m_mcs->resultdata.pData_matrix_camera2plane.size();i++)
    {
        jarry3.append(m_mcs->resultdata.pData_matrix_camera2plane[i]);
    }
    json["pData_matrix_camera2plane"]=jarry3;
    for(int i=0;i<m_mcs->resultdata.pData_matrix_plane2robot.size();i++)
    {
        jarry4.append(m_mcs->resultdata.pData_matrix_plane2robot[i]);
    }
    json["pData_matrix_plane2robot"]=jarry4;

    QJsonObject js;
    for(int i=0;i<m_mcs->resultdata.P_data.size();i++)
    {
        QJsonArray jarry;
        int id=m_mcs->resultdata.P_data[i].pID;
        for(int j=0;j<m_mcs->resultdata.P_data[i].pos.size();j++)
        {
            QJsonObject pos;
            pos["x"]=m_mcs->resultdata.P_data[i].pos[j].x;
            pos["y"]=m_mcs->resultdata.P_data[i].pos[j].y;
            pos["z"]=m_mcs->resultdata.P_data[i].pos[j].z;
            pos["rx"]=m_mcs->resultdata.P_data[i].pos[j].rx;
            pos["ry"]=m_mcs->resultdata.P_data[i].pos[j].ry;
            pos["rz"]=m_mcs->resultdata.P_data[i].pos[j].rz;
            pos["out1"]=m_mcs->resultdata.P_data[i].pos[j].out1;
            pos["out2"]=m_mcs->resultdata.P_data[i].pos[j].out2;
            pos["out3"]=m_mcs->resultdata.P_data[i].pos[j].out3;
            pos["tool"]=m_mcs->resultdata.P_data[i].pos[j].tool;
            pos["tcp"]=m_mcs->resultdata.P_data[i].pos[j].tcp;
            pos["usertcp"]=m_mcs->resultdata.P_data[i].pos[j].usertcp;
            pos["uy"]=m_mcs->resultdata.P_data[i].pos[j].uy;
            pos["vz"]=m_mcs->resultdata.P_data[i].pos[j].vz;
            jarry.append(pos);
        }
        js[QString::number(id)]=jarry;
    }
    json["pData_point"]=js;


    jsent["echo"]=json;

    QString msg=JsonToQstring(jsent);
    QByteArray arry=msg.toUtf8();
    arry.push_back('\0');
    client->write(arry);
#if _MSC_VER
    _sleep(100);
#else
    usleep(100000);
#endif
}

void pshowdlg::pullpData()
{
    QJsonObject jsent;
    QJsonObject json;
    QJsonObject js;
    for(int i=0;i<m_mcs->resultdata.P_data.size();i++)
    {
        QJsonArray jarry;
        int id=m_mcs->resultdata.P_data[i].pID;
        for(int j=0;j<m_mcs->resultdata.P_data[i].pos.size();j++)
        {
            QJsonObject pos;
            pos["x"]=m_mcs->resultdata.P_data[i].pos[j].x;
            pos["y"]=m_mcs->resultdata.P_data[i].pos[j].y;
            pos["z"]=m_mcs->resultdata.P_data[i].pos[j].z;
            pos["rx"]=m_mcs->resultdata.P_data[i].pos[j].rx;
            pos["ry"]=m_mcs->resultdata.P_data[i].pos[j].ry;
            pos["rz"]=m_mcs->resultdata.P_data[i].pos[j].rz;
            pos["out1"]=m_mcs->resultdata.P_data[i].pos[j].out1;
            pos["out2"]=m_mcs->resultdata.P_data[i].pos[j].out2;
            pos["out3"]=m_mcs->resultdata.P_data[i].pos[j].out3;
            pos["tool"]=m_mcs->resultdata.P_data[i].pos[j].tool;
            pos["tcp"]=m_mcs->resultdata.P_data[i].pos[j].tcp;
            pos["usertcp"]=m_mcs->resultdata.P_data[i].pos[j].usertcp;
            pos["uy"]=m_mcs->resultdata.P_data[i].pos[j].uy;
            pos["vz"]=m_mcs->resultdata.P_data[i].pos[j].vz;
            jarry.append(pos);
        }
        js[QString::number(id)]=jarry;
    }
    json["pData_point"]=js;
    jsent["echo"]=json;

    QString msg=JsonToQstring(jsent);
    QByteArray arry=msg.toUtf8();
    arry.push_back('\0');
    client->write(arry);
}

QJsonObject pshowdlg::QstringToJson(QString jsonString)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toLocal8Bit().data());
    if(jsonDocument.isNull())
    {
        qDebug()<< "String NULL"<< jsonString.toLocal8Bit().data();
    }
    QJsonObject jsonObject = jsonDocument.object();
    return jsonObject;
}

QString pshowdlg::JsonToQstring(QJsonObject jsonObject)
{
    return QString(QJsonDocument(jsonObject).toJson());
}

pshowdlgThread::pshowdlgThread(pshowdlg *statci_p)
{
    _p=statci_p;
}

void pshowdlgThread::run()
{
    while (1)
    {
        if(_p->b_thread1==true)
        {
            if(_p->link_pshow_state==true)
            {
                int real_readnum_1=modbus_read_registers(_p->ctx_pshow,ALS_REALTIME_POSX_REG_ADD,0x15,_p->pos_data);
                int real_readnum_2=modbus_read_registers(_p->ctx_pshow,ALS_STATE_REG_ADD,0x3,_p->result_data);
                int real_readnum_3=modbus_read_registers(_p->ctx_pshow,ALS_P_REALTIME_POSX_REG_ADD,0x15,_p->p_pos_data);
                if(real_readnum_1==0x15&&real_readnum_2==0x03&&real_readnum_3==0x15)
                {
                    _p->getrobinfo();
                }
                if(_p->b_init_show_pshow_text_finish==true)
                {
                    _p->b_init_show_pshow_text_finish=false;
                    emit Send_show_pshow_text();
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

void pshowdlgThread::Stop()
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




