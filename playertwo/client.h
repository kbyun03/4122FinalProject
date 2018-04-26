

#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpSocket>


class QTcpSocket;

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QString ip="192.168.1.2", quint16 port_number = 20000);
    QTcpSocket *tcpSocket = nullptr;
    void SendData(const char *data);
    void ReadData();

Q_SIGNALS:
    void newData();
private:

    char cData[1024];
    quint16 port;
    quint16 data_read;
};

#endif
