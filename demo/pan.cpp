#include "pan.h"
#include "ui_pan.h"

pan::pan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pan)
{
    ui->setupUi(this);
    pan::set_time();

}

pan::~pan()
{
    delete ui;
}


void pan::set_time(int seted_time)
{
    QString temp = QString::number(seted_time);
    ui->txtl_pan_time->setText(temp);
}

void pan::on_btn_pan_set_clicked()//进入设置
{
    if(s == nullptr)
    {
        s = new setting();
        s->show();
        connect(s,&setting::setting_close,this,&pan::close_s);
    }
    else
    {
        s->raise();
    }
}

void pan::close_s()//协助设置函数确保一次只有一个设置界面
{
    delete s;
    s = nullptr;
}
