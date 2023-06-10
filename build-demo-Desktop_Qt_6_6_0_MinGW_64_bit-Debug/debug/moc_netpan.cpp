/****************************************************************************
** Meta object code from reading C++ file 'netpan.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../demo/netpan.h"
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'netpan.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSnetpanENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSnetpanENDCLASS = QtMocHelpers::stringData(
    "netpan",
    "on_btn_startgame_clicked",
    "",
    "on_btn_lose_clicked",
    "get_btn_sign",
    "idx",
    "get_online_sign",
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
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSnetpanENDCLASS_t {
    uint offsetsAndSizes[38];
    char stringdata0[7];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[13];
    char stringdata5[4];
    char stringdata6[16];
    char stringdata7[16];
    char stringdata8[19];
    char stringdata9[13];
    char stringdata10[12];
    char stringdata11[7];
    char stringdata12[12];
    char stringdata13[5];
    char stringdata14[23];
    char stringdata15[8];
    char stringdata16[10];
    char stringdata17[6];
    char stringdata18[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSnetpanENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSnetpanENDCLASS_t qt_meta_stringdata_CLASSnetpanENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "netpan"
        QT_MOC_LITERAL(7, 24),  // "on_btn_startgame_clicked"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 19),  // "on_btn_lose_clicked"
        QT_MOC_LITERAL(53, 12),  // "get_btn_sign"
        QT_MOC_LITERAL(66, 3),  // "idx"
        QT_MOC_LITERAL(70, 15),  // "get_online_sign"
        QT_MOC_LITERAL(86, 15),  // "on_back_clicked"
        QT_MOC_LITERAL(102, 18),  // "on_sendbtn_clicked"
        QT_MOC_LITERAL(121, 12),  // "receieveData"
        QT_MOC_LITERAL(134, 11),  // "QTcpSocket*"
        QT_MOC_LITERAL(146, 6),  // "client"
        QT_MOC_LITERAL(153, 11),  // "NetworkData"
        QT_MOC_LITERAL(165, 4),  // "data"
        QT_MOC_LITERAL(170, 22),  // "receieveDataFromServer"
        QT_MOC_LITERAL(193, 7),  // "reStart"
        QT_MOC_LITERAL(201, 9),  // "reConnect"
        QT_MOC_LITERAL(211, 5),  // "reSet"
        QT_MOC_LITERAL(217, 20)   // "chose_color_and_name"
    },
    "netpan",
    "on_btn_startgame_clicked",
    "",
    "on_btn_lose_clicked",
    "get_btn_sign",
    "idx",
    "get_online_sign",
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
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSnetpanENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    0,   87,    2, 0x08,    2 /* Private */,
       4,    1,   88,    2, 0x08,    3 /* Private */,
       6,    1,   91,    2, 0x08,    5 /* Private */,
       7,    0,   94,    2, 0x08,    7 /* Private */,
       8,    0,   95,    2, 0x08,    8 /* Private */,
       9,    2,   96,    2, 0x08,    9 /* Private */,
      14,    1,  101,    2, 0x08,   12 /* Private */,
      15,    0,  104,    2, 0x08,   14 /* Private */,
      16,    0,  105,    2, 0x08,   15 /* Private */,
      17,    0,  106,    2, 0x08,   16 /* Private */,
      18,    0,  107,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 12,   11,   13,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject netpan::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSnetpanENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSnetpanENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSnetpanENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<netpan, std::true_type>,
        // method 'on_btn_startgame_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_lose_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'get_btn_sign'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'get_online_sign'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_back_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sendbtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'receieveData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTcpSocket *, std::false_type>,
        QtPrivate::TypeAndForceComplete<NetworkData, std::false_type>,
        // method 'receieveDataFromServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<NetworkData, std::false_type>,
        // method 'reStart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reSet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'chose_color_and_name'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void netpan::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<netpan *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btn_startgame_clicked(); break;
        case 1: _t->on_btn_lose_clicked(); break;
        case 2: _t->get_btn_sign((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->get_online_sign((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_back_clicked(); break;
        case 5: _t->on_sendbtn_clicked(); break;
        case 6: _t->receieveData((*reinterpret_cast< std::add_pointer_t<QTcpSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<NetworkData>>(_a[2]))); break;
        case 7: _t->receieveDataFromServer((*reinterpret_cast< std::add_pointer_t<NetworkData>>(_a[1]))); break;
        case 8: _t->reStart(); break;
        case 9: _t->reConnect(); break;
        case 10: _t->reSet(); break;
        case 11: _t->chose_color_and_name(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QTcpSocket* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *netpan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *netpan::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSnetpanENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int netpan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
