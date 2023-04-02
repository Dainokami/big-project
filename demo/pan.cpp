#include "pan.h"
#include "ui_pan.h"

pan::pan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pan)
{
    ui->setupUi(this);
    setWindowTitle("NOGO");

    //以下设置背景图
    QImage *img_pan = new QImage;
    img_pan->load("C:\\Users\\86130\\Desktop\\project\\pan2.jpg");
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

    //以下设置bgm
  /* player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player->setSource(QUrl::fromLocalFile("E:\\Qt_project\\big_project\\demo\\image\\bgm.mp3"));
    audioOutput->setVolume(50);
    player->setLoops(INFINITY);
    player->play();*/





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
void pan::paintEvent(QPaintEvent *)
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

void pan::set_time(int seted_time)
{
    game_max_time = seted_time;
    now_time = game_max_time;
    pan::BeginCountdown();
    QString temp = QString::number(seted_time);
    ui->txtl_pan_time->setText(temp);
}

void pan::BeginCountdown()
{
   if (m->isActive() == false)
   {
        m->start();
   }
}

void pan::OnTimerCountdown()
{
   now_time -= 1;
   ui->txtl_pan_time->setText(QString::number(now_time));

   if(now_time <= 0)
   {
       if(now_player==  white_player)
            QMessageBox::information(NULL, "嘻嘻嘻嘻", "白棋你超时了捏", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
       else if(now_player== black_player)
            QMessageBox::information(NULL, "嘻嘻嘻嘻", "黑棋你超时了捏", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

        clear_pan();
        ui->txtl_pan_time->setEnabled(true);
        ui->line_player_0->setEnabled(true);
        ui->line_player_1->setEnabled(true);
        ui->comboBox_2->setEnabled(true);
        ui->comboBox->setEnabled(true);
        game_state = off;
        now_player = black_player;
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

void pan::play_the_Go(QPushButton *btn)
{
    if(game_state == on)
    {
        if(now_player == white_player)
        {
            btn->setStyleSheet("background-color:white;border-radius:30px;border:2px groove gray;border-style:outset;");
            btn->setFlat(false);
        }
        else if(now_player == black_player)
        {
            btn->setStyleSheet("background-color:black;border-radius:30px;border:2px groove gray;border-style:outset;");
            btn->setFlat(false);
        }
    }
}

void pan::judge()//函数内部有分析
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            if(copy_Qi[i][j] == empty_unchecked)
                dfs(i,j,-1);
            num++;
        }//用dfs重新绘制棋盘，本质是遍历，把子棋盘上“没查过的未落子处”坐标传进去。

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            if(copy_Qi[i][j] == white_loseQi_or_unchecked)
                white_flag = on;
            else if(copy_Qi[i][j] == black_loseQi_or_unchecked)
                black_flag = on;
            num++;
        }//检查一遍子棋盘，康康有没有棋子没气了

    for(int i=0;i<9;i++)
        qDebug()<<Qi[i][0]<<Qi[i][1]<<Qi[i][2]<<Qi[i][3]<<Qi[i][4]<<Qi[i][5]<<Qi[i][6]<<Qi[i][7]<<Qi[i][8];

    for(int i=0;i<9;i++)
        qDebug()<<copy_Qi[i][0]<<copy_Qi[i][1]<<copy_Qi[i][2]<<copy_Qi[i][3]<<copy_Qi[i][4]<<copy_Qi[i][5]<<copy_Qi[i][6]<<copy_Qi[i][7]<<copy_Qi[i][8];
    qDebug()<<num;
    if(black_flag== on && white_flag== on)
    {
        if(now_player== black_player)//黑白棋都没气且黑棋下了最后一步棋，判定黑棋无路可走而输
        {
            m->stop();
            game_state = off;
            QMessageBox::information(NULL, "嘻嘻嘻嘻", "黑棋你输了捏", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            now_player = black_player;
            clear_pan();
            ui->txtl_pan_time->setEnabled(true);
            ui->line_player_0->setEnabled(true);
            ui->line_player_1->setEnabled(true);
            ui->comboBox_2->setEnabled(true);
            ui->comboBox->setEnabled(true);
            m->stop();
        }
        else//黑白棋都没气且白棋下了最后一步棋，判定白棋无路可走而输
        {
            m->stop();
            game_state = off;
            QMessageBox::information(NULL, "嘻嘻嘻嘻", "白棋你输了捏", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            now_player = black_player;
            clear_pan();
            ui->txtl_pan_time->setEnabled(true);
            ui->line_player_0->setEnabled(true);
            ui->line_player_1->setEnabled(true);
            ui->comboBox_2->setEnabled(true);
            ui->comboBox->setEnabled(true);
            m->stop();
        }

    }
    else if(black_flag==on)//黑棋没气了。黑棋围的，鉴定为紫砂；白棋围的，鉴定为白棋输
    {
        m->stop();
        game_state = off;
        if(now_player == black_player)
            QMessageBox::information(NULL, "嘻嘻嘻嘻", "黑棋你紫砂了捏", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        else if(now_player == white_player)
            QMessageBox::information(NULL, "嘻嘻嘻嘻", "白棋你输了捏", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        now_player = black_player;
        clear_pan();
        ui->txtl_pan_time->setEnabled(true);
        ui->line_player_0->setEnabled(true);
        ui->line_player_1->setEnabled(true);
        ui->comboBox_2->setEnabled(true);
        ui->comboBox->setEnabled(true);
        m->stop();
    }
    else if(white_flag ==on)//白棋没气了。白棋围的，鉴定为紫砂；黑棋围的，鉴定为白棋输
    {
        m->stop();
        game_state = off;
        if(now_player == white_player)
            QMessageBox::information(NULL, "嘻嘻嘻嘻", "白棋你紫砂了捏", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        else if(now_player == black_player)
            QMessageBox::information(NULL, "嘻嘻嘻嘻", "黑棋你输了捏", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        now_player = black_player;
        clear_pan();
        ui->txtl_pan_time->setEnabled(true);
        ui->line_player_0->setEnabled(true);
        ui->line_player_1->setEnabled(true);
        ui->comboBox_2->setEnabled(true);
        ui->comboBox->setEnabled(true);
        m->stop();
    }


}

void pan::dfs(int x, int y,int flag)
//本质是通过dfs重新绘制一副棋盘，从未落子处开始，从未落子进入黑棋部分则是有气，从有气的黑棋进入为检查的黑棋也是有气，白棋同理。
//flag是指上一个坐标是如何进入现在的坐标的，即二维数组step的第一维，flag=-1一位这个坐标是直接从judge传来的未落子坐标
{
    if(copy_Qi[x][y] == empty_unchecked && flag == -1)
    {
        copy_Qi[x][y] = empty_checked;
        for(int i=0;i<4;i++)
            if(x+step[i][0]>=0 && x+step[i][0]<9 && y+step[i][1]>=0 && y+step[i][1]<9 && copy_Qi[x+step[i][0]][y+step[i][1]] != empty_unchecked && copy_Qi[x+step[i][0]][y+step[i][1]] != black_have_Qi && copy_Qi[x+step[i][0]][y+step[i][1]] != white_have_Qi)
            {    dfs(x+step[i][0] , y+step[i][1], i);num++;}
        return;
    }

    if(Qi[x][y] == white_loseQi_or_unchecked)
    {
        if(Qi[x-step[flag][0]][y-step[flag][1]] == empty_unchecked)
        {
            copy_Qi[x][y] = white_have_Qi;
        }
        else if(copy_Qi[x-step[flag][0]][y-step[flag][1]] == white_have_Qi)
        {
            copy_Qi[x][y] = white_have_Qi;
        }
        else
            return;

        for(int i=0;i<4;i++)
            if(x+step[i][0]>=0 && x+step[i][0]<9 && y+step[i][1]>=0 && y+step[i][1]<9 && (i+2)%4 !=flag && copy_Qi[x+step[i][0]][y+step[i][1]] != empty_checked && copy_Qi[x+step[i][0]][y+step[i][1]] != black_have_Qi && copy_Qi[x+step[i][0]][y+step[i][1]] != white_have_Qi)
            {    dfs(x+step[i][0] , y+step[i][1], i);num++;}
        return;
    }
    if(Qi[x][y] == black_loseQi_or_unchecked)
    {
        if(Qi[x-step[flag][0]][y-step[flag][1]] == empty_unchecked)
        {
            copy_Qi[x][y] = black_have_Qi;
        }
        else if(copy_Qi[x-step[flag][0]][y-step[flag][1]] == black_have_Qi)
        {
            copy_Qi[x][y] = black_have_Qi;
        }
        else
            return;

        for(int i=0;i<4;i++)
            if(x+step[i][0]>=0 && x+step[i][0]<9 && y+step[i][1]>=0 && y+step[i][1]<9 && (i+2)%4 !=flag && copy_Qi[x+step[i][0]][y+step[i][1]] != empty_checked && copy_Qi[x+step[i][0]][y+step[i][1]] != black_have_Qi && copy_Qi[x+step[i][0]][y+step[i][1]] != white_have_Qi)
            {    dfs(x+step[i][0] , y+step[i][1], i);num++;}
        return;
    }



}

void pan::clear_pan()
{
    black_flag=off;
    white_flag=off;

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            Qi[i][j] = empty_unchecked;
            copy_Qi[i][j]=empty_unchecked;
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

void pan::on_btn_startgame_clicked()
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
    ui->line_player_0->setEnabled(false);
    ui->line_player_1->setEnabled(false);
    ui->comboBox_2->setEnabled(false);
    ui->comboBox->setEnabled(false);
    game_state = on;
}

void pan::on_btn_stop_clicked()
{
    if(game_state ==on)
    {
        m->stop();
        game_state = off;

    }
    else if(game_state == off)
    {
        this->on_btn_startgame_clicked();
    }


}

void pan::on_btn_startgame_2_clicked()
{
    m->start();
    game_state = on;

}

void pan::get_btn_sign(int idx)
{
    for(int i_=0;i_<9;i_++)
        for(int j_=0;j_<9;j_++)
            if(idx == i_*10+j_ && Qi[i_][j_] == empty_unchecked && game_state == on)
            {
                now_time = game_max_time;
                QString temp = "btn_"+QString::number(i_)+"_"+QString::number(j_);
                QPushButton *button = this->findChild<QPushButton*>(temp);
                Qi[i_][j_] = now_player;

                for(int i=0;i<9;i++)
                    for(int j=0;j<9;j++)
                        copy_Qi[i][j] = Qi[i][j];


                play_the_Go(button);
                judge();
                if(game_state == on)
                {
                    if(now_player == white_player)
                        now_player = black_player;
                    else if(now_player == black_player)
                        now_player = white_player;
                }
                break;
            }

}

void pan::on_btn_restart_clicked()
{
    clear_pan();
    game_state = on;
    now_player = black_player;
}

void pan::on_btn_lose_clicked()
{
    m->stop();
    QMessageBox::information(NULL, "嘻嘻嘻嘻", "你投降了捏", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    game_state = off;
    now_player = black_player;
    clear_pan();
    ui->txtl_pan_time->setEnabled(true);
    ui->line_player_0->setEnabled(true);
    ui->line_player_1->setEnabled(true);
    ui->comboBox_2->setEnabled(true);
    ui->comboBox->setEnabled(true);
    m->stop();
}

void pan::on_btn_isEnable_clicked()
{
    if(ui->btn_isEnable->isChecked())
        ui->txtl_pan_time->setEnabled(true);
    else
        ui->txtl_pan_time->setEnabled(false);
}

