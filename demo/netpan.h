#ifndef NETnetpan_H
#define NETnetpan_H


#include <QImage>
#include <QTimer>
#include <qsignalmapper.h>
#include <QObject>
#include <QPushButton>
#include <QMessageBox>
#include <QPainter>
#include <QDebug>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFile>
#include <QFileDialog>
#include "networkdata.h"
#include "networkserver.h"
#include "networksocket.h"
#include <QSet>
#include <QDateTime>

namespace Ui {
class netpan;
}

class netpan : public QWidget
{
    Q_OBJECT

public:
    explicit netpan(QWidget *parent = nullptr);
    ~netpan();

    const int size=50;
    const int x=295,y=165;
    // 服务端
    NetworkServer* server;
    // 客户端
    NetworkSocket* socket;
    // 最后一个客户端
    QTcpSocket* lastOne;
    QString IP;
    int PORT;
    // 客户端池，NetworkServer 有一个 QList 的，但这里我想用 set，所以又弄了一个
    QSet<QTcpSocket*> clients;
    QString username = "team4";

private slots :

    void on_btn_startgame_clicked();//开始游戏
    void on_btn_lose_clicked();//投降
    void get_btn_sign(int idx);//为了不给每个按钮写个函数，就通过传递按钮的坐标来起到对应的按钮反应
    void on_btn_stop_clicked();//暂停游戏，如果已经暂停了就开始
    void get_online_sign(int idx,qint64 timestamp);
    void on_back_clicked();
    void on_sendbtn_clicked();
    void receieveData(QTcpSocket* client, NetworkData data);
    void receieveDataFromServer(NetworkData data);
    void reStart();
    void reConnect();
    void reSet();
    void chose_color_and_name();

private:
    Ui::netpan *ui;
    QTimer *m;
    void paintEvent(QPaintEvent *);//绘图函数声明
    QPainter *paint;
    QMediaPlayer *player;//用于音乐
    QAudioOutput *audioOutput;//用于音乐


    void set_time(int seted_time = 50);//设置倒计时时间
    void BeginCountdown();//打开计时器
    void OnTimerCountdown();//输出倒计时
    void delete_time();//删除计时器
    void play_the_Go(QPushButton *now_btn,QPushButton *last_btn);//绘制棋盘，其实就是把对应的按钮画成黑棋或白棋
    int judge();//在每次落子后判断有无胜负,若会吃子或紫砂则传回no，反之则传yes
    void clear_pan();//恢复棋盘初始状态，包括清屏,清空气,重设时间
    void dfs(int x,int y,int flag);//深度搜索棋盘，是judge函数里面的一个小函数，具体见cpp。
    void save();//保存文件

    QString fupan;//保存复盘信息
    double black_time=0;
    double white_time=0;
    int all_time=0;
    int length=9;//棋盘的长度，默认是9x9
    int now_step=0;//现在是第几步棋
    int now_player = -1;//当前棋手
    int Qi[13][13]={0};//母棋盘。
    int copy_Qi[170][13][13]={0};//供dfs的子棋盘，在dfs前会copy成母棋盘，dfs后会变成相对应的子棋盘
    int black_flag=0;//若dfs后有loseQi的黑棋则变为on（值为1），不然就一直是off（值为0）
    int white_flag=0;////同上
    int step[4][2]={0,1,1,0,0,-1,-1,0};//为了方便dfs而设置的向量
    int game_max_time;//倒计时的最大时长
    int now_time=0;//倒计时的当前时长
    bool game_state = 0;//该变量为1则游戏开始，为0则不然
    int loc=-1;//落子位置，用于高亮当前子和记录对局,-1指游戏开始未有落子
    bool mode = 0;
    int mycolor = black_player;
    int GGtimes = 0;
    QString fightername = "fighter";


    enum Chess
    {
        black_loseQi_or_unchecked = -1,empty_unchecked,white_loseQi_or_unchecked,empty_checked,white_have_Qi,black_have_Qi
    }chess;//母棋盘中每个子是前三个状态中的一个，子棋盘中loseQi_or_unchecked指还没检查或检查后没气的，

    enum Player_state
    {
        black_player=-1,white_player =1
    }player_state;

    enum WINLOSE
    {
        no,yes
    }winlose;

    enum State
    {
        off,on
    }state;//既是游戏的状态也用于whiteflag和blackstage的状态

    enum MODE
    {
        SERVER,SOCKET
    }Mode;
};


#endif // NETPAN_H
