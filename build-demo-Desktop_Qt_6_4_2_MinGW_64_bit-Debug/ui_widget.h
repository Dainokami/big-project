/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
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

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        lab_wid_title = new QLabel(Widget);
        lab_wid_title->setObjectName("lab_wid_title");
        lab_wid_title->setGeometry(QRect(225, 70, 350, 120));
        QFont font;
        font.setFamilies({QString::fromUtf8("Papyrus")});
        font.setPointSize(50);
        lab_wid_title->setFont(font);
        btn_wid_start = new QPushButton(Widget);
        btn_wid_start->setObjectName("btn_wid_start");
        btn_wid_start->setGeometry(QRect(280, 310, 211, 61));
        btn_wid_exit = new QPushButton(Widget);
        btn_wid_exit->setObjectName("btn_wid_exit");
        btn_wid_exit->setGeometry(QRect(280, 480, 211, 61));

        retranslateUi(Widget);
        QObject::connect(btn_wid_exit, &QPushButton::clicked, Widget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        lab_wid_title->setText(QCoreApplication::translate("Widget", "NOGO", nullptr));
        btn_wid_start->setText(QCoreApplication::translate("Widget", "\350\277\233\345\205\245\346\270\270\346\210\217", nullptr));
        btn_wid_exit->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
