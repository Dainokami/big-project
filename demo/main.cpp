#include "widget.h"

#include <QApplication>
#include <QDir>
#include <QFile>
#include <QMutex>
#include <QTextStream>
#include <QTime>


void outputMessage(QtMsgType type,const QMessageLogContext &context,const QString &msg);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qInstallMessageHandler(outputMessage);
    Widget w;
    w.show();
    return a.exec();
}

void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex;
    mutex.lock();
    QString text;
    switch(type)
    {
    case QtDebugMsg:
        text = QString("Debug:");
        break;
    case QtWarningMsg:
        text = QString("Warning:");
        break;
    case QtCriticalMsg:
        text = QString("Critical:");
        break;
    case QtFatalMsg:
        text = QString("Fatal:");
    }
    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString current_date = QString("(%1)").arg(current_date_time);
    QString message = QString("%1 \r\n%2 %3 \r\n%4").arg(current_date).arg(text).arg(context_info).arg(msg);

    //判断文件夹是否存在，不存在新建
    QString aFile = QDir::currentPath() + "/LogFile";
    QDir dir(aFile);
    if(!dir.exists())
    {
        dir.mkdir(aFile);//只创建一级子目录，即必须保证上级目录存在
    }

    QString current_time = QDateTime::currentDateTime().toString("yyyyMMdd");
    QFile file(aFile+"/log"+current_time+".txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n \r\n";

    file.flush();
    file.close();
    mutex.unlock();
}

