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
private:
  void paintEvent(QPaintEvent *);//绘图函数声明
  //void mousePressEvent(QMouseEvent *);
  QPainter *paint;

private slots :



    void on_btn_startgame_clicked();

    void on_btn_stop_clicked();

    void on_btn_startgame_2_clicked();

    void on_btn_lose_clicked();

    void get_btn_sign(int idx);

    void on_btn_restart_clicked();

    void on_btn_isEnable_clicked();

public slots :


private:
    Ui::pan *ui;
    void set_time(int seted_time = 50);
    void BeginCountdown();
    void OnTimerCountdown();
    void delete_time();
    void play_the_Go(QPushButton *btn);
    void judge();
    void clear_pan();
    void dfs(int x,int y);


    int now_player = -1;
    int Qi[9][9]={0};//棋盘的状态，0是未落子，1是白棋落子，-1是黑棋落子。
    int replaced_Qi[9][9]={0};

    QTimer *m;
    int game_max_time;
    int now_time=0;
    bool game_state = 0;//该变量为1则游戏开始，为0则不然


};

#endif // PAN_H
