/****************************************************************************
** Meta object code from reading C++ file 'pan.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../demo/pan.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pan.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_pan_t {
    uint offsetsAndSizes[20];
    char stringdata0[4];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[27];
    char stringdata5[20];
    char stringdata6[13];
    char stringdata7[4];
    char stringdata8[23];
    char stringdata9[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_pan_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_pan_t qt_meta_stringdata_pan = {
    {
        QT_MOC_LITERAL(0, 3),  // "pan"
        QT_MOC_LITERAL(4, 24),  // "on_btn_startgame_clicked"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 19),  // "on_btn_stop_clicked"
        QT_MOC_LITERAL(50, 26),  // "on_btn_startgame_2_clicked"
        QT_MOC_LITERAL(77, 19),  // "on_btn_lose_clicked"
        QT_MOC_LITERAL(97, 12),  // "get_btn_sign"
        QT_MOC_LITERAL(110, 3),  // "idx"
        QT_MOC_LITERAL(114, 22),  // "on_btn_restart_clicked"
        QT_MOC_LITERAL(137, 23)   // "on_btn_isEnable_clicked"
    },
    "pan",
    "on_btn_startgame_clicked",
    "",
    "on_btn_stop_clicked",
    "on_btn_startgame_2_clicked",
    "on_btn_lose_clicked",
    "get_btn_sign",
    "idx",
    "on_btn_restart_clicked",
    "on_btn_isEnable_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_pan[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    1,   60,    2, 0x08,    5 /* Private */,
       8,    0,   63,    2, 0x08,    7 /* Private */,
       9,    0,   64,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject pan::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_pan.offsetsAndSizes,
    qt_meta_data_pan,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_pan_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<pan, std::true_type>,
        // method 'on_btn_startgame_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_stop_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_startgame_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_lose_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'get_btn_sign'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_btn_restart_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_isEnable_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void pan::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<pan *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btn_startgame_clicked(); break;
        case 1: _t->on_btn_stop_clicked(); break;
        case 2: _t->on_btn_startgame_2_clicked(); break;
        case 3: _t->on_btn_lose_clicked(); break;
        case 4: _t->get_btn_sign((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_btn_restart_clicked(); break;
        case 6: _t->on_btn_isEnable_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *pan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pan::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pan.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int pan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
