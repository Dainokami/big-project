#ifndef PAN_H
#define PAN_H

#include <QWidget>
#include <QImage>
#include <QTimer>

namespace Ui {
class pan;
}

class pan : public QWidget
{
    Q_OBJECT

public:
    explicit pan(QWidget *parent = nullptr);
    ~pan();

private slots :



    void on_btn_startgame_clicked();

public slots :


private:
    Ui::pan *ui;
    void set_time(int seted_time = 50);
    void BeginCountdown();
    void OnTimerCountdown();
    void delete_time();

    QTimer *m;
    int game_max_time;
    int now_time=0;
};

#endif // PAN_H
