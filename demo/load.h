#ifndef LOAD_H
#define LOAD_H

#include <QWidget>

namespace Ui {
class load;
}

class load : public QWidget
{
    Q_OBJECT

public:
    explicit load(QWidget *parent = nullptr);
    ~load();

private:
    Ui::load *ui;
};

#endif // LOAD_H
