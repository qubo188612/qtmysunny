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
        FileOut.cpp \
        ResultData.cpp \
        TimeFunction.cpp \
        cam_sen.cpp \
        main.cpp \
        my_parameters.cpp \
        qtmysunnydlg.cpp \
        showtasknumdlg.cpp \
        soptopcamera.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    qtmysunnydlg.ui \
    showtasknumdlg.ui

HEADERS += \
    FileOut.h \
    ResultData.h \
    TimeFunction.h \
    cam_sen.h \
    global.h \
    my_parameters.h \
    qtmysunnydlg.h \
    showtasknumdlg.h \
    soptopcamera.h

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
INCLUDEPATH += /home/qubo/modbus/libmodbus/install/include \
#INCLUDEPATH += /home/qubo/modbus/libmodbus/src

LIBS += /home/qubo/modbus/libmodbus/install/lib/libmodbus.so

