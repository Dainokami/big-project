/****************************************************************************
** Meta object code from reading C++ file 'load.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../demo/load.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'load.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_load_t {
    uint offsetsAndSizes[18];
    char stringdata0[5];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[26];
    char stringdata5[20];
    char stringdata6[28];
    char stringdata7[20];
    char stringdata8[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_load_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_load_t qt_meta_stringdata_load = {
    {
        QT_MOC_LITERAL(0, 4),  // "load"
        QT_MOC_LITERAL(5, 15),  // "on_back_clicked"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 18),  // "on_re_load_clicked"
        QT_MOC_LITERAL(41, 25),  // "on_lineEdit_returnPressed"
        QT_MOC_LITERAL(67, 19),  // "on_btn_last_clicked"
        QT_MOC_LITERAL(87, 27),  // "on_btn_play_or_stop_clicked"
        QT_MOC_LITERAL(115, 19),  // "on_btn_next_clicked"
        QT_MOC_LITERAL(135, 19)   // "on_btn_jump_clicked"
    },
    "load",
    "on_back_clicked",
    "",
    "on_re_load_clicked",
    "on_lineEdit_returnPressed",
    "on_btn_last_clicked",
    "on_btn_play_or_stop_clicked",
    "on_btn_next_clicked",
    "on_btn_jump_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_load[] = {

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
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void load::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<load *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_back_clicked(); break;
        case 1: _t->on_re_load_clicked(); break;
        case 2: _t->on_lineEdit_returnPressed(); break;
        case 3: _t->on_btn_last_clicked(); break;
        case 4: _t->on_btn_play_or_stop_clicked(); break;
        case 5: _t->on_btn_next_clicked(); break;
        case 6: _t->on_btn_jump_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject load::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_load.offsetsAndSizes,
    qt_meta_data_load,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_load_t
, QtPrivate::TypeAndForceComplete<load, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *load::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *load::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_load.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int load::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
