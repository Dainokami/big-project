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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pan
{
public:
    QLineEdit *txtl_pan_time;
    QLabel *label;
    QPushButton *btn_startgame;
    QPushButton *btn_stop;
    QLabel *label_pan;
    QPushButton *btn_lose;
    QCheckBox *checkBox;
    QLabel *label_2;

    void setupUi(QWidget *pan)
    {
        if (pan->objectName().isEmpty())
            pan->setObjectName(QString::fromUtf8("pan"));
        pan->setEnabled(true);
        pan->resize(1051, 615);
        txtl_pan_time = new QLineEdit(pan);
        txtl_pan_time->setObjectName(QString::fromUtf8("txtl_pan_time"));
        txtl_pan_time->setEnabled(true);
        txtl_pan_time->setGeometry(QRect(930, 140, 113, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(true);
        txtl_pan_time->setFont(font);
        label = new QLabel(pan);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(830, 140, 81, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label->setFont(font1);
        btn_startgame = new QPushButton(pan);
        btn_startgame->setObjectName(QString::fromUtf8("btn_startgame"));
        btn_startgame->setGeometry(QRect(740, 280, 91, 61));
        btn_stop = new QPushButton(pan);
        btn_stop->setObjectName(QString::fromUtf8("btn_stop"));
        btn_stop->setGeometry(QRect(950, 280, 91, 61));
        label_pan = new QLabel(pan);
        label_pan->setObjectName(QString::fromUtf8("label_pan"));
        label_pan->setGeometry(QRect(60, 10, 601, 601));
        QFont font2;
        font2.setPointSize(90);
        font2.setBold(true);
        label_pan->setFont(font2);
        label_pan->setPixmap(QPixmap(QString::fromUtf8("image/pan.jpg")));
        label_pan->setScaledContents(true);
        btn_lose = new QPushButton(pan);
        btn_lose->setObjectName(QString::fromUtf8("btn_lose"));
        btn_lose->setGeometry(QRect(740, 430, 91, 61));
        checkBox = new QCheckBox(pan);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(940, 210, 95, 24));
        label_2 = new QLabel(pan);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(830, 210, 91, 20));
        label_2->setFont(font1);

        retranslateUi(pan);

        QMetaObject::connectSlotsByName(pan);
    } // setupUi

    void retranslateUi(QWidget *pan)
    {
        pan->setWindowTitle(QCoreApplication::translate("pan", "Form", nullptr));
        txtl_pan_time->setText(QString());
        label->setText(QCoreApplication::translate("pan", "\345\200\222\350\256\241\346\227\266\357\274\232", nullptr));
        btn_startgame->setText(QCoreApplication::translate("pan", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        btn_stop->setText(QCoreApplication::translate("pan", "\346\232\202\345\201\234\346\270\270\346\210\217", nullptr));
        label_pan->setText(QString());
        btn_lose->setText(QCoreApplication::translate("pan", "\350\256\244\350\276\223", nullptr));
        checkBox->setText(QString());
        label_2->setText(QCoreApplication::translate("pan", "\346\230\257\345\220\246\345\205\210\346\211\213\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pan: public Ui_pan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAN_H
