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

void Widget::on_btn_wid_load_clicked()
{
    l = new load();
    l->show();
    l->getter();
    this->close();
}

void Widget::on_btn_wid_start_2_clicked()
{
    np = new netpan();
    np->show();
    this->close();
}

void pan::on_back_clicked()
{
    Widget *w = new Widget();
    w->show();
    delete this;
}

void load::on_back_clicked()
{
    Widget *w = new Widget();
    w->show();
    this->close();

}

void netpan::on_back_clicked()
{
    if(mode == SOCKET)
        this->socket->send(NetworkData(OPCODE::LEAVE_OP,username,""));
    else if(mode == SERVER)
    {
        if(lastOne)
            this->server->send(lastOne,NetworkData(OPCODE::LEAVE_OP,username,""));
    }
    Widget *w = new Widget();
    w->show();
    delete this;
}



