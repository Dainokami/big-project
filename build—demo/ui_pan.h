/********************************************************************************
** Form generated from reading UI file 'pan.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAN_H
#define UI_PAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pan
{
public:

    void setupUi(QWidget *pan)
    {
        if (pan->objectName().isEmpty())
            pan->setObjectName(QString::fromUtf8("pan"));
        pan->resize(400, 300);

        retranslateUi(pan);

        QMetaObject::connectSlotsByName(pan);
    } // setupUi

    void retranslateUi(QWidget *pan)
    {
        pan->setWindowTitle(QCoreApplication::translate("pan", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pan: public Ui_pan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAN_H
