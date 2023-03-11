#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include <QCloseEvent>
namespace Ui {
class setting;
}

class setting : public QWidget
{
    Q_OBJECT

public:
    explicit setting(QWidget *parent = nullptr);
    ~setting();
    void closeEvent(QCloseEvent *event);

signals:
    void  setting_close();//用于发出信号保证只存在一个设置界面

private slots:
    void on_btn_set_ok_clicked();

private:
    Ui::setting *ui;
};

#endif // SETTING_H
