

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
    void SendData(QByteArray data);
    void ReadData();
    void ReadData(char *data, quint8 size);
    char cData[1024];

Q_SIGNALS:
    void newData();
private:


    quint16 port;
    quint16 data_read;
};

#endif
