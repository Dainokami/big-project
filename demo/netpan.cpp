#include "netpan.h"
#include "ui_netpan.h"

netpan::netpan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::netpan)
{
    ui->setupUi(this);
    setWindowTitle("NOGO");


    ui->btn_white->setStyleSheet("");
    ui->btn_black->setStyleSheet("background-color:black;border-radius:25px;border:2px groove gray;border-style:outset;");
    connect(this->ui->choseb,&QRadioButton::clicked,this,&netpan::chose_color_and_name);
    connect(this->ui->chosew,&QRadioButton::clicked,this,&netpan::chose_color_and_name);
    connect(this->ui->checkai, &QCheckBox::stateChanged, this, &netpan::onCheckBoxAIStateChanged);

    // 本地 IP，所有电脑都可以用这个 IP 指向自己
    IP = "127.0.0.1";
    // 端口，不要太简单，要避免和别的软件冲突
    PORT = 16667;

    this->ui->IPEdit->setText(IP);
    this->ui->PORTEdit->setText(QString::number(PORT));

    // 创建一个服务端
    this->server = new NetworkServer(this);

    lastOne = nullptr;

    // 创建一个客户端
    this->socket = new NetworkSocket(new QTcpSocket(),this);

    connect(this->socket->base(),&QTcpSocket::connected,this,[&](){this->ui->connectLabel->setText("connection succeed");netlog = QString::number(QDateTime::currentMSecsSinceEpoch()) + username + "连接服务器成功\n";qDebug()<<netlog;});
    connect(this->socket,&NetworkSocket::receive,this,&netpan::receieveDataFromServer);
    connect(this->server,&NetworkServer::receive,this,&netpan::receieveData);
    connect(this->ui->reSetButton,&QPushButton::clicked,this,&netpan::reSet);
    connect(this->ui->reConnectButton,&QPushButton::clicked,this,&netpan::reConnect);
    connect(this->ui->reStartButton,&QPushButton::clicked,this,&netpan::reStart);
    // 客户端向 IP:PORT 连接，不会连到自己
    this->socket->hello(IP,PORT);
    // 阻塞等待，2000ms超时
    this->socket->base()->waitForConnected(2000);


    //以下设置定时器
    m = new QTimer(this);
    m->setInterval(1000);
    connect(m,&QTimer::timeout,this,netpan::OnTimerCountdown);
    ui->txtl_pan_time->setText("50");
    ai=new AI();
    //以下关联按钮
    QSignalMapper *myMapper = new QSignalMapper(this);
    QPushButton *button[9][9]={ui->btn_0_0,ui->btn_0_1,ui->btn_0_2,ui->btn_0_3,ui->btn_0_4,ui->btn_0_5,ui->btn_0_6,ui->btn_0_7,ui->btn_0_8,ui->btn_1_0,ui->btn_1_1,ui->btn_1_2,ui->btn_1_3,ui->btn_1_4,ui->btn_1_5,ui->btn_1_6,ui->btn_1_7,ui->btn_1_8,ui->btn_2_0,ui->btn_2_1,ui->btn_2_2,ui->btn_2_3,ui->btn_2_4,ui->btn_2_5,ui->btn_2_6,ui->btn_2_7,ui->btn_2_8,ui->btn_3_0,ui->btn_3_1,ui->btn_3_2,ui->btn_3_3,ui->btn_3_4,ui->btn_3_5,ui->btn_3_6,ui->btn_3_7,ui->btn_3_8,ui->btn_4_0,ui->btn_4_1,ui->btn_4_2,ui->btn_4_3,ui->btn_4_4,ui->btn_4_5,ui->btn_4_6,ui->btn_4_7,ui->btn_4_8,ui->btn_5_0,ui->btn_5_1,ui->btn_5_2,ui->btn_5_3,ui->btn_5_4,ui->btn_5_5,ui->btn_5_6,ui->btn_5_7,ui->btn_5_8,ui->btn_6_0,ui->btn_6_1,ui->btn_6_2,ui->btn_6_3,ui->btn_6_4,ui->btn_6_5,ui->btn_6_6,ui->btn_6_7,ui->btn_6_8,ui->btn_7_0,ui->btn_7_1,ui->btn_7_2,ui->btn_7_3,ui->btn_7_4,ui->btn_7_5,ui->btn_7_6,ui->btn_7_7,ui->btn_7_8,ui->btn_8_0,ui->btn_8_1,ui->btn_8_2,ui->btn_8_3,ui->btn_8_4,ui->btn_8_5,ui->btn_8_6,ui->btn_8_7,ui->btn_8_8};
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
    connect(player, SIGNAL(QMediaPlayer::positionChanged(qint64)), this, SLOT(QMediaPlayer::positionChanged(qint64)));
    player->setSource(QUrl::fromLocalFile("E:\\Qt_project\\big_project\\demo\\image\\bgm.mp3"));
    audioOutput->setVolume(50);
    player->setLoops(INFINITY);
    player->play();
}

