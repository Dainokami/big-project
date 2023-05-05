#include "chatroom.h"
#include "ui_chatroom.h"

ChatRoom::ChatRoom(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatRoom)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);//设置关闭窗口是自动释放内存
    setMinimumSize(400, 500);//设置窗口最小尺寸为800*600
    resize(400, 500);
    this->setStyleSheet(QString("background-color:#FFFFFF;"));//设置背景颜色为白色。和标题栏颜色一致。
    setWindowTitle("nogo聊天室");

    QFont font;
    font.setPointSize(12);//设置字体大小
    font.setBold(false);
    font.setFamily("楷体");

    UserNameLineEdit = new QLineEdit(this);
    UserNameLineEdit->setFont(font);
    UserNameLineEdit->setGeometry(this->width() * 0.1, 10, this->width() * 0.3, 24);//设置位置
    UserNameLineEdit->setPlaceholderText("聊天昵称");
    UserNameLineEdit->setMaxLength(8);//最多输入8位信息

    AddChatRoom = new QPushButton(this);
    AddChatRoom->setObjectName("AddChatRoom");
    AddChatRoom->setFont(font);
    AddChatRoom->setText("加入聊天室");
    AddChatRoom->setGeometry(this->width() * 0.45, 10, this->width() * 0.2, 24);
    AddChatRoom->setStyleSheet("QPushButton#AddChatRoom{color:#FAFAFA;border-radius: 8px;background-color:#05BAFB;}"
                               "#AddChatRoom:hover{background-color:#1FC7FD;}"
                               "#AddChatRoom:pressed{background-color:#1FC7FD}");
    connect(AddChatRoom, SIGNAL(clicked()), this, SLOT(ClickedAddChatRoomButton()));

    ChatRoomTextEdit = new QTextEdit(this);
    ChatRoomTextEdit->setGeometry(this->width() * 0.05, 45, this->width() * 0.9, (this->height() - 80) * 0.83);
//    ChatRoomTextEdit->setDisabled(true);

    InputTextEdit = new QLineEdit(this);
    InputTextEdit->setGeometry(this->width() * 0.05, 45 + (this->height() - 80) * 0.87, this->width() * 0.9, (this->height() - 80) * 0.12);
    InputTextEdit->setPlaceholderText("请输入...");

    OnlineCountLabel = new QLabel(this);
    OnlineCountLabel->setGeometry(this->width() * 0.1, this->height() - 25, this->width() * 0.25, 20);
    OnlineCountLabel->setText(QString("在线人数："));

    SendMessage = new QPushButton(this);
    SendMessage->setObjectName("SendMessage");
    SendMessage->setFont(font);
    SendMessage->setText("发送");
    SendMessage->setGeometry(this->width() * 0.7, this->height() - 30, this->width() * 0.25, 24);
    SendMessage->setStyleSheet("QPushButton#SendMessage{color:#FAFAFA;border-radius: 8px;background-color:#05BAFB;}"
                               "#SendMessage:hover{background-color:#1FC7FD;}"
                               "#SendMessage:pressed{background-color:#1FC7FD}");
    connect(SendMessage, SIGNAL(clicked()), this, SLOT(ClickedSendMessageButton()));
    SendMessage->hide();

    FlushOnline = new QPushButton(this);
    FlushOnline->setObjectName("FlushOnline");
    FlushOnline->setFont(font);
    FlushOnline->setText("刷新聊天室");
    FlushOnline->setGeometry(this->width() * 0.7, 10, this->width() * 0.2, 24);
    FlushOnline->setStyleSheet("QPushButton#FlushOnline{color:#FAFAFA;border-radius: 8px;background-color:#05BAFB;}"
                               "#FlushOnline:hover{background-color:#1FC7FD;}"
                               "#FlushOnline:pressed{background-color:#1FC7FD}");
    connect(FlushOnline, SIGNAL(clicked()), this, SLOT(ClickedFlushOnlineButton()));
    FlushOnline->hide();

    font.setPointSize(10);
    font.setFamily("宋体");
    ChatRoomTextEdit->setFont(font);
    InputTextEdit->setFont(font);
    OnlineCountLabel->setFont(font);

    connectedState = false;
    chatSocket = new QTcpSocket(this);
    onlineSocket = new QTcpSocket(this);

    connect(chatSocket, &QTcpSocket::readyRead, this, &ChatRoom::ReadChatMessageSlot);
    connect(chatSocket, &QTcpSocket::disconnected, this, &ChatRoom::ChatDisConnectSlot);
    connect(onlineSocket, &QTcpSocket::readyRead, this, &ChatRoom::ReadOnlineMessageSlot);
    connect(onlineSocket, &QTcpSocket::disconnected, this, &ChatRoom::OnlineDisConnectSlot);
}

