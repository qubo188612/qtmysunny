#include "E2proomData.h"

E2proomData::E2proomData()
{
#if _MSC_VER
    QString filePath =  "./SAVE";
    QDir dir(filePath);
    if(!dir.exists())
        QDir().mkdir(filePath);
#else
    std::string dir = "./SAVE";
    if (access(dir.c_str(), 0) == -1)
    {
      mkdir("./SAVE",S_IRWXU);
    }
#endif

    camdlg_modposX1_min=E2POOM_CAMDLG_MODPOSX1_MIN;
    camdlg_modposX1_max=E2POOM_CAMDLG_MODPOSX1_MAX;
    camdlg_modposX1_use=E2POOM_CAMDLG_MODPOSX1_USE;
    camdlg_modposY1_min=E2POOM_CAMDLG_MODPOSY1_MIN;
    camdlg_modposY1_max=E2POOM_CAMDLG_MODPOSY1_MAX;
    camdlg_modposY1_use=E2POOM_CAMDLG_MODPOSY1_USE;
    camdlg_modposX2_min=E2POOM_CAMDLG_MODPOSX2_MIN;
    camdlg_modposX2_max=E2POOM_CAMDLG_MODPOSX2_MAX;
    camdlg_modposX2_use=E2POOM_CAMDLG_MODPOSX2_USE;
    camdlg_modposY2_min=E2POOM_CAMDLG_MODPOSY2_MIN;
    camdlg_modposY2_max=E2POOM_CAMDLG_MODPOSY2_MAX;
    camdlg_modposY2_use=E2POOM_CAMDLG_MODPOSY2_USE;
    camdlg_modposX3_min=E2POOM_CAMDLG_MODPOSX3_MIN;
    camdlg_modposX3_max=E2POOM_CAMDLG_MODPOSX3_MAX;
    camdlg_modposX3_use=E2POOM_CAMDLG_MODPOSX3_USE;
    camdlg_modposY3_min=E2POOM_CAMDLG_MODPOSY3_MIN;
    camdlg_modposY3_max=E2POOM_CAMDLG_MODPOSY3_MAX;
    camdlg_modposY3_use=E2POOM_CAMDLG_MODPOSY3_USE;
    camdlg_modposX4_min=E2POOM_CAMDLG_MODPOSX4_MIN;
    camdlg_modposX4_max=E2POOM_CAMDLG_MODPOSX4_MAX;
    camdlg_modposX4_use=E2POOM_CAMDLG_MODPOSX4_USE;
    camdlg_modposY4_min=E2POOM_CAMDLG_MODPOSY4_MIN;
    camdlg_modposY4_max=E2POOM_CAMDLG_MODPOSY4_MAX;
    camdlg_modposY4_use=E2POOM_CAMDLG_MODPOSY4_USE;

    camdlg_cvimg_posX1_min=E2POOM_CAMDLG_CVIMG_POSX1_MIN;
    camdlg_cvimg_posX1_max=E2POOM_CAMDLG_CVIMG_POSX1_MAX;
    camdlg_cvimg_posX1_use=E2POOM_CAMDLG_CVIMG_POSX1_USE;
    camdlg_cvimg_posY1_min=E2POOM_CAMDLG_CVIMG_POSY1_MIN;
    camdlg_cvimg_posY1_max=E2POOM_CAMDLG_CVIMG_POSY1_MAX;
    camdlg_cvimg_posY1_use=E2POOM_CAMDLG_CVIMG_POSY1_USE;
    camdlg_cvimg_posX2_min=E2POOM_CAMDLG_CVIMG_POSX2_MIN;
    camdlg_cvimg_posX2_max=E2POOM_CAMDLG_CVIMG_POSX2_MAX;
    camdlg_cvimg_posX2_use=E2POOM_CAMDLG_CVIMG_POSX2_USE;
    camdlg_cvimg_posY2_min=E2POOM_CAMDLG_CVIMG_POSY2_MIN;
    camdlg_cvimg_posY2_max=E2POOM_CAMDLG_CVIMG_POSY2_MAX;
    camdlg_cvimg_posY2_use=E2POOM_CAMDLG_CVIMG_POSY2_USE;
    camdlg_cvimg_posX3_min=E2POOM_CAMDLG_CVIMG_POSX3_MIN;
    camdlg_cvimg_posX3_max=E2POOM_CAMDLG_CVIMG_POSX3_MAX;
    camdlg_cvimg_posX3_use=E2POOM_CAMDLG_CVIMG_POSX3_USE;
    camdlg_cvimg_posY3_min=E2POOM_CAMDLG_CVIMG_POSY3_MIN;
    camdlg_cvimg_posY3_max=E2POOM_CAMDLG_CVIMG_POSY3_MAX;
    camdlg_cvimg_posY3_use=E2POOM_CAMDLG_CVIMG_POSY3_USE;
    camdlg_cvimg_posX4_min=E2POOM_CAMDLG_CVIMG_POSX4_MIN;
    camdlg_cvimg_posX4_max=E2POOM_CAMDLG_CVIMG_POSX4_MAX;
    camdlg_cvimg_posX4_use=E2POOM_CAMDLG_CVIMG_POSX4_USE;
    camdlg_cvimg_posY4_min=E2POOM_CAMDLG_CVIMG_POSY4_MIN;
    camdlg_cvimg_posY4_max=E2POOM_CAMDLG_CVIMG_POSY4_MAX;
    camdlg_cvimg_posY4_use=E2POOM_CAMDLG_CVIMG_POSY4_USE;

    read_para();
}

