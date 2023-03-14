#include "setting.h"
#include "ui_setting.h"

setting::setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);

}

setting::~setting()
{
    delete ui;
}

void setting::closeEvent(QCloseEvent *event)
{
    emit setting_close();
}

void setting::on_btn_set_ok_clicked()//设置思考时间
{
    //待完成
    emit send_time(ui->txtl_set_time->text());
    this->close();
}


