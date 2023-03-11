#ifndef PAN_H
#define PAN_H

#include <QWidget>
#include <setting.h>
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
    void close_s();
    void on_btn_pan_set_clicked();

    private:
    Ui::pan *ui;
    void set_time(int seted_time = 50);
    setting *s = nullptr;


};

#endif // PAN_H
