#include "soptopcamera.h"

Camshow::Camshow(SoptopCamera *statci_p): Node("my_eyes")
{
  _p=statci_p;

  _param_camera = std::make_shared<rclcpp::AsyncParametersClient>(this, "camera_tis_node");
  _param_camera_get = std::make_shared<rclcpp::SyncParametersClient>(this, "camera_tis_node");
  _param_gpio = std::make_shared<rclcpp::AsyncParametersClient>(this, "gpio_raspberry_node");
/*
  _p->roscmd_open_laser(true);  //激光打开
  _p->roscmd_open_camera(true); //相机打开
  _p->roscmd_set_exposure(_p->i32_exposure); //应用相机曝光
*/ 
/*
  ros_open_laser(true);  //激光打开
  ros_open_camera(true); //相机打开
  ros_set_exposure(_p->i32_exposure); //应用相机曝光
*/
//ros_get_exposure(&_p->i32_exposure);//获取相机曝光
#ifdef DEBUG_MYINTERFACES
  subscription_ = this->create_subscription<tutorial_interfaces::msg::IfAlgorhmitmsg>(
        "/laser_imagepos_node/result", rclcpp::SensorDataQoS(), std::bind(&Camshow::topic_callback, this, _1));
#else
  subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
        "/rotate_image_node/image_rotated", rclcpp::SensorDataQoS(), std::bind(&Camshow::topic_callback, this, _1));
#endif
}

Camshow::~Camshow()
{

}

#ifdef DEBUG_MYINTERFACES
    void Camshow::topic_callback(const tutorial_interfaces::msg::IfAlgorhmitmsg msg)  const
    {
      if(_p->b_connect==true)
      { 
        _p->cv_ptr = cv_bridge::toCvCopy(msg.imageout, msg.imageout.encoding);
        if(!_p->cv_ptr->image.empty())
        {
            _p->cv_image=_p->cv_ptr->image;
            _p->b_updataimage_finish=true;
            _p->callbacknumber++;
            if(_p->luzhi==true)
            {
                _p->writer << _p->cv_ptr->image;
            }
        }
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
#else
    void Camshow::topic_callback(const sensor_msgs::msg::Image msg)  const
    {
      if(_p->b_connect==true)
      {
        cv_bridge::CvImagePtr cv_ptr;
        cv_ptr = cv_bridge::toCvCopy(msg, "mono8");
        if(!cv_ptr->image.empty())
        {
            (_p->cv_image)=cv_ptr->image.clone();
            _p->b_updataimage_finish=true;
            _p->callbacknumber++;
            if(_p->luzhi==true)
            {
                _p->writer << cv_ptr->image;
            }
        }
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
#endif

void Camshow::ros_open_laser(bool b)
{
    if(b==false)
        _param_gpio->set_parameters({rclcpp::Parameter("laser", false)});  //激光关闭
    else if(b==true)
        _param_gpio->set_parameters({rclcpp::Parameter("laser", true)});    //激光打开
}

void Camshow::ros_open_camera(bool b)
{
    if(b==false)
        _param_camera->set_parameters({rclcpp::Parameter("power", false)});  //相机关闭
    else if(b==true)
        _param_camera->set_parameters({rclcpp::Parameter("power", true)});    //相机打开
}

void Camshow::ros_set_exposure(int exposure)
{
    _param_camera->set_parameters({rclcpp::Parameter("exposure_time", exposure)});
}

int Camshow::ros_get_exposure(int *exposure)
{
    const std::vector<std::string> KEYS2 = {"exposure_time"};
    _param_camera_get->wait_for_service();
    auto vp = _param_camera_get->get_parameters(KEYS2);
    for (auto & p : vp)
    {
        if (p.get_name() == "exposure_time")
        {
            auto k = p.as_int();
            *exposure=k;
            return 0;
        }
    }
    return -1;
}

SoptopCamera::SoptopCamera()
{
  i32_exposure_min=SOPTOPCAM_EXPOSURE_MIN;
  i32_exposure_max=SOPTOPCAM_EXPOSURE_MAX;
  i32_exposure_use=SOPTOPCAM_EXPOSURE_USE;

  read_para();

  b_connect=false;
  stop_b_connect=true;
  b_updataimage_finish=false;
  StartCamera_thread = new StartCameraThread(this);
  callbacknumber=0;
  oldcallbacknumber=0;
  callback_error=0;
  luzhi=false;
}

SoptopCamera::~SoptopCamera()
{
  StartCamera_thread->quit();
  StartCamera_thread->wait();
  delete StartCamera_thread;
  StartCamera_thread=NULL;
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
  switch (cv_image.type())
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
  QImage img = QImage((const uchar*)cv_image.data, cv_image.cols, cv_image.rows,
  cv_image.cols * cv_image.channels(), format);
  img = img.scaled(m_lab_show->width(),m_lab_show->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//图片自适应lab大小
  m_lab_show->setPixmap(QPixmap::fromImage(img));
}

double SoptopCamera::Getfps()
{
    return 50.0;
}

void SoptopCamera::StartRecord(QString filename)//开始录制视频
{
    bool isColor = (cv_image.type()==CV_8UC3);
    double fps     = Getfps();
    int frameW  = cv_image.cols;
    int frameH  = cv_image.rows;
    int codec=cv::VideoWriter::fourcc('X','V','I','D');
    writer.open(filename.toStdString(),codec,fps,cv::Size(frameW,frameH),isColor);
    luzhi=true;
}

void SoptopCamera::StopRecord()//停止录制视频
{
    luzhi=false;
    writer.release();
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


