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

    void check();//（该函数在cpp有介绍）处理存档文件数据，根据文件内容调整棋盘大小，同时进行输入合法性检查,然后将无序的存档数据转为易处理的数字存入名为log的数组（本组用行数*100+列数来处理坐标）
    void getter();//打开并读取存档
    void play_the_Go(QPushButton *now_btn);//下棋函数，即将某个按钮由无色变为棋子颜色
    void clear();//清空参数和棋盘
    void paintEvent(QPaintEvent *);//绘图函数声明
private slots:
    void on_back_clicked();//返回上一页面

    void on_re_load_clicked();//重新加载存档

    void on_btn_last_clicked();//回撤一步（若此时在播放复盘则顺便暂停之）

    void on_btn_play_or_stop_clicked();//开始播放复盘，或暂停播放转为手动复盘

    void on_btn_next_clicked();//下一步

    void on_btn_jump_clicked();//跳转到某步

    void on_lineEdit_returnPressed();//和上个函数类似，只不过这个是在输入步数时按enter触发

private:
    Ui::load *ui;
    QPainter *paint;
    QTimer *m;

    int log[180]={0};       //存放处理后的存档数据
    int max_step=0;         //最大步数
    int step=0;             //当前局面对应的步数
    int length=13;          //棋盘长度
    const int size=50;      //画图用常数
    const int x=35,y=35;    //画图用常数
    QString fupan;          //存放从txt存档文件中读取的原数据
    int now_player = -1;    //当前棋手
    enum Player_state
    {
        black_player=-1,white_player =1
    }player_state;
};

#endif // LOAD_H
