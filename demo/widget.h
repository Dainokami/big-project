#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <load.h>
#include <pan.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_btn_wid_start_clicked();//进入棋盘

    void on_btn_wid_load_clicked();

private:
    Ui::Widget *ui;
    load *l = nullptr;
    pan *p = nullptr;
};
#endif // WIDGET_H
