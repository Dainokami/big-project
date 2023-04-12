#ifndef LOAD_H
#define LOAD_H

#include <QWidget>
#include <QPainter>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>




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

private:
    Ui::load *ui;
    void paintEvent(QPaintEvent *);//绘图函数声明
    QPainter *paint;
    int length=13;
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
