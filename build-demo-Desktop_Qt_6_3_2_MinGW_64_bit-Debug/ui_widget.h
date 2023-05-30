/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *lab_wid_title;
    QPushButton *btn_wid_start;
    QPushButton *btn_wid_exit;
    QPushButton *btn_wid_start_2;
    QPushButton *btn_wid_load;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        lab_wid_title = new QLabel(Widget);
        lab_wid_title->setObjectName(QString::fromUtf8("lab_wid_title"));
        lab_wid_title->setGeometry(QRect(225, 70, 350, 120));
        QFont font;
        font.setFamilies({QString::fromUtf8("Papyrus")});
        font.setPointSize(50);
        lab_wid_title->setFont(font);
        btn_wid_start = new QPushButton(Widget);
        btn_wid_start->setObjectName(QString::fromUtf8("btn_wid_start"));
        btn_wid_start->setGeometry(QRect(280, 310, 101, 101));
        btn_wid_exit = new QPushButton(Widget);
        btn_wid_exit->setObjectName(QString::fromUtf8("btn_wid_exit"));
        btn_wid_exit->setGeometry(QRect(280, 490, 211, 61));
        btn_wid_start_2 = new QPushButton(Widget);
        btn_wid_start_2->setObjectName(QString::fromUtf8("btn_wid_start_2"));
        btn_wid_start_2->setGeometry(QRect(390, 310, 101, 101));
        btn_wid_load = new QPushButton(Widget);
        btn_wid_load->setObjectName(QString::fromUtf8("btn_wid_load"));
        btn_wid_load->setGeometry(QRect(280, 420, 211, 61));

        retranslateUi(Widget);
        QObject::connect(btn_wid_exit, &QPushButton::clicked, Widget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        lab_wid_title->setText(QCoreApplication::translate("Widget", "NOGO", nullptr));
        btn_wid_start->setText(QCoreApplication::translate("Widget", "\345\215\225\346\234\272", nullptr));
        btn_wid_exit->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
        btn_wid_start_2->setText(QCoreApplication::translate("Widget", "\350\201\224\346\234\272", nullptr));
        btn_wid_load->setText(QCoreApplication::translate("Widget", "\345\257\274\345\205\245\345\257\271\345\261\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
