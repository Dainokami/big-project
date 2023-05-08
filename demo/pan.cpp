#include "pan.h"
#include "ui_pan.h"

pan::pan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pan)
{
    ui->setupUi(this);
    setWindowTitle("NOGO");


    connect(ui->rad_9x9,&QRadioButton::clicked,this,pan::change_pan);
    connect(ui->rad_11x11,&QRadioButton::clicked,this,pan::change_pan);
    connect(ui->rad_13x13,&QRadioButton::clicked,this,pan::change_pan);
    ui->btn_white->setStyleSheet("");
    ui->btn_black->setStyleSheet("background-color:black;border-radius:25px;border:2px groove gray;border-style:outset;");


    //以下设置定时器
    m = new QTimer(this);
    m->setInterval(1000);
    connect(m,&QTimer::timeout,this,pan::OnTimerCountdown);
    ui->txtl_pan_time->setText("50");

    //以下关联按钮
    QSignalMapper *myMapper = new QSignalMapper(this);
    QPushButton *button[13][13]={ui->btn_0_0,ui->btn_0_1,ui->btn_0_2,ui->btn_0_3,ui->btn_0_4,ui->btn_0_5,ui->btn_0_6,ui->btn_0_7,ui->btn_0_8,ui->btn_0_9,ui->btn_0_10,ui->btn_0_11,ui->btn_0_12,ui->btn_1_0,ui->btn_1_1,ui->btn_1_2,ui->btn_1_3,ui->btn_1_4,ui->btn_1_5,ui->btn_1_6,ui->btn_1_7,ui->btn_1_8,ui->btn_1_9,ui->btn_1_10,ui->btn_1_11,ui->btn_1_12,ui->btn_2_0,ui->btn_2_1,ui->btn_2_2,ui->btn_2_3,ui->btn_2_4,ui->btn_2_5,ui->btn_2_6,ui->btn_2_7,ui->btn_2_8,ui->btn_2_9,ui->btn_2_10,ui->btn_2_11,ui->btn_2_12,ui->btn_3_0,ui->btn_3_1,ui->btn_3_2,ui->btn_3_3,ui->btn_3_4,ui->btn_3_5,ui->btn_3_6,ui->btn_3_7,ui->btn_3_8,ui->btn_3_9,ui->btn_3_10,ui->btn_3_11,ui->btn_3_12,ui->btn_4_0,ui->btn_4_1,ui->btn_4_2,ui->btn_4_3,ui->btn_4_4,ui->btn_4_5,ui->btn_4_6,ui->btn_4_7,ui->btn_4_8,ui->btn_4_9,ui->btn_4_10,ui->btn_4_11,ui->btn_4_12,ui->btn_5_0,ui->btn_5_1,ui->btn_5_2,ui->btn_5_3,ui->btn_5_4,ui->btn_5_5,ui->btn_5_6,ui->btn_5_7,ui->btn_5_8,ui->btn_5_9,ui->btn_5_10,ui->btn_5_11,ui->btn_5_12,ui->btn_6_0,ui->btn_6_1,ui->btn_6_2,ui->btn_6_3,ui->btn_6_4,ui->btn_6_5,ui->btn_6_6,ui->btn_6_7,ui->btn_6_8,ui->btn_6_9,ui->btn_6_10,ui->btn_6_11,ui->btn_6_12,ui->btn_7_0,ui->btn_7_1,ui->btn_7_2,ui->btn_7_3,ui->btn_7_4,ui->btn_7_5,ui->btn_7_6,ui->btn_7_7,ui->btn_7_8,ui->btn_7_9,ui->btn_7_10,ui->btn_7_11,ui->btn_7_12,ui->btn_8_0,ui->btn_8_1,ui->btn_8_2,ui->btn_8_3,ui->btn_8_4,ui->btn_8_5,ui->btn_8_6,ui->btn_8_7,ui->btn_8_8,ui->btn_8_9,ui->btn_8_10,ui->btn_8_11,ui->btn_8_12,ui->btn_9_0,ui->btn_9_1,ui->btn_9_2,ui->btn_9_3,ui->btn_9_4,ui->btn_9_5,ui->btn_9_6,ui->btn_9_7,ui->btn_9_8,ui->btn_9_9,ui->btn_9_10,ui->btn_9_11,ui->btn_9_12,ui->btn_10_0,ui->btn_10_1,ui->btn_10_2,ui->btn_10_3,ui->btn_10_4,ui->btn_10_5,ui->btn_10_6,ui->btn_10_7,ui->btn_10_8,ui->btn_10_9,ui->btn_10_10,ui->btn_10_11,ui->btn_10_12,ui->btn_11_0,ui->btn_11_1,ui->btn_11_2,ui->btn_11_3,ui->btn_11_4,ui->btn_11_5,ui->btn_11_6,ui->btn_11_7,ui->btn_11_8,ui->btn_11_9,ui->btn_11_10,ui->btn_11_11,ui->btn_11_12,ui->btn_12_0,ui->btn_12_1,ui->btn_12_2,ui->btn_12_3,ui->btn_12_4,ui->btn_12_5,ui->btn_12_6,ui->btn_12_7,ui->btn_12_8,ui->btn_12_9,ui->btn_12_10,ui->btn_12_11,ui->btn_12_12};
    for(int i=0;i<length;i++)
        for(int j=0;j<length;j++)
        {
            connect(button[i][j],SIGNAL(clicked(bool)),myMapper,SLOT(map()));
            myMapper->setMapping(button[i][j],i*100+j);
        }
    connect(myMapper,SIGNAL(mappedInt(int)),this,SLOT(get_btn_sign(int)));

    //以下设置bgm
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    player->setSource(QUrl::fromLocalFile("E:\\Qt_project\\big_project\\demo\\image\\bgm.mp3"));
    audioOutput->setVolume(50);
    player->setLoops(INFINITY);
    player->play();
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
    player->stop();
    delete player;
    delete audioOutput;
    player = nullptr;
    audioOutput = nullptr;
    delete ui;
}

