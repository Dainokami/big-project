#include "pan.h"
#include "ui_pan.h"

pan::pan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pan)
{
    ui->setupUi(this);

    //以下设置背景图
    QImage *img_pan = new QImage;
    img_pan->load("D:\\git demo\\big-project3\\demo\\picture\\picture.jpeg");
    ui->label_pan->setPixmap(QPixmap::fromImage(*img_pan));

    //以下设置定时器
    m = new QTimer(this);
    m->setInterval(1000);
    connect(m,&QTimer::timeout,this,pan::OnTimerCountdown);
    ui->txtl_pan_time->setText("50");

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
void pan::paintEvent(QPaintEvent *)//绘制棋盘
{
    paint=new QPainter;
    paint->begin(this);
    paint->setPen(QPen(Qt::black,2,Qt::SolidLine));
      for(int i=0;i<lu+1;i++)
        {
          paint->drawLine(x,y+size*i,x+size*(lu),y+size*i);//画线函数：x1,y1,x2,y2:画从(x1,y1)到(x2,y2)的线
        }
      //画lu+1条竖线
      for(int i=0;i<lu+1;i++)
        {
          paint->drawLine(x+size*i,y,x+size*i,y+size*(lu));
        }
      //ui->setupUi()
}
void pan::set_time(int seted_time)//设置时间并激活时间
{
    game_max_time = seted_time;
    now_time = game_max_time;
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

void pan::OnTimerCountdown()//输出倒计时
{
   now_time -= 1;
   ui->txtl_pan_time->setText(QString::number(now_time));

   if(now_time <= 0)
   {
       if(now_player==1)
            QMessageBox::information(NULL, "嘻嘻嘻嘻", "白棋你超时了捏", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
       else if(now_player==-1)
            QMessageBox::information(NULL, "嘻嘻嘻嘻", "黑棋你超时了捏", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

        clear_pan();
        ui->txtl_pan_time->setEnabled(true);
        game_state = 0;
        now_player = -1;
        m->stop();
   }
}

void pan::delete_time()//删除计时器
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
            btn->setStyleSheet("background-color:white;border-radius:30px;border:2px groove gray;border-style:outset;");
            btn->setFlat(false);
        }
        else if(now_player == -1)
        {
            btn->setStyleSheet("background-color:black;border-radius:30px;border:2px groove gray;border-style:outset;");
            btn->setFlat(false);
        }
    }
}

void pan::judge()//这个函数用于判断输赢（待实现）
{
    now_player *= -1;







}

void pan::dfs(int x, int y)//深度搜索判断气有无被断（待实现）
{

}

void pan::clear_pan()//该函数用于清屏,清空气,重设时间
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            Qi[i][j] = 0;
            QString temp = "btn_"+QString::number(i)+"_"+QString::number(j);
            QPushButton *button = this->findChild<QPushButton*>(temp);
            button->setStyleSheet("background-color:transparent;");
            button->setFlat(true);

        }
    if(ui->txtl_pan_time->isEnabled())
    {
        ui->txtl_pan_time->setEnabled(false);
        ui->btn_isEnable->setChecked(false);
        set_time(ui->txtl_pan_time->text().toInt());
    }
    else
        set_time(game_max_time);

}

void pan::on_btn_startgame_clicked()//开始游戏按钮
{
    if(ui->txtl_pan_time->isEnabled())
    {
        ui->txtl_pan_time->setEnabled(false);
        ui->btn_isEnable->setChecked(false);
        set_time(ui->txtl_pan_time->text().toInt());
    }
    else
        m->start();
    ui->txtl_pan_time->setEnabled(false);
    game_state = 1;
}

void pan::on_btn_stop_clicked()//游戏暂停按钮
{
    m->stop();
    game_state = 0;
}

void pan::on_btn_startgame_2_clicked()//继续游戏按钮(和开始游戏合并了，已删除)
{
    m->start();
    game_state = 1;

}

void pan::get_btn_sign(int idx)//处理下棋的81个按钮
{
    for(int i_=0;i_<9;i_++)
        for(int j_=0;j_<9;j_++)
            if(idx == i_*10+j_ && Qi[i_][j_] == 0 && game_state == 1)
            {
                now_time = game_max_time;
                QString temp = "btn_"+QString::number(i_)+"_"+QString::number(j_);
                QPushButton *button = this->findChild<QPushButton*>(temp);
                Qi[i_][j_] = now_player;                
                play_the_Go(button);
                judge();
            }

}

void pan::on_btn_restart_clicked()//再来一把按钮
{
    clear_pan();
    game_state = 1;
    now_player = -1;
}

void pan::on_btn_lose_clicked()//投降
{
    QMessageBox::information(NULL, "嘻嘻嘻嘻", "你投降了捏", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    game_state = 0;
    now_player = -1;
    clear_pan();
    ui->txtl_pan_time->setEnabled(true);
    m->stop();
}

void pan::on_btn_isEnable_clicked()
{
    if(ui->btn_isEnable->isChecked())
        ui->txtl_pan_time->setEnabled(true);
    else
        ui->txtl_pan_time->setEnabled(false);
}

