#include <QApplication>
#include "qtmysunnydlg.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if _MSC_VER
    QTextCodec *codec = QTextCodec::codecForName("GBK");
#else
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
#endif
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#endif
    qtmysunnyDlg main_window;
    main_window.setWindowTitle(QString::fromLocal8Bit("3D激光跟踪参数设置软件"));
#if _MSC_VER||WINDOWS_TCP
#else
    main_window.m_mcs->cam->sop_cam[0].argc=argc;
    main_window.m_mcs->cam->sop_cam[0].argv=argv;
#endif
    main_window.show();
    return a.exec();
}