E2proomData::~E2proomData()
{

}

void E2proomData::check_para()
{
    if(camdlg_modposX1<camdlg_modposX1_min||camdlg_modposX1>camdlg_modposX1_max)
        camdlg_modposX1=camdlg_modposX1_use;
    if(camdlg_modposY1<camdlg_modposY1_min||camdlg_modposY1>camdlg_modposY1_max)
        camdlg_modposY1=camdlg_modposY1_use;
    if(camdlg_modposX2<camdlg_modposX2_min||camdlg_modposX2>camdlg_modposX2_max)
        camdlg_modposX2=camdlg_modposX2_use;
    if(camdlg_modposY2<camdlg_modposY2_min||camdlg_modposY2>camdlg_modposY2_max)
        camdlg_modposY2=camdlg_modposY2_use;
    if(camdlg_modposX3<camdlg_modposX3_min||camdlg_modposX3>camdlg_modposX3_max)
        camdlg_modposX3=camdlg_modposX3_use;
    if(camdlg_modposY3<camdlg_modposY3_min||camdlg_modposY3>camdlg_modposY3_max)
        camdlg_modposY3=camdlg_modposY3_use;
    if(camdlg_modposX4<camdlg_modposX4_min||camdlg_modposX4>camdlg_modposX4_max)
        camdlg_modposX4=camdlg_modposX4_use;
    if(camdlg_modposY4<camdlg_modposY4_min||camdlg_modposY4>camdlg_modposY4_max)
        camdlg_modposY4=camdlg_modposY4_use;
    if(camdlg_cvimg_posX1<camdlg_cvimg_posX1_min||camdlg_cvimg_posX1>camdlg_cvimg_posX1_max)
        camdlg_cvimg_posX1=camdlg_cvimg_posX1_use;
    if(camdlg_cvimg_posY1<camdlg_cvimg_posY1_min||camdlg_cvimg_posY1>camdlg_cvimg_posY1_max)
        camdlg_cvimg_posY1=camdlg_cvimg_posY1_use;
    if(camdlg_cvimg_posX2<camdlg_cvimg_posX2_min||camdlg_cvimg_posX2>camdlg_cvimg_posX2_max)
        camdlg_cvimg_posX2=camdlg_cvimg_posX2_use;
    if(camdlg_cvimg_posY2<camdlg_cvimg_posY2_min||camdlg_cvimg_posY2>camdlg_cvimg_posY2_max)
        camdlg_cvimg_posY2=camdlg_cvimg_posY2_use;
    if(camdlg_cvimg_posX3<camdlg_cvimg_posX3_min||camdlg_cvimg_posX3>camdlg_cvimg_posX3_max)
        camdlg_cvimg_posX3=camdlg_cvimg_posX3_use;
    if(camdlg_cvimg_posY3<camdlg_cvimg_posY3_min||camdlg_cvimg_posY3>camdlg_cvimg_posY3_max)
        camdlg_cvimg_posY3=camdlg_cvimg_posY3_use;
    if(camdlg_cvimg_posX4<camdlg_cvimg_posX4_min||camdlg_cvimg_posX4>camdlg_cvimg_posX4_max)
        camdlg_cvimg_posX4=camdlg_cvimg_posX4_use;
    if(camdlg_cvimg_posY4<camdlg_cvimg_posY4_min||camdlg_cvimg_posY4>camdlg_cvimg_posY4_max)
        camdlg_cvimg_posY4=camdlg_cvimg_posY4_use;
}

