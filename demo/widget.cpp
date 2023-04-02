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