ChatRoom::~ChatRoom()
{
    if(ChatRoomTextEdit != NULL)
        delete ChatRoomTextEdit;
    if(InputTextEdit != NULL)
        delete InputTextEdit;
    if(OnlineCountLabel != NULL)
        delete OnlineCountLabel;
    if(UserNameLineEdit != NULL)
        delete UserNameLineEdit;
    if(AddChatRoom != NULL)
        delete AddChatRoom;
    if(SendMessage != NULL)
        delete SendMessage;
    if(FlushOnline != NULL)
        delete FlushOnline;
    if(chatSocket != NULL)
        delete chatSocket;
    if(onlineSocket != NULL)
        delete onlineSocket;
    delete ui;
}

void ChatRoom::paintEvent(QPaintEvent*)
{
    UserNameLineEdit->setGeometry(this->width() * 0.1, 10, this->width() * 0.3, 24);//设置位置
    AddChatRoom->setGeometry(this->width() * 0.45, 10, this->width() * 0.2, 24);
    SendMessage->setGeometry(this->width() * 0.7, this->height() - 30, this->width() * 0.25, 24);
    FlushOnline->setGeometry(this->width() * 0.7, 10, this->width() * 0.2, 24);
    ChatRoomTextEdit->setGeometry(this->width() * 0.05, 45, this->width() * 0.9, (this->height() - 80) * 0.83);
    InputTextEdit->setGeometry(this->width() * 0.05, 45 + (this->height() - 80) * 0.87, this->width() * 0.9, (this->height() - 80) * 0.12);
    OnlineCountLabel->setGeometry(this->width() * 0.1, this->height() - 25, this->width() * 0.25, 20);
}

void ChatRoom::timerEvent(QTimerEvent*)
{

}

void ChatRoom::keyPressEvent(QKeyEvent* e)
{
    if(connectedState)
    {
        switch(e->key())
        {
        case Qt::Key_F5:
            ClickedFlushOnlineButton();
            break;
        case Qt::Key_Return:
        case Qt::Key_Enter:
            ClickedSendMessageButton();
            break;
        case Qt::Key_Escape:
            ClickedAddChatRoomButton();
            break;
        default:
            break;
        }
    }
    else
    {
        switch(e->key())
        {
        case Qt::Key_Return:
        case Qt::Key_Enter:
            ClickedAddChatRoomButton();
            break;
        default:
            break;
        }
    }
}

void ChatRoom::ClickedAddChatRoomButton()
{
    if(UserNameLineEdit->text().length() <= 0)
    {
        QMessageBox(QMessageBox::Warning, "警告", "请输入群聊昵称后再加入群聊...", QMessageBox::Yes).exec();
        return;
    }
    if(UserNameLineEdit->text().length() > 8)
    {
        QMessageBox(QMessageBox::Warning, "警告", "群聊昵称长度不允许超过8位...", QMessageBox::Yes).exec();
        return;
    }
    QString Username = UserNameLineEdit->text();
    for(int i = 0; i < Username.length(); i++)
        if(!((Username.at(i).unicode() >= 0x4E00 && Username.at(i).unicode() <=0x9FA5) || (Username.at(i) >= 'a' && Username.at(i) <= 'z') || (Username.at(i) >= 'A' && Username.at(i) <= 'Z')))
        {
            QMessageBox(QMessageBox::Warning, "警告", "群聊昵称只允许英文和汉字...", QMessageBox::Yes).exec();
            return;
        }
    if(!connectedState)//如果未连接
    {
        ChatRoomTextEdit->clear();
        chatSocket->connectToHost(chatAddress, chatPort);
        if(chatSocket->waitForConnected())
        {
            ChatRoomTextEdit->append(QString("加入聊天室成功..."));
        }
        else
        {
            ChatRoomTextEdit->append(QString("\n无法连接服务器1...\n"));
            return;
        }
        onlineSocket->connectToHost(onlineAddress, onlinePort);
        if(onlineSocket->waitForConnected())
        {
            ChatRoomTextEdit->append(QString("读取在线信息成功..."));
        }
        else
        {
            ChatRoomTextEdit->append(QString("\n无法连接服务器2...\n"));
            chatSocket->close();
            return;
        }
        AddChatRoom->setText(QString("断开连接"));
        AddChatRoom->setStyleSheet("QPushButton#AddChatRoom{color:#FAFAFA;border-radius: 8px;background-color:#FF4040;}"
                                   "#AddChatRoom:hover{background-color:#EE3B3B;}"
                                   "#AddChatRoom:pressed{background-color:#EE3B3B;}");
        chatSocket->write(UserNameLineEdit->text().toUtf8());
        onlineSocket->write(UserNameLineEdit->text().toUtf8());
        connectedState = true;
        FlushOnline->show();
        SendMessage->show();
        UserNameLineEdit->setDisabled(true);
    }
    else
    {
        chatSocket->close();
        onlineSocket->close();
        UserNameLineEdit->setEnabled(true);
        AddChatRoom->setText("加入聊天室");
        AddChatRoom->setStyleSheet("QPushButton#AddChatRoom{color:#FAFAFA;border-radius: 8px;background-color:#05BAFB;}"
                                   "#AddChatRoom:hover{background-color:#1FC7FD;}"
                                   "#AddChatRoom:pressed{background-color:#1FC7FD}");
        ChatRoomTextEdit->append(QString("成功断开连接..."));
        SendMessage->hide();
        FlushOnline->hide();
        connectedState = false;
    }
}

