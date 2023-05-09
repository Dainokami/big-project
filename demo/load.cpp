#include "load.h"
#include "ui_load.h"

load::load(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::load)
{
    ui->setupUi(this);
     setWindowTitle("NOGO");
}

load::~load()
{
    delete ui;
}

void load::check()
{
    if(fupan.indexOf('L')!=-1 ||fupan.indexOf('M')!=-1 ||fupan.indexOf("12")!=-1 ||fupan.indexOf("13")!=-1)
        length = 13;
    else if(fupan.indexOf('J')!=-1 ||fupan.indexOf('K')!=-1 ||fupan.indexOf("10")!=-1 ||fupan.indexOf("11")!=-1)
        length = 11;
    else
        length = 9;

    load::update();

    int ptr=0;
    int length = fupan.length();
    while (true)
    {
        for(;ptr<length;)
            if(fupan.at(ptr) == ' ')
            {ptr++;break;}
            else
                ptr++;

        if(ptr<=length-1)
        {
            char tem = fupan.at(load_loc).unicode()-'A';
            int a = (int)tem+1;
            QString now_btn_str = "btn_"+QString::number(a)+"_"+QString(fupan.at(load_loc+1));
            if(ptr-load_loc == 4)
                now_btn_str += QString(fupan.at(load_loc+2));
            QPushButton *now_btn = this->findChild<QPushButton*>(now_btn_str);

            qDebug()<<now_btn_str;

            if(now_btn ==nullptr)
            {
                QMessageBox::warning(this,"错误","你打开了错误的存档\n请再次选择正确的存档");
                clear();
                break;
            }
            else
            {
                qDebug()<<"yes";
                play_the_Go(now_btn);
                load_loc = ptr;
                now_player*=-1;
            }
        }
        else
        {
            break;
        }
    }

    load::update();
}

void load::paintEvent(QPaintEvent *)
{
    paint=new QPainter;
    paint->begin(this);
    paint->setPen(QPen(Qt::black,2,Qt::SolidLine));
      for(int i=0;i<length;i++)
        {
          paint->drawLine(x,y+size*i,x+size*(length-1),y+size*i);//画线函数：x1,y1,x2,y2:画从(x1,y1)到(x2,y2)的线
        }
      //画lu+1条竖线
      for(int i=0;i<length;i++)
        {
          paint->drawLine(x+size*i,y,x+size*i,y+size*(length-1));
        }
      //ui->setupUi()
}

void load::getter()
{
    QFileDialog fileDialog;
    QString fileName = fileDialog.getOpenFileName(this,tr("Open File"),"/data",tr("Text File(*.txt)"));
    if(fileName == "")
    {
        return;
    }
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,tr("错误"),tr("打开文件失败"));
        return;
    }
    else
    {
        QTextStream in(&file);
        fupan = in.readAll();
        QMessageBox::warning(this,tr("提示"),tr("打开文件成功"));
        file.close();
        check();
    }


}

void load::play_the_Go(QPushButton *now_btn)
{
    if(now_player == white_player)
    {
        now_btn->setStyleSheet("background-color:white;border-radius:25px;border:2px groove gray;border-style:outset;");
    }
    else if(now_player == black_player)
    {
        now_btn->setStyleSheet("background-color:black;border-radius:25px;border:2px groove gray;border-style:outset;");
    }
}

void load::clear()
{
    load_loc = 0;
    for(int i=1;i<=13;i++)
        for(int j=1;j<=13;j++)
        {
            QString now_btn_str = "btn_"+QString::number(i)+"_"+QString::number(j);
            QPushButton *now_btn = this->findChild<QPushButton*>(now_btn_str);
            now_btn->setStyleSheet("");
        }
    now_player = black_player;
    load::update();
}

void load::on_re_load_clicked()
{
    this->getter();
}

