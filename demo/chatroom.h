#ifndef CHATROOM_H
#define CHATROOM_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDateTime>
#include <QTimerEvent>
#include <QKeyEvent>
#pragma execution_character_set("utf-8")

QT_BEGIN_NAMESPACE
namespace Ui { class ChatRoom; }
QT_END_NAMESPACE

class ChatRoom : public QWidget
{
    Q_OBJECT

public:
    ChatRoom(QWidget *parent = nullptr);
    ~ChatRoom();
    void paintEvent(QPaintEvent*) override;
    void timerEvent(QTimerEvent*) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void ClickedAddChatRoomButton();
    void ClickedSendMessageButton();
    void ClickedFlushOnlineButton();
    void ReadChatMessageSlot();
    void ChatDisConnectSlot();
    void ReadOnlineMessageSlot();
    void OnlineDisConnectSlot();
private:
    Ui::ChatRoom *ui;
    QTextEdit* ChatRoomTextEdit;//聊天室
    QLineEdit* InputTextEdit;//输入框
    QLabel* OnlineCountLabel;//在线人数信息
    QLineEdit* UserNameLineEdit;//用户姓名
    QPushButton* AddChatRoom;//加入聊天室
    QPushButton* SendMessage;//发送消息
    QPushButton* FlushOnline;//刷新在线人数
    QTcpSocket* chatSocket;//聊天套接字
    QTcpSocket* onlineSocket;//在线套接字
    const QString chatAddress = QString("121.199.25.19");
    const quint16 chatPort = 39880;
    const QString onlineAddress = QString("121.199.25.19");
    const quint16 onlinePort = 39905;
    bool connectedState;
};
#endif // CHATROOM_H
