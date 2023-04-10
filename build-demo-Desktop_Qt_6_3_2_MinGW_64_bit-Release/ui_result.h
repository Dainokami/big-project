/********************************************************************************
** Form generated from reading UI file 'result.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULT_H
#define UI_RESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_result
{
public:

    void setupUi(QWidget *result)
    {
        if (result->objectName().isEmpty())
            result->setObjectName(QString::fromUtf8("result"));
        result->resize(400, 300);

        retranslateUi(result);

        QMetaObject::connectSlotsByName(result);
    } // setupUi

    void retranslateUi(QWidget *result)
    {
        result->setWindowTitle(QCoreApplication::translate("result", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class result: public Ui_result {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULT_H
