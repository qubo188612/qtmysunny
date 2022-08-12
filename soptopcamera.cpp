#include "soptopcamera.h"

Camshow::Camshow(SoptopCamera *statci_p): Node("my_eyes")
{
  _p=statci_p;
/*
  _p->roscmd_open_laser(true);  //激光打开
  _p->roscmd_open_camera(true); //相机打开
  _p->roscmd_set_exposure(_p->i32_exposure); //应用相机曝光
*/
  subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
        "/rotate_image_node/image_rotated", rclcpp::SensorDataQoS(), std::bind(&Camshow::topic_callback, this, _1));
}

Camshow::~Camshow()
{

}

void Camshow::topic_callback(const sensor_msgs::msg::Image msg)  const
{
  if(_p->b_connect==true)
  {
    cv_bridge::CvImagePtr cv_ptr;
    cv_ptr = cv_bridge::toCvCopy(msg, "mono8");
    *(_p->cv_image)=cv_ptr->image.clone();
    _p->b_updataimage_finish=true;
    _p->callbacknumber++;
  }
  else
  {/*
    _p->roscmd_open_laser(false);  //激光打开
    _p->roscmd_open_camera(false); //相机打开
   */
    rclcpp::shutdown();
    _p->stop_b_connect=true;
  }
}

SoptopCamera::SoptopCamera()
{
  i32_exposure_min=SOPTOPCAM_EXPOSURE_MIN;
  i32_exposure_max=SOPTOPCAM_EXPOSURE_MAX;
  i32_exposure_use=SOPTOPCAM_EXPOSURE_USE;

  read_para();

  cv_image=new cv::Mat;
  b_connect=false;
  stop_b_connect=true;
  b_updataimage_finish=false;
  StartCamera_thread = new StartCameraThread(this);
  callbacknumber=0;
  oldcallbacknumber=0;
  callback_error=0;
}

SoptopCamera::~SoptopCamera()
{
  StartCamera_thread->quit();
  StartCamera_thread->wait();
  delete StartCamera_thread;
  StartCamera_thread=NULL;
  delete cv_image;
}

void SoptopCamera::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==timerid1)
    {
        if(b_connect==true||stop_b_connect==false)
        {
            if(callbacknumber==oldcallbacknumber)
            {
                callback_error=1;
            }
            else
            {
                callback_error=0;
            }
            oldcallbacknumber=callbacknumber;
        }
    }
}

void SoptopCamera::read_para()
{
    uint8_t *buff=new uint8_t[SOPTOPCAM_SAVEBUFF];
    if(buff==NULL)
    {
      init_para();
      return;
    }
    CFileOut fo;
    if(0 > fo.ReadFile(SOPTOPCAM_SYSPATH_MOTO,buff,SOPTOPCAM_SAVEBUFF))
    {
      init_para();
      return;
    }
    int32_t *i32_p;
    i32_p = (int32_t*)buff;
    i32_exposure = *i32_p;
    i32_p++;

    delete[] buff;
}

void SoptopCamera::write_para()
{
    check_para();
    uint8_t *buff=new uint8_t[SOPTOPCAM_SAVEBUFF];
    if(buff==NULL)
      return;

    int32_t *i32_p;

    i32_p = (int32_t*)buff;
    *i32_p = i32_exposure;
    i32_p ++;

    CFileOut fo;
    fo.WriteFile(SOPTOPCAM_SYSPATH_MOTO,buff,SOPTOPCAM_SAVEBUFF);

    if(buff!=NULL)
      delete []buff;
}

void SoptopCamera::check_para()
{
    if(i32_exposure<i32_exposure_min||i32_exposure>i32_exposure_max)
    {
      i32_exposure=i32_exposure_use;
    }
}

void SoptopCamera::init_para()
{
    i32_exposure=i32_exposure_use;
}

void SoptopCamera::InitConnect(QLabel *lab_show)
{
  if(b_connect==false)
  {
    callbacknumber=0;
    oldcallbacknumber=0;
    timerid1 = startTimer(1000);
    m_lab_show=lab_show;
    b_connect=true;
    StartCamera_thread->start();
  }
}

void SoptopCamera::DisConnect()
{
  if(b_connect==true)
  {  
    stop_b_connect=false;
    b_connect=false;
    while (stop_b_connect==false)
    {
      QThread::sleep(0);
      if(callback_error==1)//相机卡住了，强制退出ROS
      {
          rclcpp::shutdown();
          stop_b_connect=true;
          break;
      }
    }
    killTimer(timerid1);
  }
}

void SoptopCamera::roscmd_set_exposure(int exposure)
{
  if(b_connect==true)
  {
    QString array="ros2 param set /camera_tis_node exposure_time ";
    QString data=QString::number(exposure);
    array=array+data;
    system(array.toUtf8());
  }
}

int SoptopCamera::roscmd_get_exposure(int *exposure)
{
    if(b_connect==true)
    {
      QString array="ros2 param get /camera_tis_node exposure_time ";
    //  system(array.toUtf8());
      QProcess process;
      process.start(array);
      process.waitForFinished();
      QString result = process.readAllStandardOutput();
      if(result.size()>0)
      {
          QString msg="Integer value is: ";
          if(result.contains(msg,Qt::CaseSensitive))
          {
              //正确值
              int a = result.indexOf(msg);//定位
              int b = result.indexOf("\n",a+msg.size());
              QString data = result.mid(a+msg.size(),b-a-msg.size());
              *exposure=data.toInt();
          }
          else
          {
              return 1;
          }
      }
    }
    return 0;
}

void SoptopCamera::roscmd_open_laser(bool b)
{
    if(b==false)
        system("ros2 param set gpio_raspberry_node laser False");  //激光关闭
    else if(b==true)
        system("ros2 param set gpio_raspberry_node laser True");    //激光打开
}

void SoptopCamera::roscmd_open_camera(bool b)
{
    if(b==false)
        system("ros2 param set /camera_tis_node power False");  //相机关闭
    else if(b==true)
        system("ros2 param set /camera_tis_node power True");    //相机打开
}

void SoptopCamera::int_show_image_inlab()
{
  QImage::Format format = QImage::Format_RGB888;
  switch (cv_image->type())
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
  QImage img = QImage((const uchar*)cv_image->data, cv_image->cols, cv_image->rows,
  cv_image->cols * cv_image->channels(), format);
  img = img.scaled(m_lab_show->width(),m_lab_show->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//图片自适应lab大小
  m_lab_show->setPixmap(QPixmap::fromImage(img));
}

StartCameraThread::StartCameraThread(SoptopCamera *statci_p)
{
  _p=statci_p;
}

void StartCameraThread::run()
{
  if(_p->b_connect==true)
  {
    rclcpp::init(_p->argc,_p->argv);
    rclcpp::spin(std::make_shared<Camshow>(_p));
  }
}


