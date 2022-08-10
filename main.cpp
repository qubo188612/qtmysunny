#include <QApplication>
#include "qtmysunnydlg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtmysunnyDlg main_window;
    main_window.setWindowTitle("3D激光焊缝跟踪参数设置软件");
    main_window.m_mcs->cam->sop_cam[0].argc=argc;
    main_window.m_mcs->cam->sop_cam[0].argv=argv;
    main_window.show();
    return a.exec();
}