void E2proomData::read_para()
{
    read_camdlg_para();
    read_sunnydlg_para();
    read_sshdlg_para();
    check_para();
}

void E2proomData::write_camdlg_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_CAMDLG_SAVEBUFF];
    if(buff==NULL)
      return;

    Int32 *i32_p;

    i32_p = (Int32*)buff;
    *i32_p=camdlg_modposX1;
    i32_p++;
    *i32_p=camdlg_modposY1;
    i32_p++;
    *i32_p=camdlg_modposX2;
    i32_p++;
    *i32_p=camdlg_modposY2;
    i32_p++;
    *i32_p=camdlg_modposX3;
    i32_p++;
    *i32_p=camdlg_modposY3;
    i32_p++;
    *i32_p=camdlg_modposX4;
    i32_p++;
    *i32_p=camdlg_modposY4;
    i32_p++;
    *i32_p=camdlg_cvimg_posX1;
    i32_p++;
    *i32_p=camdlg_cvimg_posY1;
    i32_p++;
    *i32_p=camdlg_cvimg_posX2;
    i32_p++;
    *i32_p=camdlg_cvimg_posY2;
    i32_p++;
    *i32_p=camdlg_cvimg_posX3;
    i32_p++;
    *i32_p=camdlg_cvimg_posY3;
    i32_p++;
    *i32_p=camdlg_cvimg_posX4;
    i32_p++;
    *i32_p=camdlg_cvimg_posY4;
    i32_p++;

    fo.WriteFile((char*)E2POOM_CAMDLG_SYSPATH_MOTO,buff,E2POOM_CAMDLG_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::read_camdlg_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_CAMDLG_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile((char*)E2POOM_CAMDLG_SYSPATH_MOTO,buff,E2POOM_CAMDLG_SAVEBUFF))
    {
        init_camdlg_para();
        if(buff!=NULL)
        {
          delete []buff;
          buff=NULL;
        }
    }
    else
    {
      Int32 *i32_p;

      i32_p = (Int32*)buff;
      camdlg_modposX1=*i32_p;
      i32_p++;
      camdlg_modposY1=*i32_p;
      i32_p++;
      camdlg_modposX2=*i32_p;
      i32_p++;
      camdlg_modposY2=*i32_p;
      i32_p++;
      camdlg_modposX3=*i32_p;
      i32_p++;
      camdlg_modposY3=*i32_p;
      i32_p++;
      camdlg_modposX4=*i32_p;
      i32_p++;
      camdlg_modposY4=*i32_p;
      i32_p++;
      camdlg_cvimg_posX1=*i32_p;
      i32_p++;
      camdlg_cvimg_posY1=*i32_p;
      i32_p++;
      camdlg_cvimg_posX2=*i32_p;
      i32_p++;
      camdlg_cvimg_posY2=*i32_p;
      i32_p++;
      camdlg_cvimg_posX3=*i32_p;
      i32_p++;
      camdlg_cvimg_posY3=*i32_p;
      i32_p++;
      camdlg_cvimg_posX4=*i32_p;
      i32_p++;
      camdlg_cvimg_posY4=*i32_p;
      i32_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_camdlg_para()
{
    camdlg_modposX1=camdlg_modposX1_use;
    camdlg_modposY1=camdlg_modposY1_use;
    camdlg_modposX2=camdlg_modposX2_use;
    camdlg_modposY2=camdlg_modposY2_use;
    camdlg_modposX3=camdlg_modposX3_use;
    camdlg_modposY3=camdlg_modposY3_use;
    camdlg_modposX4=camdlg_modposX4_use;
    camdlg_modposY4=camdlg_modposY4_use;
    camdlg_cvimg_posX1=camdlg_cvimg_posX1_use;
    camdlg_cvimg_posY1=camdlg_cvimg_posY1_use;
    camdlg_cvimg_posX2=camdlg_cvimg_posX2_use;
    camdlg_cvimg_posY2=camdlg_cvimg_posY2_use;
    camdlg_cvimg_posX3=camdlg_cvimg_posX3_use;
    camdlg_cvimg_posY3=camdlg_cvimg_posY3_use;
    camdlg_cvimg_posX4=camdlg_cvimg_posX4_use;
    camdlg_cvimg_posY4=camdlg_cvimg_posY4_use;
}

void E2proomData::write_sunnydlg_para()
{
    QVariantHash data=sunnydlg_enjson();

    QJsonObject rootObj = QJsonObject::fromVariantHash(data);
    QJsonDocument document;
    document.setObject(rootObj);

    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QString json_str(byte_array);
    //根据实际填写路径
    QFile file(E2POOM_SUNNYDLG_SYSPATH_MOTO);

    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "file error!";
        return;
    }
    QTextStream in(&file);
    in << json_str;

    file.close();   // 关闭file

    return;
}

