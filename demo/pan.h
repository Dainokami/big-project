#ifndef PAN_H
#define PAN_H





#include <QWidget>
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


namespace Ui {
class pan;
}

class pan : public QWidget
{
    Q_OBJECT

public:
    explicit pan(QWidget *parent = nullptr);
    ~pan();
    const int lu=8;
    const int size=61;
    const int x=115,y=55;

private slots :

    void on_btn_startgame_clicked();//开始游戏

    void on_btn_stop_clicked();//暂停游戏，如果已经暂停了就开始

    void on_btn_startgame_2_clicked();//继续游戏，但没用就被删了，Qt删了这个函数后会有点bug，所以没删

    void on_btn_lose_clicked();//投降

    void get_btn_sign(int idx);//为了不给每个按钮写个函数，就通过传递按钮的坐标来起到对应的按钮反应

    void on_btn_restart_clicked();//重开游戏

    void on_btn_isEnable_clicked();//控制倒计时框可不可以编辑，在游戏过程中默认不可以

private:
    Ui::pan *ui;
    QTimer *m;
    void paintEvent(QPaintEvent *);//绘图函数声明
    QPainter *paint;
    QMediaPlayer *player;//用于音乐
    QAudioOutput *audioOutput;//用于音乐


    void set_time(int seted_time = 50);//设置倒计时时间
    void BeginCountdown();//打开计时器
    void OnTimerCountdown();//输出倒计时
    void delete_time();//删除计时器
    void play_the_Go(QPushButton *btn);//绘制棋盘，其实就是把对应的按钮画成黑棋或白棋
    void judge();//在每次落子后判断有无胜负
    void clear_pan();//恢复棋盘初始状态，包括清屏,清空气,重设时间
    void dfs(int x,int y,int flag);//深度搜索棋盘，是judge函数里面的一个小函数，具体见cpp。


    int now_player = -1;//当前棋手
    int Qi[9][9]={0};//母棋盘。
    int copy_Qi[9][9]={0};//供dfs的子棋盘，在dfs前会copy成母棋盘，dfs后会变成相对应的子棋盘
    int black_flag=0;//若dfs后有loseQi的黑棋则变为on（值为1），不然就一直是off（值为0）
    int white_flag=0;////同上
    int step[4][2]={0,1,1,0,0,-1,-1,0};//为了方便dfs而设置的向量
    int game_max_time;//倒计时的最大时长
    int now_time=0;//倒计时的当前时长
    bool game_state = 0;//该变量为1则游戏开始，为0则不然


    enum Chess
    {
        black_loseQi_or_unchecked = -1,empty_unchecked,white_loseQi_or_unchecked,empty_checked,white_have_Qi,black_have_Qi
    }chess;//母棋盘中每个子是前三个状态中的一个，子棋盘中loseQi_or_unchecked指还没检查或检查后没气的，

    enum Player_state
    {
        black_player=-1,white_player =1
    }player_state;

    enum State
    {
        off,on
    }state;//既是游戏的状态也用于whiteflag和blackstage的状态
    int num=0;
};

#endif // PAN_H
