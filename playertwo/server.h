
#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QtNetwork>
#include <Game.h>
class QTcpServer;

class Server : public QDialog
{
    Q_OBJECT

public:
    explicit Server(quint16 port_number = 20000);
    void SendData(const char *data);
    void ReadData();
    Game *game;
    void updateGame();
private slots:
    void SetConnection();

private:
    QTcpServer *tcpServer = nullptr;
    quint16 port;
    QTcpSocket *clientConnection;
    char cData[1024];
};

#endif