void E2proomData::read_sunnydlg_para()
{
    QFile loadFile(E2POOM_SUNNYDLG_SYSPATH_MOTO);

    if (!loadFile.open(QIODevice::ReadOnly))
    {
        init_sunnydlg_para();
        return;
    }

    QByteArray allData = loadFile.readAll();
    loadFile.close();

    if(0!=sunnydlg_dejson(allData))
    {
        init_sunnydlg_para();
        return;
    }
}

void E2proomData::init_sunnydlg_para()
{
    sunnydlg_ipaddress="192.168.1.2";
}

QVariantHash E2proomData::sunnydlg_enjson()
{
    QVariantHash data;
    data.insert("sunnydlg_ipaddress", sunnydlg_ipaddress);

    return data;
}

int E2proomData::sunnydlg_dejson(QByteArray allData)
{
    QJsonParseError json_error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(allData, &json_error));

    if (json_error.error != QJsonParseError::NoError)
    {
        qDebug() << "JSON error!";
        return 1;
    }

    QJsonObject rootObj = jsonDoc.object();
    QJsonObject::Iterator it;
    for(it=rootObj.begin();it!=rootObj.end();it++)//遍历Key
    {
        QString keyString=it.key();
        if(keyString=="sunnydlg_ipaddress")//相机
        {
            sunnydlg_ipaddress=it.value().toString();
        }
    }

    return 0;
}

void E2proomData::write_sshdlg_para()
{
    QVariantHash data=sshdlg_enjson();

    QJsonObject rootObj = QJsonObject::fromVariantHash(data);
    QJsonDocument document;
    document.setObject(rootObj);

    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QString json_str(byte_array);
    //根据实际填写路径
    QFile file(E2POOM_SSHDLG_SYSPATH_MOTO);

    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "file error!";
        return;
    }
    QTextStream in(&file);
    in << json_str;

    file.close();   // 关闭file

    return;
}

void E2proomData::read_sshdlg_para()
{
    QFile loadFile(E2POOM_SSHDLG_SYSPATH_MOTO);

    if (!loadFile.open(QIODevice::ReadOnly))
    {
        init_sshdlg_para();
        return;
    }

    QByteArray allData = loadFile.readAll();
    loadFile.close();

    if(0!=sshdlg_dejson(allData))
    {
        init_sshdlg_para();
        return;
    }
}

void E2proomData::init_sshdlg_para()
{
    sshdlg_usename="pi";
    sshdlg_password="123456";
}

QVariantHash E2proomData::sshdlg_enjson()
{
    QVariantHash data;
    data.insert("sshdlg_usename", sshdlg_usename);
    data.insert("sshdlg_password", sshdlg_password);

    return data;
}

int E2proomData::sshdlg_dejson(QByteArray allData)
{
    QJsonParseError json_error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(allData, &json_error));

    if (json_error.error != QJsonParseError::NoError)
    {
        qDebug() << "JSON error!";
        return 1;
    }

    QJsonObject rootObj = jsonDoc.object();
    QJsonObject::Iterator it;
    for(it=rootObj.begin();it!=rootObj.end();it++)//遍历Key
    {
        QString keyString=it.key();
        if(keyString=="sshdlg_usename")//相机
        {
            sshdlg_usename=it.value().toString();
        }
        if(keyString=="sshdlg_password")//相机
        {
            sshdlg_password=it.value().toString();
        }
    }

    return 0;
}
