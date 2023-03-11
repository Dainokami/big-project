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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pan
{
public:
    QLineEdit *txtl_pan_time;
    QPushButton *btn_pan_set;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_pan;

    void setupUi(QWidget *pan)
    {
        if (pan->objectName().isEmpty())
            pan->setObjectName(QString::fromUtf8("pan"));
        pan->resize(1051, 615);
        txtl_pan_time = new QLineEdit(pan);
        txtl_pan_time->setObjectName(QString::fromUtf8("txtl_pan_time"));
        txtl_pan_time->setEnabled(false);
        txtl_pan_time->setGeometry(QRect(930, 140, 113, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(true);
        txtl_pan_time->setFont(font);
        btn_pan_set = new QPushButton(pan);
        btn_pan_set->setObjectName(QString::fromUtf8("btn_pan_set"));
        btn_pan_set->setGeometry(QRect(950, 10, 81, 41));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        btn_pan_set->setFont(font1);
        label = new QLabel(pan);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(830, 140, 81, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        label->setFont(font2);
        pushButton = new QPushButton(pan);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(740, 280, 91, 61));
        pushButton_2 = new QPushButton(pan);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(950, 280, 91, 61));
        label_pan = new QLabel(pan);
        label_pan->setObjectName(QString::fromUtf8("label_pan"));
        label_pan->setGeometry(QRect(10, 10, 601, 601));
        QFont font3;
        font3.setPointSize(90);
        font3.setBold(true);
        label_pan->setFont(font3);

        retranslateUi(pan);

        QMetaObject::connectSlotsByName(pan);
    } // setupUi

    void retranslateUi(QWidget *pan)
    {
        pan->setWindowTitle(QCoreApplication::translate("pan", "Form", nullptr));
        txtl_pan_time->setText(QString());
        btn_pan_set->setText(QCoreApplication::translate("pan", "\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("pan", "\345\200\222\350\256\241\346\227\266\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("pan", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("pan", "\346\232\202\345\201\234\346\270\270\346\210\217", nullptr));
        label_pan->setText(QCoreApplication::translate("pan", "\350\277\231\346\230\257\346\243\213\347\233\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pan: public Ui_pan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAN_H