netpan::~netpan()
{
    delete ai;
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

    netlog = QString::number(now_step+1) + "  send to  " +fightername + "  LEAVE_OP  ";
    qDebug()<<netlog;

    if(mode == SOCKET)
        this->socket->send(NetworkData(OPCODE::LEAVE_OP,username,""));
    else if(mode == SERVER)
    {
        if(lastOne)
            this->server->send(lastOne,NetworkData(OPCODE::LEAVE_OP,username,""));
    }


        this->socket->bye();

    delete ui;
}

void netpan::onCheckBoxAIStateChanged(int state)
{
    checkAI_state=state;
}

void netpan::paintEvent(QPaintEvent *)
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
     paint->end();
}

void netpan::set_time(int seted_time)
{
    game_max_time = seted_time;
    now_time = game_max_time;
    netpan::BeginCountdown();
    QString temp = QString::number(seted_time);
    ui->txtl_pan_time->setText(temp);
}

void netpan::BeginCountdown()
{
   if (m->isActive() == false)
   {
        m->start();
   }
}

void netpan::OnTimerCountdown()
{
    if(game_state == on &&firstmove==1)
    {

        now_time -= 1;
        ui->txtl_pan_time->setText(QString::number(now_time));
        if(now_player==mycolor)
            ui->btn_lose->setEnabled(true);


        if(now_time <= 0)
        {
            fupan += "T";
            if(now_player!=mycolor)
            {
                //算时间
                if(mycolor == black_player)
                {
                    black_time += game_max_time;
                    all_time += game_max_time;
                    black_time /= (now_step/2);
                    white_time /= (now_step/2);
                }
                else
                {
                    white_time += game_max_time;
                    all_time += game_max_time;
                    black_time /= ((now_step+1)/2);
                    if(now_step!=1)
                        white_time /= ((now_step-1)/2);
                }

                //告知对方超时
                netlog = QString::number(now_step+1) + "  send to  " +fightername + "  TIMEOUT_END_OP  ";
                qDebug()<<netlog;

                if(mode == SOCKET)
                    this->socket->send(NetworkData(OPCODE::TIMEOUT_END_OP,username,""));
                else if(mode == SERVER)
                {
                    if(lastOne)
                        this->server->send(lastOne,NetworkData(OPCODE::TIMEOUT_END_OP,username,""));
                }
                GGtimes++;

                QString infom = "哈哈"+fightername+"超时了捏\n我赢辣："+"\n我们的对局是："+fupan+"\n总步数为："+QString::number(now_step)+"\n黑方平均思考时间："+QString::number(black_time)+"\n白方平均思考时间："+QString::number(white_time)+"\n总思考时间："+QString::number(all_time)+"\n是否保存对局到本地？";
                int result = QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
                if(result == QMessageBox::Yes)
                save();
                clear_pan();
            }

            ui->txtl_pan_time->setEnabled(true);
            ui->line_player_0->setEnabled(true);
            ui->line_player_1->setEnabled(true);
            game_state = off;
            m->stop();
        }
    }
}

/*void netpan::on_btn_stop_clicked()
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
*/
void netpan::delete_time()
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

