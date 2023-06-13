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
#include <ai.h>
#include <qcheckbox.h>
#include <QCheckBox>

namespace Ui {
class netpan;
}

class netpan : public QWidget
{
    Q_OBJECT

public:
    explicit netpan(QWidget *parent = nullptr);
    ~netpan();

    const int size=50;              //画图用
    const int x=295,y=165;          //画图用
    NetworkServer* server;          // 服务端
    NetworkSocket* socket;          // 客户端
    QTcpSocket* lastOne;            // 最后一个客户端
    QString IP;
    int PORT;
    QSet<QTcpSocket*> clients;
    QString username = "team4";

private slots :

    void on_btn_startgame_clicked();                            //开始游戏
    void on_btn_lose_clicked();                                 //投降
    void get_btn_sign(int idx);                                 //为了不给每个按钮写个函数，就通过传递按钮的坐标来起到对应的按钮反应
    void get_online_sign(int idx);                              //跟上个函数差不多，只不过用来处理对方的MOVE_OP，
    void on_back_clicked();                                     //返回主界面
    void on_sendbtn_clicked();                                  //发送聊天对话
    void receieveData(QTcpSocket* client, NetworkData data);    //服务端接受客户端信号
    void receieveDataFromServer(NetworkData data);              //客户端接受服务端信号
    void reStart();                                             //服务端重启
    void reConnect();                                           //客户端重连
    void reSet();                                               //重新设置IP和PORT
    void chose_color_and_name();                                //设置颜色和用户名
private:
    Ui::netpan *ui;
    QTimer *m;
    void paintEvent(QPaintEvent *);                             //绘图函数声明
    QPainter *paint;
    QMediaPlayer *player;                                       //用于音乐
    QAudioOutput *audioOutput;                                  //用于音乐
    AI *ai=new AI();

    void set_time(int seted_time = 50);                         //设置倒计时时间
    void BeginCountdown();                                      //打开计时器
    void OnTimerCountdown();                                    //输出倒计时
    void delete_time();                                         //删除计时器
    void play_the_Go(QPushButton *now_btn,QPushButton *last_btn);//绘制棋盘，其实就是把对应的按钮画成黑棋或白棋
    int judge();                                                //在每次落子后判断有无胜负,若会吃子或紫砂则传回no，反之则传yes
    void clear_pan();                                           //恢复棋盘初始状态，包括清屏,清空气,重设时间
    void dfs(int x,int y,int flag);                             //深度搜索棋盘，是judge函数里面的一个小函数，具体见cpp。
    void save();                                                //保存文件

    void onCheckBoxAIStateChanged(int state);


    QString fupan;                      //保存复盘信息
    double black_time=0;                //复盘用，统计黑子的用思考时间
    double white_time=0;                //同上
    int all_time=0;                     //同上
    int length=9;                       //棋盘的长度，默认是9x9
    int now_step=0;                     //现在是第几步棋
    int now_player = -1;                //当前棋手
    int Qi[13][13]={0};                 //母棋盘。
    int copy_Qi[170][13][13]={0};       //供dfs的子棋盘，在dfs前会copy成母棋盘，dfs后会变成相对应的子棋盘
    int black_flag=0;                   //若dfs后有loseQi的黑棋则变为on（值为1），不然就一直是off（值为0）
    int white_flag=0;                   //同上
    int step[4][2]={0,1,1,0,0,-1,-1,0}; //为了方便dfs而设置的向量
    int game_max_time;                  //倒计时的最大时长
    int now_time=0;                     //倒计时的当前时长
    bool game_state = 0;                //该变量为1则游戏开始，为0则不然
    int loc=-1;                         //落子位置，用于高亮当前子和记录对局,-1指游戏开始未有落子
    bool mode = 0;                      //本机模式，是做服务端还是客户端
    int mycolor = black_player;         //本端颜色
    int GGtimes = 0;                    //发送GG_OP的次数，防止无限发送GG_OP
    bool isWinner = 0;                  //是不是赢家
    QString fightername = "fighter";    //对手名字
    QString netlog = "";                //log日志输出用的qstring
    bool isbeginner = 0;                //是不是发送READY_OP的人
    bool firstmove=false;               //黑棋有没有下第一步
    int checkAI_state=0;                //ai是否启动


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