void ChatRoom::ReadChatMessageSlot()
{
    QByteArray arr = chatSocket->readAll();
    QString str = arr.data();
    QString mes = QString("  ");
    QStringList list = str.split(':');
    ChatRoomTextEdit->append(list.at(0) + QString(" - ") + QDateTime::currentDateTime().toString("dddd yyyy.MM.dd hh:mm:ss"));
    for(int i = 1; i < list.count(); i++)
        mes += list.at(i);
    ChatRoomTextEdit->append(mes);
}

void ChatRoom::ChatDisConnectSlot()
{
    //QMessageBox(QMessageBox::Warning, "异常", "服务器可能炸了...断开连接...", QMessageBox::Yes).exec();
    ChatRoomTextEdit->append(QString("\n已从服务器断开...\n"));
    if(connectedState)
    {
        chatSocket->close();
        onlineSocket->close();
        UserNameLineEdit->setEnabled(true);
        AddChatRoom->setText("加入聊天室");
        AddChatRoom->setStyleSheet("QPushButton#AddChatRoom{color:#FAFAFA;border-radius: 8px;background-color:#05BAFB;}"
                                   "#AddChatRoom:hover{background-color:#1FC7FD;}"
                                   "#AddChatRoom:pressed{background-color:#1FC7FD}");
        SendMessage->hide();
        FlushOnline->hide();
        connectedState = false;
    }
    return;
}

void ChatRoom::ReadOnlineMessageSlot()
{
    QByteArray arr = onlineSocket->readAll();
    QString str = arr.data();
    OnlineCountLabel->setText(QString("在线人数:%1").arg(arr.data()));
}

void ChatRoom::OnlineDisConnectSlot()
{
    //QMessageBox(QMessageBox::Warning, "异常", "服务器断开连接...", QMessageBox::Yes).exec();
    ChatRoomTextEdit->append(QString("\n已从服务器断开...\n"));
    if(connectedState)
    {
        chatSocket->close();
        onlineSocket->close();
        UserNameLineEdit->setEnabled(true);
        AddChatRoom->setText("加入聊天室");
        AddChatRoom->setStyleSheet("QPushButton#AddChatRoom{color:#FAFAFA;border-radius: 8px;background-color:#05BAFB;}"
                                   "#AddChatRoom:hover{background-color:#1FC7FD;}"
                                   "#AddChatRoom:pressed{background-color:#1FC7FD}");
        SendMessage->hide();
        FlushOnline->hide();
        connectedState = false;
    }
    return;
}

void ChatRoom::ClickedSendMessageButton()
{
    QString str = InputTextEdit->text();
    if(str.length() <= 0)
    {
        QMessageBox(QMessageBox::Warning, "警告", "不允许发送空消息...", QMessageBox::Yes).exec();
        return;
    }
    if(connectedState && chatSocket->isValid() && chatSocket->isOpen())
    {
        chatSocket->write(str.toUtf8());    //给服务端发送信息
        InputTextEdit->clear();
    }
    ChatRoomTextEdit->append(UserNameLineEdit->text() + QString(" - ") + QDateTime::currentDateTime().toString("dddd yyyy.MM.dd hh:mm:ss"));
    ChatRoomTextEdit->append(QString("  ") + str);
}

void ChatRoom::ClickedFlushOnlineButton()
{
    if(connectedState && onlineSocket->isValid() && onlineSocket->isOpen())
    {
        onlineSocket->write(QString("request for online count").toUtf8());    //给服务端发送信息
    }
}
