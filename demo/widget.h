#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <setting.h>
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
    void close_s();
    void on_btn_wid_set_clicked();

    void on_btn_wid_start_clicked();

private:
    Ui::Widget *ui;
    setting *s = nullptr;
    pan *p = nullptr;
};
#endif // WIDGET_H
