/****************************************************************************
** Meta object code from reading C++ file 'qtmysunnydlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qtmysunny/qtmysunnydlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtmysunnydlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qtmysunnyDlg_t {
    QByteArrayData data[9];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qtmysunnyDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qtmysunnyDlg_t qt_meta_stringdata_qtmysunnyDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "qtmysunnyDlg"
QT_MOC_LITERAL(1, 13, 18), // "init_show_pos_list"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 20), // "init_show_pos_failed"
QT_MOC_LITERAL(4, 54, 23), // "init_show_cvimage_inlab"
QT_MOC_LITERAL(5, 78, 7), // "cv::Mat"
QT_MOC_LITERAL(6, 86, 13), // "init_set_task"
QT_MOC_LITERAL(7, 100, 26), // "on_tabWidget_tabBarClicked"
QT_MOC_LITERAL(8, 127, 5) // "index"

    },
    "qtmysunnyDlg\0init_show_pos_list\0\0"
    "init_show_pos_failed\0init_show_cvimage_inlab\0"
    "cv::Mat\0init_set_task\0on_tabWidget_tabBarClicked\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qtmysunnyDlg[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void qtmysunnyDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<qtmysunnyDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->init_show_pos_list(); break;
        case 1: _t->init_show_pos_failed(); break;
        case 2: _t->init_show_cvimage_inlab((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 3: _t->init_set_task(); break;
        case 4: _t->on_tabWidget_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qtmysunnyDlg::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_qtmysunnyDlg.data,
    qt_meta_data_qtmysunnyDlg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qtmysunnyDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qtmysunnyDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qtmysunnyDlg.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int qtmysunnyDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
struct qt_meta_stringdata_getposThread_t {
    QByteArrayData data[7];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_getposThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_getposThread_t qt_meta_stringdata_getposThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "getposThread"
QT_MOC_LITERAL(1, 13, 18), // "Send_show_pos_list"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 20), // "Send_show_pos_failed"
QT_MOC_LITERAL(4, 54, 23), // "Send_show_cvimage_inlab"
QT_MOC_LITERAL(5, 78, 7), // "cv::Mat"
QT_MOC_LITERAL(6, 86, 13) // "Send_set_task"

    },
    "getposThread\0Send_show_pos_list\0\0"
    "Send_show_pos_failed\0Send_show_cvimage_inlab\0"
    "cv::Mat\0Send_set_task"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_getposThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    1,   36,    2, 0x06 /* Public */,
       6,    0,   39,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

       0        // eod
};

void getposThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<getposThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Send_show_pos_list(); break;
        case 1: _t->Send_show_pos_failed(); break;
        case 2: _t->Send_show_cvimage_inlab((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 3: _t->Send_set_task(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (getposThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&getposThread::Send_show_pos_list)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (getposThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&getposThread::Send_show_pos_failed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (getposThread::*)(cv::Mat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&getposThread::Send_show_cvimage_inlab)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (getposThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&getposThread::Send_set_task)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject getposThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_getposThread.data,
    qt_meta_data_getposThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *getposThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *getposThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_getposThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int getposThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void getposThread::Send_show_pos_list()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void getposThread::Send_show_pos_failed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void getposThread::Send_show_cvimage_inlab(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void getposThread::Send_set_task()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