void netpan::play_the_Go(QPushButton *now_btn,QPushButton *last_btn)
{
    if(game_state == on )
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

int netpan::judge()//函数内部有分析
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

void netpan::dfs(int x, int y,int flag)
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

void netpan::clear_pan()
{
    black_flag=off;
    white_flag=off;
    now_step=0;
    loc = -1;
    fupan = "";
    black_time=0;
    white_time=0;
    all_time=0;
    GGtimes=0;
    netlog = "";
    isWinner = 0;
    isbeginner = 0;
    firstmove=false;

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
    ui->choseb->setEnabled(true);
    ui->chosew->setEnabled(true);
    ui->btn_lose->setEnabled(false);

    if(ui->txtl_pan_time->isEnabled())
    {
        ui->txtl_pan_time->setEnabled(false);
        set_time(ui->txtl_pan_time->text().toInt());
    }
    else
        set_time(game_max_time);

}

void netpan::on_btn_startgame_clicked()
{
    now_player = black_player;
    isbeginner = 1;
    if(mode == SOCKET && game_state == off)
    {
        netlog = QString::number(now_step+1) + "  send to  " +fightername + "  READY_OP  ";
        qDebug()<<netlog;
        if(mycolor == black_player)
            this->socket->send(NetworkData(OPCODE::READY_OP,username,"b"));
        else
            this->socket->send(NetworkData(OPCODE::READY_OP,username,"w"));

    }
    else if(mode == SERVER && game_state == off)
    {
        netlog = QString::number(now_step+1) + "  send to  " +fightername + "  READY_OP  ";
        qDebug()<<netlog;
        if(mycolor == black_player)
        {
            if(lastOne)
                this->server->send(lastOne,NetworkData(OPCODE::READY_OP,username,"b"));
        }
        else
        {
            if(lastOne)
                this->server->send(lastOne,NetworkData(OPCODE::READY_OP,username,"w"));
        }
    }
    else if(game_state == on)
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

    }


}

void netpan::get_btn_sign(int idx)
{
    int i_=idx/100;
    int j_=idx%100;
    if(Qi[i_][j_] == empty_unchecked && game_state == on && now_player==mycolor)
    {

        Qi[i_][j_] = now_player;

        for(int i=0;i<length;i++)
            for(int j=0;j<length;j++)
                copy_Qi[now_step][i][j] = Qi[i][j];


        //传给对手
        char tem = 'A'+i_;
        QString temstr = tem + QString::number(j_+1);
        if(!firstmove)
            firstmove=true;

        if(mode == SOCKET)
            this->socket->send(NetworkData(OPCODE::MOVE_OP,temstr,""));
        else if(mode == SERVER)
        {
            if(lastOne)
                this->server->send(lastOne,NetworkData(OPCODE::MOVE_OP,temstr,""));
        }
        netlog = QString::number(now_step+1) + "  send to  " +fightername + "  MOVE_OP  "+temstr;
        qDebug()<<netlog;

        if(judge())
        {
            now_step++;
            //设置时间
            if(now_player==black_player)
                black_time += game_max_time - now_time;
            else
                white_time += game_max_time - now_time;
            all_time += game_max_time - now_time;
            now_time = game_max_time ;

            //绘制棋子
            if(loc == -1)
                loc = idx;
            QString now_btn_str = "btn_"+QString::number(i_)+"_"+QString::number(j_);
            QString last_btn_str = "btn_"+QString::number(loc/100)+"_"+QString::number(loc%100);
            QPushButton *now_btn = this->findChild<QPushButton*>(now_btn_str);
            QPushButton *last_btn = this->findChild<QPushButton*>(last_btn_str);
            play_the_Go(now_btn,last_btn);
            ui->btn_lose->setEnabled(false);


            //制作复盘
            fupan = fupan + tem + QString::number(j_+1) + ' ';
            loc = idx;

            //切换棋手
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

void netpan::get_online_sign(int idx)
{
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
            ui->btn_lose->setEnabled(true);

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

            netlog = QString::number(now_step+1) + "  send to  " +fightername + "  SUICIDE_OP  ";
            qDebug()<<netlog;

            if(mode == SOCKET)
                this->socket->send(NetworkData(OPCODE::SUICIDE_END_OP,username,""));
            else if(mode == SERVER)
            {
                if(lastOne)
                    this->server->send(lastOne,NetworkData(OPCODE::SUICIDE_END_OP,username,""));
            }
            GGtimes++;
        }
    }

    //
    if(checkAI_state == Qt::Checked)
    {
        get_btn_sign(ai.AImakeMove(Qi[9][9]));
    }
}

void netpan::on_btn_lose_clicked()
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
        }
        else
        {
            black_time /= ((now_step+1)/2.0);
            if(now_step!=1)
                white_time /= ((now_step-1)/2.0);
            now_step++;

        }

        QString infom = "我输辣\n恭喜胜者："+fightername+"\n我们的对局是："+fupan+"\n总步数为："+QString::number(now_step)+"\n黑方平均思考时间："+QString::number(black_time)+"\n白方平均思考时间："+QString::number(white_time)+"\n总思考时间："+QString::number(all_time)+"\n是否保存对局到本地？";
        int result = QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        if(result == QMessageBox::Yes)
            save();

        netlog = QString::number(now_step+1) + "  send to  " +fightername + "  GIVEUP_OP  ";
        qDebug()<<netlog;

        if(mode == SOCKET)
            this->socket->send(NetworkData(OPCODE::GIVEUP_OP,username,""));
        else if(mode == SERVER)
        {
            if(lastOne)
                this->server->send(lastOne,NetworkData(OPCODE::GIVEUP_OP,username,""));
        }

        game_state = off;
        m->stop();
    }
}

