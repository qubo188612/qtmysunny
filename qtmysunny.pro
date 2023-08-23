QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat
QT       += core gui network

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        CConnectionForSshClient.cpp \
        E2proomData.cpp \
        FileOut.cpp \
        PictureBox.cpp \
        ResultData.cpp \
        TimeFunction.cpp \
        XTcp.cpp \
        calibration.cpp \
        cam_sen.cpp \
        cambuilddlg.cpp \
        craftdlg.cpp \
        main.cpp \
        my_parameters.cpp \
        pshowdlg.cpp \
        qtmysunnydlg.cpp \
        showtasknumdlg.cpp \
        soptocameratcpip.cpp \
        soptopcamera.cpp \
        sshpassworddlg.cpp \
        taskcleardlg.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    cambuilddlg.ui \
    craftdlg.ui \
    pshowdlg.ui \
    qtmysunnydlg.ui \
    showtasknumdlg.ui \
    sshpassworddlg.ui \
    taskcleardlg.ui

HEADERS += \
    CConnectionForSshClient.h \
    E2proomData.h \
    FileOut.h \
    PictureBox.h \
    ResultData.h \
    TimeFunction.h \
    XTcp.h \
    calibration.h \
    cam_sen.h \
    cambuilddlg.h \
    craftdlg.h \
    global.h \
    my_parameters.h \
    pshowdlg.h \
    qtmysunnydlg.h \
    showtasknumdlg.h \
    soptocameratcpip.h \
    soptopcamera.h \
    sshpassworddlg.h \
    taskcleardlg.h \
    tistdtypes.h

win32{
#opencv库的添加
INCLUDEPATH += D:/opencv-4.6.0/build/include \

LIBS += D:/opencv-4.6.0/build/x64/vc16/lib/opencv*.lib \

#自定义ROS接口添加
#INCLUDEPATH += C:/Users/34638/Documents/ros2topic/myRos2test/install/tutorial_interfaces/include \

#LIBS += C:/Users/34638/Documents/ros2topic/myRos2test/install/tutorial_interfaces/lib/*.lib \

#ROS库添加
#INCLUDEPATH += C:/opt/ros/foxy/x64/include \

#LIBS += C:/opt/ros/foxy/x64/Lib/*.lib \


#modbustcp库的添加
INCLUDEPATH += D:/libmodbus/include \

LIBS += D:/libmodbus/x64/lib/*.lib

#Eigen库的添加
INCLUDEPATH += D:/eigen3

#QSsh库的添加
INCLUDEPATH += C:/Users/34638/Documents/QtProject/QSsh/src/libs/qssh \

LIBS += C:/Users/34638/Documents/QtProject/QSsh/build/lib/QSsh.lib

INCLUDEPATH += C:/Botan/include/botan-2 \

LIBS += C:/Botan/lib/*.lib
}

unix {
#opencv库的添加
INCLUDEPATH += /usr/local/OpenCV/Release/include/opencv4 \

LIBS += /usr/local/OpenCV/Release/lib/libopencv_*

#ROS库添加
INCLUDEPATH +=/opt/ros/galactic/include \

LIBS += /opt/ros/galactic/lib/lib*.so
LIBS += /opt/ros/galactic/lib/x86_64-linux-gnu/lib*.so

#自定义ROS接口添加
INCLUDEPATH +=/home/qubo/myRos2test/install/tutorial_interfaces/include \

LIBS += /home/qubo/myRos2test/install/tutorial_interfaces/lib/libtutorial_interfaces*.so

#modbustcp库的添加
INCLUDEPATH += /usr/include \

LIBS += /usr/lib/x86_64-linux-gnu/libmodbus.so

#Eigen库的添加
INCLUDEPATH += /usr/include/eigen3

#QSsh库的添加
INCLUDEPATH += /home/qubo/Qt/6.2.4/gcc_64/include/QSsh

unix:!macx: LIBS += -L /home/qubo/Qt/6.2.4/gcc_64/lib/ -lQSsh

}

