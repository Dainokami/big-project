#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("NOGO");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_wid_start_clicked()
{
    p = new pan();
    p->show();
    this->close();
}

void pan::on_back_clicked()
{
    Widget *w = new Widget();
    w->show();
    this->close();
}

void Widget::on_btn_wid_load_clicked()
{
    l = new load();
    l->show();
    l->getter();
    this->close();
}

void load::on_back_clicked()
{
    Widget *w = new Widget();
    w->show();
    this->close();
}