void netpan::save()
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

void netpan::on_sendbtn_clicked()
{
    netlog = QString::number(now_step+1) + "  send to  " +fightername + "  CHAT_OP  ";
    qDebug()<<netlog;

    if(mode == SOCKET)
        this->socket->send(NetworkData(OPCODE::CHAT_OP,this->ui->Chatline->text(),"send by client"));
    else if(mode == SERVER)
    {
        if(lastOne)
            this->server->send(lastOne,NetworkData(OPCODE::CHAT_OP,this->ui->Chatline->text(),"send by server"));
    }

    QString text = this->ui->Chatline->text();
    QString data = username + "\t" + text;
    this->ui->Chatline->setText("");
    this->ui->Chatplain->appendPlainText(data+"\n");
}

void netpan::receieveData(QTcpSocket* client, NetworkData data)
{
    lastOne=client;
    // 获得地址的字符串表示，调试用
    QString ptrStr = QString("0x%1").arg((quintptr)client,
                        QT_POINTER_SIZE, 16, QChar('0'));
    //this->ui->lastOneLabel->setText("LastOne: "+ptrStr);
    this->clients.insert(client);
    if(data.op == OPCODE::CHAT_OP)
    {
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  CHAT_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;
        QString temdata = fightername + "\t" + data.data1;
        this->ui->Chatplain->appendPlainText(temdata+"\n");
    }
    else if(data.op == OPCODE::MOVE_OP && game_state == on && now_player!=mycolor)
    {
        if(!firstmove)
            firstmove=true;
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  MOVE_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;
        char*  ch;
        QByteArray ba = data.data1.left(1).toLatin1(); // must
        ch=ba.data();
        int idx = (*ch-'A') * 100 + data.data1.mid(1).toInt()-1;
        get_online_sign(idx);

    }
    else if(data.op == OPCODE::READY_OP&&game_state == off)
    {
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  READY_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;
        fightername = data.data1;

        if(isbeginner)
        {

            if(mycolor == black_player)
                ui->line_player_1->setText(fightername);
            else
                ui->line_player_0->setText(fightername);

            game_state = on;
            on_btn_startgame_clicked();
            ui->choseb->setEnabled(false);
            ui->chosew->setEnabled(false);
        }
        else
        {
            QString temstr = "";
            if(data.data2 == 'w')
                temstr = data.data1  + "(执白)向你发送对局邀请";
            else
                temstr = data.data1  + "(执黑)向你发送对局邀请";
            fightername = data.data1;

            int result = QMessageBox::information(NULL, temstr, "是否接受", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
            if(result == QMessageBox::Yes)
            {


                netlog = QString::number(now_step+1) + "  send to  " +fightername + "  READY_OP  ";
                qDebug()<<netlog;

                if(lastOne)
                    this->server->send(lastOne,NetworkData(OPCODE::READY_OP,username,""));


                if(data.data2 == 'w')
                {
                    mycolor = black_player;
                    ui->line_player_0->setText(username);
                    ui->line_player_1->setText(fightername);
                    ui->choseb->click();
                }
                else
                {
                    mycolor = white_player;
                    ui->line_player_1->setText(username);
                    ui->line_player_0->setText(fightername);
                    ui->chosew->click();
                }
                game_state = on;
                on_btn_startgame_clicked();
                ui->choseb->setEnabled(false);
                ui->chosew->setEnabled(false);
            }
            else if(result == QMessageBox::No)
            {
                netlog = QString::number(now_step+1) + "  send to  " +fightername + "  REJECT_OP  ";
                qDebug()<<netlog;

                if(lastOne)
                    this->server->send(lastOne,NetworkData(OPCODE::REJECT_OP,username,""));
            }
        }
    }
    else if(data.op == OPCODE::REJECT_OP)
    {
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  REJECT_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;
        isbeginner=0;
    }
    else if(data.op == OPCODE::TIMEOUT_END_OP)
    {
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  TIMEOUT_END_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;
        if(now_time<=1 && now_player == mycolor && GGtimes == 0)
        {
            netlog = QString::number(now_step+1) + "  send to  " +fightername + "  TIMEOUT_END_OP  ";
            qDebug()<<netlog;
            if(lastOne)
                this->server->send(lastOne,NetworkData(OPCODE::TIMEOUT_END_OP,username,"这仇我记下了"));


            m->stop();
            if(mycolor == black_player)
            {
                black_time += game_max_time;
                all_time += game_max_time;
                black_time /= (now_step/2);
                white_time /= (now_step/2);
            }
            else
            {
                white_time += game_max_time;
                all_time += game_max_time;
                black_time /= ((now_step+1)/2);
                if(now_step!=1)
                    white_time /= ((now_step-1)/2);
            }

            QString infom = "NOOOOO我超时了\n恭喜胜者："+fightername+"(执黑)\n我们的对局是："+fupan+"\n总步数为："+QString::number(now_step)+"\n黑方平均思考时间："+QString::number(black_time)+"\n白方平均思考时间："+QString::number(white_time)+"\n总思考时间："+QString::number(all_time)+"\n是否保存对局到本地？";
            int result = QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
            if(result == QMessageBox::Yes)
            save();
            clear_pan();
            ui->txtl_pan_time->setEnabled(true);
            ui->line_player_0->setEnabled(true);
            ui->line_player_1->setEnabled(true);
            game_state = off;


        }
        else if(now_time>1 && now_player == mycolor && GGtimes == 0){m->stop();}
        else if(GGtimes>0)
        {
            clear_pan();
            ui->txtl_pan_time->setEnabled(true);
            ui->line_player_0->setEnabled(true);
            ui->line_player_1->setEnabled(true);
            game_state = off;
            m->stop();
        }
        GGtimes++;
    }
    else if(data.op == OPCODE::GIVEUP_OP)
    {
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  GIVEUP_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;
        fupan += "G";
        isWinner = 1;
        if(now_player==black_player)
        {
            if(now_step != 0)
            {
                black_time /= (now_step/2);
                white_time /= (now_step/2);
            }
            now_step++;
        }
        else
        {
            black_time /= ((now_step+1)/2.0);
            if(now_step!=1)
                white_time /= ((now_step-1)/2.0);
            now_step++;

        }
        QString infom = "对方输辣\n恭喜胜者："+username+"\n我们的对局是："+fupan+"\n总步数为："+QString::number(now_step)+"\n黑方平均思考时间："+QString::number(black_time)+"\n白方平均思考时间："+QString::number(white_time)+"\n总思考时间："+QString::number(all_time)+"\n是否保存对局到本地？";
        int result = QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        if(result == QMessageBox::Yes)
            save();
        netlog = QString::number(now_step+1) + "  send to  " +fightername + "  GIVEUP_END_OP  ";
        qDebug()<<netlog;

        if(lastOne)
            this->server->send(lastOne,NetworkData(OPCODE::GIVEUP_END_OP,username,""));




    }
    else if(data.op == OPCODE::GIVEUP_END_OP)
    {
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  GIVEUP_END_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;

        if(!isWinner)
        {
            netlog = QString::number(now_step+1) + "  send to  " +fightername + "  GIVEUP_END_OP  ";
            qDebug()<<netlog;
            if(lastOne)
                this->server->send(lastOne,NetworkData(OPCODE::GIVEUP_END_OP,username,""));
        }
        clear_pan();
        ui->txtl_pan_time->setEnabled(true);
        ui->line_player_0->setEnabled(true);
        ui->line_player_1->setEnabled(true);
        game_state = off;
        m->stop();
    }
    else if(data.op == OPCODE::SUICIDE_END_OP)
    {
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  SUICIDE_END_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;
        if(GGtimes == 0)
        {
           m->stop();
           QString temstr = data.data1  + "认为你落子非法输了";
           int result = QMessageBox::information(NULL, temstr, "是否接受", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
           if(result == QMessageBox::Yes)
           {
               netlog = QString::number(now_step+1) + "  send to  " +fightername + "  SUICIDE_OP  ";
               qDebug()<<netlog;
               if(lastOne)
                   this->server->send(lastOne,NetworkData(OPCODE::SUICIDE_END_OP,username,""));
               clear_pan();
               ui->txtl_pan_time->setEnabled(true);
               ui->line_player_0->setEnabled(true);
               ui->line_player_1->setEnabled(true);
               game_state = off;
               m->stop();
           }
           else if(result == QMessageBox::No){m->stop();}
        }
        else
        {
            clear_pan();
            ui->txtl_pan_time->setEnabled(true);
            ui->line_player_0->setEnabled(true);
            ui->line_player_1->setEnabled(true);
            game_state = off;
            m->stop();
        }
    }
    else if(data.op == OPCODE::LEAVE_OP)
    {
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  LEAVE_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;
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
            }
            else
            {
                black_time /= ((now_step+1)/2.0);
                if(now_step!=1)
                    white_time /= ((now_step-1)/2.0);
                now_step++;

            }

            QString infom = "对方离开了比赛\n恭喜胜者："+username+"\n我们的对局是："+fupan+"\n总步数为："+QString::number(now_step)+"\n黑方平均思考时间："+QString::number(black_time)+"\n白方平均思考时间："+QString::number(white_time)+"\n总思考时间："+QString::number(all_time)+"\n是否保存对局到本地？";
            int result = QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
            if(result == QMessageBox::Yes)
                save();
            game_state = off;
            clear_pan();
            ui->txtl_pan_time->setEnabled(true);
            ui->line_player_0->setEnabled(true);
            ui->line_player_1->setEnabled(true);
            m->stop();
        }
    }

}

