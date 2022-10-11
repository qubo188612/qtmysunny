﻿#include "soptocameratcpip.h"

#if _MSC_VER||WINDOWS_TCP

Soptocameratcpip::Soptocameratcpip()
{
    b_connect=false;
    luzhi=false;
    b_updataimage_finish=false;
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
    int codec=cv::VideoWriter::fourcc('X','V','I','D');
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
            int rcvnum=_p->m_client.Recv((char*)_p->rcv_buf,RECVBUFFER_MAX);
            if(rcvnum>0)
            {
                std::vector<uchar> decode;
                decode.insert(decode.end(),_p->rcv_buf,_p->rcv_buf+rcvnum);
              //image = cv::imdecode(decode, CV_LOAD_IMAGE_COLOR);//图像解码
                myimgtcp(decode,image);//图像自定义解码
                if(_p->b_int_show_image_inlab==false&&_p->b_updataimage_finish==false)
                {
                    if(!_p->cv_image.empty())
                    {
                        _p->b_int_show_image_inlab=true;
                    //  _p->cv_image=image;
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
        else
        {
            _p->b_stop_rcv_thread=true;
            break;
        }
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

int tcprcvThread::myimgtcp(std::vector<uchar> decode,cv::Mat &image)
{
    int cols,rows,channels;
    if(decode.size()<5)
        return 1;
    channels=decode[0];
    if(channels!=1&&channels!=3)
        return 1;
    cols=(((int)decode[1])<<8)+decode[2];
    rows=(((int)decode[3])<<8)+decode[4];
    if(decode.size()!=cols*rows*channels+5)
        return 1;
    switch(channels)
    {
        case 1:
            image=cv::Mat(rows,cols,CV_8UC1,decode.data()+5);
        break;
        case 3:
            image=cv::Mat(rows,cols,CV_8UC3,decode.data()+5);
        break;
    }
    _p->cv_image=image.clone();
    return 0;
}

#endif
