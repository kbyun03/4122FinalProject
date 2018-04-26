
#include <QtWidgets>
#include <QtNetwork>

#include "client.h"

Client::Client(QString ip, quint16 port_number)
    :   tcpSocket(new QTcpSocket(this))
    , port(port_number)
{

       QHostAddress ipaddress(ip);

       tcpSocket->abort();
       tcpSocket->connectToHost(ipaddress, port);
       tcpSocket->waitForReadyRead(1000);
//       ReadData();
//       sprintf(cData, "Replying from port %i", port);
//       SendData(cData);
//       QTimer * timer = new QTimer();
//       connect(timer,&QTimer::timeout ,this, &Client::ReadData);
//       timer->start(200);
       //connect(tcpSocket, &QIODevice::readyRead, this, &Client::ReadData);


}
void Client::SendData(const char *data)
{
    tcpSocket->write(data);
}
void Client::ReadData()
{
    //if(tcpSocket->bytesAvailable())
    //{
        data_read = tcpSocket->read(cData, 1024);
        qDebug()<<data_read<<" "<<cData;
    //    emit newData();
    //}
}



