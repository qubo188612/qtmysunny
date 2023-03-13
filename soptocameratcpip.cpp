﻿#include "soptocameratcpip.h"

#if _MSC_VER||WINDOWS_TCP

#ifdef DEBUG_CLOUD_TCP
QMutex mutex_IfAlgorhmitcloud;
#endif

Soptocameratcpip::Soptocameratcpip()
{
    b_connect=false;
    luzhi=false;
    b_updataimage_finish=false;
    b_updatacloud_finish=false;
    b_int_show_image_inlab=false;
    callbacknumber=0;
    rcv_buf=new uchar[RECVBUFFER_MAX];

    b_rcv_thread=false;
    b_stop_rcv_thread=false;
    rcv_thread = new tcprcvThread(this);
}

Soptocameratcpip::~Soptocameratcpip()
{
    delete []rcv_buf;
}

void Soptocameratcpip::InitConnect(PictureBox *lab_show,QString hostName, int port)
{
    if(b_connect==false)
    {
      m_lab_show=lab_show;
      std::string str = hostName.toStdString();
      const char* ch = str.c_str();
      m_client.CreateSocket();
      m_client.Connect(ch,port);
      m_client.SetBlock(0);
      if(0!=m_client.SetRcvBufferlong(RECVBUFFER_MAX))
      {
          printf("SetRcvBufferlong false");
      }
      char data[1]={1};
      m_client.Send(data,1);
      b_rcv_thread=true;
      rcv_thread->start();
      connect_mod=0;
      b_connect=true;
    }
}

void Soptocameratcpip::InitConnect_cloud(QString hostName,int port)
{
    if(b_connect==false)
    {
      std::string str = hostName.toStdString();
      const char* ch = str.c_str();
      m_client.CreateSocket();
      m_client.Connect(ch,port);
      m_client.SetBlock(0);
      if(0!=m_client.SetRcvBufferlong(RECVBUFFER_MAX))
      {
          printf("SetRcvBufferlong false");
      }
      char data[1]={1};
      m_client.Send(data,1);
      b_rcv_thread=true;
      rcv_thread->start();
      connect_mod=1;
      b_connect=true;
    }
}

void Soptocameratcpip::DisConnect()
{
    if(b_connect==true)
    {
      char data[1]={0};
      m_client.Send(data,1);
#if _MSC_VER
      _sleep(50);
#else
      usleep(50000);
#endif
      rcv_thread->Stop();
      rcv_thread->quit();
      rcv_thread->wait();
      m_client.Close();
      b_connect=false;
    }
}

void Soptocameratcpip::StartRecord(QString filename)
{
    bool isColor = (cv_image.type()==CV_8UC3);
    double fps     = Getfps();
    int frameW  = cv_image.cols;
    int frameH  = cv_image.rows;
    int codec=cv::VideoWriter::fourcc('M','J','P','G');
    writer.open(filename.toStdString(),codec,fps,cv::Size(frameW,frameH),isColor);
    luzhi=true;
}

void Soptocameratcpip::StopRecord()
{
    luzhi=false;
    writer.release();
}

double Soptocameratcpip::Getfps()
{
    return 50.0;
}

QJsonObject Soptocameratcpip::QstringToJson(QString jsonString)
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toLocal8Bit().data());
    if(jsonDocument.isNull())
    {
        qDebug()<< "String NULL"<< jsonString.toLocal8Bit().data();
    }
    QJsonObject jsonObject = jsonDocument.object();
    return jsonObject;
}

QString Soptocameratcpip::JsonToQstring(QJsonObject jsonObject)
{
    return QString(QJsonDocument(jsonObject).toJson());
}

tcprcvThread::tcprcvThread(Soptocameratcpip *statci_p)
{
    _p=statci_p;
}

