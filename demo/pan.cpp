#include "pan.h"
#include "ui_pan.h"

pan::pan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pan)
{
    ui->setupUi(this);

    //以下设置背景图
    QImage *img_pan = new QImage;
    img_pan->load("E:\\Qt‘s project\\big-project\\demo\\image\\pan.jpg");
    ui->label_pan->setPixmap(QPixmap::fromImage(*img_pan));

    //以下设置定时器
    m = new QTimer(this);
    m->setInterval(1000);
    connect(m,&QTimer::timeout,this,pan::OnTimerCountdown);

    //以下关联按钮
    QSignalMapper *myMapper = new QSignalMapper(this);
    QPushButton *button[9][9]={ui->btn_0_0,ui->btn_0_1,ui->btn_0_2,ui->btn_0_3,ui->btn_0_4,ui->btn_0_5,ui->btn_0_6,ui->btn_0_7,ui->btn_0_8,ui->btn_1_0,ui->btn_1_1,ui->btn_1_2,ui->btn_1_3,ui->btn_1_4,ui->btn_1_5,ui->btn_1_6,ui->btn_1_7,ui->btn_1_8,ui->btn_2_0,ui->btn_2_1,ui->btn_2_2,ui->btn_2_3,ui->btn_2_4,ui->btn_2_5,ui->btn_2_6,ui->btn_2_7,ui->btn_2_8,ui->btn_3_0,ui->btn_3_1,ui->btn_3_2,ui->btn_3_3,ui->btn_3_4,ui->btn_3_5,ui->btn_3_6,ui->btn_3_7,ui->btn_3_8,ui->btn_4_0,ui->btn_4_1,ui->btn_4_2,ui->btn_4_3,ui->btn_4_4,ui->btn_4_5,ui->btn_4_6,ui->btn_4_7,ui->btn_4_8,ui->btn_5_0,ui->btn_5_1,ui->btn_5_2,ui->btn_5_3,ui->btn_5_4,ui->btn_5_5,ui->btn_5_6,ui->btn_5_7,ui->btn_5_8,ui->btn_6_0,ui->btn_6_1,ui->btn_6_2,ui->btn_6_3,ui->btn_6_4,ui->btn_6_5,ui->btn_6_6,ui->btn_6_7,ui->btn_6_8,ui->btn_7_0,ui->btn_7_1,ui->btn_7_2,ui->btn_7_3,ui->btn_7_4,ui->btn_7_5,ui->btn_7_6,ui->btn_7_7,ui->btn_7_8,ui->btn_8_0,ui->btn_8_1,ui->btn_8_2,ui->btn_8_3,ui->btn_8_4,ui->btn_8_5,ui->btn_8_6,ui->btn_8_7,ui->btn_8_8};
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            connect(button[i][j],SIGNAL(clicked(bool)),myMapper,SLOT(map()));
            myMapper->setMapping(button[i][j],i*10+j);
        }
    connect(myMapper,SIGNAL(mappedInt(int)),this,SLOT(get_btn_sign(int)));

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
        m->start();
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

void pan::play_the_Go(QPushButton *btn)//用于绘制棋子
{
    if(game_state == 1)
    {
        if(now_player == 1)
        {
            btn->setStyleSheet("background-color:white");
            btn->setFlat(false);
        }
        else if(now_player == -1)
        {
            btn->setStyleSheet("background-color:black");
            btn->setFlat(false);
        }
    }
}

void pan::judge()//这个函数用于判断输赢
{
    now_player *= -1;
}

void pan::on_btn_startgame_clicked()
{

    ui->txtl_pan_time->setEnabled(false);
    game_state = 1;
    set_time(ui->txtl_pan_time->text().toInt());


}

void pan::on_btn_stop_clicked()
{
    m->stop();
    game_state = 0;
}

void pan::on_btn_startgame_2_clicked()
{
    m->start();
    game_state = 1;
}

void pan::get_btn_sign(int idx)
{
    for(int i_=0;i_<9;i_++)
        for(int j_=0;j_<9;j_++)
            if(idx == i_*10+j_ && Qi[i_][j_] == 0)
            {
                QString temp = "btn_"+QString::number(i_)+"_"+QString::number(j_);
                QPushButton *button = this->findChild<QPushButton*>(temp);
                Qi[i_][j_] = now_player;
                judge();
                play_the_Go(button);
            }

}