/********************************************************************************
** Form generated from reading UI file 'chatroom.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATROOM_H
#define UI_CHATROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatRoom
{
public:

    void setupUi(QWidget *ChatRoom)
    {
        if (ChatRoom->objectName().isEmpty())
            ChatRoom->setObjectName(QString::fromUtf8("ChatRoom"));
        ChatRoom->resize(771, 521);

        retranslateUi(ChatRoom);

        QMetaObject::connectSlotsByName(ChatRoom);
    } // setupUi

    void retranslateUi(QWidget *ChatRoom)
    {
        ChatRoom->setWindowTitle(QCoreApplication::translate("ChatRoom", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatRoom: public Ui_ChatRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOM_H
