/****************************************************************************
** Meta object code from reading C++ file 'chatroom.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../demo/chatroom.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatroom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatRoom_t {
    uint offsetsAndSizes[18];
    char stringdata0[9];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[25];
    char stringdata5[20];
    char stringdata6[19];
    char stringdata7[22];
    char stringdata8[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ChatRoom_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_ChatRoom_t qt_meta_stringdata_ChatRoom = {
    {
        QT_MOC_LITERAL(0, 8),  // "ChatRoom"
        QT_MOC_LITERAL(9, 24),  // "ClickedAddChatRoomButton"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 24),  // "ClickedSendMessageButton"
        QT_MOC_LITERAL(60, 24),  // "ClickedFlushOnlineButton"
        QT_MOC_LITERAL(85, 19),  // "ReadChatMessageSlot"
        QT_MOC_LITERAL(105, 18),  // "ChatDisConnectSlot"
        QT_MOC_LITERAL(124, 21),  // "ReadOnlineMessageSlot"
        QT_MOC_LITERAL(146, 20)   // "OnlineDisConnectSlot"
    },
    "ChatRoom",
    "ClickedAddChatRoomButton",
    "",
    "ClickedSendMessageButton",
    "ClickedFlushOnlineButton",
    "ReadChatMessageSlot",
    "ChatDisConnectSlot",
    "ReadOnlineMessageSlot",
    "OnlineDisConnectSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatRoom[] = {

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

void ChatRoom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatRoom *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ClickedAddChatRoomButton(); break;
        case 1: _t->ClickedSendMessageButton(); break;
        case 2: _t->ClickedFlushOnlineButton(); break;
        case 3: _t->ReadChatMessageSlot(); break;
        case 4: _t->ChatDisConnectSlot(); break;
        case 5: _t->ReadOnlineMessageSlot(); break;
        case 6: _t->OnlineDisConnectSlot(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject ChatRoom::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ChatRoom.offsetsAndSizes,
    qt_meta_data_ChatRoom,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ChatRoom_t
, QtPrivate::TypeAndForceComplete<ChatRoom, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ChatRoom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatRoom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatRoom.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ChatRoom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
