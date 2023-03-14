#include "pan.h"
#include "ui_pan.h"

pan::pan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pan)
{
    ui->setupUi(this);
    QImage *img_pan = new QImage;
    img_pan->load("E:\\Qt‘s project\\big-project\\demo\\image\\pan.jpg");
    ui->label_pan->setPixmap(QPixmap::fromImage(*img_pan));


    m = new QTimer(this);
    m->setInterval(1000);
    connect(m,&QTimer::timeout,this,pan::OnTimerCountdown);

}

pan::~pan()
{
    if (m)
    {
        if (m->isActive() == true)
        {
            m->stop();
        }
        delete m;
        m= nullptr;
    }
    delete ui;
}


void pan::set_time(int seted_time)
{
    this->game_max_time = seted_time;
    this->now_time = game_max_time;
    pan::BeginCountdown();
    QString temp = QString::number(seted_time);
    ui->txtl_pan_time->setText(temp);
}


void pan::BeginCountdown()//当前定时器未激活时，激活定时器
{
   if (m->isActive() == false)
   {
        m->start(game_max_time);
   }
}

void pan::OnTimerCountdown()
{
   //定时器，没触发一次，时间减1，直到最后一次倒计时为0秒时，停止定时器
   now_time -= 1;
   //使用QLabel控件显示倒计时的时间
   ui->txtl_pan_time->setText(QString::number(now_time));
   if(now_time == 0)
   {
      //说明，定时器最后一次触发，可以做停止以及其它操作，假设，现在做停止定时器操作
      m->stop();
   }
}

void pan::delete_time()
{
    if (m)
    {
        if (m->isActive() == true)
        {
            m->stop();
        }
        delete m;
        m= nullptr;
    }
}

void pan::on_btn_startgame_clicked()
{
    ui->checkBox->setEnabled(false);
    ui->txtl_pan_time->setEnabled(false);
    set_time(ui->txtl_pan_time->text().toInt());

}