void tcprcvThread::run()
{
    while (1)
    {
        if(_p->b_rcv_thread==true)
        {
            if(_p->connect_mod==0)
            {
                int rcvnum=_p->m_client.Recv((char*)_p->rcv_buf,RECVBUFFER_MAX);
                if(rcvnum>0)
                {
                    std::vector<uchar> decode;
                    decode.insert(decode.end(),_p->rcv_buf,_p->rcv_buf+rcvnum);
                    _p->cv_image = cv::imdecode(decode, CV_LOAD_IMAGE_COLOR);//图像解码

                    if(_p->b_int_show_image_inlab==false&&_p->b_updataimage_finish==false)
                    {
                        if(!_p->cv_image.empty())
                        {
                            _p->b_int_show_image_inlab=true;
                            _p->b_updataimage_finish=true;
                            _p->callbacknumber++;
                            if(_p->luzhi==true)
                            {
                                _p->writer << _p->cv_image;
                            }
                        }
                    }
                }
            }
        #ifdef DEBUG_CLOUD_TCP
            else if(_p->connect_mod==1)
            {
                int rcvnum=_p->m_client.Recv((char*)_p->rcv_buf,RECVBUFFER_MAX);
                if(rcvnum>0)
                {
                    mutex_IfAlgorhmitcloud.lock();//锁住线程，防止在修改IfAlgorhmitcloud内存时被其他线程调用
                    _p->rcv_buf[rcvnum]='\0';
                    QString msg=QString::fromLocal8Bit((char*)_p->rcv_buf);
                    QJsonObject json=_p->QstringToJson(msg);
                    QJsonObject header=json["header"].toObject();
                    QJsonObject stamp=header["stamp"].toObject();
                    _p->IfAlgorhmitcloud.header.stamp.sec=stamp["sec"].toInt();
                    _p->IfAlgorhmitcloud.header.stamp.nanosec=stamp["nanosec"].toInt();
                    _p->IfAlgorhmitcloud.header.frame_id=header["frame_id"].toString();
                    QJsonArray lasertrackoutcloud=json["lasertrackoutcloud"].toArray();
                    _p->IfAlgorhmitcloud.lasertrackoutcloud.resize(lasertrackoutcloud.size());
                    for(int i=0;i<lasertrackoutcloud.size();i++)
                    {
                        QJsonObject qtask=lasertrackoutcloud[i].toObject();
                        _p->IfAlgorhmitcloud.lasertrackoutcloud[i].x=qtask["x"].toDouble();
                        _p->IfAlgorhmitcloud.lasertrackoutcloud[i].y=qtask["y"].toDouble();
                        _p->IfAlgorhmitcloud.lasertrackoutcloud[i].u=qtask["u"].toInt();
                        _p->IfAlgorhmitcloud.lasertrackoutcloud[i].v=qtask["v"].toInt();
                    }
                    QJsonArray targetpointoutcloud=json["targetpointoutcloud"].toArray();
                    _p->IfAlgorhmitcloud.targetpointoutcloud.resize(targetpointoutcloud.size());
                    for(int i=0;i<targetpointoutcloud.size();i++)
                    {
                        QJsonObject qtask=targetpointoutcloud[i].toObject();
                        _p->IfAlgorhmitcloud.targetpointoutcloud[i].x=qtask["x"].toDouble();
                        _p->IfAlgorhmitcloud.targetpointoutcloud[i].y=qtask["y"].toDouble();
                        _p->IfAlgorhmitcloud.targetpointoutcloud[i].u=qtask["u"].toInt();
                        _p->IfAlgorhmitcloud.targetpointoutcloud[i].v=qtask["v"].toInt();
                        _p->IfAlgorhmitcloud.targetpointoutcloud[i].name=qtask["name"].toString();
                    }
                    _p->IfAlgorhmitcloud.solderjoints=json["solderjoints"].toBool();
                    _p->b_updatacloud_finish=true;
                    mutex_IfAlgorhmitcloud.unlock();//解锁线程
                }
            }
        #endif
        }
        else
        {
            _p->b_stop_rcv_thread=true;
            break;
        }
        sleep(0);
    }
}

void tcprcvThread::Stop()
{
  if(_p->b_rcv_thread==true)
  {
    _p->b_stop_rcv_thread=false;
    _p->b_rcv_thread=false;
    while (_p->b_stop_rcv_thread==false)
    {
      sleep(0);
    }
  }
}



#endif
