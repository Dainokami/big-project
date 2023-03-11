#ifndef PAN_H
#define PAN_H

#include <QWidget>

namespace Ui {
class pan;
}

class pan : public QWidget
{
    Q_OBJECT

public:
    explicit pan(QWidget *parent = nullptr);
    ~pan();

private:
    Ui::pan *ui;
};

#endif // PAN_H
