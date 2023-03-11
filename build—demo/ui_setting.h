/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setting
{
public:
    QLabel *label_1;
    QLineEdit *txtl_set_time;
    QPushButton *btn_set_ok;
    QPushButton *btn_set_cancel;

    void setupUi(QWidget *setting)
    {
        if (setting->objectName().isEmpty())
            setting->setObjectName(QString::fromUtf8("setting"));
        setting->resize(350, 500);
        label_1 = new QLabel(setting);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(20, 90, 111, 51));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        label_1->setFont(font);
        txtl_set_time = new QLineEdit(setting);
        txtl_set_time->setObjectName(QString::fromUtf8("txtl_set_time"));
        txtl_set_time->setGeometry(QRect(160, 100, 171, 31));
        btn_set_ok = new QPushButton(setting);
        btn_set_ok->setObjectName(QString::fromUtf8("btn_set_ok"));
        btn_set_ok->setGeometry(QRect(30, 340, 93, 29));
        btn_set_cancel = new QPushButton(setting);
        btn_set_cancel->setObjectName(QString::fromUtf8("btn_set_cancel"));
        btn_set_cancel->setGeometry(QRect(220, 340, 93, 29));

        retranslateUi(setting);
        QObject::connect(btn_set_cancel, &QPushButton::clicked, setting, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(setting);
    } // setupUi

    void retranslateUi(QWidget *setting)
    {
        setting->setWindowTitle(QCoreApplication::translate("setting", "Form", nullptr));
        label_1->setText(QCoreApplication::translate("setting", "\350\266\205\346\227\266\346\227\266\351\225\277", nullptr));
        btn_set_ok->setText(QCoreApplication::translate("setting", "\347\241\256\350\256\244", nullptr));
        btn_set_cancel->setText(QCoreApplication::translate("setting", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setting: public Ui_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
