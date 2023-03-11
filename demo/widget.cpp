#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_btn_wid_set_clicked()
{
    if(s == nullptr)
    {
        s = new setting();
        s->show();
        connect(s,&setting::setting_close,this,&Widget::close_s);
    }
    else
    {
        s->raise();
    }
}

void Widget::close_s()
{
    delete s;
    s = nullptr;
}

void Widget::on_btn_wid_start_clicked()
{
    p = new pan();
    p->show();
    this->close();
}

