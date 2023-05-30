#ifndef LOAD_H
#define LOAD_H

#include <QWidget>
#include <QPainter>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>




namespace Ui {
class load;
}

class load : public QWidget
{
    Q_OBJECT

public:
    explicit load(QWidget *parent = nullptr);
    ~load();

    void check();
    void getter();
    void play_the_Go(QPushButton *now_btn);
    void clear();

private slots:
    void on_back_clicked();


    void on_re_load_clicked();

    void on_lineEdit_returnPressed();

    void on_btn_last_clicked();

    void on_btn_play_or_stop_clicked();

    void on_btn_next_clicked();

    void on_btn_jump_clicked();

private:
    Ui::load *ui;
    void paintEvent(QPaintEvent *);//绘图函数声明
    QPainter *paint;
    QTimer *m;

    int max_step=0;
    int length_pan=0;
    int ptr=0;
    int step=0;
    int length=13;
    int log[180]={0};
    const int size=50;
    const int x=35,y=35;
    QString fupan;
    int now_player = -1;//当前棋手
    int load_loc=0;
    enum Player_state
    {
        black_player=-1,white_player =1
    }player_state;
};

#endif // LOAD_H