void netpan::receieveDataFromServer(NetworkData data)
{
    if(data.op == OPCODE::CHAT_OP)
    {
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  CHAT_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;
        QString temdata = fightername + "\t" + data.data1;
        this->ui->Chatplain->appendPlainText(temdata+"\n");
    }
    else if(data.op == OPCODE::MOVE_OP && game_state == on && now_player!=mycolor)
    {
        if(!firstmove)
            firstmove=true;

        netlog = QString::number(now_step+1) + "  get  " +fightername + "  MOVE_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;
        char*  ch;
        QByteArray ba = data.data1.left(1).toLatin1(); // must
        ch=ba.data();
        int idx = (*ch-'A') * 100 + data.data1.mid(1).toInt()-1;
        get_online_sign(idx);
    }
    else if(data.op == OPCODE::READY_OP)
    {
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  READY_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;
        fightername = data.data1;

        if(isbeginner)
        {

            if(mycolor == black_player)
                ui->line_player_1->setText(fightername);
            else
                ui->line_player_0->setText(fightername);

            game_state = on;
            on_btn_startgame_clicked();
            ui->choseb->setEnabled(false);
            ui->chosew->setEnabled(false);
        }
        else
        {
            QString temstr = "";
            if(data.data2 == 'w')
                temstr = data.data1  + "(执白)向你发送对局邀请";
            else
                temstr = data.data1  + "(执黑)向你发送对局邀请";


            int result = QMessageBox::information(NULL, temstr, "是否接受", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
            if(result == QMessageBox::Yes)
            {
                netlog = QString::number(now_step+1) + "  send to  " +fightername + "  READY_OP  ";
                qDebug()<<netlog;

                this->socket->send(NetworkData(OPCODE::READY_OP,username,""));
                if(data.data2 == 'w')
                {
                    mycolor = black_player;
                    ui->line_player_0->setText(username);
                    ui->line_player_1->setText(fightername);
                    ui->choseb->click();
                }
                else
                {
                    mycolor = white_player;
                    ui->line_player_1->setText(username);
                    ui->line_player_0->setText(fightername);
                    ui->chosew->click();
                }
                game_state = on;
                on_btn_startgame_clicked();
                ui->choseb->setEnabled(false);
                ui->chosew->setEnabled(false);
            }
            else if(result == QMessageBox::No)
            {
                netlog = QString::number(now_step+1) + "  send to  " +fightername + "  REJECT_OP  ";
                qDebug()<<netlog;
                if(lastOne)
                    this->socket->send(NetworkData(OPCODE::REJECT_OP,username,""));
            }
        }
    }
    else if(data.op == OPCODE::REJECT_OP)
    {
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  REJECT_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;
        isbeginner=0;
    }
    else if(data.op == OPCODE::TIMEOUT_END_OP)
    {
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  TIMEOUT_END_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;
        if(now_time<=1 && now_player == mycolor && GGtimes == 0)
        {
            netlog = QString::number(now_step+1) + "  send to  " +fightername + "  TIMEOUT_END_OP  ";
            qDebug()<<netlog;
            if(lastOne)
                this->socket->send(NetworkData(OPCODE::TIMEOUT_END_OP,username,"这仇我记下了"));


            m->stop();
            if(mycolor == black_player)
            {
                black_time += game_max_time;
                all_time += game_max_time;
                black_time /= (now_step/2);
                white_time /= (now_step/2);
            }
            else
            {
                white_time += game_max_time;
                all_time += game_max_time;
                black_time /= ((now_step+1)/2);
                if(now_step!=1)
                    white_time /= ((now_step-1)/2);
            }

            QString infom = "NOOOOO我超时了\n恭喜胜者："+fightername+"(执黑)\n我们的对局是："+fupan+"\n总步数为："+QString::number(now_step)+"\n黑方平均思考时间："+QString::number(black_time)+"\n白方平均思考时间："+QString::number(white_time)+"\n总思考时间："+QString::number(all_time)+"\n是否保存对局到本地？";
            int result = QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
            if(result == QMessageBox::Yes)
            save();
            clear_pan();
            ui->txtl_pan_time->setEnabled(true);
            ui->line_player_0->setEnabled(true);
            ui->line_player_1->setEnabled(true);
            game_state = off;


        }
        else if(now_time>1 && now_player == mycolor && GGtimes == 0){m->stop();}
        else if(GGtimes>0)
        {
            clear_pan();
            ui->txtl_pan_time->setEnabled(true);
            ui->line_player_0->setEnabled(true);
            ui->line_player_1->setEnabled(true);
            game_state = off;
            m->stop();
        }
        GGtimes++;
    }
    else if(data.op == OPCODE::GIVEUP_OP)
    {
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  GIVEUP_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;

        fupan += "G";
        isWinner = 1;
        if(now_player==black_player)
        {
            if(now_step != 0)
            {
                black_time /= (now_step/2);
                white_time /= (now_step/2);
            }
            now_step++;
        }
        else
        {
            black_time /= ((now_step+1)/2.0);
            if(now_step!=1)
                white_time /= ((now_step-1)/2.0);
            now_step++;

        }
        QString infom = "对方输辣\n恭喜胜者："+username+"\n我们的对局是："+fupan+"\n总步数为："+QString::number(now_step)+"\n黑方平均思考时间："+QString::number(black_time)+"\n白方平均思考时间："+QString::number(white_time)+"\n总思考时间："+QString::number(all_time)+"\n是否保存对局到本地？";
        int result = QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        if(result == QMessageBox::Yes)
            save();
        netlog = QString::number(now_step+1) + "  send to  " +fightername + "  GIVEUP_END_OP  ";
        qDebug()<<netlog;
        this->socket->send(NetworkData(OPCODE::GIVEUP_END_OP,username,""));



    }
    else if(data.op == OPCODE::GIVEUP_END_OP)
    {
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  GIVEUP_END_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;
        if(!isWinner)
        {
            netlog = QString::number(now_step+1) + "  send to  " +fightername + "  GIVEUP_END_OP  ";
            qDebug()<<netlog;
            this->socket->send(NetworkData(OPCODE::GIVEUP_END_OP,username,""));
        }
            clear_pan();
            ui->txtl_pan_time->setEnabled(true);
            ui->line_player_0->setEnabled(true);
            ui->line_player_1->setEnabled(true);
            game_state = off;
            m->stop();

    }
    else if(data.op == OPCODE::SUICIDE_END_OP)
    {
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  SUICIDE_END_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;
        if(GGtimes == 0)
        {
           m->stop();
           QString temstr = data.data1  + "认为你落子非法输了";
           int result = QMessageBox::information(NULL, temstr, "是否接受", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
           if(result == QMessageBox::Yes)
           {
               netlog = QString::number(now_step+1) + "  send to  " +fightername + "  SUICIDE_OP  ";
               qDebug()<<netlog;
               this->socket->send(NetworkData(OPCODE::SUICIDE_END_OP,username,""));
               clear_pan();
               ui->txtl_pan_time->setEnabled(true);
               ui->line_player_0->setEnabled(true);
               ui->line_player_1->setEnabled(true);
               game_state = off;
               m->stop();
           }
           else if(result == QMessageBox::No){m->stop();}
        }
        else
        {
            clear_pan();
            ui->txtl_pan_time->setEnabled(true);
            ui->line_player_0->setEnabled(true);
            ui->line_player_1->setEnabled(true);
            game_state = off;
            m->stop();
        }
    }
    else if(data.op == OPCODE::LEAVE_OP)
    {
        netlog = QString::number(now_step+1) + "  get  " +fightername + "  LEAVE_OP  "+data.data1 +"  "+data.data2;
        qDebug()<<netlog;
        this->socket->bye();
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
            }
            else
            {
                black_time /= ((now_step+1)/2.0);
                if(now_step!=1)
                    white_time /= ((now_step-1)/2.0);
                now_step++;

            }

            QString infom = "对方离开了比赛\n恭喜胜者："+username+"\n我们的对局是："+fupan+"\n总步数为："+QString::number(now_step)+"\n黑方平均思考时间："+QString::number(black_time)+"\n白方平均思考时间："+QString::number(white_time)+"\n总思考时间："+QString::number(all_time)+"\n是否保存对局到本地？";
            int result = QMessageBox::information(NULL, "游戏结束啦！", infom, QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
            if(result == QMessageBox::Yes)
                save();
            game_state = off;
            clear_pan();
            ui->txtl_pan_time->setEnabled(true);
            ui->line_player_0->setEnabled(true);
            ui->line_player_1->setEnabled(true);
            m->stop();
        }
    }

}

void netpan::reStart()
{
    if(mode == SOCKET)
        this->socket->bye();

    mode = SERVER;
    this->ui->connectLabel->setText("disconnect");
    disconnect(this->server,&NetworkServer::receive,this,&netpan::receieveData);
    clients.clear();
    delete this->server;
    this->server = new NetworkServer(this);
    // 端口相当于传信息的窗户，收的人要在这守着
    this->server->listen(QHostAddress::Any,PORT);
    lastOne = nullptr;
    connect(this->server,&NetworkServer::receive,this,&netpan::receieveData);
}

void netpan::reConnect()
{
    qDebug("trying connect");
    if(mode == SERVER)
    {
        disconnect(this->server,&NetworkServer::receive,this,&netpan::receieveData);
        clients.clear();
        delete this->server;
    }
    mode = SOCKET;
    this->ui->connectLabel->setText("connection fail");
    this->socket->bye();
    this->socket->hello(IP,PORT);
    if(!this->socket->base()->waitForConnected(3000)){
    }
}
/*void netpan::reStart()
{
    if(mode == SOCKET)
        this->socket->bye();

    mode = SERVER;
    this->ui->connectLabel->setText("disconnect");

    disconnect(this->server,&NetworkServer::receive,this,&netpan::receieveData);
    clients.clear();
    delete this->server;
    this->server = new NetworkServer(this);
    // 端口相当于传信息的窗户，收的人要在这守着
    this->server->listen(QHostAddress::Any,PORT);
    lastOne = nullptr;
    connect(this->server,&NetworkServer::receive,this,&netpan::receieveData);
}

void netpan::reConnect()
{
    qDebug("trying connect");
    if(mode == SERVER)
    {
        disconnect(this->server,&NetworkServer::receive,this,&netpan::receieveData);
        clients.clear();
        delete this->server;
    }
    mode = SOCKET;
    this->ui->connectLabel->setText("connection fail");
    this->socket->bye();
    this->socket->hello(IP,PORT);
    if(!this->socket->base()->waitForConnected(3000)){
    }
}*/

void netpan::reSet()
{

    this->ui->connectLabel->setText("connection fail");
    IP=this->ui->IPEdit->text();
    PORT=this->ui->PORTEdit->text().toInt();
    /*this->reStart();
    this->reConnect();*/
}

void netpan::chose_color_and_name()
{
    if(ui->choseb->isChecked())
    {
        mycolor = black_player;
        username = ui->line_player_0->text();
    }
    else
    {
        mycolor = white_player;
        username = ui->line_player_1->text();
    }
}


