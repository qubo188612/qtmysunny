#include <QApplication>
#include "qtmysunnydlg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtmysunnyDlg main_window;
    main_window.setWindowTitle(QStringLiteral("3D激光跟踪参数设置软件"));
#if _MSC_VER||WINDOWS_TCP
#else
    main_window.m_mcs->cam->sop_cam[0].argc=argc;
    main_window.m_mcs->cam->sop_cam[0].argv=argv;
#endif
    main_window.show();
    return a.exec();
}
