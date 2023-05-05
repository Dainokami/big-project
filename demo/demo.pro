QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatroom.cpp \
    load.cpp \
    main.cpp \
    netpan.cpp \
    pan.cpp \
    widget.cpp

HEADERS += \
    chatroom.h \
    load.h \
    netpan.h \
    pan.h \
    widget.h

FORMS += \
    chatroom.ui \
    load.ui \
    netpan.ui \
    pan.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image_music.qrc
