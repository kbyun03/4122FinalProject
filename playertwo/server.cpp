#include <QtWidgets>
#include <QtCore>

#include "server.h"
#
Server::Server(quint16 port_number)
    : port(port_number)
{

    QString ipAddress;
       QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
       // use the first non-localhost IPv4 address
       for (int i = 0; i < ipAddressesList.size(); ++i) {
           if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
               ipAddressesList.at(i).toIPv4Address()) {
               ipAddress = ipAddressesList.at(i).toString();
               break;
           }
       }
       // if we did not find one, use IPv4 localhost
       if (ipAddress.isEmpty())
           ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
       QHostAddress ipaddress(ipAddress);
        tcpServer = new QTcpServer(this);
       if (!tcpServer->listen(ipaddress, port)) {
           return;
       }
       connect(tcpServer, &QTcpServer::newConnection, this, &Server::SetConnection);
}



void Server::SetConnection()
{
    clientConnection = tcpServer->nextPendingConnection();
    game->StartGame();
    connect(clientConnection, &QIODevice::readyRead, this, &Server::ReadData);
    QTimer * timer = new QTimer(this);
    connect(timer,&QTimer::timeout , this, &Server::updateGame);
    timer->start(50);
}

void Server::SendData(const char *data)
{
    clientConnection->write(data);
}
void Server::ReadData()
{
    char buff[1024];
    clientConnection->read(buff, 1024);
    game->UpdateGameScreen(buff);

}

void Server::updateGame()
{
    QJsonObject json_data;
    Bullet *b;
    for (int i = 0; i< game->player2->bullets.size(); i++)
    {
        b = game->player2->bullets[i];
        if (!b->sent)
        {
            json_data["bullet"] = b->x();
            b->sent = true;
            game->player2->bullets.remove(i);
            i = i-1;
            break;
        }
        game->player2->bullets.remove(i);
        i = i-1;
    }
    json_data["player2_x"] = game->player2->x();
    json_data["player2_y"] = game->player2->y();
    QJsonDocument doc(json_data);
    SendData(doc.toJson(QJsonDocument::Compact).constData());
}