void pan::paintEvent(QPaintEvent *)
{
    paint=new QPainter;
    paint->begin(this);
    paint->setPen(QPen(Qt::black,2,Qt::SolidLine));
      for(int i=0;i<length;i++)
        {
          paint->drawLine(x,y+size*i,x+size*(length-1),y+size*i);//画线函数：x1,y1,x2,y2:画从(x1,y1)到(x2,y2)的线
        }
      //画lu+1条竖线
      for(int i=0;i<length;i++)
        {
          paint->drawLine(x+size*i,y,x+size*i,y+size*(length-1));
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
       fupan += "R";
       if(now_player==black_player)
       {
           black_time += game_max_time;
           all_time += game_max_time;
           black_time /= (now_step/2);
           white_time /= (now_step/2);

           QString infom = "黑棋你超时了捏\n恭喜胜者："+ui->line_player_1->text()+"(执白)\n你们的对局是："+fupan+"\n总步数为："+QString::number(now_step)+"\n黑方平均思考时间："+QString::number(black_time)+"\n白方平均思考时间："+QString::number(white_time)+"\n总思考时间："+QString::number(all_time)+"\n是否保存对局到本地？";
           int result = QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
           if(result == QMessageBox::Yes)
               save();
       }
       else
       {
           white_time += game_max_time;
           all_time += game_max_time;
           black_time /= ((now_step+1)/2);
           if(now_step!=1)
               white_time /= ((now_step-1)/2);
           QString infom = "白棋你超时了捏\n恭喜胜者："+ui->line_player_0->text()+"(执黑)\n你们的对局是："+fupan+"\n总步数为："+QString::number(now_step)+"\n黑方平均思考时间："+QString::number(black_time)+"\n白方平均思考时间："+QString::number(white_time)+"\n总思考时间："+QString::number(all_time)+"\n是否保存对局到本地？";
           int result = QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
           if(result == QMessageBox::Yes)
               save();
       }

        clear_pan();
        ui->txtl_pan_time->setEnabled(true);
        ui->line_player_0->setEnabled(true);
        ui->line_player_1->setEnabled(true);
        ui->rad_9x9->setEnabled(true);
        ui->rad_11x11->setEnabled(true);
        ui->rad_13x13->setEnabled(true);
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

void pan::play_the_Go(QPushButton *now_btn,QPushButton *last_btn)
{
    if(game_state == on)
    {
        if(now_player == white_player)
        {
            last_btn->setStyleSheet("background-color:black;border-radius:25px;border:2px groove gray;border-style:outset;");
            now_btn->setStyleSheet("background-color:white;border-radius:25px;border:2px groove red;border-style:outset;");
            now_btn->setEnabled(false);
            ui->btn_white->setStyleSheet("");
            ui->btn_black->setStyleSheet("background-color:black;border-radius:25px;border:2px groove gray;border-style:outset;");
        }
        else if(now_player == black_player)
        {
            last_btn->setStyleSheet("background-color:white;border-radius:25px;border:2px groove gray;border-style:outset;");
            now_btn->setStyleSheet("background-color:black;border-radius:25px;border:2px groove red;border-style:outset;");
            now_btn->setEnabled(false);
            ui->btn_white->setStyleSheet("background-color:white;border-radius:25px;border:2px groove gray;border-style:outset;");
            ui->btn_black->setStyleSheet("");
        }
    }
}

int pan::judge()//函数内部有分析
{
    for(int i=0;i<length;i++)
        for(int j=0;j<length;j++)
        {
            if(copy_Qi[now_step][i][j] == empty_unchecked)
                dfs(i,j,-1);
        }//用dfs重新绘制棋盘，本质是遍历，把子棋盘上“没查过的未落子处”坐标传进去。

    for(int i=0;i<length;i++)
        for(int j=0;j<length;j++)
        {
            if(copy_Qi[now_step][i][j] == white_loseQi_or_unchecked)
                white_flag = on;
            else if(copy_Qi[now_step][i][j] == black_loseQi_or_unchecked)
                black_flag = on;
        }//检查一遍子棋盘，康康有没有棋子没气了

    for(int i=0;i<length;i++)
        qDebug()<<Qi[i][0]<<Qi[i][1]<<Qi[i][2]<<Qi[i][3]<<Qi[i][4]<<Qi[i][5]<<Qi[i][6]<<Qi[i][7]<<Qi[i][8]<<Qi[i][9]<<Qi[i][10]<<Qi[i][11]<<Qi[i][12];
;
    for(int i=0;i<length;i++)
        qDebug()<<copy_Qi[now_step][i][0]<<copy_Qi[now_step][i][1]<<copy_Qi[now_step][i][2]<<copy_Qi[now_step][i][3]<<copy_Qi[now_step][i][4]<<copy_Qi[now_step][i][5]<<copy_Qi[now_step][i][6]<<copy_Qi[now_step][i][7]<<copy_Qi[now_step][i][8];
    if(black_flag== on && white_flag== on)
    {
        if(now_player== black_player)//黑白棋都没气且黑棋下了最后一步棋，判定黑棋无路可走而输
        {
            QMessageBox::information(this, "嘻嘻嘻嘻", "黑棋你要输了捏，下次注意点", QMessageBox::Yes , QMessageBox::Yes);
            return no;
        }
        else//黑白棋都没气且白棋下了最后一步棋，判定白棋无路可走而输
        {
            QMessageBox::information(NULL, "嘻嘻嘻嘻", "白棋你要输了捏，下次注意点", QMessageBox::Yes , QMessageBox::Yes);
            return no;
        }

    }
    else if(black_flag==on)//黑棋没气了。黑棋围的，鉴定为紫砂；白棋围的，鉴定为白棋输
    {
        if(now_player == black_player)
            QMessageBox::information(NULL, "嘻嘻嘻嘻", "黑棋要你紫砂了捏，下次注意点", QMessageBox::Yes , QMessageBox::Yes);
        else if(now_player == white_player)
            QMessageBox::information(NULL, "嘻嘻嘻嘻", "白棋你要输了捏，下次注意点", QMessageBox::Yes , QMessageBox::Yes);
        return no;
    }
    else if(white_flag ==on)//白棋没气了。白棋围的，鉴定为紫砂；黑棋围的，鉴定为白棋输
    {
        if(now_player == white_player)
            QMessageBox::information(NULL, "嘻嘻嘻嘻", "白棋你要紫砂了捏，下次注意点", QMessageBox::Yes , QMessageBox::Yes);
        else if(now_player == black_player)
            QMessageBox::information(NULL, "嘻嘻嘻嘻", "黑棋你要输了捏，下次注意点", QMessageBox::Yes , QMessageBox::Yes);
        return no;
    }

    return yes;
}

void pan::dfs(int x, int y,int flag)
//本质是通过dfs重新绘制一副棋盘，从未落子处开始，从未落子进入黑棋部分则是有气，从有气的黑棋进入为检查的黑棋也是有气，白棋同理。
//flag是指上一个坐标是如何进入现在的坐标的，即二维数组step的第一维，flag=-1一位这个坐标是直接从judge传来的未落子坐标
{
    if(copy_Qi[now_step][x][y] == empty_unchecked && flag == -1)
    {
        copy_Qi[now_step][x][y] = empty_checked;
        for(int i=0;i<4;i++)
            if(x+step[i][0]>=0 && x+step[i][0]<length && y+step[i][1]>=0 && y+step[i][1]<length && copy_Qi[now_step][x+step[i][0]][y+step[i][1]] != empty_unchecked && copy_Qi[now_step][x+step[i][0]][y+step[i][1]] != black_have_Qi && copy_Qi[now_step][x+step[i][0]][y+step[i][1]] != white_have_Qi)
            {    dfs(x+step[i][0] , y+step[i][1], i);}
        return;
    }

    if(Qi[x][y] == white_loseQi_or_unchecked)
    {
        if(Qi[x-step[flag][0]][y-step[flag][1]] == empty_unchecked)
        {
            copy_Qi[now_step][x][y] = white_have_Qi;
        }
        else if(copy_Qi[now_step][x-step[flag][0]][y-step[flag][1]] == white_have_Qi)
        {
            copy_Qi[now_step][x][y] = white_have_Qi;
        }
        else
            return;

        for(int i=0;i<4;i++)
            if(x+step[i][0]>=0 && x+step[i][0]<length && y+step[i][1]>=0 && y+step[i][1]<length && (i+2)%4 !=flag && copy_Qi[now_step][x+step[i][0]][y+step[i][1]] != empty_checked && copy_Qi[now_step][x+step[i][0]][y+step[i][1]] != black_have_Qi && copy_Qi[now_step][x+step[i][0]][y+step[i][1]] != white_have_Qi)
            {    dfs(x+step[i][0] , y+step[i][1], i);}
        return;
    }
    if(Qi[x][y] == black_loseQi_or_unchecked)
    {
        if(Qi[x-step[flag][0]][y-step[flag][1]] == empty_unchecked)
        {
            copy_Qi[now_step][x][y] = black_have_Qi;
        }
        else if(copy_Qi[now_step][x-step[flag][0]][y-step[flag][1]] == black_have_Qi)
        {
            copy_Qi[now_step][x][y] = black_have_Qi;
        }
        else
            return;

        for(int i=0;i<4;i++)
            if(x+step[i][0]>=0 && x+step[i][0]<length && y+step[i][1]>=0 && y+step[i][1]<length && (i+2)%4 !=flag && copy_Qi[now_step][x+step[i][0]][y+step[i][1]] != empty_checked && copy_Qi[now_step][x+step[i][0]][y+step[i][1]] != black_have_Qi && copy_Qi[now_step][x+step[i][0]][y+step[i][1]] != white_have_Qi)
            {    dfs(x+step[i][0] , y+step[i][1], i);}
        return;
    }



}

void pan::change_pan()
{
    if(ui->rad_9x9->isChecked())
        length = 9;
    else if(ui->rad_11x11->isChecked())
        length = 11;
    else if(ui->rad_13x13->isChecked())
        length = 13;

    pan::update();
    for(int i=0;i<13;i++)
        for(int j=0;j<13;j++)
        {
            QString temp = "btn_"+QString::number(i)+"_"+QString::number(j);
            QPushButton *button = this->findChild<QPushButton*>(temp);
            button->setEnabled(false);
        }
    for(int i=0;i<length;i++)
        for(int j=0;j<length;j++)
        {
            QString temp = "btn_"+QString::number(i)+"_"+QString::number(j);
            QPushButton *button = this->findChild<QPushButton*>(temp);
            button->setEnabled(true);
        }

}

void pan::clear_pan()
{
    black_flag=off;
    white_flag=off;
    now_step=0;
    loc = -1;
    fupan = "";
    black_time=0;
    white_time=0;
    all_time=0;

    for(int i=0;i<length;i++)
        for(int j=0;j<length;j++)
        {
            Qi[i][j] = empty_unchecked;

            for(int l=1;l<170;l++)
                copy_Qi[l][i][j]=empty_unchecked;

            QString temp = "btn_"+QString::number(i)+"_"+QString::number(j);
            QPushButton *button = this->findChild<QPushButton*>(temp);
            button->setStyleSheet("");
            button->setEnabled(true);

        }

    ui->btn_white->setStyleSheet("");
    ui->btn_black->setStyleSheet("background-color:black;border-radius:25px;border:2px groove gray;border-style:outset;");

    if(ui->txtl_pan_time->isEnabled())
    {
        ui->txtl_pan_time->setEnabled(false);
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
        set_time(ui->txtl_pan_time->text().toInt());
    }
    else
        m->start();
    ui->txtl_pan_time->setEnabled(false);
    ui->line_player_0->setEnabled(false);
    ui->line_player_1->setEnabled(false);
    ui->rad_9x9->setEnabled(false);
    ui->rad_11x11->setEnabled(false);
    ui->rad_13x13->setEnabled(false);
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

void pan::get_btn_sign(int idx)
{
    qDebug()<<idx;
    int i_=idx/100;
    int j_=idx%100;
    if(Qi[i_][j_] == empty_unchecked && game_state == on)
    {

        Qi[i_][j_] = now_player;

        for(int i=0;i<length;i++)
            for(int j=0;j<length;j++)
                copy_Qi[now_step][i][j] = Qi[i][j];


        if(judge())
        {
            now_step++;

            if(now_player==black_player)
                black_time += game_max_time - now_time;
            else
                white_time += game_max_time - now_time;
            all_time += game_max_time - now_time;
            now_time = game_max_time;


            if(loc == -1)
                loc = idx;
            QString now_btn_str = "btn_"+QString::number(i_)+"_"+QString::number(j_);
            QString last_btn_str = "btn_"+QString::number(loc/100)+"_"+QString::number(loc%100);
            QPushButton *now_btn = this->findChild<QPushButton*>(now_btn_str);
            QPushButton *last_btn = this->findChild<QPushButton*>(last_btn_str);

            play_the_Go(now_btn,last_btn);

            char tem = 'A'+i_;
            fupan = fupan + tem + QString::number(j_+1) + ' ';
            loc = idx;

            if(game_state == on)
            {
                if(now_player == white_player)
                    now_player = black_player;
                else if(now_player == black_player)
                    now_player = white_player;
            }


        }
        else
        {
            Qi[i_][j_]= empty_unchecked;
            white_flag=off;
            black_flag=off;
        }
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
    if(game_state == on)
    {
        m->stop();
        fupan += "G";
        if(now_player==black_player)
        {
            if(now_step != 0)
            {
                black_time /= (now_step/2);
                white_time /= (now_step/2);
            }
            now_step++;
            QString infom = "恭喜胜者："+ui->line_player_1->text()+"(执白)\n你们的对局是："+fupan+"\n总步数为："+QString::number(now_step)+"\n黑方平均思考时间："+QString::number(black_time)+"\n白方平均思考时间："+QString::number(white_time)+"\n总思考时间："+QString::number(all_time)+"\n是否保存对局到本地？";
            int result = QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
            if(result == QMessageBox::Yes)
                save();
        }
        else
        {
            black_time /= ((now_step+1)/2.0);
            if(now_step!=1)
                white_time /= ((now_step-1)/2.0);
            now_step++;
            QString infom = "恭喜胜者："+ui->line_player_0->text()+"(执黑)\n你们的对局是："+fupan+"\n总步数为："+QString::number(now_step)+"\n黑方平均思考时间："+QString::number(black_time)+"\n白方平均思考时间："+QString::number(white_time)+"\n总思考时间："+QString::number(all_time)+"\n是否保存对局到本地？";
            int result = QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
            if(result == QMessageBox::Yes)
                save();
        }
        game_state = off;
        now_player = black_player;
        clear_pan();
        ui->txtl_pan_time->setEnabled(true);
        ui->line_player_0->setEnabled(true);
        ui->line_player_1->setEnabled(true);
        ui->rad_9x9->setEnabled(true);
        ui->rad_11x11->setEnabled(true);
        ui->rad_13x13->setEnabled(true);
        m->stop();
    }
}

void pan::save()
{
    QFileDialog fileDialog;
    QString fileName = fileDialog.getSaveFileName(this,tr("Open File"),"/data",tr("Text File(*.txt)"));
    if(fileName == "")
    {
        return;
    }
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,tr("错误"),tr("打开文件失败"));
        return;
    }
    else
    {
        QTextStream out(&file);
        out<<fupan;
        QMessageBox::warning(this,tr("提示"),tr("载入文件成功"));
        file.close();
    }

}



