#include "load.h"
#include "ui_load.h"

load::load(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::load)
{
    ui->setupUi(this);
}

load::~load()
{
    delete ui;
}
