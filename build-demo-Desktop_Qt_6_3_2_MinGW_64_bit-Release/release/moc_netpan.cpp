/****************************************************************************
** Meta object code from reading C++ file 'netpan.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../demo/netpan.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'netpan.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_netpan_t {
    uint offsetsAndSizes[42];
    char stringdata0[7];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[13];
    char stringdata5[4];
    char stringdata6[20];
    char stringdata7[16];
    char stringdata8[10];
    char stringdata9[16];
    char stringdata10[19];
    char stringdata11[13];
    char stringdata12[12];
    char stringdata13[7];
    char stringdata14[12];
    char stringdata15[5];
    char stringdata16[23];
    char stringdata17[8];
    char stringdata18[10];
    char stringdata19[6];
    char stringdata20[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_netpan_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_netpan_t qt_meta_stringdata_netpan = {
    {
        QT_MOC_LITERAL(0, 6),  // "netpan"
        QT_MOC_LITERAL(7, 24),  // "on_btn_startgame_clicked"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 19),  // "on_btn_lose_clicked"
        QT_MOC_LITERAL(53, 12),  // "get_btn_sign"
        QT_MOC_LITERAL(66, 3),  // "idx"
        QT_MOC_LITERAL(70, 19),  // "on_btn_stop_clicked"
        QT_MOC_LITERAL(90, 15),  // "get_online_sign"
        QT_MOC_LITERAL(106, 9),  // "timestamp"
        QT_MOC_LITERAL(116, 15),  // "on_back_clicked"
        QT_MOC_LITERAL(132, 18),  // "on_sendbtn_clicked"
        QT_MOC_LITERAL(151, 12),  // "receieveData"
        QT_MOC_LITERAL(164, 11),  // "QTcpSocket*"
        QT_MOC_LITERAL(176, 6),  // "client"
        QT_MOC_LITERAL(183, 11),  // "NetworkData"
        QT_MOC_LITERAL(195, 4),  // "data"
        QT_MOC_LITERAL(200, 22),  // "receieveDataFromServer"
        QT_MOC_LITERAL(223, 7),  // "reStart"
        QT_MOC_LITERAL(231, 9),  // "reConnect"
        QT_MOC_LITERAL(241, 5),  // "reSet"
        QT_MOC_LITERAL(247, 20)   // "chose_color_and_name"
    },
    "netpan",
    "on_btn_startgame_clicked",
    "",
    "on_btn_lose_clicked",
    "get_btn_sign",
    "idx",
    "on_btn_stop_clicked",
    "get_online_sign",
    "timestamp",
    "on_back_clicked",
    "on_sendbtn_clicked",
    "receieveData",
    "QTcpSocket*",
    "client",
    "NetworkData",
    "data",
    "receieveDataFromServer",
    "reStart",
    "reConnect",
    "reSet",
    "chose_color_and_name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_netpan[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    1 /* Private */,
       3,    0,   93,    2, 0x08,    2 /* Private */,
       4,    1,   94,    2, 0x08,    3 /* Private */,
       6,    0,   97,    2, 0x08,    5 /* Private */,
       7,    2,   98,    2, 0x08,    6 /* Private */,
       9,    0,  103,    2, 0x08,    9 /* Private */,
      10,    0,  104,    2, 0x08,   10 /* Private */,
      11,    2,  105,    2, 0x08,   11 /* Private */,
      16,    1,  110,    2, 0x08,   14 /* Private */,
      17,    0,  113,    2, 0x08,   16 /* Private */,
      18,    0,  114,    2, 0x08,   17 /* Private */,
      19,    0,  115,    2, 0x08,   18 /* Private */,
      20,    0,  116,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::LongLong,    5,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14,   13,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void netpan::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<netpan *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btn_startgame_clicked(); break;
        case 1: _t->on_btn_lose_clicked(); break;
        case 2: _t->get_btn_sign((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_btn_stop_clicked(); break;
        case 4: _t->get_online_sign((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 5: _t->on_back_clicked(); break;
        case 6: _t->on_sendbtn_clicked(); break;
        case 7: _t->receieveData((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<NetworkData>>(_a[2]))); break;
        case 8: _t->receieveDataFromServer((*reinterpret_cast< std::add_pointer_t<NetworkData>>(_a[1]))); break;
        case 9: _t->reStart(); break;
        case 10: _t->reConnect(); break;
        case 11: _t->reSet(); break;
        case 12: _t->chose_color_and_name(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        }
    }
}

const QMetaObject netpan::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_netpan.offsetsAndSizes,
    qt_meta_data_netpan,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_netpan_t
, QtPrivate::TypeAndForceComplete<netpan, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<qint64, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>, QtPrivate::TypeAndForceComplete<NetworkData, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<NetworkData, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *netpan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *netpan::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_netpan.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int netpan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
